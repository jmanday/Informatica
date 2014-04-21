	.file	"daxpyO0.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Tiempo(seg.):%11.9f\t"
.LC2:
	.string	"\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB41:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
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
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movq	%rsi, %rbx
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movl	%eax, %r13d
	movq	16(%rbx), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movl	%eax, %r14d
	movslq	%r13d, %rbx
	salq	$2, %rbx
	movq	%rbx, %rdi
	call	malloc
	movq	%rax, %r12
	movq	%rbx, %rdi
	call	malloc
	movq	%rax, %rbp
	movl	$0, %edi
	call	time
	movl	%eax, %edi
	call	srand
	testl	%r13d, %r13d
	jle	.L2
	movl	$0, %ebx
	movl	$1717986919, %r15d
.L3:
	call	rand
	movl	%eax, %ecx
	imull	%r15d
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %edx
	subl	%edx, %ecx
	addl	$1, %ecx
	movl	%ecx, (%r12,%rbx,4)
	addq	$1, %rbx
	cmpl	%ebx, %r13d
	jg	.L3
	movq	%rsp, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, %eax
.L4:
	movl	%r14d, %edx
	imull	(%r12,%rax,4), %edx
	addl	%edx, 0(%rbp,%rax,4)
	addq	$1, %rax
	cmpl	%eax, %r13d
	jg	.L4
.L5:
	leaq	16(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC0(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	movl	$.LC2, %edi
	call	puts
	addq	$40, %rsp
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
	movq	%rsp, %rsi
	movl	$0, %edi
	call	clock_gettime
	jmp	.L5
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
