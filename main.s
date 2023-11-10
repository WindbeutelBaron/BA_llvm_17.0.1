	.text
	.attribute	4, 16
	.attribute	5, "rv64i2p1_m2p0_a2p1_c2p0"
	.file	"main.c"
	.globl	main                            # -- Begin function main
	.p2align	1
	.type	main,@function
main:                                   # @main
# %bb.0:                                # %entry
	check	703710 5
	addi	sp, sp, -32
	sd	ra, 24(sp)                      # 8-byte Folded Spill
	sd	s0, 16(sp)                      # 8-byte Folded Spill
	addi	s0, sp, 32
	li	a0, 0
	sw	a0, -20(s0)
	li	a0, 5
	sw	a0, -24(s0)
	li	a0, 3
	sw	a0, -28(s0)
	lw	a1, -28(s0)
	li	a0, 1
	blt	a0, a1, .LBB0_2
	j	.LBB0_1
.LBB0_1:                                # %if.then
	check	703710 5
	li	a0, 6
	sw	a0, -28(s0)
	j	.LBB0_3
.LBB0_2:                                # %if.else
	check	703710 5
	li	a0, 2
	sw	a0, -28(s0)
	j	.LBB0_3
.LBB0_3:                                # %if.end
	check	703710 5
	lw	a0, -24(s0)
	lw	a1, -28(s0)
	addw	a0, a0, a1
	ld	ra, 24(sp)                      # 8-byte Folded Reload
	ld	s0, 16(sp)                      # 8-byte Folded Reload
	addi	sp, sp, 32
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
                                        # -- End function
	.ident	"clang version 17.0.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
