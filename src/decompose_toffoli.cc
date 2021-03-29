/** \file
 * Toffoli gate decomposer pass implementation.
 */

#include "decompose_toffoli.h"

#include "ql/utils/vec.h"
#include "ql/com/options/options.h"

namespace ql {

using namespace utils;

static void decompose_toffoli_kernel(
    const ir::KernelRef &kernel,
    const plat::PlatformRef &platform
) {
    QL_DOUT("decompose_toffoli_kernel()");
    auto &cicuit_vec = kernel->c.get_vec();
    for (auto cit = cicuit_vec.begin(); cit != cicuit_vec.end(); ++cit) {
        auto g = *cit;
        QL_DOUT("... decompose_toffoli, considering gate: " << g->qasm());
        ir::GateType gtype = g->type();

        if (gtype == ir::GateType::TOFFOLI || g->name == "toffoli") {
            ir::Kernel toff_kernel("toff_kernel");
            auto opt = com::options::get("decompose_toffoli");

            QL_DOUT("... decompose_toffoli (option=" << opt << "), decomposing gate '" << g->qasm() << "' in new kernel: " << toff_kernel.name);
            toff_kernel.instruction_map = kernel->instruction_map;
            toff_kernel.qubit_count = kernel->qubit_count;
            toff_kernel.cycle_time = kernel->cycle_time;
            toff_kernel.condition = g->condition;
            toff_kernel.cond_operands = g->cond_operands;

            Vec<UInt> goperands = g->operands;
            UInt cq1 = goperands[0];
            UInt cq2 = goperands[1];
            UInt tq = goperands[2];
            if (opt == "AM") {
                toff_kernel.controlled_cnot_AM(tq, cq1, cq2);
            } else {
                toff_kernel.controlled_cnot_NC(tq, cq1, cq2);
            }
            QL_DOUT("... decompose_toffoli, done decomposing toffoli gate in new kernel: " << toff_kernel.name);

            ir::Circuit &toff_ckt = toff_kernel.get_circuit();
            cit = cicuit_vec.erase(cit);
            QL_DOUT("... decompose_toffoli, inserting decomposition of toffoli gate from new kernel: " << toff_kernel.name << " into kernel.c");
            cit = cicuit_vec.insert(cit, toff_ckt.begin(), toff_ckt.end());
            kernel->cycles_valid = false;
            QL_DOUT("... decompose_toffoli, new kernel.c after insertion of decomposition: " << qasm(kernel->c));
        }
    }
    QL_DOUT("... decompose_toffoli, new kernel.c: " << qasm(kernel->c));
    QL_DOUT("decompose_toffoli() [Done] ");
}

void decompose_toffoli(
    const ir::ProgramRef &program,
    const plat::PlatformRef &platform,
    const Str &passname
) {
    auto tdopt = com::options::get("decompose_toffoli");
    if (tdopt == "AM" || tdopt == "NC") {
        QL_IOUT("Decomposing Toffoli ...");
        for (auto &kernel : program->kernels) {
            decompose_toffoli_kernel(kernel, platform);
        }
    } else if (tdopt == "no") {
        QL_IOUT("Not Decomposing Toffoli ...");
    } else {
        QL_FATAL("Unknown option '" << tdopt << "' set for decompose_toffoli");
    }
}

} // namespace ql
