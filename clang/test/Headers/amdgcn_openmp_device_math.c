// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -internal-isystem %S/Inputs/include -x c -fopenmp -triple x86_64-unknown-unknown -fopenmp-targets=amdgcn-amd-amdhsa -emit-llvm-bc %s -o %t-host.bc
// RUN: %clang_cc1 -internal-isystem %S/../../lib/Headers/openmp_wrappers -include __clang_openmp_device_functions.h -internal-isystem %S/../../lib/Headers/openmp_wrappers -internal-isystem %S/Inputs/include -x c -fopenmp -triple amdgcn-amd-amdhsa -aux-triple x86_64-unknown-unknown -fopenmp-targets=amdgcn-amd-amdhsa -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-host.bc -o - | FileCheck %s --check-prefixes=CHECK,CHECK-C
// RUN: %clang_cc1 -internal-isystem %S/Inputs/include -x c++ -fopenmp -triple x86_64-unknown-unknown -fopenmp-targets=amdgcn-amd-amdhsa -emit-llvm-bc %s -o %t-host.bc
// RUN: %clang_cc1 -internal-isystem %S/../../lib/Headers/openmp_wrappers -include __clang_openmp_device_functions.h -internal-isystem %S/../../lib/Headers/openmp_wrappers -internal-isystem %S/Inputs/include -x c++ -fopenmp -triple amdgcn-amd-amdhsa -aux-triple x86_64-unknown-unknown -fopenmp-targets=amdgcn-amd-amdhsa -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-host.bc -o - | FileCheck %s --check-prefixes=CHECK,CHECK-CPP

#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#endif

#pragma omp begin declare target

