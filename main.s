	.text
	.attribute	4, 16
	.attribute	5, "rv64i2p1_m2p0_a2p1_c2p0"
	.file	"main.c"
	.globl	kall                            # -- Begin function kall
	.p2align	1
	.type	kall,@function
kall:                                   # @kall
# %bb.0:                                # %entry
	check	1048575, 1, 1, 1, 1
	addi	sp, sp, -32
	sd	ra, 24(sp)                      # 8-byte Folded Spill
	sd	s0, 16(sp)                      # 8-byte Folded Spill
	addi	s0, sp, 32
                                        # kill: def $x12 killed $x11
                                        # kill: def $x12 killed $x10
	sw	a0, -20(s0)
	sw	a1, -24(s0)
	lw	a0, -20(s0)
	addiw	a0, a0, 3
	sw	a0, -20(s0)
	lw	a1, -24(s0)
	slliw	a0, a1, 2
	addw	a0, a0, a1
	sw	a0, -24(s0)
	lw	a0, -20(s0)
	li	a1, 8
	correct	0
	blt	a0, a1, .LBB0_2
	correct	0
	j	.LBB0_1
.LBB0_1:                                # %if.then
	check	1048575, 1, 1, 1, 1
	li	a0, 3
	sw	a0, -20(s0)
	correct	0
	j	.LBB0_6
.LBB0_2:                                # %if.else
	check	1048575, 1, 1, 1, 1
	lw	a1, -24(s0)
	li	a0, 14
	correct	0
	blt	a0, a1, .LBB0_4
	correct	0
	j	.LBB0_3
.LBB0_3:                                # %if.then2
	check	1048575, 1, 1, 1, 1
	li	a0, 13
	sw	a0, -24(s0)
	correct	0
	j	.LBB0_5
.LBB0_4:                                # %if.else3
	check	1048575, 1, 1, 1, 1
	correct	0
	j	.LBB0_5
.LBB0_5:                                # %if.end
	check	1048575, 1, 1, 1, 1
	correct	0
	j	.LBB0_6
.LBB0_6:                                # %if.end4
	check	1048575, 1, 1, 1, 1
	lw	a1, -20(s0)
	lw	a0, -24(s0)
	addw	a0, a0, a1
	addiw	a0, a0, -3
	ld	ra, 24(sp)                      # 8-byte Folded Reload
	ld	s0, 16(sp)                      # 8-byte Folded Reload
	addi	sp, sp, 32
	correct	0
	ret
.Lfunc_end0:
	.size	kall, .Lfunc_end0-kall
                                        # -- End function
	.globl	grow                            # -- Begin function grow
	.p2align	1
	.type	grow,@function
grow:                                   # @grow
# %bb.0:                                # %entry
	check	1048575, 1, 1, 1, 1
	addi	sp, sp, -32
	sd	ra, 24(sp)                      # 8-byte Folded Spill
	sd	s0, 16(sp)                      # 8-byte Folded Spill
	addi	s0, sp, 32
                                        # kill: def $x12 killed $x11
                                        # kill: def $x12 killed $x10
	sw	a0, -20(s0)
	sw	a1, -24(s0)
	lw	a0, -20(s0)
	lw	a1, -24(s0)
	correct	0
	call	kall
	sw	a0, -20(s0)
	lw	a0, -20(s0)
	li	a1, 8
	correct	0
	blt	a0, a1, .LBB1_2
	correct	0
	j	.LBB1_1
.LBB1_1:                                # %if.then
	check	1048575, 1, 1, 1, 1
	li	a0, 3
	sw	a0, -20(s0)
	correct	0
	j	.LBB1_2
.LBB1_2:                                # %if.end
	check	1048575, 1, 1, 1, 1
	lw	a0, -20(s0)
	lw	a1, -24(s0)
	addw	a1, a1, a0
	slliw	a0, a1, 2
	addw	a0, a0, a1
	ld	ra, 24(sp)                      # 8-byte Folded Reload
	ld	s0, 16(sp)                      # 8-byte Folded Reload
	addi	sp, sp, 32
	correct	0
	ret
.Lfunc_end1:
	.size	grow, .Lfunc_end1-grow
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	1
	.type	main,@function
main:                                   # @main
# %bb.0:                                # %entry
	check	1048575, 1, 1, 1, 1
	addi	sp, sp, -32
	sd	ra, 24(sp)                      # 8-byte Folded Spill
	sd	s0, 16(sp)                      # 8-byte Folded Spill
	addi	s0, sp, 32
	li	a0, 0
	sw	a0, -20(s0)
	li	a0, 4
	sw	a0, -24(s0)
	li	a0, 16
	sw	a0, -28(s0)
	lw	a1, -24(s0)
	li	a0, 2
	correct	0
	blt	a0, a1, .LBB2_2
	correct	0
	j	.LBB2_1
.LBB2_1:                                # %if.then
	check	1048575, 1, 1, 1, 1
	li	a0, 5
	sw	a0, -24(s0)
	correct	0
	j	.LBB2_3
.LBB2_2:                                # %if.else
	check	1048575, 1, 1, 1, 1
	lw	a0, -24(s0)
	lw	a1, -28(s0)
	correct	0
	call	grow
	sw	a0, -24(s0)
	correct	0
	j	.LBB2_3
.LBB2_3:                                # %if.end
	check	1048575, 1, 1, 1, 1
	lw	a0, -24(s0)
	ld	ra, 24(sp)                      # 8-byte Folded Reload
	ld	s0, 16(sp)                      # 8-byte Folded Reload
	addi	sp, sp, 32
	correct	0
	ret
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
                                        # -- End function
	.ident	"clang version 17.0.1 (https://github.com/WindbeutelBaron/BA_llvm_17.0.1.git 8253b234237c5f7a76d13379695a1851489cb7d0)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym kall
	.addrsig_sym grow
