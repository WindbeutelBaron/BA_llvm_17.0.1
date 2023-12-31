; NOTE: Assertions have been autogenerated by utils/update_test_checks.py UTC_ARGS: --version 2
; RUN: opt < %s -mtriple=x86_64-unknown -passes=slp-vectorizer -S | FileCheck %s --check-prefixes=SSE
; RUN: opt < %s -mtriple=x86_64-unknown -mcpu=corei7-avx -passes=slp-vectorizer -S | FileCheck %s --check-prefixes=AVX
declare float @llvm.maximum.f32(float, float)
declare float @llvm.minimum.f32(float, float)
declare double @llvm.maximum.f64(double, double)
declare double @llvm.minimum.f64(double, double)

@srcA64 = common global [8 x double] zeroinitializer, align 64
@srcB64 = common global [8 x double] zeroinitializer, align 64
@srcC64 = common global [8 x double] zeroinitializer, align 64
@srcA32 = common global [16 x float] zeroinitializer, align 64
@srcB32 = common global [16 x float] zeroinitializer, align 64
@srcC32 = common global [16 x float] zeroinitializer, align 64
@dst64 = common global [8 x double] zeroinitializer, align 64
@dst32 = common global [16 x float] zeroinitializer, align 64

define void @fmaximum_2f64() {
; SSE-LABEL: define void @fmaximum_2f64() {
; SSE-NEXT:    [[TMP1:%.*]] = load <2 x double>, ptr @srcA64, align 8
; SSE-NEXT:    [[TMP2:%.*]] = load <2 x double>, ptr @srcB64, align 8
; SSE-NEXT:    [[TMP3:%.*]] = call <2 x double> @llvm.maximum.v2f64(<2 x double> [[TMP1]], <2 x double> [[TMP2]])
; SSE-NEXT:    store <2 x double> [[TMP3]], ptr @dst64, align 8
; SSE-NEXT:    ret void
;
; AVX-LABEL: define void @fmaximum_2f64
; AVX-SAME: () #[[ATTR1:[0-9]+]] {
; AVX-NEXT:    [[TMP1:%.*]] = load <2 x double>, ptr @srcA64, align 8
; AVX-NEXT:    [[TMP2:%.*]] = load <2 x double>, ptr @srcB64, align 8
; AVX-NEXT:    [[TMP3:%.*]] = call <2 x double> @llvm.maximum.v2f64(<2 x double> [[TMP1]], <2 x double> [[TMP2]])
; AVX-NEXT:    store <2 x double> [[TMP3]], ptr @dst64, align 8
; AVX-NEXT:    ret void
;
  %a0 = load double, ptr @srcA64, align 8
  %a1 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 1), align 8
  %b0 = load double, ptr @srcB64, align 8
  %b1 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 1), align 8
  %fmaximum0 = call double @llvm.maximum.f64(double %a0, double %b0)
  %fmaximum1 = call double @llvm.maximum.f64(double %a1, double %b1)
  store double %fmaximum0, ptr @dst64, align 8
  store double %fmaximum1, ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 1), align 8
  ret void
}

define void @fmaximum_4f64() {
; SSE-LABEL: define void @fmaximum_4f64() {
; SSE-NEXT:    [[TMP1:%.*]] = load <2 x double>, ptr @srcA64, align 8
; SSE-NEXT:    [[TMP2:%.*]] = load <2 x double>, ptr @srcB64, align 8
; SSE-NEXT:    [[TMP3:%.*]] = call <2 x double> @llvm.maximum.v2f64(<2 x double> [[TMP1]], <2 x double> [[TMP2]])
; SSE-NEXT:    store <2 x double> [[TMP3]], ptr @dst64, align 8
; SSE-NEXT:    [[TMP4:%.*]] = load <2 x double>, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 2), align 8
; SSE-NEXT:    [[TMP5:%.*]] = load <2 x double>, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 2), align 8
; SSE-NEXT:    [[TMP6:%.*]] = call <2 x double> @llvm.maximum.v2f64(<2 x double> [[TMP4]], <2 x double> [[TMP5]])
; SSE-NEXT:    store <2 x double> [[TMP6]], ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 2), align 8
; SSE-NEXT:    ret void
;
; AVX-LABEL: define void @fmaximum_4f64
; AVX-SAME: () #[[ATTR1]] {
; AVX-NEXT:    [[TMP1:%.*]] = load <4 x double>, ptr @srcA64, align 8
; AVX-NEXT:    [[TMP2:%.*]] = load <4 x double>, ptr @srcB64, align 8
; AVX-NEXT:    [[TMP3:%.*]] = call <4 x double> @llvm.maximum.v4f64(<4 x double> [[TMP1]], <4 x double> [[TMP2]])
; AVX-NEXT:    store <4 x double> [[TMP3]], ptr @dst64, align 8
; AVX-NEXT:    ret void
;
  %a0 = load double, ptr @srcA64, align 8
  %a1 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 1), align 8
  %a2 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 2), align 8
  %a3 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 3), align 8
  %b0 = load double, ptr @srcB64, align 8
  %b1 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 1), align 8
  %b2 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 2), align 8
  %b3 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 3), align 8
  %fmaximum0 = call double @llvm.maximum.f64(double %a0, double %b0)
  %fmaximum1 = call double @llvm.maximum.f64(double %a1, double %b1)
  %fmaximum2 = call double @llvm.maximum.f64(double %a2, double %b2)
  %fmaximum3 = call double @llvm.maximum.f64(double %a3, double %b3)
  store double %fmaximum0, ptr @dst64, align 8
  store double %fmaximum1, ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 1), align 8
  store double %fmaximum2, ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 2), align 8
  store double %fmaximum3, ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 3), align 8
  ret void
}