// CHECK-C-LABEL: @test_math_f64(
// CHECK-C-NEXT:  entry:
// CHECK-C-NEXT:    [[RETVAL_I13:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I14:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__Y_ADDR_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__Z_ADDR_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[RETVAL_I9:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I10:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[RETVAL_I4:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I5:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[RETVAL_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[X_ADDR:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[Y_ADDR:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[Z_ADDR:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[L1:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[L2:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[L3:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[L4:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[X_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[X_ADDR]] to ptr
// CHECK-C-NEXT:    [[Y_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Y_ADDR]] to ptr
// CHECK-C-NEXT:    [[Z_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Z_ADDR]] to ptr
// CHECK-C-NEXT:    [[L1_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L1]] to ptr
// CHECK-C-NEXT:    [[L2_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L2]] to ptr
// CHECK-C-NEXT:    [[L3_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L3]] to ptr
// CHECK-C-NEXT:    [[L4_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L4]] to ptr
// CHECK-C-NEXT:    store double [[X:%.*]], ptr [[X_ADDR_ASCAST]], align 8
// CHECK-C-NEXT:    store double [[Y:%.*]], ptr [[Y_ADDR_ASCAST]], align 8
// CHECK-C-NEXT:    store double [[Z:%.*]], ptr [[Z_ADDR_ASCAST]], align 8
// CHECK-C-NEXT:    [[TMP0:%.*]] = load double, ptr [[X_ADDR_ASCAST]], align 8
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I]] to ptr
// CHECK-C-NEXT:    store double [[TMP0]], ptr [[__X_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    [[TMP1:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    [[CALL_I:%.*]] = call double @__ocml_sin_f64(double noundef [[TMP1]]) #[[ATTR3:[0-9]+]]
// CHECK-C-NEXT:    store double [[CALL_I]], ptr [[L1_ASCAST]], align 8
// CHECK-C-NEXT:    [[TMP2:%.*]] = load double, ptr [[X_ADDR_ASCAST]], align 8
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I6:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I4]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I7:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I5]] to ptr
// CHECK-C-NEXT:    store double [[TMP2]], ptr [[__X_ADDR_ASCAST_I7]], align 8
// CHECK-C-NEXT:    [[TMP3:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I7]], align 8
// CHECK-C-NEXT:    [[CALL_I8:%.*]] = call double @__ocml_cos_f64(double noundef [[TMP3]]) #[[ATTR3]]
// CHECK-C-NEXT:    store double [[CALL_I8]], ptr [[L2_ASCAST]], align 8
// CHECK-C-NEXT:    [[TMP4:%.*]] = load double, ptr [[X_ADDR_ASCAST]], align 8
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I11:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I9]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I12:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I10]] to ptr
// CHECK-C-NEXT:    store double [[TMP4]], ptr [[__X_ADDR_ASCAST_I12]], align 8
// CHECK-C-NEXT:    [[TMP5:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I12]], align 8
// CHECK-C-NEXT:    [[TMP6:%.*]] = call double @llvm.fabs.f64(double [[TMP5]])
// CHECK-C-NEXT:    store double [[TMP6]], ptr [[L3_ASCAST]], align 8
// CHECK-C-NEXT:    [[TMP7:%.*]] = load double, ptr [[X_ADDR_ASCAST]], align 8
// CHECK-C-NEXT:    [[TMP8:%.*]] = load double, ptr [[Y_ADDR_ASCAST]], align 8
// CHECK-C-NEXT:    [[TMP9:%.*]] = load double, ptr [[Z_ADDR_ASCAST]], align 8
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I15:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I13]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I16:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I14]] to ptr
// CHECK-C-NEXT:    [[__Y_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Y_ADDR_I]] to ptr
// CHECK-C-NEXT:    [[__Z_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Z_ADDR_I]] to ptr
// CHECK-C-NEXT:    store double [[TMP7]], ptr [[__X_ADDR_ASCAST_I16]], align 8
// CHECK-C-NEXT:    store double [[TMP8]], ptr [[__Y_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    store double [[TMP9]], ptr [[__Z_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    [[TMP10:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I16]], align 8
// CHECK-C-NEXT:    [[TMP11:%.*]] = load double, ptr [[__Y_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    [[TMP12:%.*]] = load double, ptr [[__Z_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    [[TMP13:%.*]] = call double @llvm.fma.f64(double [[TMP10]], double [[TMP11]], double [[TMP12]])
// CHECK-C-NEXT:    store double [[TMP13]], ptr [[L4_ASCAST]], align 8
// CHECK-C-NEXT:    ret void
//
// CHECK-CPP-LABEL: @_Z13test_math_f64ddd(
// CHECK-CPP-NEXT:  entry:
// CHECK-CPP-NEXT:    [[RETVAL_I13:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I14:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[__Y_ADDR_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[__Z_ADDR_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I9:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I10:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I4:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I5:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[X_ADDR:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[Y_ADDR:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[Z_ADDR:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[L1:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[L2:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[L3:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[L4:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-CPP-NEXT:    [[X_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[X_ADDR]] to ptr
// CHECK-CPP-NEXT:    [[Y_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Y_ADDR]] to ptr
// CHECK-CPP-NEXT:    [[Z_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Z_ADDR]] to ptr
// CHECK-CPP-NEXT:    [[L1_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L1]] to ptr
// CHECK-CPP-NEXT:    [[L2_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L2]] to ptr
// CHECK-CPP-NEXT:    [[L3_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L3]] to ptr
// CHECK-CPP-NEXT:    [[L4_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L4]] to ptr
// CHECK-CPP-NEXT:    store double [[X:%.*]], ptr [[X_ADDR_ASCAST]], align 8
// CHECK-CPP-NEXT:    store double [[Y:%.*]], ptr [[Y_ADDR_ASCAST]], align 8
// CHECK-CPP-NEXT:    store double [[Z:%.*]], ptr [[Z_ADDR_ASCAST]], align 8
// CHECK-CPP-NEXT:    [[TMP0:%.*]] = load double, ptr [[X_ADDR_ASCAST]], align 8
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I]] to ptr
// CHECK-CPP-NEXT:    store double [[TMP0]], ptr [[__X_ADDR_ASCAST_I]], align 8
// CHECK-CPP-NEXT:    [[TMP1:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I]], align 8
// CHECK-CPP-NEXT:    [[CALL_I:%.*]] = call double @__ocml_sin_f64(double noundef [[TMP1]]) #[[ATTR3:[0-9]+]]
// CHECK-CPP-NEXT:    store double [[CALL_I]], ptr [[L1_ASCAST]], align 8
// CHECK-CPP-NEXT:    [[TMP2:%.*]] = load double, ptr [[X_ADDR_ASCAST]], align 8
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I6:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I4]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I7:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I5]] to ptr
// CHECK-CPP-NEXT:    store double [[TMP2]], ptr [[__X_ADDR_ASCAST_I7]], align 8
// CHECK-CPP-NEXT:    [[TMP3:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I7]], align 8
// CHECK-CPP-NEXT:    [[CALL_I8:%.*]] = call double @__ocml_cos_f64(double noundef [[TMP3]]) #[[ATTR3]]
// CHECK-CPP-NEXT:    store double [[CALL_I8]], ptr [[L2_ASCAST]], align 8
// CHECK-CPP-NEXT:    [[TMP4:%.*]] = load double, ptr [[X_ADDR_ASCAST]], align 8
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I11:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I9]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I12:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I10]] to ptr
// CHECK-CPP-NEXT:    store double [[TMP4]], ptr [[__X_ADDR_ASCAST_I12]], align 8
// CHECK-CPP-NEXT:    [[TMP5:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I12]], align 8
// CHECK-CPP-NEXT:    [[TMP6:%.*]] = call double @llvm.fabs.f64(double [[TMP5]])
// CHECK-CPP-NEXT:    store double [[TMP6]], ptr [[L3_ASCAST]], align 8
// CHECK-CPP-NEXT:    [[TMP7:%.*]] = load double, ptr [[X_ADDR_ASCAST]], align 8
// CHECK-CPP-NEXT:    [[TMP8:%.*]] = load double, ptr [[Y_ADDR_ASCAST]], align 8
// CHECK-CPP-NEXT:    [[TMP9:%.*]] = load double, ptr [[Z_ADDR_ASCAST]], align 8
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I15:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I13]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I16:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I14]] to ptr
// CHECK-CPP-NEXT:    [[__Y_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Y_ADDR_I]] to ptr
// CHECK-CPP-NEXT:    [[__Z_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Z_ADDR_I]] to ptr
// CHECK-CPP-NEXT:    store double [[TMP7]], ptr [[__X_ADDR_ASCAST_I16]], align 8
// CHECK-CPP-NEXT:    store double [[TMP8]], ptr [[__Y_ADDR_ASCAST_I]], align 8
// CHECK-CPP-NEXT:    store double [[TMP9]], ptr [[__Z_ADDR_ASCAST_I]], align 8
// CHECK-CPP-NEXT:    [[TMP10:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I16]], align 8
// CHECK-CPP-NEXT:    [[TMP11:%.*]] = load double, ptr [[__Y_ADDR_ASCAST_I]], align 8
// CHECK-CPP-NEXT:    [[TMP12:%.*]] = load double, ptr [[__Z_ADDR_ASCAST_I]], align 8
// CHECK-CPP-NEXT:    [[TMP13:%.*]] = call double @llvm.fma.f64(double [[TMP10]], double [[TMP11]], double [[TMP12]])
// CHECK-CPP-NEXT:    store double [[TMP13]], ptr [[L4_ASCAST]], align 8
// CHECK-CPP-NEXT:    ret void
//
void test_math_f64(double x, double y, double z) {
  double l1 = sin(x);
  double l2 = cos(x);
  double l3 = fabs(x);
  double l4 = fma(x, y, z);
}

