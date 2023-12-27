#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "RISCVInstrInfo.h"
#include "RISCVTargetMachine.h"
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
      const RISCVInstrInfo *TII =
          static_cast<const RISCVInstrInfo *>(MF.getSubtarget().getInstrInfo());

      for (auto &MBB : MF) {
        uint32_t Hash = 0xFFFFF;
        uint8_t Branch = 0;
        uint8_t FallThrough = 0;
        uint8_t CallTarget = 0;
        uint8_t ReturnTarget = 0;

        if(MBB.getName() == "entry") {
          if(MF.getName() != "main"){
            CallTarget = 1;
          }
        }

        MachineInstrBundleIterator<llvm::MachineInstr> FirstInstruction = MBB.begin();

        BuildMI(MBB, FirstInstruction, FirstInstruction->getDebugLoc(), TII->get(RISCV::CHECK))
            .addImm(Hash)
            .addImm(Branch)
            .addImm(FallThrough)
            .addImm(CallTarget)
            .addImm(ReturnTarget);

        CallTarget = 0;

        for (MachineInstrBundleIterator<llvm::MachineInstr, true> I = MBB.rbegin(), E = MBB.rend(); I != E; ++I) {
          if (I == MBB.rbegin()) continue;

          MachineInstr &MI = *I;

          if (MI.isBranch()) {
            FallThrough = 1;
            BuildMI(MBB, MI.getNextNode(), MI.getDebugLoc(),
                    TII->get(RISCV::CHECK))
                .addImm(Hash)
                .addImm(Branch)
                .addImm(FallThrough)
                .addImm(CallTarget)
                .addImm(ReturnTarget);
            FallThrough = 0;
            continue;
          }

          if (MI.isCall()) {
            ReturnTarget = 1;
            BuildMI(MBB, MI.getNextNode(), MI.getDebugLoc(),
                    TII->get(RISCV::CHECK))
                .addImm(Hash)
                .addImm(Branch)
                .addImm(FallThrough)
                .addImm(CallTarget)
                .addImm(ReturnTarget);
            ReturnTarget = 0;
            continue;
          }
        }
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

namespace llvm {

FunctionPass *createRISCVInsertCheckInstructionPass() {
  return new RISCVInsertCheckInstruction();
}

}