define void @fmaximum_8f64() {
; SSE-LABEL: define void @fmaximum_8f64() {
; SSE-NEXT:    [[TMP1:%.*]] = load <2 x double>, ptr @srcA64, align 4
; SSE-NEXT:    [[TMP2:%.*]] = load <2 x double>, ptr @srcB64, align 4
; SSE-NEXT:    [[TMP3:%.*]] = call <2 x double> @llvm.maximum.v2f64(<2 x double> [[TMP1]], <2 x double> [[TMP2]])
; SSE-NEXT:    store <2 x double> [[TMP3]], ptr @dst64, align 4
; SSE-NEXT:    [[TMP4:%.*]] = load <2 x double>, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 2), align 4
; SSE-NEXT:    [[TMP5:%.*]] = load <2 x double>, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 2), align 4
; SSE-NEXT:    [[TMP6:%.*]] = call <2 x double> @llvm.maximum.v2f64(<2 x double> [[TMP4]], <2 x double> [[TMP5]])
; SSE-NEXT:    store <2 x double> [[TMP6]], ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 2), align 4
; SSE-NEXT:    [[TMP7:%.*]] = load <2 x double>, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 4), align 4
; SSE-NEXT:    [[TMP8:%.*]] = load <2 x double>, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 4), align 4
; SSE-NEXT:    [[TMP9:%.*]] = call <2 x double> @llvm.maximum.v2f64(<2 x double> [[TMP7]], <2 x double> [[TMP8]])
; SSE-NEXT:    store <2 x double> [[TMP9]], ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 4), align 4
; SSE-NEXT:    [[TMP10:%.*]] = load <2 x double>, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 6), align 4
; SSE-NEXT:    [[TMP11:%.*]] = load <2 x double>, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 6), align 4
; SSE-NEXT:    [[TMP12:%.*]] = call <2 x double> @llvm.maximum.v2f64(<2 x double> [[TMP10]], <2 x double> [[TMP11]])
; SSE-NEXT:    store <2 x double> [[TMP12]], ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 6), align 4
; SSE-NEXT:    ret void
;
; AVX-LABEL: define void @fmaximum_8f64
; AVX-SAME: () #[[ATTR1]] {
; AVX-NEXT:    [[TMP1:%.*]] = load <4 x double>, ptr @srcA64, align 4
; AVX-NEXT:    [[TMP2:%.*]] = load <4 x double>, ptr @srcB64, align 4
; AVX-NEXT:    [[TMP3:%.*]] = call <4 x double> @llvm.maximum.v4f64(<4 x double> [[TMP1]], <4 x double> [[TMP2]])
; AVX-NEXT:    store <4 x double> [[TMP3]], ptr @dst64, align 4
; AVX-NEXT:    [[TMP4:%.*]] = load <4 x double>, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 4), align 4
; AVX-NEXT:    [[TMP5:%.*]] = load <4 x double>, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 4), align 4
; AVX-NEXT:    [[TMP6:%.*]] = call <4 x double> @llvm.maximum.v4f64(<4 x double> [[TMP4]], <4 x double> [[TMP5]])
; AVX-NEXT:    store <4 x double> [[TMP6]], ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 4), align 4
; AVX-NEXT:    ret void
;
  %a0 = load double, ptr @srcA64, align 4
  %a1 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 1), align 4
  %a2 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 2), align 4
  %a3 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 3), align 4
  %a4 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 4), align 4
  %a5 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 5), align 4
  %a6 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 6), align 4
  %a7 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcA64, i32 0, i64 7), align 4
  %b0 = load double, ptr @srcB64, align 4
  %b1 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 1), align 4
  %b2 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 2), align 4
  %b3 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 3), align 4
  %b4 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 4), align 4
  %b5 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 5), align 4
  %b6 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 6), align 4
  %b7 = load double, ptr getelementptr inbounds ([8 x double], ptr @srcB64, i32 0, i64 7), align 4
  %fmaximum0 = call double @llvm.maximum.f64(double %a0, double %b0)
  %fmaximum1 = call double @llvm.maximum.f64(double %a1, double %b1)
  %fmaximum2 = call double @llvm.maximum.f64(double %a2, double %b2)
  %fmaximum3 = call double @llvm.maximum.f64(double %a3, double %b3)
  %fmaximum4 = call double @llvm.maximum.f64(double %a4, double %b4)
  %fmaximum5 = call double @llvm.maximum.f64(double %a5, double %b5)
  %fmaximum6 = call double @llvm.maximum.f64(double %a6, double %b6)
  %fmaximum7 = call double @llvm.maximum.f64(double %a7, double %b7)
  store double %fmaximum0, ptr @dst64, align 4
  store double %fmaximum1, ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 1), align 4
  store double %fmaximum2, ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 2), align 4
  store double %fmaximum3, ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 3), align 4
  store double %fmaximum4, ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 4), align 4
  store double %fmaximum5, ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 5), align 4
  store double %fmaximum6, ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 6), align 4
  store double %fmaximum7, ptr getelementptr inbounds ([8 x double], ptr @dst64, i32 0, i64 7), align 4
  ret void
}