// CHECK-C-LABEL: @test_math_f32(
// CHECK-C-NEXT:  entry:
// CHECK-C-NEXT:    [[RETVAL_I22:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I23:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__Y_ADDR_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__Z_ADDR_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[RETVAL_I18:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I19:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[RETVAL_I13:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I14:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[RETVAL_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I:%.*]] = alloca double, align 8, addrspace(5)
// CHECK-C-NEXT:    [[X_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[Y_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[Z_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[L1:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[L2:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[L3:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[L4:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[X_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[X_ADDR]] to ptr
// CHECK-C-NEXT:    [[Y_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Y_ADDR]] to ptr
// CHECK-C-NEXT:    [[Z_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Z_ADDR]] to ptr
// CHECK-C-NEXT:    [[L1_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L1]] to ptr
// CHECK-C-NEXT:    [[L2_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L2]] to ptr
// CHECK-C-NEXT:    [[L3_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L3]] to ptr
// CHECK-C-NEXT:    [[L4_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L4]] to ptr
// CHECK-C-NEXT:    store float [[X:%.*]], ptr [[X_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    store float [[Y:%.*]], ptr [[Y_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    store float [[Z:%.*]], ptr [[Z_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[TMP0:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[CONV:%.*]] = fpext float [[TMP0]] to double
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I]] to ptr
// CHECK-C-NEXT:    store double [[CONV]], ptr [[__X_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    [[TMP1:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    [[CALL_I:%.*]] = call double @__ocml_sin_f64(double noundef [[TMP1]]) #[[ATTR3]]
// CHECK-C-NEXT:    [[CONV1:%.*]] = fptrunc double [[CALL_I]] to float
// CHECK-C-NEXT:    store float [[CONV1]], ptr [[L1_ASCAST]], align 4
// CHECK-C-NEXT:    [[TMP2:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[CONV2:%.*]] = fpext float [[TMP2]] to double
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I15:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I13]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I16:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I14]] to ptr
// CHECK-C-NEXT:    store double [[CONV2]], ptr [[__X_ADDR_ASCAST_I16]], align 8
// CHECK-C-NEXT:    [[TMP3:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I16]], align 8
// CHECK-C-NEXT:    [[CALL_I17:%.*]] = call double @__ocml_cos_f64(double noundef [[TMP3]]) #[[ATTR3]]
// CHECK-C-NEXT:    [[CONV4:%.*]] = fptrunc double [[CALL_I17]] to float
// CHECK-C-NEXT:    store float [[CONV4]], ptr [[L2_ASCAST]], align 4
// CHECK-C-NEXT:    [[TMP4:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[CONV5:%.*]] = fpext float [[TMP4]] to double
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I20:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I18]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I21:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I19]] to ptr
// CHECK-C-NEXT:    store double [[CONV5]], ptr [[__X_ADDR_ASCAST_I21]], align 8
// CHECK-C-NEXT:    [[TMP5:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I21]], align 8
// CHECK-C-NEXT:    [[TMP6:%.*]] = call double @llvm.fabs.f64(double [[TMP5]])
// CHECK-C-NEXT:    [[CONV7:%.*]] = fptrunc double [[TMP6]] to float
// CHECK-C-NEXT:    store float [[CONV7]], ptr [[L3_ASCAST]], align 4
// CHECK-C-NEXT:    [[TMP7:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[CONV8:%.*]] = fpext float [[TMP7]] to double
// CHECK-C-NEXT:    [[TMP8:%.*]] = load float, ptr [[Y_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[CONV9:%.*]] = fpext float [[TMP8]] to double
// CHECK-C-NEXT:    [[TMP9:%.*]] = load float, ptr [[Z_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[CONV10:%.*]] = fpext float [[TMP9]] to double
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I24:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I22]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I25:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I23]] to ptr
// CHECK-C-NEXT:    [[__Y_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Y_ADDR_I]] to ptr
// CHECK-C-NEXT:    [[__Z_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Z_ADDR_I]] to ptr
// CHECK-C-NEXT:    store double [[CONV8]], ptr [[__X_ADDR_ASCAST_I25]], align 8
// CHECK-C-NEXT:    store double [[CONV9]], ptr [[__Y_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    store double [[CONV10]], ptr [[__Z_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    [[TMP10:%.*]] = load double, ptr [[__X_ADDR_ASCAST_I25]], align 8
// CHECK-C-NEXT:    [[TMP11:%.*]] = load double, ptr [[__Y_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    [[TMP12:%.*]] = load double, ptr [[__Z_ADDR_ASCAST_I]], align 8
// CHECK-C-NEXT:    [[TMP13:%.*]] = call double @llvm.fma.f64(double [[TMP10]], double [[TMP11]], double [[TMP12]])
// CHECK-C-NEXT:    [[CONV12:%.*]] = fptrunc double [[TMP13]] to float
// CHECK-C-NEXT:    store float [[CONV12]], ptr [[L4_ASCAST]], align 4
// CHECK-C-NEXT:    ret void
//
// CHECK-CPP-LABEL: @_Z13test_math_f32fff(
// CHECK-CPP-NEXT:  entry:
// CHECK-CPP-NEXT:    [[RETVAL_I32:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I33:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__Y_ADDR_I34:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__Z_ADDR_I35:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I28:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I29:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I24:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I25:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I19:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I20:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I14:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I15:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__Y_ADDR_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__Z_ADDR_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I9:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I10:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I4:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I5:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[X_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[Y_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[Z_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[L1:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[L2:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[L3:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[L4:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[X_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[X_ADDR]] to ptr
// CHECK-CPP-NEXT:    [[Y_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Y_ADDR]] to ptr
// CHECK-CPP-NEXT:    [[Z_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Z_ADDR]] to ptr
// CHECK-CPP-NEXT:    [[L1_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L1]] to ptr
// CHECK-CPP-NEXT:    [[L2_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L2]] to ptr
// CHECK-CPP-NEXT:    [[L3_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L3]] to ptr
// CHECK-CPP-NEXT:    [[L4_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L4]] to ptr
// CHECK-CPP-NEXT:    store float [[X:%.*]], ptr [[X_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    store float [[Y:%.*]], ptr [[Y_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    store float [[Z:%.*]], ptr [[Z_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP0:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP0]], ptr [[__X_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    [[TMP1:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I21:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I19]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I22:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I20]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP1]], ptr [[__X_ADDR_ASCAST_I22]], align 4
// CHECK-CPP-NEXT:    [[TMP2:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I22]], align 4
// CHECK-CPP-NEXT:    [[CALL_I23:%.*]] = call float @__ocml_sin_f32(float noundef [[TMP2]]) #[[ATTR3]]
// CHECK-CPP-NEXT:    store float [[CALL_I23]], ptr [[L1_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP3:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I6:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I4]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I7:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I5]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP3]], ptr [[__X_ADDR_ASCAST_I7]], align 4
// CHECK-CPP-NEXT:    [[TMP4:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I7]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I26:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I24]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I27:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I25]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP4]], ptr [[__X_ADDR_ASCAST_I27]], align 4
// CHECK-CPP-NEXT:    [[TMP5:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I27]], align 4
// CHECK-CPP-NEXT:    [[CALL_I:%.*]] = call float @__ocml_cos_f32(float noundef [[TMP5]]) #[[ATTR3]]
// CHECK-CPP-NEXT:    store float [[CALL_I]], ptr [[L2_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP6:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I11:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I9]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I12:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I10]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP6]], ptr [[__X_ADDR_ASCAST_I12]], align 4
// CHECK-CPP-NEXT:    [[TMP7:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I12]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I30:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I28]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I31:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I29]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP7]], ptr [[__X_ADDR_ASCAST_I31]], align 4
// CHECK-CPP-NEXT:    [[TMP8:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I31]], align 4
// CHECK-CPP-NEXT:    [[TMP9:%.*]] = call float @llvm.fabs.f32(float [[TMP8]])
// CHECK-CPP-NEXT:    store float [[TMP9]], ptr [[L3_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP10:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP11:%.*]] = load float, ptr [[Y_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP12:%.*]] = load float, ptr [[Z_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I16:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I14]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I17:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I15]] to ptr
// CHECK-CPP-NEXT:    [[__Y_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Y_ADDR_I]] to ptr
// CHECK-CPP-NEXT:    [[__Z_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Z_ADDR_I]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP10]], ptr [[__X_ADDR_ASCAST_I17]], align 4
// CHECK-CPP-NEXT:    store float [[TMP11]], ptr [[__Y_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    store float [[TMP12]], ptr [[__Z_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    [[TMP13:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I17]], align 4
// CHECK-CPP-NEXT:    [[TMP14:%.*]] = load float, ptr [[__Y_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    [[TMP15:%.*]] = load float, ptr [[__Z_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I36:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I32]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I37:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I33]] to ptr
// CHECK-CPP-NEXT:    [[__Y_ADDR_ASCAST_I38:%.*]] = addrspacecast ptr addrspace(5) [[__Y_ADDR_I34]] to ptr
// CHECK-CPP-NEXT:    [[__Z_ADDR_ASCAST_I39:%.*]] = addrspacecast ptr addrspace(5) [[__Z_ADDR_I35]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP13]], ptr [[__X_ADDR_ASCAST_I37]], align 4
// CHECK-CPP-NEXT:    store float [[TMP14]], ptr [[__Y_ADDR_ASCAST_I38]], align 4
// CHECK-CPP-NEXT:    store float [[TMP15]], ptr [[__Z_ADDR_ASCAST_I39]], align 4
// CHECK-CPP-NEXT:    [[TMP16:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I37]], align 4
// CHECK-CPP-NEXT:    [[TMP17:%.*]] = load float, ptr [[__Y_ADDR_ASCAST_I38]], align 4
// CHECK-CPP-NEXT:    [[TMP18:%.*]] = load float, ptr [[__Z_ADDR_ASCAST_I39]], align 4
// CHECK-CPP-NEXT:    [[TMP19:%.*]] = call float @llvm.fma.f32(float [[TMP16]], float [[TMP17]], float [[TMP18]])
// CHECK-CPP-NEXT:    store float [[TMP19]], ptr [[L4_ASCAST]], align 4
// CHECK-CPP-NEXT:    ret void
//
void test_math_f32(float x, float y, float z) {
  float l1 = sin(x);
  float l2 = cos(x);
  float l3 = fabs(x);
  float l4 = fma(x, y, z);
}

