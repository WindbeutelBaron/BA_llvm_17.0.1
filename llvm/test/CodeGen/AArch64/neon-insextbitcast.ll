; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc < %s -verify-machineinstrs -mtriple=aarch64-none-linux-gnu -mattr=+neon | FileCheck %s

define <4 x i32> @test_vins_v4i32(<4 x i32> %a, float %b) {
; CHECK-LABEL: test_vins_v4i32:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    // kill: def $s1 killed $s1 def $q1
; CHECK-NEXT:    mov v0.s[3], v1.s[0]
; CHECK-NEXT:    ret
entry:
  %c = bitcast float %b to i32
  %d = insertelement <4 x i32> %a, i32 %c, i32 3
  ret <4 x i32> %d
}

define <4 x i32> @test_vins_v4i32_0(<4 x i32> %a, float %b) {
; CHECK-LABEL: test_vins_v4i32_0:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    // kill: def $s1 killed $s1 def $q1
; CHECK-NEXT:    mov v0.s[0], v1.s[0]
; CHECK-NEXT:    ret
entry:
  %c = bitcast float %b to i32
  %d = insertelement <4 x i32> %a, i32 %c, i32 0
  ret <4 x i32> %d
}

define <2 x i32> @test_vins_v2i32(<2 x i32> %a, float %b) {
; CHECK-LABEL: test_vins_v2i32:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    // kill: def $d0 killed $d0 def $q0
; CHECK-NEXT:    // kill: def $s1 killed $s1 def $q1
; CHECK-NEXT:    mov v0.s[1], v1.s[0]
; CHECK-NEXT:    // kill: def $d0 killed $d0 killed $q0
; CHECK-NEXT:    ret
entry:
  %c = bitcast float %b to i32
  %d = insertelement <2 x i32> %a, i32 %c, i32 1
  ret <2 x i32> %d
}

define <2 x i32> @test_vins_v2i32_0(<2 x i32> %a, float %b) {
; CHECK-LABEL: test_vins_v2i32_0:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    // kill: def $d0 killed $d0 def $q0
; CHECK-NEXT:    // kill: def $s1 killed $s1 def $q1
; CHECK-NEXT:    mov v0.s[0], v1.s[0]
; CHECK-NEXT:    // kill: def $d0 killed $d0 killed $q0
; CHECK-NEXT:    ret
entry:
  %c = bitcast float %b to i32
  %d = insertelement <2 x i32> %a, i32 %c, i32 0
  ret <2 x i32> %d
}

define <2 x i64> @test_vins_v2i64(<2 x i64> %a, double %b) {
; CHECK-LABEL: test_vins_v2i64:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    // kill: def $d1 killed $d1 def $q1
; CHECK-NEXT:    mov v0.d[1], v1.d[0]
; CHECK-NEXT:    ret
entry:
  %c = bitcast double %b to i64
  %d = insertelement <2 x i64> %a, i64 %c, i32 1
  ret <2 x i64> %d
}

define <2 x i64> @test_vins_v2i64_0(<2 x i64> %a, double %b) {
; CHECK-LABEL: test_vins_v2i64_0:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    // kill: def $d1 killed $d1 def $q1
; CHECK-NEXT:    mov v0.d[0], v1.d[0]
; CHECK-NEXT:    ret
entry:
  %c = bitcast double %b to i64
  %d = insertelement <2 x i64> %a, i64 %c, i32 0
  ret <2 x i64> %d
}

define <1 x i64> @test_vins_v1i64(<1 x i64> %a, double %b) {
; CHECK-LABEL: test_vins_v1i64:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    fmov d0, d1
; CHECK-NEXT:    ret
entry:
  %c = bitcast double %b to i64
  %d = insertelement <1 x i64> %a, i64 %c, i32 0
  ret <1 x i64> %d
}


define float @test_vext_v4i32(<4 x i32> %a) {
; CHECK-LABEL: test_vext_v4i32:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    mov v0.s[0], v0.s[3]
; CHECK-NEXT:    // kill: def $s0 killed $s0 killed $q0
; CHECK-NEXT:    ret
entry:
  %b = extractelement <4 x i32> %a, i32 3
  %c = bitcast i32 %b to float
  ret float %c
}

define float @test_vext_v4i32_0(<4 x i32> %a) {
; CHECK-LABEL: test_vext_v4i32_0:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    // kill: def $s0 killed $s0 killed $q0
; CHECK-NEXT:    ret
entry:
  %b = extractelement <4 x i32> %a, i32 0
  %c = bitcast i32 %b to float
  ret float %c
}

define float @test_vext_v2i32(<2 x i32> %a) {
; CHECK-LABEL: test_vext_v2i32:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    // kill: def $d0 killed $d0 def $q0
; CHECK-NEXT:    mov v0.s[0], v0.s[1]
; CHECK-NEXT:    // kill: def $s0 killed $s0 killed $q0
; CHECK-NEXT:    ret
entry:
  %b = extractelement <2 x i32> %a, i32 1
  %c = bitcast i32 %b to float
  ret float %c
}

define float @test_vext_v2i32_0(<2 x i32> %a) {
; CHECK-LABEL: test_vext_v2i32_0:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    // kill: def $d0 killed $d0 def $q0
; CHECK-NEXT:    // kill: def $s0 killed $s0 killed $q0
; CHECK-NEXT:    ret
entry:
  %b = extractelement <2 x i32> %a, i32 0
  %c = bitcast i32 %b to float
  ret float %c
}

define double @test_vext_v2i64(<2 x i64> %a) {
; CHECK-LABEL: test_vext_v2i64:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    mov v0.d[0], v0.d[1]
; CHECK-NEXT:    // kill: def $d0 killed $d0 killed $q0
; CHECK-NEXT:    ret
entry:
  %b = extractelement <2 x i64> %a, i32 1
  %c = bitcast i64 %b to double
  ret double %c
}

define double @test_vext_v2i64_0(<2 x i64> %a) {
; CHECK-LABEL: test_vext_v2i64_0:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    // kill: def $d0 killed $d0 killed $q0
; CHECK-NEXT:    ret
entry:
  %b = extractelement <2 x i64> %a, i32 0
  %c = bitcast i64 %b to double
  ret double %c
}

define double @test_vext_v1i64(<1 x i64> %a) {
; CHECK-LABEL: test_vext_v1i64:
; CHECK:       // %bb.0: // %entry
; CHECK-NEXT:    // kill: def $d0 killed $d0 def $q0
; CHECK-NEXT:    // kill: def $d0 killed $d0 killed $q0
; CHECK-NEXT:    ret
entry:
  %b = extractelement <1 x i64> %a, i32 0
  %c = bitcast i64 %b to double
  ret double %c
}