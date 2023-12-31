// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --check-attributes --check-globals --include-generated-funcs --version 2
// RUN: %clang_cc1 -triple amdgcn-- -target-cpu gfx803 -DBITCODE -emit-llvm-bc -o %t-lib.bc %s
// RUN: %clang_cc1 -triple amdgcn-- -target-cpu gfx90a -emit-llvm-bc -o %t.bc %s
// RUN: %clang_cc1 -triple amdgcn-- -target-cpu gfx90a -emit-llvm \
// RUN:   -mlink-builtin-bitcode %t-lib.bc -o - %t.bc | FileCheck %s

#ifdef BITCODE
int foo(void) { return 42; }
int x = 12;
#endif

extern int foo(void);
extern int x;

int bar() { return foo() + x; }
//.
// CHECK: @x = internal addrspace(1) global i32 12, align 4
//.
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define dso_local i32 @bar
// CHECK-SAME: () #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-NEXT:    [[RETVAL_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL]] to ptr
// CHECK-NEXT:    [[CALL:%.*]] = call i32 @foo()
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr addrspacecast (ptr addrspace(1) @x to ptr), align 4
// CHECK-NEXT:    [[ADD:%.*]] = add nsw i32 [[CALL]], [[TMP0]]
// CHECK-NEXT:    ret i32 [[ADD]]
//
//
// CHECK: Function Attrs: convergent noinline nounwind optnone
// CHECK-LABEL: define internal i32 @foo
// CHECK-SAME: () #[[ATTR1:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-NEXT:    [[RETVAL_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL]] to ptr
// CHECK-NEXT:    ret i32 42
//
//.
// CHECK: attributes #0 = { noinline nounwind optnone "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="gfx90a" "target-features"="+16-bit-insts,+atomic-buffer-global-pk-add-f16-insts,+atomic-fadd-rtn-insts,+ci-insts,+dl-insts,+dot1-insts,+dot10-insts,+dot2-insts,+dot3-insts,+dot4-insts,+dot5-insts,+dot6-insts,+dot7-insts,+dpp,+gfx8-insts,+gfx9-insts,+gfx90a-insts,+mai-insts,+s-memrealtime,+s-memtime-inst,+wavefrontsize64" }
// CHECK: attributes #1 = { convergent noinline nounwind optnone "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="gfx90a" "target-features"="+16-bit-insts,+ci-insts,+dpp,+gfx8-insts,+s-memrealtime,+s-memtime-inst,+wavefrontsize64" }
//.
