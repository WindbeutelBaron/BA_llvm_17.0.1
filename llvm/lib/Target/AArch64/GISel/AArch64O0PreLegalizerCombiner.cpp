//=== lib/CodeGen/GlobalISel/AArch64O0PreLegalizerCombiner.cpp ------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This pass does combining of machine instructions at the generic MI level,
// before the legalizer.
//
//===----------------------------------------------------------------------===//

#include "AArch64GlobalISelUtils.h"
#include "AArch64TargetMachine.h"
#include "llvm/CodeGen/GlobalISel/Combiner.h"
#include "llvm/CodeGen/GlobalISel/CombinerHelper.h"
#include "llvm/CodeGen/GlobalISel/CombinerInfo.h"
#include "llvm/CodeGen/GlobalISel/GIMatchTableExecutor.h"
#include "llvm/CodeGen/GlobalISel/GIMatchTableExecutorImpl.h"
#include "llvm/CodeGen/GlobalISel/GISelKnownBits.h"
#include "llvm/CodeGen/GlobalISel/MIPatternMatch.h"
#include "llvm/CodeGen/GlobalISel/MachineIRBuilder.h"
#include "llvm/CodeGen/MachineDominators.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Debug.h"

#define GET_GICOMBINER_DEPS
#include "AArch64GenO0PreLegalizeGICombiner.inc"
#undef GET_GICOMBINER_DEPS

#define DEBUG_TYPE "aarch64-O0-prelegalizer-combiner"

using namespace llvm;
using namespace MIPatternMatch;
namespace {
#define GET_GICOMBINER_TYPES
#include "AArch64GenO0PreLegalizeGICombiner.inc"
#undef GET_GICOMBINER_TYPES

class AArch64O0PreLegalizerCombinerImpl : public GIMatchTableExecutor {
protected:
  CombinerHelper &Helper;
  const AArch64O0PreLegalizerCombinerImplRuleConfig &RuleConfig;

  const AArch64Subtarget &STI;
  GISelChangeObserver &Observer;
  MachineIRBuilder &B;
  MachineFunction &MF;

  MachineRegisterInfo &MRI;

public:
  AArch64O0PreLegalizerCombinerImpl(
      const AArch64O0PreLegalizerCombinerImplRuleConfig &RuleConfig,
      GISelChangeObserver &Observer, MachineIRBuilder &B,
      CombinerHelper &Helper);

  static const char *getName() { return "AArch64O0PreLegalizerCombiner"; }

  bool tryCombineAll(MachineInstr &I) const;

private:
#define GET_GICOMBINER_CLASS_MEMBERS
#include "AArch64GenO0PreLegalizeGICombiner.inc"
#undef GET_GICOMBINER_CLASS_MEMBERS
};

#define GET_GICOMBINER_IMPL
#include "AArch64GenO0PreLegalizeGICombiner.inc"
#undef GET_GICOMBINER_IMPL

AArch64O0PreLegalizerCombinerImpl::AArch64O0PreLegalizerCombinerImpl(
    const AArch64O0PreLegalizerCombinerImplRuleConfig &RuleConfig,
    GISelChangeObserver &Observer, MachineIRBuilder &B, CombinerHelper &Helper)
    : Helper(Helper), RuleConfig(RuleConfig),
      STI(B.getMF().getSubtarget<AArch64Subtarget>()), Observer(Observer), B(B),
      MF(B.getMF()), MRI(*B.getMRI()),
#define GET_GICOMBINER_CONSTRUCTOR_INITS
#include "AArch64GenO0PreLegalizeGICombiner.inc"
#undef GET_GICOMBINER_CONSTRUCTOR_INITS
{
}

class AArch64O0PreLegalizerCombinerInfo : public CombinerInfo {
  GISelKnownBits *KB;
  MachineDominatorTree *MDT;
  AArch64O0PreLegalizerCombinerImplRuleConfig RuleConfig;

public:
  AArch64O0PreLegalizerCombinerInfo(bool EnableOpt, bool OptSize, bool MinSize,
                                    GISelKnownBits *KB,
                                    MachineDominatorTree *MDT)
      : CombinerInfo(/*AllowIllegalOps*/ true, /*ShouldLegalizeIllegal*/ false,
                     /*LegalizerInfo*/ nullptr, EnableOpt, OptSize, MinSize),
        KB(KB), MDT(MDT) {
    if (!RuleConfig.parseCommandLineOption())
      report_fatal_error("Invalid rule identifier");
  }

