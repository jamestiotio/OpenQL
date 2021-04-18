/** \file
 * Defines the QuTech Central Controller Q1 processor assembly generator pass.
 */

#include "ql/arch/cc/pass/gen/vq1asm/vq1asm.h"

#include "ql/pmgr/pass_types.h"
#include "detail/backend.h"

namespace ql {
namespace arch {
namespace cc {
namespace pass {
namespace gen {
namespace vq1asm {

/**
 * Dumps docs for the code generator.
 */
void GenerateVQ1AsmPass::dump_docs(
    std::ostream &os,
    const utils::Str &line_prefix
) const {
    utils::dump_str(os, line_prefix, R"(
    Assembly code generator for the Q1 processor in the QuTech Central
    Controller, version )" CC_BACKEND_VERSION_STRING R"(

    This pass actually generates three files:
     - <prefix>.vq1asm: the assembly code output file;
     - <prefix>.map: the instrument configuration file; and
     - <prefix>.vcd: a VCD (value change dump) file for viewing the waveforms
       that the program outputs.

    The pass is compile-time configured with the following options:
     - OPT_CC_SCHEDULE_RC = )"           + utils::to_string(OPT_CC_SCHEDULE_RC)           + R"(
     - OPT_SUPPORT_STATIC_CODEWORDS = )" + utils::to_string(OPT_SUPPORT_STATIC_CODEWORDS) + R"(
     - OPT_STATIC_CODEWORDS_ARRAYS = )"  + utils::to_string(OPT_STATIC_CODEWORDS_ARRAYS)  + R"(
     - OPT_VECTOR_MODE = )"              + utils::to_string(OPT_VECTOR_MODE)              + R"(
     - OPT_FEEDBACK = )"                 + utils::to_string(OPT_FEEDBACK)                 + R"(
     - OPT_PRAGMA = )"                   + utils::to_string(OPT_PRAGMA)                   + R"(
    )");
}

/**
 * Constructs a code generator.
 */
GenerateVQ1AsmPass::GenerateVQ1AsmPass(
    const utils::Ptr<const pmgr::PassFactory> &pass_factory,
    const utils::Str &instance_name,
    const utils::Str &type_name
) : pmgr::pass_types::ProgramTransformation(pass_factory, instance_name, type_name) {

    options.add_str(
        "map_input_file",
        "Specifies the input map filename."
    );

    options.add_bool(
        "verbose",
        "Selects whether verbose comments should be added to the generated "
        ".vq1asm file.",
        true
    );

    options.add_bool(
        "run_once",
        "When set, the emitted .vq1asm program runs once instead of repeating "
        "indefinitely."
    );

}

/**
 * Runs the code generator.
 */
utils::Int GenerateVQ1AsmPass::run(
    const ir::ProgramRef &program,
    const pmgr::pass_types::Context &context
) const {

    // Make sure that the incoming code is scheduled, as expected.
    for (const auto &kernel : program->kernels) {
        if (!kernel->cycles_valid) {
            throw utils::Exception(
                "The code going into the CC backend must be scheduled, but isn't!"
            );
        }
    }

    // Parse the options.
    auto options = utils::Ptr<detail::Options>::make();
    options->output_prefix = com::options::get("output_dir") + "/" + program->unique_name;
    options->map_input_file = com::options::get("backend_cc_map_input_file");
    options->run_once = com::options::get("backend_cc_run_once") == "yes";
    options->verbose = com::options::get("backend_cc_verbose") == "yes";

    // Run the backend.
    detail::Backend().compile(program, options.as_const());

    return 0;
}

} // namespace vq1asm
} // namespace gen
} // namespace pass
} // namespace cc
} // namespace arch
} // namespace ql
