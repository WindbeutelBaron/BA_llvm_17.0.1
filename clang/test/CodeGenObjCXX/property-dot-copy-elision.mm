// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -emit-llvm -std=c++1z -fobjc-arc -o - %s | FileCheck %s

struct S0 {
  ~S0();
  id f;
};

struct S1 {
  S1();
  ~S1();
  S1(S0);
  id f;
};

@interface C
@property S1 f;
@end
@implementation C
@end

// CHECK-LABEL: define{{.*}} void @_Z5test0P1C(
// CHECK: %{{.*}} = alloca ptr
// CHECK: %[[AGG_TMP:.*]] = alloca %[[STRUCT_S1:.*]], align
// CHECK: %[[AGG_TMP_1:.*]] = alloca %[[STRUCT_S0:.*]], align
// CHECK: call void @_ZN2S0C1Ev(ptr {{[^,]*}} %[[AGG_TMP_1]])
// CHECK: call void @_ZN2S1C1E2S0(ptr {{[^,]*}} %[[AGG_TMP]], ptr noundef %[[AGG_TMP_1]])
// CHECK: call void @objc_msgSend(ptr noundef %{{.*}}, ptr noundef %{{.*}}, ptr noundef %[[AGG_TMP]])

void test0(C *c) {
  c.f = S0();
}

// CHECK: define{{.*}} void @_Z5test1P1C(
// CHECK: %{{.*}} = alloca ptr
// CHECK: %[[TEMP_LVALUE:.*]] = alloca %[[STRUCT_S1:.*]], align
// CHECK: call void @_ZN2S1C1Ev(ptr {{[^,]*}} %[[TEMP_LVALUE]])
// CHECK: call void @objc_msgSend(ptr noundef %{{.*}}, ptr noundef %{{.*}}, ptr noundef %[[TEMP_LVALUE]])

void test1(C *c) {
  c.f = S1();
}
