	.file	"daxpyO0.c"
	.section	.rodata
.LC1:
	.string	"Tiempo(seg.):%11.9f\t"
.LC2:
	.string	"\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$104, %rsp
	movl	%edi, -100(%rbp)
	movq	%rsi, -112(%rbp)
	movq	-112(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	.cfi_offset 3, -24
	call	atoi
	movl	%eax, -24(%rbp)
	movq	-112(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -20(%rbp)
	movl	-24(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -56(%rbp)
	movl	-24(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -48(%rbp)
	movl	$0, %edi
	call	time
	movl	%eax, %edi
	call	srand
	movl	$0, -28(%rbp)
	jmp	.L2
.L3:
	movl	-28(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rbx
	addq	-56(%rbp), %rbx
	call	rand
	movl	%eax, %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	leal	1(%rdx), %eax
	movl	%eax, (%rbx)
	addl	$1, -28(%rbp)
.L2:
	movl	-28(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jl	.L3
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, -28(%rbp)
	jmp	.L4
.L5:
	movl	-28(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-48(%rbp), %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	-56(%rbp), %rdx
	movl	(%rdx), %edx
	movl	%edx, %ecx
	imull	-20(%rbp), %ecx
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	-48(%rbp), %rdx
	movl	(%rdx), %edx
	addl	%ecx, %edx
	movl	%edx, (%rax)
	addl	$1, -28(%rbp)
.L4:
	movl	-28(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jl	.L5
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	-80(%rbp), %rdx
	movq	-96(%rbp), %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-72(%rbp), %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC0(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -40(%rbp)
	movl	$.LC1, %eax
	movsd	-40(%rbp), %xmm0
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf
	movl	$.LC2, %edi
	call	puts
	addq	$104, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