  bool combine(GISelChangeObserver &Observer, MachineInstr &MI,
               MachineIRBuilder &B) const override;
};

bool AArch64O0PreLegalizerCombinerInfo::combine(GISelChangeObserver &Observer,
                                                MachineInstr &MI,
                                                MachineIRBuilder &B) const {
  CombinerHelper Helper(Observer, B, /*IsPreLegalize*/ true, KB, MDT);
  AArch64O0PreLegalizerCombinerImpl Impl(RuleConfig, Observer, B, Helper);
  Impl.setupMF(*MI.getMF(), KB);

  if (Impl.tryCombineAll(MI))
    return true;

  unsigned Opc = MI.getOpcode();
  switch (Opc) {
  case TargetOpcode::G_CONCAT_VECTORS:
    return Helper.tryCombineConcatVectors(MI);
  case TargetOpcode::G_SHUFFLE_VECTOR:
    return Helper.tryCombineShuffleVector(MI);
  case TargetOpcode::G_MEMCPY_INLINE:
    return Helper.tryEmitMemcpyInline(MI);
  case TargetOpcode::G_MEMCPY:
  case TargetOpcode::G_MEMMOVE:
  case TargetOpcode::G_MEMSET: {
    // At -O0 set a maxlen of 32 to inline;
    unsigned MaxLen = 32;
    // Try to inline memcpy type calls if optimizations are enabled.
    if (Helper.tryCombineMemCpyFamily(MI, MaxLen))
      return true;
    if (Opc == TargetOpcode::G_MEMSET)
      return llvm::AArch64GISelUtils::tryEmitBZero(MI, B, EnableMinSize);
    return false;
  }
  }

  return false;
}

// Pass boilerplate
// ================

class AArch64O0PreLegalizerCombiner : public MachineFunctionPass {
public:
  static char ID;

  AArch64O0PreLegalizerCombiner();

  StringRef getPassName() const override {
    return "AArch64O0PreLegalizerCombiner";
  }

  bool runOnMachineFunction(MachineFunction &MF) override;

  void getAnalysisUsage(AnalysisUsage &AU) const override;
};
} // end anonymous namespace

void AArch64O0PreLegalizerCombiner::getAnalysisUsage(AnalysisUsage &AU) const {
  AU.addRequired<TargetPassConfig>();
  AU.setPreservesCFG();
  getSelectionDAGFallbackAnalysisUsage(AU);
  AU.addRequired<GISelKnownBitsAnalysis>();
  AU.addPreserved<GISelKnownBitsAnalysis>();
  MachineFunctionPass::getAnalysisUsage(AU);
}

AArch64O0PreLegalizerCombiner::AArch64O0PreLegalizerCombiner()
    : MachineFunctionPass(ID) {
  initializeAArch64O0PreLegalizerCombinerPass(*PassRegistry::getPassRegistry());
}

bool AArch64O0PreLegalizerCombiner::runOnMachineFunction(MachineFunction &MF) {
  if (MF.getProperties().hasProperty(
          MachineFunctionProperties::Property::FailedISel))
    return false;
  auto &TPC = getAnalysis<TargetPassConfig>();

  const Function &F = MF.getFunction();
  GISelKnownBits *KB = &getAnalysis<GISelKnownBitsAnalysis>().get(MF);
  AArch64O0PreLegalizerCombinerInfo PCInfo(
      false, F.hasOptSize(), F.hasMinSize(), KB, nullptr /* MDT */);
  Combiner C(PCInfo, &TPC);
  return C.combineMachineInstrs(MF, nullptr /* CSEInfo */);
}

char AArch64O0PreLegalizerCombiner::ID = 0;
INITIALIZE_PASS_BEGIN(AArch64O0PreLegalizerCombiner, DEBUG_TYPE,
                      "Combine AArch64 machine instrs before legalization",
                      false, false)
INITIALIZE_PASS_DEPENDENCY(TargetPassConfig)
INITIALIZE_PASS_DEPENDENCY(GISelKnownBitsAnalysis)
INITIALIZE_PASS_DEPENDENCY(GISelCSEAnalysisWrapperPass)
INITIALIZE_PASS_END(AArch64O0PreLegalizerCombiner, DEBUG_TYPE,
                    "Combine AArch64 machine instrs before legalization", false,
                    false)

namespace llvm {
FunctionPass *createAArch64O0PreLegalizerCombiner() {
  return new AArch64O0PreLegalizerCombiner();
}
} // end namespace llvm
