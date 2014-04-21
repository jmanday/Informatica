	.file	"daxpy.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Tiempo(seg.):%11.9f\t"
.LC2:
	.string	"\n"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB17:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movl	$5, %r15d
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	xorl	%r14d, %r14d
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movq	%rsi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movq	8(%rsi), %rdi
	call	atoi
	movq	16(%rbp), %rdi
	movl	%eax, %ebx
	movslq	%ebx, %r12
	salq	$2, %r12
	call	atoi
	movq	%r12, %rdi
	movl	%eax, %r13d
	call	malloc
	movq	%r12, %rdi
	movq	%rax, %rbp
	call	malloc
	xorl	%edi, %edi
	movq	%rax, %r12
	call	time
	movl	%eax, %edi
	call	srand
	jmp	.L2
.L3:
	call	rand
	cltd
	idivl	%r15d
	incl	%edx
	movl	%edx, 0(%rbp,%r14,4)
	incq	%r14
.L2:
	cmpl	%r14d, %ebx
	jg	.L3
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
	xorl	%eax, %eax
	jmp	.L4
.L5:
	movl	0(%rbp,%rax,4), %edx
	imull	%r13d, %edx
	addl	%edx, (%r12,%rax,4)
	incq	%rax
.L4:
	cmpl	%eax, %ebx
	jg	.L5
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	movl	$.LC1, %esi
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movb	$1, %al
	divsd	.LC0(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
	movl	$.LC2, %edi
	call	puts
	addq	$40, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE17:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
