#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "RISCVInstrInfo.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/Analysis/CallGraph.h"
#include "RISCVTargetMachine.h"
#include "llvm/Support/raw_ostream.h"
#include <map>
#include <vector>

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

      const RISCVInstrInfo *TII =
        static_cast<const RISCVInstrInfo *>(MF.getSubtarget().getInstrInfo());

      uint32_t Hash = 0xFFFFF;

      std::map<MachineBasicBlock*, std::vector<MachineBasicBlock*>> PredecessorMap;
      std::map<MachineBasicBlock*, uint32_t> BranchCountMap;
      uint32_t BranchCount;
      for (MachineBasicBlock &MBB : MF) {
        BranchCount = 0;
        for (MachineInstrBundleIterator<llvm::MachineInstr, true> I = MBB.rbegin(), E = MBB.rend(); I != E; ++I) {
          MachineInstr &MI = *I;
          if (MI.isCall()) {
            BuildMI(MBB, MI, MI.getDebugLoc(),
                    TII->get(RISCV::CORRECT))
                .addImm(Hash);
          }
          if (MI.isBranch()) {
            BranchCount++;
          }
        }
        for (MachineBasicBlock *PredMBB : MBB.predecessors()) {
          PredecessorMap[&MBB].push_back(PredMBB);
        }
        BranchCountMap[&MBB] = BranchCount;
      }

      auto CompareBlocks = [&BranchCountMap](llvm::MachineBasicBlock* a, llvm::MachineBasicBlock* b) {
        return BranchCountMap[a] > BranchCountMap[b];
      };
      Hash = 0;
      for (std::pair<MachineBasicBlock* const, std::vector<MachineBasicBlock*>> &Entry : PredecessorMap) {
        if (Entry.second.size() >= 2) {
          std::sort(Entry.second.begin(), Entry.second.end(), CompareBlocks);
          for (size_t i = 1; i < Entry.second.size(); ++i) {
            MachineBasicBlock *PredMBB = Entry.second[i];
            if (BranchCountMap[PredMBB] > 1) {
              MachineInstrBundleIterator<MachineInstr, true> MI = findPosition(PredMBB, Entry.first);
              BuildMI(*PredMBB, *MI, MI->getDebugLoc(),
                      TII->get(RISCV::CORRECT))
                  .addImm(Hash);
            } else {
              BuildMI(*PredMBB, PredMBB->back(), PredMBB->back().getDebugLoc(),
                      TII->get(RISCV::CORRECT))
                  .addImm(Hash);
            }
          }
          Hash++;
        }
      }
      return true;
    }


    StringRef getPassName() const override {
      return "RISCV Insert CORRECT Instruction Pass";
    }

  private:
    MachineInstrBundleIterator<MachineInstr, true> findPosition(MachineBasicBlock *PredMBB, MachineBasicBlock *TargetBB) {
      for (MachineInstrBundleIterator<MachineInstr, true> MI = PredMBB->rbegin(), E = PredMBB->rend(); MI != E; ++MI) {
        if (MI->isBranch()) {
          for (const MachineOperand &MO : MI->operands()) {
            if (MO.isMBB()) {
              if (MO.getMBB() == TargetBB) {
                return MI;
              }
            }
          }
        }
      }
      return NULL;
    }
  };

  char RISCVInsertCorrectInstruction::ID = 0;
}



INITIALIZE_PASS(RISCVInsertCorrectInstruction, "riscv-insert-correct-instruction",
                RISCV_INSERT_CORRECT_INSTRUCTION_NAME, false, false)

namespace llvm {

FunctionPass *createRISCVInsertCorrectInstructionPass() {
  return new RISCVInsertCorrectInstruction();
}

}

