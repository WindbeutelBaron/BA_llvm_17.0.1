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

#define RISCV_INSERT_CORRECT_INSTRUCTION_NAME                                        \
  "RISC-V insert correct at beggining of every Basic Block Pass"

namespace {
  class RISCVInsertCorrectInstruction : public MachineFunctionPass {
  public:
    static char ID;

    RISCVInsertCorrectInstruction() : MachineFunctionPass(ID) {
      initializeRISCVInsertCorrectInstructionPass(*PassRegistry::getPassRegistry());
    }

    bool runOnMachineFunction(MachineFunction &MF) override {
      dbgs() << "Running InsertCorrectInstructionPass on function " <<
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
        BuildMI(MBB, MBB.begin(), DL, TII->get(RISCV::CORRECT))
          .addImm(hash)
          .addImm(branch)
          .addImm(fall_through)
          .addImm(call_target)
          .addImm(return_target);
      }

      return true;
    }

    StringRef getPassName() const override {
      return "RISCV Insert CORRECT Instruction Pass";
    }
  };

  char RISCVInsertCorrectInstruction::ID = 0;
}



INITIALIZE_PASS(RISCVInsertCorrectInstruction, "riscv-insert-correct-instruction",
                RISCV_INSERT_CORRECT_INSTRUCTION_NAME, false, false)

// This function is required for `llvm::create` style pass creation
// and must be implemented in the .cpp file where the pass ID is established.

namespace llvm {

FunctionPass *createRISCVInsertCorrectInstructionPass() {
  return new RISCVInsertCorrectInstruction();
}

} // end of namespace llvm

