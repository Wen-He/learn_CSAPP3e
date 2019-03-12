	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_switch_prob            ## -- Begin function switch_prob
	.p2align	4, 0x90
_switch_prob:                           ## @switch_prob
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	addq	$-60, %rsi
	cmpq	$5, %rsi
	ja	LBB0_6
## %bb.1:
	leaq	LJTI0_0(%rip), %rax
	movslq	(%rax,%rsi,4), %rcx
	addq	%rax, %rcx
	jmpq	*%rcx
LBB0_2:
	shlq	$3, %rdi
	jmp	LBB0_7
LBB0_3:
	sarq	$3, %rdi
	jmp	LBB0_7
LBB0_4:
	leaq	(%rdi,%rdi,4), %rax
	leaq	(%rax,%rax,2), %rdi
LBB0_5:
	imulq	%rdi, %rdi
LBB0_6:
	addq	$75, %rdi
LBB0_7:
	movq	%rdi, %rax
	popq	%rbp
	retq
	.cfi_endproc
	.p2align	2, 0x90
	.data_region jt32
L0_0_set_2 = LBB0_2-LJTI0_0
L0_0_set_6 = LBB0_6-LJTI0_0
L0_0_set_3 = LBB0_3-LJTI0_0
L0_0_set_4 = LBB0_4-LJTI0_0
L0_0_set_5 = LBB0_5-LJTI0_0
LJTI0_0:
	.long	L0_0_set_2
	.long	L0_0_set_6
	.long	L0_0_set_2
	.long	L0_0_set_3
	.long	L0_0_set_4
	.long	L0_0_set_5
	.end_data_region
                                        ## -- End function

.subsections_via_symbols