// CHECK-C-LABEL: @test_math_f32_suffix(
// CHECK-C-NEXT:  entry:
// CHECK-C-NEXT:    [[RETVAL_I13:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I14:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[__Y_ADDR_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[__Z_ADDR_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[RETVAL_I9:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I10:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[RETVAL_I4:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I5:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[RETVAL_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[__X_ADDR_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[X_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[Y_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[Z_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[L1:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[L2:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[L3:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[L4:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-C-NEXT:    [[X_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[X_ADDR]] to ptr
// CHECK-C-NEXT:    [[Y_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Y_ADDR]] to ptr
// CHECK-C-NEXT:    [[Z_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Z_ADDR]] to ptr
// CHECK-C-NEXT:    [[L1_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L1]] to ptr
// CHECK-C-NEXT:    [[L2_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L2]] to ptr
// CHECK-C-NEXT:    [[L3_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L3]] to ptr
// CHECK-C-NEXT:    [[L4_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L4]] to ptr
// CHECK-C-NEXT:    store float [[X:%.*]], ptr [[X_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    store float [[Y:%.*]], ptr [[Y_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    store float [[Z:%.*]], ptr [[Z_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[TMP0:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I]] to ptr
// CHECK-C-NEXT:    store float [[TMP0]], ptr [[__X_ADDR_ASCAST_I]], align 4
// CHECK-C-NEXT:    [[TMP1:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I]], align 4
// CHECK-C-NEXT:    [[CALL_I:%.*]] = call float @__ocml_sin_f32(float noundef [[TMP1]]) #[[ATTR3]]
// CHECK-C-NEXT:    store float [[CALL_I]], ptr [[L1_ASCAST]], align 4
// CHECK-C-NEXT:    [[TMP2:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I6:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I4]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I7:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I5]] to ptr
// CHECK-C-NEXT:    store float [[TMP2]], ptr [[__X_ADDR_ASCAST_I7]], align 4
// CHECK-C-NEXT:    [[TMP3:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I7]], align 4
// CHECK-C-NEXT:    [[CALL_I8:%.*]] = call float @__ocml_cos_f32(float noundef [[TMP3]]) #[[ATTR3]]
// CHECK-C-NEXT:    store float [[CALL_I8]], ptr [[L2_ASCAST]], align 4
// CHECK-C-NEXT:    [[TMP4:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I11:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I9]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I12:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I10]] to ptr
// CHECK-C-NEXT:    store float [[TMP4]], ptr [[__X_ADDR_ASCAST_I12]], align 4
// CHECK-C-NEXT:    [[TMP5:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I12]], align 4
// CHECK-C-NEXT:    [[TMP6:%.*]] = call float @llvm.fabs.f32(float [[TMP5]])
// CHECK-C-NEXT:    store float [[TMP6]], ptr [[L3_ASCAST]], align 4
// CHECK-C-NEXT:    [[TMP7:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[TMP8:%.*]] = load float, ptr [[Y_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[TMP9:%.*]] = load float, ptr [[Z_ADDR_ASCAST]], align 4
// CHECK-C-NEXT:    [[RETVAL_ASCAST_I15:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I13]] to ptr
// CHECK-C-NEXT:    [[__X_ADDR_ASCAST_I16:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I14]] to ptr
// CHECK-C-NEXT:    [[__Y_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Y_ADDR_I]] to ptr
// CHECK-C-NEXT:    [[__Z_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Z_ADDR_I]] to ptr
// CHECK-C-NEXT:    store float [[TMP7]], ptr [[__X_ADDR_ASCAST_I16]], align 4
// CHECK-C-NEXT:    store float [[TMP8]], ptr [[__Y_ADDR_ASCAST_I]], align 4
// CHECK-C-NEXT:    store float [[TMP9]], ptr [[__Z_ADDR_ASCAST_I]], align 4
// CHECK-C-NEXT:    [[TMP10:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I16]], align 4
// CHECK-C-NEXT:    [[TMP11:%.*]] = load float, ptr [[__Y_ADDR_ASCAST_I]], align 4
// CHECK-C-NEXT:    [[TMP12:%.*]] = load float, ptr [[__Z_ADDR_ASCAST_I]], align 4
// CHECK-C-NEXT:    [[TMP13:%.*]] = call float @llvm.fma.f32(float [[TMP10]], float [[TMP11]], float [[TMP12]])
// CHECK-C-NEXT:    store float [[TMP13]], ptr [[L4_ASCAST]], align 4
// CHECK-C-NEXT:    ret void
//
// CHECK-CPP-LABEL: @_Z20test_math_f32_suffixfff(
// CHECK-CPP-NEXT:  entry:
// CHECK-CPP-NEXT:    [[RETVAL_I13:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I14:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__Y_ADDR_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__Z_ADDR_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I9:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I10:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I4:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I5:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[RETVAL_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[__X_ADDR_I:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[X_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[Y_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[Z_ADDR:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[L1:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[L2:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[L3:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[L4:%.*]] = alloca float, align 4, addrspace(5)
// CHECK-CPP-NEXT:    [[X_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[X_ADDR]] to ptr
// CHECK-CPP-NEXT:    [[Y_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Y_ADDR]] to ptr
// CHECK-CPP-NEXT:    [[Z_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[Z_ADDR]] to ptr
// CHECK-CPP-NEXT:    [[L1_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L1]] to ptr
// CHECK-CPP-NEXT:    [[L2_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L2]] to ptr
// CHECK-CPP-NEXT:    [[L3_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L3]] to ptr
// CHECK-CPP-NEXT:    [[L4_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[L4]] to ptr
// CHECK-CPP-NEXT:    store float [[X:%.*]], ptr [[X_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    store float [[Y:%.*]], ptr [[Y_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    store float [[Z:%.*]], ptr [[Z_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP0:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP0]], ptr [[__X_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    [[TMP1:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    [[CALL_I:%.*]] = call float @__ocml_sin_f32(float noundef [[TMP1]]) #[[ATTR3]]
// CHECK-CPP-NEXT:    store float [[CALL_I]], ptr [[L1_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP2:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I6:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I4]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I7:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I5]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP2]], ptr [[__X_ADDR_ASCAST_I7]], align 4
// CHECK-CPP-NEXT:    [[TMP3:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I7]], align 4
// CHECK-CPP-NEXT:    [[CALL_I8:%.*]] = call float @__ocml_cos_f32(float noundef [[TMP3]]) #[[ATTR3]]
// CHECK-CPP-NEXT:    store float [[CALL_I8]], ptr [[L2_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP4:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I11:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I9]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I12:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I10]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP4]], ptr [[__X_ADDR_ASCAST_I12]], align 4
// CHECK-CPP-NEXT:    [[TMP5:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I12]], align 4
// CHECK-CPP-NEXT:    [[TMP6:%.*]] = call float @llvm.fabs.f32(float [[TMP5]])
// CHECK-CPP-NEXT:    store float [[TMP6]], ptr [[L3_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP7:%.*]] = load float, ptr [[X_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP8:%.*]] = load float, ptr [[Y_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[TMP9:%.*]] = load float, ptr [[Z_ADDR_ASCAST]], align 4
// CHECK-CPP-NEXT:    [[RETVAL_ASCAST_I15:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL_I13]] to ptr
// CHECK-CPP-NEXT:    [[__X_ADDR_ASCAST_I16:%.*]] = addrspacecast ptr addrspace(5) [[__X_ADDR_I14]] to ptr
// CHECK-CPP-NEXT:    [[__Y_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Y_ADDR_I]] to ptr
// CHECK-CPP-NEXT:    [[__Z_ADDR_ASCAST_I:%.*]] = addrspacecast ptr addrspace(5) [[__Z_ADDR_I]] to ptr
// CHECK-CPP-NEXT:    store float [[TMP7]], ptr [[__X_ADDR_ASCAST_I16]], align 4
// CHECK-CPP-NEXT:    store float [[TMP8]], ptr [[__Y_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    store float [[TMP9]], ptr [[__Z_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    [[TMP10:%.*]] = load float, ptr [[__X_ADDR_ASCAST_I16]], align 4
// CHECK-CPP-NEXT:    [[TMP11:%.*]] = load float, ptr [[__Y_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    [[TMP12:%.*]] = load float, ptr [[__Z_ADDR_ASCAST_I]], align 4
// CHECK-CPP-NEXT:    [[TMP13:%.*]] = call float @llvm.fma.f32(float [[TMP10]], float [[TMP11]], float [[TMP12]])
// CHECK-CPP-NEXT:    store float [[TMP13]], ptr [[L4_ASCAST]], align 4
// CHECK-CPP-NEXT:    ret void
//
void test_math_f32_suffix(float x, float y, float z) {
  float l1 = sinf(x);
  float l2 = cosf(x);
  float l3 = fabsf(x);
  float l4 = fmaf(x, y, z);
}

#pragma omp end declare target
//// NOTE: These prefixes are unused and the list is autogenerated. Do not add tests below this line:
// CHECK: {{.*}}