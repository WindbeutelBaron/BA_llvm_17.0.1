// Check code generation
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -emit-llvm %s -o - | FileCheck %s --check-prefix=IR

// Check same results after serialization round-trip
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -emit-pch -o %t %s
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -include-pch %t -emit-llvm %s -o - | FileCheck %s --check-prefix=IR
// expected-no-diagnostics

#ifndef HEADER
#define HEADER

// placeholder for loop body code.
extern "C" void body(...) {}


// IR-LABEL: @func(
// IR-NEXT:  [[ENTRY:.*]]:
// IR-NEXT:    %[[START_ADDR:.+]] = alloca i32, align 4
// IR-NEXT:    %[[END_ADDR:.+]] = alloca i32, align 4
// IR-NEXT:    %[[STEP_ADDR:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTOMP_IV:.+]] = alloca i32, align 4
// IR-NEXT:    %[[TMP:.+]] = alloca i32, align 4
// IR-NEXT:    %[[I:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_1:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_2:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_3:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTUNROLLED_IV_I:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_6:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_8:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_12:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_14:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTFLOOR_0_IV__UNROLLED_IV_I:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTOMP_LB:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTOMP_UB:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTOMP_STRIDE:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTOMP_IS_LAST:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTFLOOR_0_IV__UNROLLED_IV_I18:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTTILE_0_IV__UNROLLED_IV_I:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTUNROLL_INNER_IV_I:.+]] = alloca i32, align 4
// IR-NEXT:    %[[TMP0:.+]] = call i32 @__kmpc_global_thread_num(ptr @2)
// IR-NEXT:    store i32 %[[START:.+]], ptr %[[START_ADDR]], align 4
// IR-NEXT:    store i32 %[[END:.+]], ptr %[[END_ADDR]], align 4
// IR-NEXT:    store i32 %[[STEP:.+]], ptr %[[STEP_ADDR]], align 4
// IR-NEXT:    %[[TMP1:.+]] = load i32, ptr %[[START_ADDR]], align 4
// IR-NEXT:    store i32 %[[TMP1]], ptr %[[I]], align 4
// IR-NEXT:    %[[TMP2:.+]] = load i32, ptr %[[START_ADDR]], align 4
// IR-NEXT:    store i32 %[[TMP2]], ptr %[[DOTCAPTURE_EXPR_]], align 4
// IR-NEXT:    %[[TMP3:.+]] = load i32, ptr %[[END_ADDR]], align 4
// IR-NEXT:    store i32 %[[TMP3]], ptr %[[DOTCAPTURE_EXPR_1]], align 4
// IR-NEXT:    %[[TMP4:.+]] = load i32, ptr %[[STEP_ADDR]], align 4
// IR-NEXT:    store i32 %[[TMP4]], ptr %[[DOTCAPTURE_EXPR_2]], align 4
// IR-NEXT:    %[[TMP5:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_1]], align 4
// IR-NEXT:    %[[TMP6:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_]], align 4
// IR-NEXT:    %[[SUB:.+]] = sub i32 %[[TMP5]], %[[TMP6]]
// IR-NEXT:    %[[SUB4:.+]] = sub i32 %[[SUB]], 1
// IR-NEXT:    %[[TMP7:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_2]], align 4
// IR-NEXT:    %[[ADD:.+]] = add i32 %[[SUB4]], %[[TMP7]]
// IR-NEXT:    %[[TMP8:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_2]], align 4
// IR-NEXT:    %[[DIV:.+]] = udiv i32 %[[ADD]], %[[TMP8]]
// IR-NEXT:    %[[SUB5:.+]] = sub i32 %[[DIV]], 1
// IR-NEXT:    store i32 %[[SUB5]], ptr %[[DOTCAPTURE_EXPR_3]], align 4
// IR-NEXT:    store i32 0, ptr %[[DOTUNROLLED_IV_I]], align 4
// IR-NEXT:    %[[TMP9:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_3]], align 4
// IR-NEXT:    %[[ADD7:.+]] = add i32 %[[TMP9]], 1
// IR-NEXT:    store i32 %[[ADD7]], ptr %[[DOTCAPTURE_EXPR_6]], align 4
// IR-NEXT:    %[[TMP10:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_6]], align 4
// IR-NEXT:    %[[SUB9:.+]] = sub i32 %[[TMP10]], -1
// IR-NEXT:    %[[DIV10:.+]] = udiv i32 %[[SUB9]], 2
// IR-NEXT:    %[[SUB11:.+]] = sub i32 %[[DIV10]], 1
// IR-NEXT:    store i32 %[[SUB11]], ptr %[[DOTCAPTURE_EXPR_8]], align 4
// IR-NEXT:    %[[TMP11:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_8]], align 4
// IR-NEXT:    %[[ADD13:.+]] = add i32 %[[TMP11]], 1
// IR-NEXT:    store i32 %[[ADD13]], ptr %[[DOTCAPTURE_EXPR_12]], align 4
// IR-NEXT:    %[[TMP12:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_12]], align 4
// IR-NEXT:    %[[SUB15:.+]] = sub i32 %[[TMP12]], -3
// IR-NEXT:    %[[DIV16:.+]] = udiv i32 %[[SUB15]], 4
// IR-NEXT:    %[[SUB17:.+]] = sub i32 %[[DIV16]], 1
// IR-NEXT:    store i32 %[[SUB17]], ptr %[[DOTCAPTURE_EXPR_14]], align 4
// IR-NEXT:    store i32 0, ptr %[[DOTFLOOR_0_IV__UNROLLED_IV_I]], align 4
// IR-NEXT:    %[[TMP13:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_12]], align 4
// IR-NEXT:    %[[CMP:.+]] = icmp ult i32 0, %[[TMP13]]
// IR-NEXT:    br i1 %[[CMP]], label %[[OMP_PRECOND_THEN:.+]], label %[[OMP_PRECOND_END:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_PRECOND_THEN]]:
// IR-NEXT:    store i32 0, ptr %[[DOTOMP_LB]], align 4
// IR-NEXT:    %[[TMP14:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_14]], align 4
// IR-NEXT:    store i32 %[[TMP14]], ptr %[[DOTOMP_UB]], align 4
// IR-NEXT:    store i32 1, ptr %[[DOTOMP_STRIDE]], align 4
// IR-NEXT:    store i32 0, ptr %[[DOTOMP_IS_LAST]], align 4
// IR-NEXT:    call void @__kmpc_for_static_init_4u(ptr @1, i32 %[[TMP0]], i32 34, ptr %[[DOTOMP_IS_LAST]], ptr %[[DOTOMP_LB]], ptr %[[DOTOMP_UB]], ptr %[[DOTOMP_STRIDE]], i32 1, i32 1)
// IR-NEXT:    %[[TMP15:.+]] = load i32, ptr %[[DOTOMP_UB]], align 4
// IR-NEXT:    %[[TMP16:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_14]], align 4
// IR-NEXT:    %[[CMP19:.+]] = icmp ugt i32 %[[TMP15]], %[[TMP16]]
// IR-NEXT:    br i1 %[[CMP19]], label %[[COND_TRUE:.+]], label %[[COND_FALSE:.+]]
// IR-EMPTY:
// IR-NEXT:  [[COND_TRUE]]:
// IR-NEXT:    %[[TMP17:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_14]], align 4
// IR-NEXT:    br label %[[COND_END:.+]]
// IR-EMPTY:
// IR-NEXT:  [[COND_FALSE]]:
// IR-NEXT:    %[[TMP18:.+]] = load i32, ptr %[[DOTOMP_UB]], align 4
// IR-NEXT:    br label %[[COND_END]]
// IR-EMPTY:
// IR-NEXT:  [[COND_END]]:
// IR-NEXT:    %[[COND:.+]] = phi i32 [ %[[TMP17]], %[[COND_TRUE]] ], [ %[[TMP18]], %[[COND_FALSE]] ]
// IR-NEXT:    store i32 %[[COND]], ptr %[[DOTOMP_UB]], align 4
// IR-NEXT:    %[[TMP19:.+]] = load i32, ptr %[[DOTOMP_LB]], align 4
// IR-NEXT:    store i32 %[[TMP19]], ptr %[[DOTOMP_IV]], align 4
// IR-NEXT:    br label %[[OMP_INNER_FOR_COND:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_INNER_FOR_COND]]:
// IR-NEXT:    %[[TMP20:.+]] = load i32, ptr %[[DOTOMP_IV]], align 4
// IR-NEXT:    %[[TMP21:.+]] = load i32, ptr %[[DOTOMP_UB]], align 4
// IR-NEXT:    %[[ADD20:.+]] = add i32 %[[TMP21]], 1
// IR-NEXT:    %[[CMP21:.+]] = icmp ult i32 %[[TMP20]], %[[ADD20]]
// IR-NEXT:    br i1 %[[CMP21]], label %[[OMP_INNER_FOR_BODY:.+]], label %[[OMP_INNER_FOR_END:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_INNER_FOR_BODY]]:
// IR-NEXT:    %[[TMP22:.+]] = load i32, ptr %[[DOTOMP_IV]], align 4
// IR-NEXT:    %[[MUL:.+]] = mul i32 %[[TMP22]], 4
// IR-NEXT:    %[[ADD22:.+]] = add i32 0, %[[MUL]]
// IR-NEXT:    store i32 %[[ADD22]], ptr %[[DOTFLOOR_0_IV__UNROLLED_IV_I18]], align 4
// IR-NEXT:    %[[TMP23:.+]] = load i32, ptr %[[DOTFLOOR_0_IV__UNROLLED_IV_I18]], align 4
// IR-NEXT:    store i32 %[[TMP23]], ptr %[[DOTTILE_0_IV__UNROLLED_IV_I]], align 4
// IR-NEXT:    br label %[[FOR_COND:.+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_COND]]:
// IR-NEXT:    %[[TMP24:.+]] = load i32, ptr %[[DOTTILE_0_IV__UNROLLED_IV_I]], align 4
// IR-NEXT:    %[[TMP25:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_8]], align 4
// IR-NEXT:    %[[ADD23:.+]] = add i32 %[[TMP25]], 1
// IR-NEXT:    %[[TMP26:.+]] = load i32, ptr %[[DOTFLOOR_0_IV__UNROLLED_IV_I18]], align 4
// IR-NEXT:    %[[ADD24:.+]] = add i32 %[[TMP26]], 4
// IR-NEXT:    %[[CMP25:.+]] = icmp ult i32 %[[ADD23]], %[[ADD24]]
// IR-NEXT:    br i1 %[[CMP25]], label %[[COND_TRUE26:.+]], label %[[COND_FALSE28:.+]]
// IR-EMPTY:
// IR-NEXT:  [[COND_TRUE26]]:
// IR-NEXT:    %[[TMP27:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_8]], align 4
// IR-NEXT:    %[[ADD27:.+]] = add i32 %[[TMP27]], 1
// IR-NEXT:    br label %[[COND_END30:.+]]
// IR-EMPTY:
// IR-NEXT:  [[COND_FALSE28]]:
// IR-NEXT:    %[[TMP28:.+]] = load i32, ptr %[[DOTFLOOR_0_IV__UNROLLED_IV_I18]], align 4
// IR-NEXT:    %[[ADD29:.+]] = add i32 %[[TMP28]], 4
// IR-NEXT:    br label %[[COND_END30]]
// IR-EMPTY:
// IR-NEXT:  [[COND_END30]]:
// IR-NEXT:    %[[COND31:.+]] = phi i32 [ %[[ADD27]], %[[COND_TRUE26]] ], [ %[[ADD29]], %[[COND_FALSE28]] ]
// IR-NEXT:    %[[CMP32:.+]] = icmp ult i32 %[[TMP24]], %[[COND31]]
// IR-NEXT:    br i1 %[[CMP32]], label %[[FOR_BODY:.+]], label %[[FOR_END45:.+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_BODY]]:
// IR-NEXT:    %[[TMP29:.+]] = load i32, ptr %[[DOTTILE_0_IV__UNROLLED_IV_I]], align 4
// IR-NEXT:    %[[MUL33:.+]] = mul i32 %[[TMP29]], 2
// IR-NEXT:    %[[ADD34:.+]] = add i32 0, %[[MUL33]]
// IR-NEXT:    store i32 %[[ADD34]], ptr %[[DOTUNROLLED_IV_I]], align 4
// IR-NEXT:    %[[TMP30:.+]] = load i32, ptr %[[DOTUNROLLED_IV_I]], align 4
// IR-NEXT:    store i32 %[[TMP30]], ptr %[[DOTUNROLL_INNER_IV_I]], align 4
// IR-NEXT:    br label %[[FOR_COND35:.+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_COND35]]:
// IR-NEXT:    %[[TMP31:.+]] = load i32, ptr %[[DOTUNROLL_INNER_IV_I]], align 4
// IR-NEXT:    %[[TMP32:.+]] = load i32, ptr %[[DOTUNROLLED_IV_I]], align 4
// IR-NEXT:    %[[ADD36:.+]] = add i32 %[[TMP32]], 2
// IR-NEXT:    %[[CMP37:.+]] = icmp ult i32 %[[TMP31]], %[[ADD36]]
// IR-NEXT:    br i1 %[[CMP37]], label %[[LAND_RHS:.+]], label %[[LAND_END:.+]]
// IR-EMPTY:
// IR-NEXT:  [[LAND_RHS]]:
// IR-NEXT:    %[[TMP33:.+]] = load i32, ptr %[[DOTUNROLL_INNER_IV_I]], align 4
// IR-NEXT:    %[[TMP34:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_3]], align 4
// IR-NEXT:    %[[ADD38:.+]] = add i32 %[[TMP34]], 1
// IR-NEXT:    %[[CMP39:.+]] = icmp ult i32 %[[TMP33]], %[[ADD38]]
// IR-NEXT:    br label %[[LAND_END]]
// IR-EMPTY:
// IR-NEXT:  [[LAND_END]]:
// IR-NEXT:    %[[TMP35:.+]] = phi i1 [ false, %[[FOR_COND35]] ], [ %[[CMP39]], %[[LAND_RHS]] ]
// IR-NEXT:    br i1 %[[TMP35]], label %[[FOR_BODY40:.+]], label %[[FOR_END:.+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_BODY40]]:
// IR-NEXT:    %[[TMP36:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_]], align 4
// IR-NEXT:    %[[TMP37:.+]] = load i32, ptr %[[DOTUNROLL_INNER_IV_I]], align 4
// IR-NEXT:    %[[TMP38:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_2]], align 4
// IR-NEXT:    %[[MUL41:.+]] = mul i32 %[[TMP37]], %[[TMP38]]
// IR-NEXT:    %[[ADD42:.+]] = add i32 %[[TMP36]], %[[MUL41]]
// IR-NEXT:    store i32 %[[ADD42]], ptr %[[I]], align 4
// IR-NEXT:    %[[TMP39:.+]] = load i32, ptr %[[START_ADDR]], align 4
// IR-NEXT:    %[[TMP40:.+]] = load i32, ptr %[[END_ADDR]], align 4
// IR-NEXT:    %[[TMP41:.+]] = load i32, ptr %[[STEP_ADDR]], align 4
// IR-NEXT:    %[[TMP42:.+]] = load i32, ptr %[[I]], align 4
// IR-NEXT:    call void (...) @body(i32 noundef %[[TMP39]], i32 noundef %[[TMP40]], i32 noundef %[[TMP41]], i32 noundef %[[TMP42]])
// IR-NEXT:    br label %[[FOR_INC:.+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_INC]]:
// IR-NEXT:    %[[TMP43:.+]] = load i32, ptr %[[DOTUNROLL_INNER_IV_I]], align 4
// IR-NEXT:    %[[INC:.+]] = add i32 %[[TMP43]], 1
// IR-NEXT:    store i32 %[[INC]], ptr %[[DOTUNROLL_INNER_IV_I]], align 4
// IR-NEXT:    br label %[[FOR_COND35]], !llvm.loop ![[LOOP2:[0-9]+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_END]]:
// IR-NEXT:    br label %[[FOR_INC43:.+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_INC43]]:
// IR-NEXT:    %[[TMP44:.+]] = load i32, ptr %[[DOTTILE_0_IV__UNROLLED_IV_I]], align 4
// IR-NEXT:    %[[INC44:.+]] = add i32 %[[TMP44]], 1
// IR-NEXT:    store i32 %[[INC44]], ptr %[[DOTTILE_0_IV__UNROLLED_IV_I]], align 4
// IR-NEXT:    br label %[[FOR_COND]], !llvm.loop ![[LOOP5:[0-9]+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_END45]]:
// IR-NEXT:    br label %[[OMP_BODY_CONTINUE:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_BODY_CONTINUE]]:
// IR-NEXT:    br label %[[OMP_INNER_FOR_INC:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_INNER_FOR_INC]]:
// IR-NEXT:    %[[TMP45:.+]] = load i32, ptr %[[DOTOMP_IV]], align 4
// IR-NEXT:    %[[ADD46:.+]] = add i32 %[[TMP45]], 1
// IR-NEXT:    store i32 %[[ADD46]], ptr %[[DOTOMP_IV]], align 4
// IR-NEXT:    br label %[[OMP_INNER_FOR_COND]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_INNER_FOR_END]]:
// IR-NEXT:    br label %[[OMP_LOOP_EXIT:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_LOOP_EXIT]]:
// IR-NEXT:    call void @__kmpc_for_static_fini(ptr @1, i32 %[[TMP0]])
// IR-NEXT:    br label %[[OMP_PRECOND_END]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_PRECOND_END]]:
// IR-NEXT:    call void @__kmpc_barrier(ptr @3, i32 %[[TMP0]])
// IR-NEXT:    ret void
// IR-NEXT:  }
extern "C" void func(int start, int end, int step) {
  #pragma omp for
  #pragma omp tile sizes(4)
  #pragma omp unroll partial
  for (int i = start; i < end; i+=step)
    body(start, end, step, i);
}

#endif /* HEADER */


// IR: ![[LOOP2]] = distinct !{![[LOOP2]], ![[LOOPPROP3:[0-9]+]], ![[LOOPPROP4:[0-9]+]]}
// IR: ![[LOOPPROP3]] = !{!"llvm.loop.mustprogress"}
// IR: ![[LOOPPROP4]] = !{!"llvm.loop.unroll.count", i32 2}
// IR: ![[LOOP5]] = distinct !{![[LOOP5]], ![[LOOPPROP3]]}
