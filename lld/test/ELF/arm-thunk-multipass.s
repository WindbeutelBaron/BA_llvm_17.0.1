// REQUIRES: arm
// RUN: llvm-mc -arm-add-build-attributes -filetype=obj -triple=armv7a-none-linux-gnueabi %s -o %t
// RUN: ld.lld %t -o %t2
// The output file is large, most of it zeroes. We dissassemble only the
// parts we need to speed up the test and avoid a large output file
// RUN: llvm-objdump --no-print-imm-hex -d %t2 --start-address=0x100002 --stop-address=0x10000a  | FileCheck --check-prefix=CHECK1 %s
// RUN: llvm-objdump --no-print-imm-hex -d %t2 --start-address=0x1000004 --stop-address=0x1000026  | FileCheck --check-prefix=CHECK2 %s
// RUN: llvm-objdump --no-print-imm-hex -d %t2 --start-address=0x1100014 --stop-address=0x1100022  | FileCheck --check-prefix=CHECK3 %s
// In this test case a branch that is in range and does not need its range
// extended can be pushed out of range by another Thunk, necessitating another
// pass

 .macro FUNCTION suff
 .section .text.\suff\(), "ax", %progbits
 .thumb
 .balign 0x100000
 .globl tfunc\suff\()
 .type  tfunc\suff\(), %function
tfunc\suff\():
 bx lr
 .endm

 FUNCTION 00
 .globl _start
_start:
 bl target
 b.w arm_target
// arm_target is in range but needs an interworking thunk
// CHECK1: <_start>:
// CHECK1-NEXT:   100002:       f300 d006       bl      0x1000012 <__Thumbv7ABSLongThunk_target>
// CHECK1-NEXT:   100006:       f2ff 97ff       b.w     0x1000008 <__Thumbv7ABSLongThunk_arm_target>
 nop
 nop
 nop
 .globl target2
 .type target2, %function
        nop

target2:
 FUNCTION 01
 FUNCTION 02
 FUNCTION 03
 FUNCTION 04
 FUNCTION 05
 FUNCTION 06
 FUNCTION 07
 FUNCTION 08
 FUNCTION 09
 FUNCTION 10
 FUNCTION 11
 FUNCTION 12
 FUNCTION 13
 FUNCTION 14
 FUNCTION 15

 .section .text.16, "ax", %progbits
 .arm
 .globl arm_target
 .type arm_target, %function
arm_target:
 bx lr
// CHECK2: 01000004 <arm_target>:
// CHECK2: <__Thumbv7ABSLongThunk_arm_target>:
// CHECK2-NEXT:  1000008:       f240 0c04       movw    r12, #4
// CHECK2-NEXT:  100000c:       f2c0 1c00       movt    r12, #256
// CHECK2-NEXT:  1000010:       4760    bx      r12
// CHECK2: <__Thumbv7ABSLongThunk_target>:
// CHECK2-NEXT:  1000012:       f0ff bfff       b.w     0x1100014 <target>
// CHECK2: <__Thumbv7ABSLongThunk_target2>:
// CHECK2-NEXT:  1000016:       f4ff 97fc       b.w     0x100012 <target2>

 .section .text.17, "ax", %progbits
// Just enough space so that bl target is in range if no extension thunks are
// generated.

 .space 0x100000 - 6

 .section .text.18, "ax", %progbits
 .thumb
 .globl target
 .type target, %function
// target is at maximum ARM branch range away from caller.
target:
// Similar case in the backwards direction
 bl target2
 nop
 nop
 bx lr
// CHECK3: <target>:
// CHECK3-NEXT:  1100014:       f6ff ffff       bl      0x1000016 <__Thumbv7ABSLongThunk_target2>
// CHECK3-NEXT:  1100018:       bf00    nop
// CHECK3-NEXT:  110001a:       bf00    nop
// CHECK3-NEXT:  110001c:       4770    bx      lr
