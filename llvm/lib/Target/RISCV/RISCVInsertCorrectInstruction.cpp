#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "RISCVInstrInfo.h"
#include "llvm/IR/DebugLoc.h"
#include "llvm/IR/DebugInfoMetadata.h"
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
      uint32_t hash = 0; // Example 20-bit hash

        // Ensure the values fit within the desired bit widths
      assert(hash <= 0xFFFFF && "20-bit hash is out of range");
      for (auto &MBB : MF) {
        for (auto I = MBB.rbegin(), E = MBB.rend(); I != E; ++I) {
            MachineInstr &MI = *I;
            if (MI.isBranch() || MI.isReturn() || MI.isCall() || MI.getOpcode() == RISCV::JAL || MI.getOpcode() == RISCV::JALR) {
                    dbgs() << "Instruction: " << MI << "\n";
                    for (const MachineOperand &MO : MI.operands()) {
                        dbgs() << "  Operand Type: ";
                        if (MO.isReg()) dbgs() << "Register";
                        else if (MO.isImm()) dbgs() << "Immediate";
                        else if (MO.isFPImm()) dbgs() << "Floating Point Immediate";
                        else if (MO.isMBB()) dbgs() << "Basic Block";
                        else if (MO.isGlobal()) dbgs() << "Global Address";
                        else if (MO.isSymbol()) dbgs() << "Symbol";
                        else if (MO.isCImm()) dbgs() << "Constant Integer";
                        else if (MO.isCFIIndex()) dbgs() << "CFI Index";
                        else dbgs() << "Other";
                        dbgs() << "\n";
                    }
                    
                    BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(RISCV::CORRECT))
                      .addImm(hash);
            }
        }
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

namespace llvm {

FunctionPass *createRISCVInsertCorrectInstructionPass() {
  return new RISCVInsertCorrectInstruction();
}

} // end of namespace llvm

