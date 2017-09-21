/**
 * @file   hardware_configuration.h
 * @date   07/2017
 * @author Nader Khammassi
 * @brief  hardware configuration loader
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <typeinfo>

#include <cmath>

#include <ql/openql.h>
#include <ql/exception.h>
#include <ql/json.h>
#include <ql/gate.h>



namespace ql
{

typedef std::map<std::string,ql::custom_gate *> instruction_map_t;

/**
 * loading hardware configuration
 */
class hardware_configuration
{

public:

    /**
     * ctor
     */
    hardware_configuration(std::string config_file_name) : config_file_name(config_file_name)
    {
    }

    /**
     * load
     */
    void load(ql::instruction_map_t& instruction_map, json& instruction_settings, json& hardware_settings) throw (ql::exception)
    {
        json config;
        try
        {
            config = load_json(config_file_name);
        }
        catch (json::exception e)
        {
            throw ql::exception("[x] error : ql::hardware_configuration::load() :  failed to load the hardware config file : malformed json file ! : \n\t"+
                                std::string(e.what()),false);
        }

        // load eqasm compiler backend
        if (config["eqasm_compiler"].is_null())
        {
            println("[x] error : ql::hardware_configuration::load() : eqasm compiler backend is not specified in the hardware config file !");
            // throw std::exception();
            throw ql::exception("[x] error : ql::hardware_configuration::load() : eqasm compiler backend is not specified in the hardware config file !",false);
        }
        else
        {
            eqasm_compiler_name = config["eqasm_compiler"];
        }

        // load hardware_settings
        if (config["hardware_settings"].is_null())
        {
            println("[x] error : ql::hardware_configuration::load() : 'hardware_settings' section is not specified in the hardware config file !");
            // throw std::exception();
            throw ql::exception("[x] error : ql::hardware_configuration::load() : 'hardware_settings' section is not specified in the hardware config file !",false);
        }
        else
        {
            hardware_settings    = config["hardware_settings"];
        }

        // load instruction_settings
        if (config["instructions"].is_null())
        {
            println("[x] error : ql::hardware_configuration::load() : 'instructions' section is not specified in the hardware config file !");
            // throw std::exception();
            throw ql::exception("[x] error : ql::hardware_configuration::load() : 'instructions' section is not specified in the hardware config file !",false);
        }
        else
        {
            instruction_settings = config["instructions"];
        }

        // create the control store

        // load instructions
        json instructions = config["instructions"];
        // std::cout << instructions.dump(4) << std::endl;
        for (json::iterator it = instructions.begin(); it != instructions.end(); ++it)
        {
            std::string  name = it.key();
            str::lower_case(name);
            json         attr = *it; //.value();

            std::string simple_instruction_name(name);
            if( attr.find("cc_light_instr") != attr.end() )
            {
               simple_instruction_name = attr["cc_light_instr"];
            }

            // supported_gates.push_back(load_instruction(name,attr));
            // check for duplicate operations
            if (instruction_map.find(name) != instruction_map.end())
                println("[!] warning : ql::hardware_configuration::load() : instruction '" << name << "' redefined : the old definition is overwritten !");

            instruction_map[name] = load_instruction(simple_instruction_name, attr);
            // println("instruction " << name << " loaded.");
        }
        
        // load gate decomposition/aliases
        if (!config["gate_decomposition"].is_null())
        {
           json gate_decomposition = config["gate_decomposition"];
           for (json::iterator it = gate_decomposition.begin(); it != gate_decomposition.end(); ++it)
           {
              std::string  name = it.key();
              str::lower_case(name);
              json         attr = *it; //.value();
              // check for duplicate operations
              if (instruction_map.find(name) != instruction_map.end())
                println("[!] warning : ql::hardware_configuration::load() : composite instruction '" << name << "' redefined : the old definition is overwritten !");

              if (!attr.is_array())
                 throw ql::exception("[x] error : ql::hardware_configuration::load() : 'gate_decomposition' section : gate '"+name+"' is malformed !",false);
              std::vector<gate *> gs;
              for (size_t i=0; i<attr.size(); ++i)
              {
                 std::string instr_name = attr[i];
                 // println("checking if instruction '" << instr_name << "' is already defined...");
                 if (instruction_map.find(instr_name) == instruction_map.end())
                       throw ql::exception("[x] error : ql::hardware_configuration::load() : 'gate_decomposition' section : instruction "+instr_name+" composing gate '"+name+"' is not defined !",false);
                 gs.push_back(instruction_map[instr_name]);
              }
              instruction_map[name] = new composite_gate(name,gs);
           }
        }
    }

    /**
     * load_instruction
     */
    ql::custom_gate * load_instruction(std::string name, json& instr)
    {
        custom_gate * g = new custom_gate(name);
        // skip alias fo now
        if (!instr["alias"].is_null()) // != "null")
        {
            // todo : look for the target aliased gate
            //        copy it with the new name
            println("[!] warning : hardware_configuration::load() : alias '" << name << "' detected but ignored (not supported yet : please define your instruction).");
            return g;
        }
        try
        {
            g->load(instr);
        }
        catch (ql::exception e)
        {
            println("[e] error while loading instruction '" << name << "' : " << e.what());
            throw e;
            // ql::exception("[x] error : hardware_configuration::load_instruction() : error while loading instruction '" + name + "' : " + e.what(),false);
        }
        // g->print_info();
        return g;
    }

public:

    std::string       config_file_name;
    std::string       eqasm_compiler_name;

};
}
