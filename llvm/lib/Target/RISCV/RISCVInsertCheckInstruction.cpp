#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "RISCVInstrInfo.h"
#include "RISCVTargetMachine.h"
#include "llvm/InitializePasses.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define RISCV_INSERT_CHECK_INSTRUCTION_NAME                                        \
  "RISC-V insert check at beggining of every Basic Block Pass"

namespace {
  class RISCVInsertCheckInstruction : public MachineFunctionPass {
  public:
    static char ID;

    RISCVInsertCheckInstruction() : MachineFunctionPass(ID) {
      initializeRISCVInsertCheckInstructionPass(*PassRegistry::getPassRegistry());
    }

    bool runOnMachineFunction(MachineFunction &MF) override {
      dbgs() << "Running InsertCheckInstructionPass on function " <<
            MF.getName() << "\n";
      const RISCVInstrInfo *TII =
        static_cast<const RISCVInstrInfo *>(MF.getSubtarget().getInstrInfo());


        // Placeholder immediate values
      uint32_t hash            = 0xFFFFF; // Example 20-bit hash
      uint8_t branch           = 1;
      uint8_t fall_through     = 1;
      uint8_t call_target      = 1;
      uint8_t return_target    = 1;

        // Ensure the values fit within the desired bit widths
      assert(hash            <= 0xFFFFF && "20-bit hash is out of range");
      assert(branch          <= 0x1 && "1-bit status is out of range");
      assert(fall_through    <= 0x1 && "1-bit status is out of range");
      assert(call_target     <= 0x1 && "1-bit status is out of range");
      assert(return_target   <= 0x1 && "1-bit status is out of range");

      for (auto &MBB : MF) {
        const DebugLoc &DL = MBB.findDebugLoc(MBB.begin());
        BuildMI(MBB, MBB.begin(), DL, TII->get(RISCV::CHECK))
          .addImm(hash)
          .addImm(branch)
          .addImm(fall_through)
          .addImm(call_target)
          .addImm(return_target);
      }

      return true;
    }

    StringRef getPassName() const override {
      return "RISCV Insert Check Instruction Pass";
    }
  };

  char RISCVInsertCheckInstruction::ID = 0;
}



INITIALIZE_PASS(RISCVInsertCheckInstruction, "riscv-insert-check-instruction",
                RISCV_INSERT_CHECK_INSTRUCTION_NAME, false, false)

// This function is required for `llvm::create` style pass creation
// and must be implemented in the .cpp file where the pass ID is established.

namespace llvm {

FunctionPass *createRISCVInsertCheckInstructionPass() {
  return new RISCVInsertCheckInstruction();
}

} // end of namespace llvm

