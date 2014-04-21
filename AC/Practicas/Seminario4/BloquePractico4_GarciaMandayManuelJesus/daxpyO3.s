	.file	"daxpy.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Tiempo(seg.):%11.9f\t"
.LC2:
	.string	"\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB41:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movl	$10, %edx
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rsi, %rbx
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	movq	8(%rsi), %rdi
	xorl	%esi, %esi
	call	strtol
	movq	16(%rbx), %rdi
	movq	%rax, %r14
	xorl	%esi, %esi
	movslq	%r14d, %rbx
	movl	$10, %edx
	movl	%eax, %ebp
	salq	$2, %rbx
	call	strtol
	movq	%rbx, %rdi
	movl	%eax, %r13d
	call	malloc
	movq	%rbx, %rdi
	movq	%rax, %r12
	call	malloc
	xorl	%edi, %edi
	movq	%rax, %rbx
	call	time
	movl	%eax, %edi
	call	srand
	testl	%r14d, %r14d
	jle	.L2
	xorl	%r15d, %r15d
	.p2align 4,,10
	.p2align 3
.L3:
	call	rand
	movl	%eax, %ecx
	movl	$1717986919, %eax
	imull	%ecx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	%edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %edx
	subl	%edx, %ecx
	addl	$1, %ecx
	movl	%ecx, (%r12,%r15,4)
	addq	$1, %r15
	cmpl	%r15d, %ebp
	jg	.L3
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	%rbx, %rdi
	andl	$15, %edi
	shrq	$2, %rdi
	negq	%rdi
	andl	$3, %edi
	cmpl	%r14d, %edi
	cmova	%r14d, %edi
	testl	%edi, %edi
	movl	%edi, %esi
	je	.L12
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L5:
	movl	(%r12,%rax,4), %edx
	leal	1(%rax), %ecx
	imull	%r13d, %edx
	addl	%edx, (%rbx,%rax,4)
	addq	$1, %rax
	cmpl	%eax, %edi
	ja	.L5
	cmpl	%edi, %r14d
	je	.L11
.L4:
	subl	%edi, %r14d
	movl	%r14d, %edi
	shrl	$2, %edi
	leal	0(,%rdi,4), %r9d
	testl	%r9d, %r9d
	je	.L7
	movl	%r13d, 12(%rsp)
	salq	$2, %rsi
	xorl	%eax, %eax
	movd	12(%rsp), %xmm0
	leaq	(%r12,%rsi), %r8
	xorl	%edx, %edx
	addq	%rbx, %rsi
	pshufd	$0, %xmm0, %xmm2
	.p2align 4,,10
	.p2align 3
.L8:
	movdqu	(%r8,%rax), %xmm1
	addl	$1, %edx
	movdqa	%xmm2, %xmm3
	movdqa	%xmm1, %xmm0
	psrldq	$4, %xmm1
	psrldq	$4, %xmm3
	pmuludq	%xmm3, %xmm1
	pshufd	$8, %xmm1, %xmm1
	pmuludq	%xmm2, %xmm0
	pshufd	$8, %xmm0, %xmm0
	punpckldq	%xmm1, %xmm0
	paddd	(%rsi,%rax), %xmm0
	movdqa	%xmm0, (%rsi,%rax)
	addq	$16, %rax
	cmpl	%edi, %edx
	jb	.L8
	addl	%r9d, %ecx
	cmpl	%r9d, %r14d
	je	.L11
.L7:
	movslq	%ecx, %rdx
	xorl	%eax, %eax
	salq	$2, %rdx
	addq	%rdx, %rbx
	addq	%rdx, %r12
	.p2align 4,,10
	.p2align 3
.L10:
	movl	(%r12,%rax,4), %edx
	imull	%r13d, %edx
	addl	%edx, (%rbx,%rax,4)
	addq	$1, %rax
	leal	(%rcx,%rax), %edx
	cmpl	%ebp, %edx
	jl	.L10
.L11:
	leaq	32(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	movl	$.LC1, %esi
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	40(%rsp), %rax
	subq	24(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC0(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
	movl	$.LC2, %edi
	call	puts
	addq	$56, %rsp
	.cfi_remember_state
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
.L2:
	.cfi_restore_state
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	jmp	.L11
.L12:
	xorl	%ecx, %ecx
	jmp	.L4
	.cfi_endproc
.LFE41:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
