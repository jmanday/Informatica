	.file	"SumaVectoresGlobal.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Faltan no componentes del vector"
	.align 8
.LC3:
	.string	"Tiempo(seg.):%11.9f\t / Tama\303\261o Vectores:%u\t/ V1[0]+V2[0]=V3[0](%8.6f+%8.6f=%8.6f) / / V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB18:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
	cmpl	$1, %edi
	jle	.L12
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	testl	%eax, %eax
	movl	%eax, %ebx
	je	.L3
	movl	%eax, %edx
	movsd	.LC1(%rip), %xmm3
	cvtsi2sdq	%rdx, %xmm1
	subl	$1, %eax
	addq	$1, %rax
	xorl	%ebp, %ebp
	mulsd	%xmm3, %xmm1
	.p2align 4,,10
	.p2align 3
.L6:
	cvtsi2sd	%ebp, %xmm0
	mulsd	%xmm3, %xmm0
	movapd	%xmm0, %xmm2
	addsd	%xmm1, %xmm2
	movsd	%xmm2, v1(,%rbp,8)
	movapd	%xmm1, %xmm2
	subsd	%xmm0, %xmm2
	movsd	%xmm2, v2(,%rbp,8)
	addq	$1, %rbp
	cmpq	%rax, %rbp
	jne	.L6
	movq	%rsp, %rsi
	xorl	%edi, %edi
	salq	$3, %rbp
	call	clock_gettime
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L7:
	movsd	v1(%rax), %xmm0
	addsd	v2(%rax), %xmm0
	movsd	%xmm0, v3(%rax)
	addq	$8, %rax
	cmpq	%rbp, %rax
	jne	.L7
.L8:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	16(%rsp), %rcx
	subq	(%rsp), %rcx
	leal	-1(%rbx), %edx
	movsd	v3(%rip), %xmm3
	movl	%ebx, %esi
	movl	%edx, %eax
	movsd	v2(%rip), %xmm2
	movsd	v3(,%rax,8), %xmm6
	movl	%edx, %r8d
	cvtsi2sdq	%rcx, %xmm0
	movq	24(%rsp), %rcx
	subq	8(%rsp), %rcx
	movsd	v2(,%rax,8), %xmm5
	movsd	v1(,%rax,8), %xmm4
	movl	$.LC3, %edi
	movl	$7, %eax
	cvtsi2sdq	%rcx, %xmm1
	movl	%edx, %ecx
	divsd	.LC2(%rip), %xmm1
	addsd	%xmm1, %xmm0
	movsd	v1(%rip), %xmm1
	call	printf
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L3:
	.cfi_restore_state
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
	jmp	.L8
.L12:
	movl	$.LC0, %edi
	call	puts
	orl	$-1, %edi
	call	exit
	.cfi_endproc
.LFE18:
	.size	main, .-main
	.comm	v3,80000000,32
	.comm	v2,80000000,32
	.comm	v1,80000000,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	2576980378
	.long	1069128089
	.align 8
.LC2:
	.long	0
	.long	1104006501
	.ident	"GCC: (GNU) 4.6.3 20120306 (Red Hat 4.6.3-2)"
	.section	.note.GNU-stack,"",@progbits