define double @reduction_v2f64(ptr %p) {
; SSE-LABEL: define double @reduction_v2f64
; SSE-SAME: (ptr [[P:%.*]]) {
; SSE-NEXT:    [[G1:%.*]] = getelementptr inbounds double, ptr [[P]], i64 1
; SSE-NEXT:    [[T0:%.*]] = load double, ptr [[P]], align 4
; SSE-NEXT:    [[T1:%.*]] = load double, ptr [[G1]], align 4
; SSE-NEXT:    [[M1:%.*]] = tail call double @llvm.maximum.f64(double [[T1]], double [[T0]])
; SSE-NEXT:    ret double [[M1]]
;
; AVX-LABEL: define double @reduction_v2f64
; AVX-SAME: (ptr [[P:%.*]]) #[[ATTR1]] {
; AVX-NEXT:    [[G1:%.*]] = getelementptr inbounds double, ptr [[P]], i64 1
; AVX-NEXT:    [[T0:%.*]] = load double, ptr [[P]], align 4
; AVX-NEXT:    [[T1:%.*]] = load double, ptr [[G1]], align 4
; AVX-NEXT:    [[M1:%.*]] = tail call double @llvm.maximum.f64(double [[T1]], double [[T0]])
; AVX-NEXT:    ret double [[M1]]
;
  %g1 = getelementptr inbounds double, ptr %p, i64 1
  %t0 = load double, ptr %p, align 4
  %t1 = load double, ptr %g1, align 4
  %m1 = tail call double @llvm.maximum.f64(double %t1, double %t0)
  ret double %m1
}

define float @reduction_v4f32(ptr %p) {
; SSE-LABEL: define float @reduction_v4f32
; SSE-SAME: (ptr [[P:%.*]]) {
; SSE-NEXT:    [[TMP1:%.*]] = load <4 x float>, ptr [[P]], align 4
; SSE-NEXT:    [[TMP2:%.*]] = call float @llvm.vector.reduce.fmaximum.v4f32(<4 x float> [[TMP1]])
; SSE-NEXT:    ret float [[TMP2]]
;
; AVX-LABEL: define float @reduction_v4f32
; AVX-SAME: (ptr [[P:%.*]]) #[[ATTR1]] {
; AVX-NEXT:    [[TMP1:%.*]] = load <4 x float>, ptr [[P]], align 4
; AVX-NEXT:    [[TMP2:%.*]] = call float @llvm.vector.reduce.fmaximum.v4f32(<4 x float> [[TMP1]])
; AVX-NEXT:    ret float [[TMP2]]
;
  %g1 = getelementptr inbounds float, ptr %p, i64 1
  %g2 = getelementptr inbounds float, ptr %p, i64 2
  %g3 = getelementptr inbounds float, ptr %p, i64 3
  %t0 = load float, ptr %p, align 4
  %t1 = load float, ptr %g1, align 4
  %t2 = load float, ptr %g2, align 4
  %t3 = load float, ptr %g3, align 4
  %m1 = tail call float @llvm.maximum.f32(float %t1, float %t0)
  %m2 = tail call float @llvm.maximum.f32(float %t2, float %m1)
  %m3 = tail call float @llvm.maximum.f32(float %t3, float %m2)
  ret float %m3
}

define double @reduction_v4f64_fminimum(ptr %p) {
; SSE-LABEL: define double @reduction_v4f64_fminimum
; SSE-SAME: (ptr [[P:%.*]]) {
; SSE-NEXT:    [[TMP1:%.*]] = load <4 x double>, ptr [[P]], align 4
; SSE-NEXT:    [[TMP2:%.*]] = call double @llvm.vector.reduce.fminimum.v4f64(<4 x double> [[TMP1]])
; SSE-NEXT:    ret double [[TMP2]]
;
; AVX-LABEL: define double @reduction_v4f64_fminimum
; AVX-SAME: (ptr [[P:%.*]]) #[[ATTR1]] {
; AVX-NEXT:    [[TMP1:%.*]] = load <4 x double>, ptr [[P]], align 4
; AVX-NEXT:    [[TMP2:%.*]] = call double @llvm.vector.reduce.fminimum.v4f64(<4 x double> [[TMP1]])
; AVX-NEXT:    ret double [[TMP2]]
;
  %g1 = getelementptr inbounds double, ptr %p, i64 1
  %g2 = getelementptr inbounds double, ptr %p, i64 2
  %g3 = getelementptr inbounds double, ptr %p, i64 3
  %t0 = load double, ptr %p, align 4
  %t1 = load double, ptr %g1, align 4
  %t2 = load double, ptr %g2, align 4
  %t3 = load double, ptr %g3, align 4
  %m1 = tail call double @llvm.minimum.f64(double %t1, double %t0)
  %m2 = tail call double @llvm.minimum.f64(double %t2, double %m1)
  %m3 = tail call double @llvm.minimum.f64(double %t3, double %m2)
  ret double %m3
}

define float @reduction_v8f32_fminimum(ptr %p) {
; SSE-LABEL: define float @reduction_v8f32_fminimum
; SSE-SAME: (ptr [[P:%.*]]) {
; SSE-NEXT:    [[TMP1:%.*]] = load <8 x float>, ptr [[P]], align 4
; SSE-NEXT:    [[TMP2:%.*]] = call float @llvm.vector.reduce.fminimum.v8f32(<8 x float> [[TMP1]])
; SSE-NEXT:    ret float [[TMP2]]
;
; AVX-LABEL: define float @reduction_v8f32_fminimum
; AVX-SAME: (ptr [[P:%.*]]) #[[ATTR1]] {
; AVX-NEXT:    [[TMP1:%.*]] = load <8 x float>, ptr [[P]], align 4
; AVX-NEXT:    [[TMP2:%.*]] = call float @llvm.vector.reduce.fminimum.v8f32(<8 x float> [[TMP1]])
; AVX-NEXT:    ret float [[TMP2]]
;
  %g1 = getelementptr inbounds float, ptr %p, i64 1
  %g2 = getelementptr inbounds float, ptr %p, i64 2
  %g3 = getelementptr inbounds float, ptr %p, i64 3
  %g4 = getelementptr inbounds float, ptr %p, i64 4
  %g5 = getelementptr inbounds float, ptr %p, i64 5
  %g6 = getelementptr inbounds float, ptr %p, i64 6
  %g7 = getelementptr inbounds float, ptr %p, i64 7
  %t0 = load float, ptr %p, align 4
  %t1 = load float, ptr %g1, align 4
  %t2 = load float, ptr %g2, align 4
  %t3 = load float, ptr %g3, align 4
  %t4 = load float, ptr %g4, align 4
  %t5 = load float, ptr %g5, align 4
  %t6 = load float, ptr %g6, align 4
  %t7 = load float, ptr %g7, align 4
  %m1 = tail call float @llvm.minimum.f32(float %t1, float %t0)
  %m2 = tail call float @llvm.minimum.f32(float %t2, float %m1)
  %m3 = tail call float @llvm.minimum.f32(float %t3, float %m2)
  %m4 = tail call float @llvm.minimum.f32(float %t4, float %m3)
  %m5 = tail call float @llvm.minimum.f32(float %m4, float %t6)
  %m6 = tail call float @llvm.minimum.f32(float %m5, float %t5)
  %m7 = tail call float @llvm.minimum.f32(float %m6, float %t7)
  ret float %m7
}
