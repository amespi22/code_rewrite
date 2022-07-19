	.file	"new_printf.c"
	.text
.Ltext0:
	.globl	cgc_putc
	.type	cgc_putc, @function
cgc_putc:
.LFB0:
	.file 1 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/new_printf.c"
	.loc 1 36 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	.loc 1 39 10
	leal	-12(%ebp), %eax
	pushl	%eax
	pushl	$1
	leal	8(%ebp), %eax
	pushl	%eax
	pushl	$1
	call	cgc_transmit@PLT
	addl	$16, %esp
	.loc 1 39 8
	testl	%eax, %eax
	je	.L2
	.loc 1 40 9
	subl	$12, %esp
	pushl	$2
	call	cgc__terminate@PLT
.L2:
	.loc 1 42 12
	movl	8(%ebp), %eax
	.loc 1 43 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	cgc_putc, .-cgc_putc
	.globl	cgc_int_to_str
	.type	cgc_int_to_str, @function
cgc_int_to_str:
.LFB1:
	.loc 1 46 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$48, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 48 11
	leal	-40(%ebp), %eax
	movl	%eax, -4(%ebp)
	.loc 1 49 9
	movl	$0, -8(%ebp)
	.loc 1 51 8
	cmpl	$0, 12(%ebp)
	je	.L11
	.loc 1 54 8
	cmpl	$0, 8(%ebp)
	jns	.L8
	.loc 1 56 14
	movl	12(%ebp), %eax
	movb	$45, (%eax)
	.loc 1 57 12
	addl	$1, 12(%ebp)
	.loc 1 59 13
	negl	8(%ebp)
.L8:
	.loc 1 64 19 discriminator 1
	movl	8(%ebp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	.loc 1 64 25 discriminator 1
	movl	%edx, %eax
	addl	$48, %eax
	movl	%eax, %edx
	.loc 1 64 12 discriminator 1
	movl	-4(%ebp), %eax
	movb	%dl, (%eax)
	.loc 1 65 13 discriminator 1
	movl	8(%ebp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 8(%ebp)
	.loc 1 67 10 discriminator 1
	addl	$1, -4(%ebp)
	.loc 1 68 14 discriminator 1
	addl	$1, -8(%ebp)
	.loc 1 69 5 discriminator 1
	cmpl	$0, 8(%ebp)
	jne	.L8
	.loc 1 71 11
	jmp	.L9
.L10:
	.loc 1 73 10
	subl	$1, -4(%ebp)
	.loc 1 74 16
	movl	-4(%ebp), %eax
	movzbl	(%eax), %edx
	.loc 1 74 14
	movl	12(%ebp), %eax
	movb	%dl, (%eax)
	.loc 1 75 12
	addl	$1, 12(%ebp)
.L9:
	.loc 1 71 18
	movl	-8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	%edx, -8(%ebp)
	.loc 1 71 11
	testl	%eax, %eax
	jg	.L10
	.loc 1 78 10
	movl	12(%ebp), %eax
	movb	$0, (%eax)
	jmp	.L4
.L11:
	.loc 1 52 9
	nop
.L4:
	.loc 1 79 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	cgc_int_to_str, .-cgc_int_to_str
	.globl	cgc_int_to_hex
	.type	cgc_int_to_hex, @function
cgc_int_to_hex:
.LFB2:
	.loc 1 82 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$48, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 84 11
	leal	-40(%ebp), %eax
	movl	%eax, -4(%ebp)
	.loc 1 85 9
	movl	$0, -8(%ebp)
	.loc 1 87 8
	cmpl	$0, 12(%ebp)
	je	.L18
.L13:
	.loc 1 92 19
	movl	8(%ebp), %eax
	andl	$15, %eax
	.loc 1 92 25
	addl	$48, %eax
	movl	%eax, %edx
	.loc 1 92 12
	movl	-4(%ebp), %eax
	movb	%dl, (%eax)
	.loc 1 93 6
	movl	-4(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 93 5
	cmpb	$57, %al
	jle	.L15
	.loc 1 94 6
	movl	-4(%ebp), %eax
	movzbl	(%eax), %eax
	addl	$7, %eax
	movl	%eax, %edx
	movl	-4(%ebp), %eax
	movb	%dl, (%eax)
.L15:
	.loc 1 96 13
	movl	8(%ebp), %eax
	shrl	$4, %eax
	movl	%eax, 8(%ebp)
	.loc 1 98 10
	addl	$1, -4(%ebp)
	.loc 1 99 14
	addl	$1, -8(%ebp)
	.loc 1 100 5
	cmpl	$0, 8(%ebp)
	jne	.L13
	.loc 1 102 11
	jmp	.L16
.L17:
	.loc 1 104 10
	subl	$1, -4(%ebp)
	.loc 1 105 16
	movl	-4(%ebp), %eax
	movzbl	(%eax), %edx
	.loc 1 105 14
	movl	12(%ebp), %eax
	movb	%dl, (%eax)
	.loc 1 106 12
	addl	$1, 12(%ebp)
.L16:
	.loc 1 102 18
	movl	-8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	%edx, -8(%ebp)
	.loc 1 102 11
	testl	%eax, %eax
	jg	.L17
	.loc 1 109 10
	movl	12(%ebp), %eax
	movb	$0, (%eax)
	jmp	.L12
.L18:
	.loc 1 88 9
	nop
.L12:
	.loc 1 110 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	cgc_int_to_hex, .-cgc_int_to_hex
	.section	.rodata
.LC0:
	.string	"nan"
.LC1:
	.string	"inf"
.LC3:
	.string	"0.00000"
	.text
	.globl	cgc_float_to_str
	.type	cgc_float_to_str, @function
cgc_float_to_str:
.LFB3:
	.loc 1 113 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	movl	8(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -60(%ebp)
	.loc 1 114 8
	cmpl	$0, 16(%ebp)
	je	.L47
	.loc 1 117 10
	subl	$8, %esp
	pushl	-60(%ebp)
	pushl	-64(%ebp)
	call	cgc_isnan@PLT
	addl	$16, %esp
	.loc 1 117 8
	testl	%eax, %eax
	je	.L22
	.loc 1 119 9
	subl	$8, %esp
	leal	.LC0@GOTOFF(%ebx), %eax
	pushl	%eax
	pushl	16(%ebp)
	call	cgc_strcpy@PLT
	addl	$16, %esp
	jmp	.L48
.L22:
	.loc 1 121 15
	subl	$8, %esp
	pushl	-60(%ebp)
	pushl	-64(%ebp)
	call	cgc_isinf@PLT
	addl	$16, %esp
	.loc 1 121 13
	testl	%eax, %eax
	je	.L23
	.loc 1 123 9
	subl	$8, %esp
	leal	.LC1@GOTOFF(%ebx), %eax
	pushl	%eax
	pushl	16(%ebp)
	call	cgc_strcpy@PLT
	addl	$16, %esp
	jmp	.L48
.L23:
	.loc 1 125 13
	fldl	-64(%ebp)
	fldz
	fucomip	%st(1), %st
	fstp	%st(0)
	jp	.L24
	fldl	-64(%ebp)
	fldz
	fucomip	%st(1), %st
	fstp	%st(0)
	jne	.L24
	.loc 1 127 9
	subl	$8, %esp
	leal	.LC3@GOTOFF(%ebx), %eax
	pushl	%eax
	pushl	16(%ebp)
	call	cgc_strcpy@PLT
	addl	$16, %esp
	jmp	.L48
.L24:
.LBB2:
	.loc 1 136 13
	movl	$0, -28(%ebp)
	.loc 1 137 15
	movl	16(%ebp), %eax
	movl	%eax, -24(%ebp)
	.loc 1 139 12
	fldz
	fldl	-64(%ebp)
	fcomip	%st(1), %st
	fstp	%st(0)
	jbe	.L46
	.loc 1 140 17
	fldl	-64(%ebp)
	fldl	.LC4@GOTOFF(%ebx)
	faddp	%st, %st(1)
	fstpl	-64(%ebp)
	jmp	.L28
.L46:
	.loc 1 142 17
	fldl	-64(%ebp)
	fldl	.LC4@GOTOFF(%ebx)
	fsubrp	%st, %st(1)
	fstpl	-64(%ebp)
.L28:
	.loc 1 145 12
	fldl	-64(%ebp)
	fldz
	fcomip	%st(1), %st
	fstp	%st(0)
	jbe	.L29
	.loc 1 147 17
	movl	$1, -28(%ebp)
	.loc 1 148 16
	movl	-24(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -24(%ebp)
	.loc 1 148 20
	movb	$45, (%eax)
	.loc 1 149 17
	fldl	-64(%ebp)
	fchs
	fstpl	-64(%ebp)
.L29:
	.loc 1 153 13
	subl	$8, %esp
	pushl	-60(%ebp)
	pushl	-64(%ebp)
	call	cgc_log10@PLT
	addl	$16, %esp
	.loc 1 153 11
	fnstcw	-66(%ebp)
	movzwl	-66(%ebp), %eax
	orb	$12, %ah
	movw	%ax, -68(%ebp)
	fldcw	-68(%ebp)
	fistpl	-12(%ebp)
	fldcw	-66(%ebp)
	.loc 1 155 12
	cmpl	$0, -12(%ebp)
	jg	.L31
	.loc 1 156 15
	movl	$0, -12(%ebp)
.L31:
	.loc 1 158 24
	movl	$0, -16(%ebp)
	.loc 1 159 21
	movl	$0, -20(%ebp)
	.loc 1 160 15
	jmp	.L32
.L37:
.LBB3:
	.loc 1 162 29
	fildl	-12(%ebp)
	leal	-8(%esp), %esp
	fstpl	(%esp)
	fldl	.LC5@GOTOFF(%ebx)
	leal	-8(%esp), %esp
	fstpl	(%esp)
	call	cgc_pow@PLT
	addl	$16, %esp
	fstpl	-40(%ebp)
	.loc 1 163 16
	fldz
	fldl	-40(%ebp)
	fcomip	%st(1), %st
	fstp	%st(0)
	jbe	.L33
	.loc 1 163 33 discriminator 1
	subl	$8, %esp
	pushl	-36(%ebp)
	pushl	-40(%ebp)
	call	cgc_isinf@PLT
	addl	$16, %esp
	.loc 1 163 29 discriminator 1
	testl	%eax, %eax
	jne	.L33
	.loc 1 165 25
	fldl	-64(%ebp)
	fdivl	-40(%ebp)
	subl	$8, %esp
	leal	-8(%esp), %esp
	fstpl	(%esp)
	call	cgc_floor@PLT
	addl	$16, %esp
	.loc 1 165 23
	fnstcw	-66(%ebp)
	movzwl	-66(%ebp), %eax
	orb	$12, %ah
	movw	%ax, -68(%ebp)
	fldcw	-68(%ebp)
	fistpl	-44(%ebp)
	fldcw	-66(%ebp)
	.loc 1 166 31
	fildl	-44(%ebp)
	fmull	-40(%ebp)
	.loc 1 166 21
	fldl	-64(%ebp)
	fsubp	%st, %st(1)
	fstpl	-64(%ebp)
	.loc 1 168 30
	movl	-44(%ebp), %eax
	leal	48(%eax), %ecx
	.loc 1 168 20
	movl	-24(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -24(%ebp)
	.loc 1 168 30
	movl	%ecx, %edx
	.loc 1 168 24
	movb	%dl, (%eax)
	.loc 1 170 20
	cmpl	$0, -20(%ebp)
	je	.L33
	.loc 1 171 35
	addl	$1, -16(%ebp)
.L33:
	.loc 1 174 16
	cmpl	$0, -12(%ebp)
	jne	.L35
	.loc 1 174 25 discriminator 1
	fldz
	fldl	-64(%ebp)
	fcomip	%st(1), %st
	fstp	%st(0)
	jbe	.L35
	.loc 1 176 20
	movl	-24(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -24(%ebp)
	.loc 1 176 24
	movb	$46, (%eax)
	.loc 1 177 29
	movl	$1, -20(%ebp)
	.loc 1 178 32
	movl	$0, -16(%ebp)
.L35:
	.loc 1 181 14
	subl	$1, -12(%ebp)
.L32:
.LBE3:
	.loc 1 160 15
	fldl	.LC6@GOTOFF(%ebx)
	fldl	-64(%ebp)
	fcomip	%st(1), %st
	fstp	%st(0)
	ja	.L37
	.loc 1 160 31 discriminator 1
	cmpl	$0, -12(%ebp)
	jns	.L37
	.loc 1 184 15
	jmp	.L38
.L40:
	.loc 1 186 16
	movl	-24(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -24(%ebp)
	.loc 1 186 20
	movb	$48, (%eax)
	.loc 1 187 27
	addl	$1, -16(%ebp)
.L38:
	.loc 1 184 15
	cmpl	$0, -20(%ebp)
	je	.L39
	.loc 1 184 29 discriminator 1
	movl	-16(%ebp), %eax
	cmpl	20(%ebp), %eax
	jl	.L40
.L39:
	.loc 1 190 12
	movl	-24(%ebp), %eax
	movb	$0, (%eax)
	jmp	.L48
.L47:
.LBE2:
	.loc 1 115 9
	nop
.L48:
	.loc 1 192 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	cgc_float_to_str, .-cgc_float_to_str
	.globl	cgc_vprintf
	.type	cgc_vprintf, @function
cgc_vprintf:
.LFB4:
	.loc 1 195 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$144, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	.loc 1 196 9
	movl	$0, -12(%ebp)
	.loc 1 202 8
	cmpl	$0, 8(%ebp)
	jne	.L52
	.loc 1 203 16
	movl	$-1, %eax
	jmp	.L116
.L115:
	.loc 1 207 14
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 207 12
	cmpb	$64, %al
	jne	.L53
	.loc 1 209 16
	addl	$1, 8(%ebp)
	.loc 1 211 18
	movl	$0, -16(%ebp)
	.loc 1 212 22
	movl	$0, -20(%ebp)
	.loc 1 213 25
	movl	$0, -24(%ebp)
	.loc 1 214 31
	movl	$0, -28(%ebp)
	.loc 1 215 20
	movl	$0, -56(%ebp)
	.loc 1 218 17
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 218 16
	cmpb	$64, %al
	jne	.L54
	.loc 1 220 17
	subl	$12, %esp
	pushl	$64
	call	cgc_putc
	addl	$16, %esp
	.loc 1 221 20
	addl	$1, 8(%ebp)
	.loc 1 222 32
	addl	$1, -12(%ebp)
	.loc 1 223 17
	jmp	.L52
.L54:
	.loc 1 226 17
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 226 16
	cmpb	$45, %al
	jne	.L55
	.loc 1 228 35
	movl	$1, -28(%ebp)
	.loc 1 229 17
	addl	$1, 8(%ebp)
.L55:
	.loc 1 232 29
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 232 17
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_isdigit@PLT
	addl	$16, %esp
	.loc 1 232 16
	testl	%eax, %eax
	je	.L56
	.loc 1 234 21
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 234 20
	cmpb	$48, %al
	jne	.L57
	.loc 1 236 34
	movl	$1, -24(%ebp)
	.loc 1 237 24
	addl	$1, 8(%ebp)
.L57:
	.loc 1 240 33
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 240 21
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_isdigit@PLT
	addl	$16, %esp
	.loc 1 240 20
	testl	%eax, %eax
	je	.L56
	.loc 1 242 29
	subl	$12, %esp
	pushl	8(%ebp)
	call	cgc_atoi@PLT
	addl	$16, %esp
	movl	%eax, -16(%ebp)
	.loc 1 245 27
	jmp	.L58
.L59:
	.loc 1 246 28
	addl	$1, 8(%ebp)
.L58:
	.loc 1 245 40
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 245 28
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_isdigit@PLT
	addl	$16, %esp
	.loc 1 245 27
	testl	%eax, %eax
	jne	.L59
.L56:
	.loc 1 250 17
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 250 16
	cmpb	$46, %al
	jne	.L60
	.loc 1 253 20
	addl	$1, 8(%ebp)
	.loc 1 255 27
	subl	$12, %esp
	pushl	8(%ebp)
	call	cgc_atoi@PLT
	addl	$16, %esp
	movl	%eax, -20(%ebp)
	.loc 1 258 23
	jmp	.L61
.L62:
	.loc 1 259 24
	addl	$1, 8(%ebp)
.L61:
	.loc 1 258 36
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 258 24
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_isdigit@PLT
	addl	$16, %esp
	.loc 1 258 23
	testl	%eax, %eax
	jne	.L62
.L60:
	.loc 1 264 17
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 264 16
	cmpb	$99, %al
	jne	.L63
.LBB4:
	.loc 1 266 54
	movl	12(%ebp), %eax
	leal	4(%eax), %edx
	movl	%edx, 12(%ebp)
	movl	(%eax), %eax
	.loc 1 266 22
	movb	%al, -57(%ebp)
	.loc 1 268 25
	movl	-16(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -56(%ebp)
	.loc 1 271 20
	cmpl	$0, -28(%ebp)
	jne	.L64
	.loc 1 272 27
	movl	$0, -32(%ebp)
	.loc 1 272 21
	jmp	.L65
.L68:
	.loc 1 274 28
	cmpl	$0, -24(%ebp)
	je	.L66
	.loc 1 275 29
	subl	$12, %esp
	pushl	$48
	call	cgc_putc
	addl	$16, %esp
	jmp	.L67
.L66:
	.loc 1 277 29
	subl	$12, %esp
	pushl	$32
	call	cgc_putc
	addl	$16, %esp
.L67:
	.loc 1 279 40 discriminator 2
	addl	$1, -12(%ebp)
	.loc 1 272 43 discriminator 2
	addl	$1, -32(%ebp)
.L65:
	.loc 1 272 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L68
.L64:
	.loc 1 284 17
	movsbl	-57(%ebp), %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_putc
	addl	$16, %esp
	.loc 1 285 32
	addl	$1, -12(%ebp)
	.loc 1 288 20
	cmpl	$0, -28(%ebp)
	je	.L69
	.loc 1 289 27
	movl	$0, -32(%ebp)
	.loc 1 289 21
	jmp	.L70
.L71:
	.loc 1 292 25 discriminator 3
	subl	$12, %esp
	pushl	$32
	call	cgc_putc
	addl	$16, %esp
	.loc 1 293 40 discriminator 3
	addl	$1, -12(%ebp)
	.loc 1 289 43 discriminator 3
	addl	$1, -32(%ebp)
.L70:
	.loc 1 289 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L71
.L69:
	.loc 1 297 20
	addl	$1, 8(%ebp)
	.loc 1 298 17
	jmp	.L52
.L63:
.LBE4:
	.loc 1 302 17
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 302 16
	cmpb	$100, %al
	jne	.L72
.LBB5:
	.loc 1 304 21
	movl	12(%ebp), %eax
	leal	4(%eax), %edx
	movl	%edx, 12(%ebp)
	movl	(%eax), %eax
	movl	%eax, -64(%ebp)
	.loc 1 307 17
	subl	$8, %esp
	leal	-144(%ebp), %eax
	pushl	%eax
	pushl	-64(%ebp)
	call	cgc_int_to_str
	addl	$16, %esp
	.loc 1 310 33
	movl	-16(%ebp), %esi
	.loc 1 310 35
	subl	$12, %esp
	leal	-144(%ebp), %eax
	pushl	%eax
	call	cgc_strlen@PLT
	addl	$16, %esp
	.loc 1 310 33
	subl	%eax, %esi
	movl	%esi, %eax
	.loc 1 310 25
	movl	%eax, -56(%ebp)
	.loc 1 313 20
	cmpl	$0, -28(%ebp)
	jne	.L73
	.loc 1 314 27
	movl	$0, -32(%ebp)
	.loc 1 314 21
	jmp	.L74
.L77:
	.loc 1 316 28
	cmpl	$0, -24(%ebp)
	je	.L75
	.loc 1 317 29
	subl	$12, %esp
	pushl	$48
	call	cgc_putc
	addl	$16, %esp
	jmp	.L76
.L75:
	.loc 1 319 29
	subl	$12, %esp
	pushl	$32
	call	cgc_putc
	addl	$16, %esp
.L76:
	.loc 1 321 40 discriminator 2
	addl	$1, -12(%ebp)
	.loc 1 314 43 discriminator 2
	addl	$1, -32(%ebp)
.L74:
	.loc 1 314 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L77
.L73:
	.loc 1 326 19
	leal	-144(%ebp), %eax
	movl	%eax, -36(%ebp)
	.loc 1 327 23
	jmp	.L78
.L79:
	.loc 1 329 31
	movl	-36(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 329 21
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_putc
	addl	$16, %esp
	.loc 1 330 36
	addl	$1, -12(%ebp)
	.loc 1 331 22
	addl	$1, -36(%ebp)
.L78:
	.loc 1 327 25
	movl	-36(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 327 23
	testb	%al, %al
	jne	.L79
	.loc 1 335 20
	cmpl	$0, -28(%ebp)
	je	.L80
	.loc 1 336 27
	movl	$0, -32(%ebp)
	.loc 1 336 21
	jmp	.L81
.L82:
	.loc 1 339 25 discriminator 3
	subl	$12, %esp
	pushl	$32
	call	cgc_putc
	addl	$16, %esp
	.loc 1 340 40 discriminator 3
	addl	$1, -12(%ebp)
	.loc 1 336 43 discriminator 3
	addl	$1, -32(%ebp)
.L81:
	.loc 1 336 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L82
.L80:
	.loc 1 344 20
	addl	$1, 8(%ebp)
	.loc 1 345 17
	jmp	.L52
.L72:
.LBE5:
	.loc 1 350 18
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 350 16
	cmpb	$120, %al
	jne	.L83
.LBB6:
	.loc 1 352 30
	movl	12(%ebp), %eax
	leal	4(%eax), %edx
	movl	%edx, 12(%ebp)
	movl	(%eax), %eax
	movl	%eax, -68(%ebp)
	.loc 1 355 17
	subl	$8, %esp
	leal	-144(%ebp), %eax
	pushl	%eax
	pushl	-68(%ebp)
	call	cgc_int_to_hex
	addl	$16, %esp
	.loc 1 358 33
	movl	-16(%ebp), %esi
	.loc 1 358 35
	subl	$12, %esp
	leal	-144(%ebp), %eax
	pushl	%eax
	call	cgc_strlen@PLT
	addl	$16, %esp
	.loc 1 358 33
	subl	%eax, %esi
	movl	%esi, %eax
	.loc 1 358 25
	movl	%eax, -56(%ebp)
	.loc 1 361 20
	cmpl	$0, -28(%ebp)
	jne	.L84
	.loc 1 362 27
	movl	$0, -32(%ebp)
	.loc 1 362 21
	jmp	.L85
.L88:
	.loc 1 364 28
	cmpl	$0, -24(%ebp)
	je	.L86
	.loc 1 365 29
	subl	$12, %esp
	pushl	$48
	call	cgc_putc
	addl	$16, %esp
	jmp	.L87
.L86:
	.loc 1 367 29
	subl	$12, %esp
	pushl	$32
	call	cgc_putc
	addl	$16, %esp
.L87:
	.loc 1 369 40 discriminator 2
	addl	$1, -12(%ebp)
	.loc 1 362 43 discriminator 2
	addl	$1, -32(%ebp)
.L85:
	.loc 1 362 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L88
.L84:
	.loc 1 374 19
	leal	-144(%ebp), %eax
	movl	%eax, -40(%ebp)
	.loc 1 375 23
	jmp	.L89
.L90:
	.loc 1 377 31
	movl	-40(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 377 21
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_putc
	addl	$16, %esp
	.loc 1 378 36
	addl	$1, -12(%ebp)
	.loc 1 379 22
	addl	$1, -40(%ebp)
.L89:
	.loc 1 375 25
	movl	-40(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 375 23
	testb	%al, %al
	jne	.L90
	.loc 1 383 20
	cmpl	$0, -28(%ebp)
	je	.L91
	.loc 1 384 27
	movl	$0, -32(%ebp)
	.loc 1 384 21
	jmp	.L92
.L93:
	.loc 1 387 25 discriminator 3
	subl	$12, %esp
	pushl	$32
	call	cgc_putc
	addl	$16, %esp
	.loc 1 388 40 discriminator 3
	addl	$1, -12(%ebp)
	.loc 1 384 43 discriminator 3
	addl	$1, -32(%ebp)
.L92:
	.loc 1 384 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L93
.L91:
	.loc 1 392 20
	addl	$1, 8(%ebp)
	.loc 1 393 17
	jmp	.L52
.L83:
.LBE6:
	.loc 1 397 17
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 397 16
	cmpb	$102, %al
	jne	.L94
.LBB7:
	.loc 1 402 24
	movl	12(%ebp), %eax
	leal	8(%eax), %edx
	movl	%edx, 12(%ebp)
	fldl	(%eax)
	fstpl	-80(%ebp)
	.loc 1 405 17
	pushl	-20(%ebp)
	leal	-144(%ebp), %eax
	pushl	%eax
	pushl	-76(%ebp)
	pushl	-80(%ebp)
	call	cgc_float_to_str
	addl	$16, %esp
	.loc 1 408 33
	movl	-16(%ebp), %esi
	.loc 1 408 35
	subl	$12, %esp
	leal	-144(%ebp), %eax
	pushl	%eax
	call	cgc_strlen@PLT
	addl	$16, %esp
	.loc 1 408 33
	subl	%eax, %esi
	movl	%esi, %eax
	.loc 1 408 25
	movl	%eax, -56(%ebp)
	.loc 1 411 20
	cmpl	$0, -28(%ebp)
	jne	.L95
	.loc 1 412 27
	movl	$0, -32(%ebp)
	.loc 1 412 21
	jmp	.L96
.L99:
	.loc 1 414 28
	cmpl	$0, -24(%ebp)
	je	.L97
	.loc 1 415 29
	subl	$12, %esp
	pushl	$48
	call	cgc_putc
	addl	$16, %esp
	jmp	.L98
.L97:
	.loc 1 417 29
	subl	$12, %esp
	pushl	$32
	call	cgc_putc
	addl	$16, %esp
.L98:
	.loc 1 419 40 discriminator 2
	addl	$1, -12(%ebp)
	.loc 1 412 43 discriminator 2
	addl	$1, -32(%ebp)
.L96:
	.loc 1 412 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L99
.L95:
	.loc 1 424 19
	leal	-144(%ebp), %eax
	movl	%eax, -44(%ebp)
	.loc 1 425 23
	jmp	.L100
.L101:
	.loc 1 427 31
	movl	-44(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 427 21
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_putc
	addl	$16, %esp
	.loc 1 428 36
	addl	$1, -12(%ebp)
	.loc 1 429 22
	addl	$1, -44(%ebp)
.L100:
	.loc 1 425 25
	movl	-44(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 425 23
	testb	%al, %al
	jne	.L101
	.loc 1 431 20
	addl	$1, 8(%ebp)
	.loc 1 432 17
	jmp	.L52
.L94:
.LBE7:
	.loc 1 435 17
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 435 16
	cmpb	$115, %al
	jne	.L52
.LBB8:
	.loc 1 437 23
	movl	12(%ebp), %eax
	leal	4(%eax), %edx
	movl	%edx, 12(%ebp)
	movl	(%eax), %eax
	movl	%eax, -48(%ebp)
	.loc 1 440 20
	cmpl	$0, -20(%ebp)
	jle	.L102
	.loc 1 440 50 discriminator 1
	subl	$12, %esp
	pushl	-48(%ebp)
	call	cgc_strlen@PLT
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 440 48 discriminator 1
	movl	-20(%ebp), %eax
	.loc 1 440 35 discriminator 1
	cmpl	%eax, %edx
	jbe	.L102
	.loc 1 442 35
	movl	-20(%ebp), %eax
	movl	%eax, -52(%ebp)
	jmp	.L103
.L102:
	.loc 1 444 37
	subl	$12, %esp
	pushl	-48(%ebp)
	call	cgc_strlen@PLT
	addl	$16, %esp
	.loc 1 444 35
	movl	%eax, -52(%ebp)
.L103:
	.loc 1 447 25
	movl	-16(%ebp), %eax
	subl	-52(%ebp), %eax
	movl	%eax, -56(%ebp)
	.loc 1 451 20
	cmpl	$0, -28(%ebp)
	jne	.L109
	.loc 1 452 27
	movl	$0, -32(%ebp)
	.loc 1 452 21
	jmp	.L105
.L108:
	.loc 1 454 28
	cmpl	$0, -24(%ebp)
	je	.L106
	.loc 1 455 29
	subl	$12, %esp
	pushl	$48
	call	cgc_putc
	addl	$16, %esp
	jmp	.L107
.L106:
	.loc 1 457 29
	subl	$12, %esp
	pushl	$32
	call	cgc_putc
	addl	$16, %esp
.L107:
	.loc 1 459 40 discriminator 2
	addl	$1, -12(%ebp)
	.loc 1 452 43 discriminator 2
	addl	$1, -32(%ebp)
.L105:
	.loc 1 452 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L108
	.loc 1 463 23
	jmp	.L109
.L111:
	.loc 1 465 31
	movl	-48(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 465 21
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_putc
	addl	$16, %esp
	.loc 1 466 36
	addl	$1, -12(%ebp)
	.loc 1 467 31
	addl	$1, -48(%ebp)
	.loc 1 468 21
	subl	$1, -52(%ebp)
.L109:
	.loc 1 463 25
	movl	-48(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 463 23
	testb	%al, %al
	je	.L110
	.loc 1 463 37 discriminator 1
	cmpl	$0, -52(%ebp)
	jg	.L111
.L110:
	.loc 1 472 20
	cmpl	$0, -28(%ebp)
	je	.L112
	.loc 1 473 27
	movl	$0, -32(%ebp)
	.loc 1 473 21
	jmp	.L113
.L114:
	.loc 1 476 25 discriminator 3
	subl	$12, %esp
	pushl	$32
	call	cgc_putc
	addl	$16, %esp
	.loc 1 477 40 discriminator 3
	addl	$1, -12(%ebp)
	.loc 1 473 43 discriminator 3
	addl	$1, -32(%ebp)
.L113:
	.loc 1 473 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L114
.L112:
	.loc 1 481 20
	addl	$1, 8(%ebp)
	.loc 1 482 17
	jmp	.L52
.L53:
.LBE8:
	.loc 1 489 23
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 489 13
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_putc
	addl	$16, %esp
	.loc 1 490 16
	addl	$1, 8(%ebp)
	.loc 1 492 28
	addl	$1, -12(%ebp)
.L52:
	.loc 1 205 13
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 205 11
	testb	%al, %al
	jne	.L115
	.loc 1 496 12
	movl	-12(%ebp), %eax
.L116:
	.loc 1 497 1 discriminator 1
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	cgc_vprintf, .-cgc_vprintf
	.globl	cgc_vsprintf
	.type	cgc_vsprintf, @function
cgc_vsprintf:
.LFB5:
	.loc 1 503 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$144, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	.loc 1 504 9
	movl	$0, -12(%ebp)
	.loc 1 510 8
	cmpl	$0, 12(%ebp)
	jne	.L120
	.loc 1 511 16
	movl	$-1, %eax
	jmp	.L184
.L183:
	.loc 1 515 14
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 515 12
	cmpb	$64, %al
	jne	.L121
	.loc 1 517 16
	addl	$1, 12(%ebp)
	.loc 1 519 18
	movl	$0, -16(%ebp)
	.loc 1 520 22
	movl	$0, -20(%ebp)
	.loc 1 521 25
	movl	$0, -24(%ebp)
	.loc 1 522 31
	movl	$0, -28(%ebp)
	.loc 1 523 20
	movl	$0, -56(%ebp)
	.loc 1 526 17
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 526 16
	cmpb	$64, %al
	jne	.L122
	.loc 1 528 20
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 528 37
	movb	$64, (%eax)
	.loc 1 529 20
	addl	$1, 12(%ebp)
	.loc 1 530 32
	addl	$1, -12(%ebp)
	.loc 1 531 17
	jmp	.L120
.L122:
	.loc 1 534 17
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 534 16
	cmpb	$45, %al
	jne	.L123
	.loc 1 536 35
	movl	$1, -28(%ebp)
	.loc 1 537 17
	addl	$1, 12(%ebp)
.L123:
	.loc 1 540 29
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 540 17
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_isdigit@PLT
	addl	$16, %esp
	.loc 1 540 16
	testl	%eax, %eax
	je	.L124
	.loc 1 542 21
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 542 20
	cmpb	$48, %al
	jne	.L125
	.loc 1 544 34
	movl	$1, -24(%ebp)
	.loc 1 545 24
	addl	$1, 12(%ebp)
.L125:
	.loc 1 548 33
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 548 21
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_isdigit@PLT
	addl	$16, %esp
	.loc 1 548 20
	testl	%eax, %eax
	je	.L124
	.loc 1 550 29
	subl	$12, %esp
	pushl	12(%ebp)
	call	cgc_atoi@PLT
	addl	$16, %esp
	movl	%eax, -16(%ebp)
	.loc 1 552 27
	jmp	.L126
.L127:
	.loc 1 553 28
	addl	$1, 12(%ebp)
.L126:
	.loc 1 552 40
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 552 28
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_isdigit@PLT
	addl	$16, %esp
	.loc 1 552 27
	testl	%eax, %eax
	jne	.L127
.L124:
	.loc 1 557 17
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 557 16
	cmpb	$46, %al
	jne	.L128
	.loc 1 560 20
	addl	$1, 12(%ebp)
	.loc 1 562 27
	subl	$12, %esp
	pushl	12(%ebp)
	call	cgc_atoi@PLT
	addl	$16, %esp
	movl	%eax, -20(%ebp)
	.loc 1 565 23
	jmp	.L129
.L130:
	.loc 1 566 24
	addl	$1, 12(%ebp)
.L129:
	.loc 1 565 36
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 565 24
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_isdigit@PLT
	addl	$16, %esp
	.loc 1 565 23
	testl	%eax, %eax
	jne	.L130
.L128:
	.loc 1 571 17
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 571 16
	cmpb	$99, %al
	jne	.L131
.LBB9:
	.loc 1 573 54
	movl	16(%ebp), %eax
	leal	4(%eax), %edx
	movl	%edx, 16(%ebp)
	movl	(%eax), %eax
	.loc 1 573 22
	movb	%al, -57(%ebp)
	.loc 1 575 25
	movl	-16(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -56(%ebp)
	.loc 1 578 20
	cmpl	$0, -28(%ebp)
	jne	.L132
	.loc 1 579 27
	movl	$0, -32(%ebp)
	.loc 1 579 21
	jmp	.L133
.L136:
	.loc 1 581 28
	cmpl	$0, -24(%ebp)
	je	.L134
	.loc 1 582 32
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 582 49
	movb	$48, (%eax)
	jmp	.L135
.L134:
	.loc 1 584 32
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 584 49
	movb	$32, (%eax)
.L135:
	.loc 1 586 40 discriminator 2
	addl	$1, -12(%ebp)
	.loc 1 579 43 discriminator 2
	addl	$1, -32(%ebp)
.L133:
	.loc 1 579 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L136
.L132:
	.loc 1 590 20
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	.loc 1 590 37
	movzbl	-57(%ebp), %eax
	movb	%al, (%edx)
	.loc 1 591 32
	addl	$1, -12(%ebp)
	.loc 1 594 20
	cmpl	$0, -28(%ebp)
	je	.L137
	.loc 1 595 27
	movl	$0, -32(%ebp)
	.loc 1 595 21
	jmp	.L138
.L139:
	.loc 1 598 28 discriminator 3
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 598 45 discriminator 3
	movb	$32, (%eax)
	.loc 1 599 40 discriminator 3
	addl	$1, -12(%ebp)
	.loc 1 595 43 discriminator 3
	addl	$1, -32(%ebp)
.L138:
	.loc 1 595 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L139
.L137:
	.loc 1 603 20
	addl	$1, 12(%ebp)
	.loc 1 604 17
	jmp	.L120
.L131:
.LBE9:
	.loc 1 608 17
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 608 16
	cmpb	$100, %al
	jne	.L140
.LBB10:
	.loc 1 610 21
	movl	16(%ebp), %eax
	leal	4(%eax), %edx
	movl	%edx, 16(%ebp)
	movl	(%eax), %eax
	movl	%eax, -64(%ebp)
	.loc 1 613 17
	subl	$8, %esp
	leal	-144(%ebp), %eax
	pushl	%eax
	pushl	-64(%ebp)
	call	cgc_int_to_str
	addl	$16, %esp
	.loc 1 616 33
	movl	-16(%ebp), %esi
	.loc 1 616 35
	subl	$12, %esp
	leal	-144(%ebp), %eax
	pushl	%eax
	call	cgc_strlen@PLT
	addl	$16, %esp
	.loc 1 616 33
	subl	%eax, %esi
	movl	%esi, %eax
	.loc 1 616 25
	movl	%eax, -56(%ebp)
	.loc 1 619 20
	cmpl	$0, -28(%ebp)
	jne	.L141
	.loc 1 620 27
	movl	$0, -32(%ebp)
	.loc 1 620 21
	jmp	.L142
.L145:
	.loc 1 622 28
	cmpl	$0, -24(%ebp)
	je	.L143
	.loc 1 623 32
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 623 49
	movb	$48, (%eax)
	jmp	.L144
.L143:
	.loc 1 625 32
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 625 49
	movb	$32, (%eax)
.L144:
	.loc 1 627 40 discriminator 2
	addl	$1, -12(%ebp)
	.loc 1 620 43 discriminator 2
	addl	$1, -32(%ebp)
.L142:
	.loc 1 620 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L145
.L141:
	.loc 1 632 19
	leal	-144(%ebp), %eax
	movl	%eax, -36(%ebp)
	.loc 1 633 23
	jmp	.L146
.L147:
	.loc 1 635 24
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	.loc 1 635 42
	movl	-36(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 635 41
	movb	%al, (%edx)
	.loc 1 636 36
	addl	$1, -12(%ebp)
	.loc 1 637 22
	addl	$1, -36(%ebp)
.L146:
	.loc 1 633 25
	movl	-36(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 633 23
	testb	%al, %al
	jne	.L147
	.loc 1 641 20
	cmpl	$0, -28(%ebp)
	je	.L148
	.loc 1 642 27
	movl	$0, -32(%ebp)
	.loc 1 642 21
	jmp	.L149
.L150:
	.loc 1 645 28 discriminator 3
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 645 45 discriminator 3
	movb	$32, (%eax)
	.loc 1 646 40 discriminator 3
	addl	$1, -12(%ebp)
	.loc 1 642 43 discriminator 3
	addl	$1, -32(%ebp)
.L149:
	.loc 1 642 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L150
.L148:
	.loc 1 650 20
	addl	$1, 12(%ebp)
	.loc 1 651 17
	jmp	.L120
.L140:
.LBE10:
	.loc 1 656 18
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 656 16
	cmpb	$120, %al
	jne	.L151
.LBB11:
	.loc 1 658 30
	movl	16(%ebp), %eax
	leal	4(%eax), %edx
	movl	%edx, 16(%ebp)
	movl	(%eax), %eax
	movl	%eax, -68(%ebp)
	.loc 1 661 17
	subl	$8, %esp
	leal	-144(%ebp), %eax
	pushl	%eax
	pushl	-68(%ebp)
	call	cgc_int_to_hex
	addl	$16, %esp
	.loc 1 664 33
	movl	-16(%ebp), %esi
	.loc 1 664 35
	subl	$12, %esp
	leal	-144(%ebp), %eax
	pushl	%eax
	call	cgc_strlen@PLT
	addl	$16, %esp
	.loc 1 664 33
	subl	%eax, %esi
	movl	%esi, %eax
	.loc 1 664 25
	movl	%eax, -56(%ebp)
	.loc 1 667 20
	cmpl	$0, -28(%ebp)
	jne	.L152
	.loc 1 668 27
	movl	$0, -32(%ebp)
	.loc 1 668 21
	jmp	.L153
.L156:
	.loc 1 670 28
	cmpl	$0, -24(%ebp)
	je	.L154
	.loc 1 671 32
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 671 50
	movb	$48, (%eax)
	jmp	.L155
.L154:
	.loc 1 673 32
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 673 50
	movb	$32, (%eax)
.L155:
	.loc 1 675 40 discriminator 2
	addl	$1, -12(%ebp)
	.loc 1 668 43 discriminator 2
	addl	$1, -32(%ebp)
.L153:
	.loc 1 668 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L156
.L152:
	.loc 1 680 19
	leal	-144(%ebp), %eax
	movl	%eax, -40(%ebp)
	.loc 1 681 23
	jmp	.L157
.L158:
	.loc 1 683 24
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	.loc 1 683 42
	movl	-40(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 683 41
	movb	%al, (%edx)
	.loc 1 684 36
	addl	$1, -12(%ebp)
	.loc 1 685 22
	addl	$1, -40(%ebp)
.L157:
	.loc 1 681 25
	movl	-40(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 681 23
	testb	%al, %al
	jne	.L158
	.loc 1 689 20
	cmpl	$0, -28(%ebp)
	je	.L159
	.loc 1 690 27
	movl	$0, -32(%ebp)
	.loc 1 690 21
	jmp	.L160
.L161:
	.loc 1 693 28 discriminator 3
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 693 45 discriminator 3
	movb	$32, (%eax)
	.loc 1 694 40 discriminator 3
	addl	$1, -12(%ebp)
	.loc 1 690 43 discriminator 3
	addl	$1, -32(%ebp)
.L160:
	.loc 1 690 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L161
.L159:
	.loc 1 698 20
	addl	$1, 12(%ebp)
	.loc 1 699 17
	jmp	.L120
.L151:
.LBE11:
	.loc 1 703 17
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 703 16
	cmpb	$102, %al
	jne	.L162
.LBB12:
	.loc 1 706 24
	movl	16(%ebp), %eax
	leal	8(%eax), %edx
	movl	%edx, 16(%ebp)
	fldl	(%eax)
	fstpl	-80(%ebp)
	.loc 1 709 17
	pushl	-20(%ebp)
	leal	-144(%ebp), %eax
	pushl	%eax
	pushl	-76(%ebp)
	pushl	-80(%ebp)
	call	cgc_float_to_str
	addl	$16, %esp
	.loc 1 712 33
	movl	-16(%ebp), %esi
	.loc 1 712 35
	subl	$12, %esp
	leal	-144(%ebp), %eax
	pushl	%eax
	call	cgc_strlen@PLT
	addl	$16, %esp
	.loc 1 712 33
	subl	%eax, %esi
	movl	%esi, %eax
	.loc 1 712 25
	movl	%eax, -56(%ebp)
	.loc 1 715 20
	cmpl	$0, -28(%ebp)
	jne	.L163
	.loc 1 716 27
	movl	$0, -32(%ebp)
	.loc 1 716 21
	jmp	.L164
.L167:
	.loc 1 718 28
	cmpl	$0, -24(%ebp)
	je	.L165
	.loc 1 719 32
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 719 49
	movb	$48, (%eax)
	jmp	.L166
.L165:
	.loc 1 721 32
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 721 49
	movb	$32, (%eax)
.L166:
	.loc 1 723 40 discriminator 2
	addl	$1, -12(%ebp)
	.loc 1 716 43 discriminator 2
	addl	$1, -32(%ebp)
.L164:
	.loc 1 716 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L167
.L163:
	.loc 1 728 19
	leal	-144(%ebp), %eax
	movl	%eax, -44(%ebp)
	.loc 1 729 23
	jmp	.L168
.L169:
	.loc 1 731 24
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	.loc 1 731 43
	movl	-44(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 731 41
	movb	%al, (%edx)
	.loc 1 732 36
	addl	$1, -12(%ebp)
	.loc 1 733 22
	addl	$1, -44(%ebp)
.L168:
	.loc 1 729 25
	movl	-44(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 729 23
	testb	%al, %al
	jne	.L169
	.loc 1 735 20
	addl	$1, 12(%ebp)
	.loc 1 736 17
	jmp	.L120
.L162:
.LBE12:
	.loc 1 739 17
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 739 16
	cmpb	$115, %al
	jne	.L120
.LBB13:
	.loc 1 741 23
	movl	16(%ebp), %eax
	leal	4(%eax), %edx
	movl	%edx, 16(%ebp)
	movl	(%eax), %eax
	movl	%eax, -48(%ebp)
	.loc 1 744 20
	cmpl	$0, -20(%ebp)
	jle	.L170
	.loc 1 744 50 discriminator 1
	subl	$12, %esp
	pushl	-48(%ebp)
	call	cgc_strlen@PLT
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 744 48 discriminator 1
	movl	-20(%ebp), %eax
	.loc 1 744 35 discriminator 1
	cmpl	%eax, %edx
	jbe	.L170
	.loc 1 746 35
	movl	-20(%ebp), %eax
	movl	%eax, -52(%ebp)
	jmp	.L171
.L170:
	.loc 1 748 37
	subl	$12, %esp
	pushl	-48(%ebp)
	call	cgc_strlen@PLT
	addl	$16, %esp
	.loc 1 748 35
	movl	%eax, -52(%ebp)
.L171:
	.loc 1 751 25
	movl	-16(%ebp), %eax
	subl	-52(%ebp), %eax
	movl	%eax, -56(%ebp)
	.loc 1 755 20
	cmpl	$0, -28(%ebp)
	jne	.L177
	.loc 1 756 27
	movl	$0, -32(%ebp)
	.loc 1 756 21
	jmp	.L173
.L176:
	.loc 1 758 28
	cmpl	$0, -24(%ebp)
	je	.L174
	.loc 1 759 32
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 759 49
	movb	$48, (%eax)
	jmp	.L175
.L174:
	.loc 1 761 32
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 761 49
	movb	$32, (%eax)
.L175:
	.loc 1 762 40 discriminator 2
	addl	$1, -12(%ebp)
	.loc 1 756 43 discriminator 2
	addl	$1, -32(%ebp)
.L173:
	.loc 1 756 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L176
	.loc 1 766 23
	jmp	.L177
.L179:
	.loc 1 768 24
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	.loc 1 768 43
	movl	-48(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 768 41
	movb	%al, (%edx)
	.loc 1 769 36
	addl	$1, -12(%ebp)
	.loc 1 770 31
	addl	$1, -48(%ebp)
	.loc 1 771 21
	subl	$1, -52(%ebp)
.L177:
	.loc 1 766 25
	movl	-48(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 766 23
	testb	%al, %al
	je	.L178
	.loc 1 766 37 discriminator 1
	cmpl	$0, -52(%ebp)
	jg	.L179
.L178:
	.loc 1 775 20
	cmpl	$0, -28(%ebp)
	je	.L180
	.loc 1 776 27
	movl	$0, -32(%ebp)
	.loc 1 776 21
	jmp	.L181
.L182:
	.loc 1 779 28 discriminator 3
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 779 45 discriminator 3
	movb	$32, (%eax)
	.loc 1 780 40 discriminator 3
	addl	$1, -12(%ebp)
	.loc 1 776 43 discriminator 3
	addl	$1, -32(%ebp)
.L181:
	.loc 1 776 21 discriminator 1
	movl	-32(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L182
.L180:
	.loc 1 784 20
	addl	$1, 12(%ebp)
	.loc 1 785 17
	jmp	.L120
.L121:
.LBE13:
	.loc 1 792 16
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	.loc 1 792 35
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 792 33
	movb	%al, (%edx)
	.loc 1 793 16
	addl	$1, 12(%ebp)
	.loc 1 795 28
	addl	$1, -12(%ebp)
.L120:
	.loc 1 513 13
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 513 11
	testb	%al, %al
	jne	.L183
	.loc 1 799 12
	movl	-12(%ebp), %eax
.L184:
	.loc 1 800 1 discriminator 1
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	cgc_vsprintf, .-cgc_vsprintf
	.globl	cgc_printf
	.type	cgc_printf, @function
cgc_printf:
.LFB6:
	.loc 1 803 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4120, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 809 5
	leal	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	.loc 1 814 12
	movl	-16(%ebp), %eax
	subl	$8, %esp
	pushl	%eax
	pushl	8(%ebp)
	call	cgc_vprintf
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 817 12
	movl	-12(%ebp), %eax
	.loc 1 818 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE6:
	.size	cgc_printf, .-cgc_printf
	.globl	cgc_sprintf
	.type	cgc_sprintf, @function
cgc_sprintf:
.LFB7:
	.loc 1 821 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 825 5
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	.loc 1 826 12
	movl	-16(%ebp), %eax
	subl	$4, %esp
	pushl	%eax
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	cgc_vsprintf
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 829 12
	movl	-12(%ebp), %eax
	.loc 1 830 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE7:
	.size	cgc_sprintf, .-cgc_sprintf
	.section	.rodata
	.align 8
.LC4:
	.long	2296604913
	.long	1054144693
	.align 8
.LC5:
	.long	0
	.long	1076101120
	.align 8
.LC6:
	.long	2296604913
	.long	1055193269
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB8:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE8:
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LFB9:
	.cfi_startproc
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE9:
	.text
.Letext0:
	.file 2 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/include/libcgc.h"
	.file 3 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/cgc_stdarg.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x685
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF428
	.byte	0xc
	.long	.LASF429
	.long	.LASF430
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.long	.Ldebug_macro0
	.uleb128 0x2
	.long	.LASF390
	.byte	0x2
	.byte	0x13
	.byte	0x17
	.long	0x35
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF387
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.long	.LASF388
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF389
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.long	.LASF391
	.byte	0x3
	.byte	0x20
	.byte	0x1b
	.long	0x5d
	.uleb128 0x5
	.byte	0x4
	.long	.LASF431
	.long	0x67
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF392
	.uleb128 0x6
	.long	0x67
	.uleb128 0x2
	.long	.LASF393
	.byte	0x3
	.byte	0x27
	.byte	0x18
	.long	0x51
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF394
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF395
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF396
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF397
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF398
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF399
	.uleb128 0x7
	.long	.LASF401
	.byte	0x1
	.value	0x334
	.byte	0x5
	.long	0x4a
	.long	.LFB7
	.long	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.long	0x106
	.uleb128 0x8
	.string	"str"
	.byte	0x1
	.value	0x334
	.byte	0x18
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x8
	.string	"fmt"
	.byte	0x1
	.value	0x334
	.byte	0x29
	.long	0x10c
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x9
	.uleb128 0xa
	.string	"arg"
	.byte	0x1
	.value	0x336
	.byte	0xd
	.long	0x73
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xb
	.long	.LASF400
	.byte	0x1
	.value	0x337
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xc
	.byte	0x4
	.long	0x67
	.uleb128 0xc
	.byte	0x4
	.long	0x6e
	.uleb128 0x7
	.long	.LASF402
	.byte	0x1
	.value	0x322
	.byte	0x5
	.long	0x4a
	.long	.LFB6
	.long	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0x17d
	.uleb128 0x8
	.string	"fmt"
	.byte	0x1
	.value	0x322
	.byte	0x1d
	.long	0x10c
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x9
	.uleb128 0xa
	.string	"arg"
	.byte	0x1
	.value	0x324
	.byte	0xd
	.long	0x73
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xb
	.long	.LASF400
	.byte	0x1
	.value	0x325
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xb
	.long	.LASF403
	.byte	0x1
	.value	0x326
	.byte	0xa
	.long	0x17d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -4120
	.uleb128 0xd
	.long	.LASF419
	.byte	0x1
	.value	0x327
	.byte	0x10
	.long	0x29
	.byte	0
	.uleb128 0xe
	.long	0x67
	.long	0x18e
	.uleb128 0xf
	.long	0x43
	.value	0xfff
	.byte	0
	.uleb128 0x7
	.long	.LASF404
	.byte	0x1
	.value	0x1f6
	.byte	0x5
	.long	0x4a
	.long	.LFB5
	.long	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0x327
	.uleb128 0x8
	.string	"str"
	.byte	0x1
	.value	0x1f6
	.byte	0x19
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x8
	.string	"fmt"
	.byte	0x1
	.value	0x1f6
	.byte	0x2a
	.long	0x10c
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x8
	.string	"arg"
	.byte	0x1
	.value	0x1f6
	.byte	0x37
	.long	0x73
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0xb
	.long	.LASF405
	.byte	0x1
	.value	0x1f8
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xb
	.long	.LASF406
	.byte	0x1
	.value	0x1f9
	.byte	0xa
	.long	0x327
	.uleb128 0x3
	.byte	0x91
	.sleb128 -152
	.uleb128 0xb
	.long	.LASF407
	.byte	0x1
	.value	0x1fa
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xb
	.long	.LASF408
	.byte	0x1
	.value	0x1fa
	.byte	0x10
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xb
	.long	.LASF409
	.byte	0x1
	.value	0x1fa
	.byte	0x1b
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xb
	.long	.LASF410
	.byte	0x1
	.value	0x1fa
	.byte	0x29
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0xa
	.string	"i"
	.byte	0x1
	.value	0x1fb
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xb
	.long	.LASF411
	.byte	0x1
	.value	0x1fc
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x10
	.long	.LBB9
	.long	.LBE9-.LBB9
	.long	0x275
	.uleb128 0xa
	.string	"c"
	.byte	0x1
	.value	0x23d
	.byte	0x16
	.long	0x67
	.uleb128 0x3
	.byte	0x91
	.sleb128 -65
	.byte	0
	.uleb128 0x10
	.long	.LBB10
	.long	.LBE10-.LBB10
	.long	0x2a2
	.uleb128 0xb
	.long	.LASF412
	.byte	0x1
	.value	0x262
	.byte	0x15
	.long	0x4a
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0xa
	.string	"c"
	.byte	0x1
	.value	0x263
	.byte	0x17
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.byte	0
	.uleb128 0x10
	.long	.LBB11
	.long	.LBE11-.LBB11
	.long	0x2cf
	.uleb128 0xb
	.long	.LASF412
	.byte	0x1
	.value	0x292
	.byte	0x1e
	.long	0x43
	.uleb128 0x3
	.byte	0x91
	.sleb128 -76
	.uleb128 0xa
	.string	"c"
	.byte	0x1
	.value	0x293
	.byte	0x17
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.byte	0
	.uleb128 0x10
	.long	.LBB12
	.long	.LBE12-.LBB12
	.long	0x2fc
	.uleb128 0xb
	.long	.LASF413
	.byte	0x1
	.value	0x2c2
	.byte	0x18
	.long	0x337
	.uleb128 0x3
	.byte	0x91
	.sleb128 -88
	.uleb128 0xa
	.string	"c"
	.byte	0x1
	.value	0x2c3
	.byte	0x17
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.byte	0
	.uleb128 0x11
	.long	.LBB13
	.long	.LBE13-.LBB13
	.uleb128 0xb
	.long	.LASF414
	.byte	0x1
	.value	0x2e5
	.byte	0x17
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xb
	.long	.LASF415
	.byte	0x1
	.value	0x2e6
	.byte	0x15
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -60
	.byte	0
	.byte	0
	.uleb128 0xe
	.long	0x67
	.long	0x337
	.uleb128 0x12
	.long	0x43
	.byte	0x3f
	.byte	0
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.long	.LASF416
	.uleb128 0x13
	.long	.LASF417
	.byte	0x1
	.byte	0xc2
	.byte	0x5
	.long	0x4a
	.long	.LFB4
	.long	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x4bc
	.uleb128 0x14
	.string	"fmt"
	.byte	0x1
	.byte	0xc2
	.byte	0x1e
	.long	0x10c
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x14
	.string	"arg"
	.byte	0x1
	.byte	0xc2
	.byte	0x2b
	.long	0x73
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x15
	.long	.LASF405
	.byte	0x1
	.byte	0xc4
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x15
	.long	.LASF406
	.byte	0x1
	.byte	0xc5
	.byte	0xa
	.long	0x327
	.uleb128 0x3
	.byte	0x91
	.sleb128 -152
	.uleb128 0x15
	.long	.LASF407
	.byte	0x1
	.byte	0xc6
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x15
	.long	.LASF408
	.byte	0x1
	.byte	0xc6
	.byte	0x10
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x15
	.long	.LASF409
	.byte	0x1
	.byte	0xc6
	.byte	0x1b
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x15
	.long	.LASF410
	.byte	0x1
	.byte	0xc6
	.byte	0x29
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x16
	.string	"i"
	.byte	0x1
	.byte	0xc7
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x15
	.long	.LASF411
	.byte	0x1
	.byte	0xc8
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x10
	.long	.LBB4
	.long	.LBE4-.LBB4
	.long	0x40a
	.uleb128 0xa
	.string	"c"
	.byte	0x1
	.value	0x10a
	.byte	0x16
	.long	0x67
	.uleb128 0x3
	.byte	0x91
	.sleb128 -65
	.byte	0
	.uleb128 0x10
	.long	.LBB5
	.long	.LBE5-.LBB5
	.long	0x437
	.uleb128 0xb
	.long	.LASF412
	.byte	0x1
	.value	0x130
	.byte	0x15
	.long	0x4a
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0xa
	.string	"c"
	.byte	0x1
	.value	0x131
	.byte	0x17
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.byte	0
	.uleb128 0x10
	.long	.LBB6
	.long	.LBE6-.LBB6
	.long	0x464
	.uleb128 0xb
	.long	.LASF412
	.byte	0x1
	.value	0x160
	.byte	0x1e
	.long	0x43
	.uleb128 0x3
	.byte	0x91
	.sleb128 -76
	.uleb128 0xa
	.string	"c"
	.byte	0x1
	.value	0x161
	.byte	0x17
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.byte	0
	.uleb128 0x10
	.long	.LBB7
	.long	.LBE7-.LBB7
	.long	0x491
	.uleb128 0xb
	.long	.LASF413
	.byte	0x1
	.value	0x192
	.byte	0x18
	.long	0x337
	.uleb128 0x3
	.byte	0x91
	.sleb128 -88
	.uleb128 0xa
	.string	"c"
	.byte	0x1
	.value	0x193
	.byte	0x17
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.byte	0
	.uleb128 0x11
	.long	.LBB8
	.long	.LBE8-.LBB8
	.uleb128 0xb
	.long	.LASF414
	.byte	0x1
	.value	0x1b5
	.byte	0x17
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xb
	.long	.LASF415
	.byte	0x1
	.value	0x1b6
	.byte	0x15
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -60
	.byte	0
	.byte	0
	.uleb128 0x17
	.long	.LASF423
	.byte	0x1
	.byte	0x70
	.byte	0x6
	.long	.LFB3
	.long	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x585
	.uleb128 0x14
	.string	"val"
	.byte	0x1
	.byte	0x70
	.byte	0x1f
	.long	0x337
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x14
	.string	"buf"
	.byte	0x1
	.byte	0x70
	.byte	0x2a
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x18
	.long	.LASF408
	.byte	0x1
	.byte	0x70
	.byte	0x33
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x11
	.long	.LBB2
	.long	.LBE2-.LBB2
	.uleb128 0x15
	.long	.LASF418
	.byte	0x1
	.byte	0x83
	.byte	0xd
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0x16
	.string	"m"
	.byte	0x1
	.byte	0x84
	.byte	0xd
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x19
	.string	"m1"
	.byte	0x1
	.byte	0x85
	.byte	0xd
	.long	0x4a
	.uleb128 0x15
	.long	.LASF420
	.byte	0x1
	.byte	0x86
	.byte	0xd
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x15
	.long	.LASF421
	.byte	0x1
	.byte	0x87
	.byte	0xd
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x16
	.string	"neg"
	.byte	0x1
	.byte	0x88
	.byte	0xd
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x16
	.string	"c"
	.byte	0x1
	.byte	0x89
	.byte	0xf
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x11
	.long	.LBB3
	.long	.LBE3-.LBB3
	.uleb128 0x15
	.long	.LASF422
	.byte	0x1
	.byte	0xa2
	.byte	0x14
	.long	0x337
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x1a
	.long	.LASF424
	.byte	0x1
	.byte	0x51
	.byte	0x6
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x5e5
	.uleb128 0x14
	.string	"val"
	.byte	0x1
	.byte	0x51
	.byte	0x23
	.long	0x43
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x14
	.string	"buf"
	.byte	0x1
	.byte	0x51
	.byte	0x2e
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x15
	.long	.LASF406
	.byte	0x1
	.byte	0x53
	.byte	0xa
	.long	0x5e5
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x16
	.string	"c"
	.byte	0x1
	.byte	0x54
	.byte	0xb
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x15
	.long	.LASF425
	.byte	0x1
	.byte	0x55
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.uleb128 0xe
	.long	0x67
	.long	0x5f5
	.uleb128 0x12
	.long	0x43
	.byte	0x1f
	.byte	0
	.uleb128 0x1a
	.long	.LASF426
	.byte	0x1
	.byte	0x2d
	.byte	0x6
	.long	.LFB1
	.long	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x655
	.uleb128 0x14
	.string	"val"
	.byte	0x1
	.byte	0x2d
	.byte	0x1a
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x14
	.string	"buf"
	.byte	0x1
	.byte	0x2d
	.byte	0x25
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x15
	.long	.LASF406
	.byte	0x1
	.byte	0x2f
	.byte	0xa
	.long	0x5e5
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x16
	.string	"c"
	.byte	0x1
	.byte	0x30
	.byte	0xb
	.long	0x106
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x15
	.long	.LASF425
	.byte	0x1
	.byte	0x31
	.byte	0x9
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.uleb128 0x1b
	.long	.LASF427
	.byte	0x1
	.byte	0x23
	.byte	0x5
	.long	0x4a
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x14
	.string	"c"
	.byte	0x1
	.byte	0x23
	.byte	0x13
	.long	0x4a
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x15
	.long	.LASF419
	.byte	0x1
	.byte	0x25
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.uleb128 0x2119
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.value	0
	.value	0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	0
	.long	0
	.section	.debug_macro,"",@progbits
.Ldebug_macro0:
	.value	0x4
	.byte	0x2
	.long	.Ldebug_line0
	.byte	0x3
	.uleb128 0
	.uleb128 0x1
	.byte	0x5
	.uleb128 0x1
	.long	.LASF0
	.byte	0x5
	.uleb128 0x2
	.long	.LASF1
	.byte	0x5
	.uleb128 0x3
	.long	.LASF2
	.byte	0x5
	.uleb128 0x4
	.long	.LASF3
	.byte	0x5
	.uleb128 0x5
	.long	.LASF4
	.byte	0x5
	.uleb128 0x6
	.long	.LASF5
	.byte	0x5
	.uleb128 0x7
	.long	.LASF6
	.byte	0x5
	.uleb128 0x8
	.long	.LASF7
	.byte	0x5
	.uleb128 0x9
	.long	.LASF8
	.byte	0x5
	.uleb128 0xa
	.long	.LASF9
	.byte	0x5
	.uleb128 0xb
	.long	.LASF10
	.byte	0x5
	.uleb128 0xc
	.long	.LASF11
	.byte	0x5
	.uleb128 0xd
	.long	.LASF12
	.byte	0x5
	.uleb128 0xe
	.long	.LASF13
	.byte	0x5
	.uleb128 0xf
	.long	.LASF14
	.byte	0x5
	.uleb128 0x10
	.long	.LASF15
	.byte	0x5
	.uleb128 0x11
	.long	.LASF16
	.byte	0x5
	.uleb128 0x12
	.long	.LASF17
	.byte	0x5
	.uleb128 0x13
	.long	.LASF18
	.byte	0x5
	.uleb128 0x14
	.long	.LASF19
	.byte	0x5
	.uleb128 0x15
	.long	.LASF20
	.byte	0x5
	.uleb128 0x16
	.long	.LASF21
	.byte	0x5
	.uleb128 0x17
	.long	.LASF22
	.byte	0x5
	.uleb128 0x18
	.long	.LASF23
	.byte	0x5
	.uleb128 0x19
	.long	.LASF24
	.byte	0x5
	.uleb128 0x1a
	.long	.LASF25
	.byte	0x5
	.uleb128 0x1b
	.long	.LASF26
	.byte	0x5
	.uleb128 0x1c
	.long	.LASF27
	.byte	0x5
	.uleb128 0x1d
	.long	.LASF28
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF29
	.byte	0x5
	.uleb128 0x1f
	.long	.LASF30
	.byte	0x5
	.uleb128 0x20
	.long	.LASF31
	.byte	0x5
	.uleb128 0x21
	.long	.LASF32
	.byte	0x5
	.uleb128 0x22
	.long	.LASF33
	.byte	0x5
	.uleb128 0x23
	.long	.LASF34
	.byte	0x5
	.uleb128 0x24
	.long	.LASF35
	.byte	0x5
	.uleb128 0x25
	.long	.LASF36
	.byte	0x5
	.uleb128 0x26
	.long	.LASF37
	.byte	0x5
	.uleb128 0x27
	.long	.LASF38
	.byte	0x5
	.uleb128 0x28
	.long	.LASF39
	.byte	0x5
	.uleb128 0x29
	.long	.LASF40
	.byte	0x5
	.uleb128 0x2a
	.long	.LASF41
	.byte	0x5
	.uleb128 0x2b
	.long	.LASF42
	.byte	0x5
	.uleb128 0x2c
	.long	.LASF43
	.byte	0x5
	.uleb128 0x2d
	.long	.LASF44
	.byte	0x5
	.uleb128 0x2e
	.long	.LASF45
	.byte	0x5
	.uleb128 0x2f
	.long	.LASF46
	.byte	0x5
	.uleb128 0x30
	.long	.LASF47
	.byte	0x5
	.uleb128 0x31
	.long	.LASF48
	.byte	0x5
	.uleb128 0x32
	.long	.LASF49
	.byte	0x5
	.uleb128 0x33
	.long	.LASF50
	.byte	0x5
	.uleb128 0x34
	.long	.LASF51
	.byte	0x5
	.uleb128 0x35
	.long	.LASF52
	.byte	0x5
	.uleb128 0x36
	.long	.LASF53
	.byte	0x5
	.uleb128 0x37
	.long	.LASF54
	.byte	0x5
	.uleb128 0x38
	.long	.LASF55
	.byte	0x5
	.uleb128 0x39
	.long	.LASF56
	.byte	0x5
	.uleb128 0x3a
	.long	.LASF57
	.byte	0x5
	.uleb128 0x3b
	.long	.LASF58
	.byte	0x5
	.uleb128 0x3c
	.long	.LASF59
	.byte	0x5
	.uleb128 0x3d
	.long	.LASF60
	.byte	0x5
	.uleb128 0x3e
	.long	.LASF61
	.byte	0x5
	.uleb128 0x3f
	.long	.LASF62
	.byte	0x5
	.uleb128 0x40
	.long	.LASF63
	.byte	0x5
	.uleb128 0x41
	.long	.LASF64
	.byte	0x5
	.uleb128 0x42
	.long	.LASF65
	.byte	0x5
	.uleb128 0x43
	.long	.LASF66
	.byte	0x5
	.uleb128 0x44
	.long	.LASF67
	.byte	0x5
	.uleb128 0x45
	.long	.LASF68
	.byte	0x5
	.uleb128 0x46
	.long	.LASF69
	.byte	0x5
	.uleb128 0x47
	.long	.LASF70
	.byte	0x5
	.uleb128 0x48
	.long	.LASF71
	.byte	0x5
	.uleb128 0x49
	.long	.LASF72
	.byte	0x5
	.uleb128 0x4a
	.long	.LASF73
	.byte	0x5
	.uleb128 0x4b
	.long	.LASF74
	.byte	0x5
	.uleb128 0x4c
	.long	.LASF75
	.byte	0x5
	.uleb128 0x4d
	.long	.LASF76
	.byte	0x5
	.uleb128 0x4e
	.long	.LASF77
	.byte	0x5
	.uleb128 0x4f
	.long	.LASF78
	.byte	0x5
	.uleb128 0x50
	.long	.LASF79
	.byte	0x5
	.uleb128 0x51
	.long	.LASF80
	.byte	0x5
	.uleb128 0x52
	.long	.LASF81
	.byte	0x5
	.uleb128 0x53
	.long	.LASF82
	.byte	0x5
	.uleb128 0x54
	.long	.LASF83
	.byte	0x5
	.uleb128 0x55
	.long	.LASF84
	.byte	0x5
	.uleb128 0x56
	.long	.LASF85
	.byte	0x5
	.uleb128 0x57
	.long	.LASF86
	.byte	0x5
	.uleb128 0x58
	.long	.LASF87
	.byte	0x5
	.uleb128 0x59
	.long	.LASF88
	.byte	0x5
	.uleb128 0x5a
	.long	.LASF89
	.byte	0x5
	.uleb128 0x5b
	.long	.LASF90
	.byte	0x5
	.uleb128 0x5c
	.long	.LASF91
	.byte	0x5
	.uleb128 0x5d
	.long	.LASF92
	.byte	0x5
	.uleb128 0x5e
	.long	.LASF93
	.byte	0x5
	.uleb128 0x5f
	.long	.LASF94
	.byte	0x5
	.uleb128 0x60
	.long	.LASF95
	.byte	0x5
	.uleb128 0x61
	.long	.LASF96
	.byte	0x5
	.uleb128 0x62
	.long	.LASF97
	.byte	0x5
	.uleb128 0x63
	.long	.LASF98
	.byte	0x5
	.uleb128 0x64
	.long	.LASF99
	.byte	0x5
	.uleb128 0x65
	.long	.LASF100
	.byte	0x5
	.uleb128 0x66
	.long	.LASF101
	.byte	0x5
	.uleb128 0x67
	.long	.LASF102
	.byte	0x5
	.uleb128 0x68
	.long	.LASF103
	.byte	0x5
	.uleb128 0x69
	.long	.LASF104
	.byte	0x5
	.uleb128 0x6a
	.long	.LASF105
	.byte	0x5
	.uleb128 0x6b
	.long	.LASF106
	.byte	0x5
	.uleb128 0x6c
	.long	.LASF107
	.byte	0x5
	.uleb128 0x6d
	.long	.LASF108
	.byte	0x5
	.uleb128 0x6e
	.long	.LASF109
	.byte	0x5
	.uleb128 0x6f
	.long	.LASF110
	.byte	0x5
	.uleb128 0x70
	.long	.LASF111
	.byte	0x5
	.uleb128 0x71
	.long	.LASF112
	.byte	0x5
	.uleb128 0x72
	.long	.LASF113
	.byte	0x5
	.uleb128 0x73
	.long	.LASF114
	.byte	0x5
	.uleb128 0x74
	.long	.LASF115
	.byte	0x5
	.uleb128 0x75
	.long	.LASF116
	.byte	0x5
	.uleb128 0x76
	.long	.LASF117
	.byte	0x5
	.uleb128 0x77
	.long	.LASF118
	.byte	0x5
	.uleb128 0x78
	.long	.LASF119
	.byte	0x5
	.uleb128 0x79
	.long	.LASF120
	.byte	0x5
	.uleb128 0x7a
	.long	.LASF121
	.byte	0x5
	.uleb128 0x7b
	.long	.LASF122
	.byte	0x5
	.uleb128 0x7c
	.long	.LASF123
	.byte	0x5
	.uleb128 0x7d
	.long	.LASF124
	.byte	0x5
	.uleb128 0x7e
	.long	.LASF125
	.byte	0x5
	.uleb128 0x7f
	.long	.LASF126
	.byte	0x5
	.uleb128 0x80
	.long	.LASF127
	.byte	0x5
	.uleb128 0x81
	.long	.LASF128
	.byte	0x5
	.uleb128 0x82
	.long	.LASF129
	.byte	0x5
	.uleb128 0x83
	.long	.LASF130
	.byte	0x5
	.uleb128 0x84
	.long	.LASF131
	.byte	0x5
	.uleb128 0x85
	.long	.LASF132
	.byte	0x5
	.uleb128 0x86
	.long	.LASF133
	.byte	0x5
	.uleb128 0x87
	.long	.LASF134
	.byte	0x5
	.uleb128 0x88
	.long	.LASF135
	.byte	0x5
	.uleb128 0x89
	.long	.LASF136
	.byte	0x5
	.uleb128 0x8a
	.long	.LASF137
	.byte	0x5
	.uleb128 0x8b
	.long	.LASF138
	.byte	0x5
	.uleb128 0x8c
	.long	.LASF139
	.byte	0x5
	.uleb128 0x8d
	.long	.LASF140
	.byte	0x5
	.uleb128 0x8e
	.long	.LASF141
	.byte	0x5
	.uleb128 0x8f
	.long	.LASF142
	.byte	0x5
	.uleb128 0x90
	.long	.LASF143
	.byte	0x5
	.uleb128 0x91
	.long	.LASF144
	.byte	0x5
	.uleb128 0x92
	.long	.LASF145
	.byte	0x5
	.uleb128 0x93
	.long	.LASF146
	.byte	0x5
	.uleb128 0x94
	.long	.LASF147
	.byte	0x5
	.uleb128 0x95
	.long	.LASF148
	.byte	0x5
	.uleb128 0x96
	.long	.LASF149
	.byte	0x5
	.uleb128 0x97
	.long	.LASF150
	.byte	0x5
	.uleb128 0x98
	.long	.LASF151
	.byte	0x5
	.uleb128 0x99
	.long	.LASF152
	.byte	0x5
	.uleb128 0x9a
	.long	.LASF153
	.byte	0x5
	.uleb128 0x9b
	.long	.LASF154
	.byte	0x5
	.uleb128 0x9c
	.long	.LASF155
	.byte	0x5
	.uleb128 0x9d
	.long	.LASF156
	.byte	0x5
	.uleb128 0x9e
	.long	.LASF157
	.byte	0x5
	.uleb128 0x9f
	.long	.LASF158
	.byte	0x5
	.uleb128 0xa0
	.long	.LASF159
	.byte	0x5
	.uleb128 0xa1
	.long	.LASF160
	.byte	0x5
	.uleb128 0xa2
	.long	.LASF161
	.byte	0x5
	.uleb128 0xa3
	.long	.LASF162
	.byte	0x5
	.uleb128 0xa4
	.long	.LASF163
	.byte	0x5
	.uleb128 0xa5
	.long	.LASF164
	.byte	0x5
	.uleb128 0xa6
	.long	.LASF165
	.byte	0x5
	.uleb128 0xa7
	.long	.LASF166
	.byte	0x5
	.uleb128 0xa8
	.long	.LASF167
	.byte	0x5
	.uleb128 0xa9
	.long	.LASF168
	.byte	0x5
	.uleb128 0xaa
	.long	.LASF169
	.byte	0x5
	.uleb128 0xab
	.long	.LASF170
	.byte	0x5
	.uleb128 0xac
	.long	.LASF171
	.byte	0x5
	.uleb128 0xad
	.long	.LASF172
	.byte	0x5
	.uleb128 0xae
	.long	.LASF173
	.byte	0x5
	.uleb128 0xaf
	.long	.LASF174
	.byte	0x5
	.uleb128 0xb0
	.long	.LASF175
	.byte	0x5
	.uleb128 0xb1
	.long	.LASF176
	.byte	0x5
	.uleb128 0xb2
	.long	.LASF177
	.byte	0x5
	.uleb128 0xb3
	.long	.LASF178
	.byte	0x5
	.uleb128 0xb4
	.long	.LASF179
	.byte	0x5
	.uleb128 0xb5
	.long	.LASF180
	.byte	0x5
	.uleb128 0xb6
	.long	.LASF181
	.byte	0x5
	.uleb128 0xb7
	.long	.LASF182
	.byte	0x5
	.uleb128 0xb8
	.long	.LASF183
	.byte	0x5
	.uleb128 0xb9
	.long	.LASF184
	.byte	0x5
	.uleb128 0xba
	.long	.LASF185
	.byte	0x5
	.uleb128 0xbb
	.long	.LASF186
	.byte	0x5
	.uleb128 0xbc
	.long	.LASF187
	.byte	0x5
	.uleb128 0xbd
	.long	.LASF188
	.byte	0x5
	.uleb128 0xbe
	.long	.LASF189
	.byte	0x5
	.uleb128 0xbf
	.long	.LASF190
	.byte	0x5
	.uleb128 0xc0
	.long	.LASF191
	.byte	0x5
	.uleb128 0xc1
	.long	.LASF192
	.byte	0x5
	.uleb128 0xc2
	.long	.LASF193
	.byte	0x5
	.uleb128 0xc3
	.long	.LASF194
	.byte	0x5
	.uleb128 0xc4
	.long	.LASF195
	.byte	0x5
	.uleb128 0xc5
	.long	.LASF196
	.byte	0x5
	.uleb128 0xc6
	.long	.LASF197
	.byte	0x5
	.uleb128 0xc7
	.long	.LASF198
	.byte	0x5
	.uleb128 0xc8
	.long	.LASF199
	.byte	0x5
	.uleb128 0xc9
	.long	.LASF200
	.byte	0x5
	.uleb128 0xca
	.long	.LASF201
	.byte	0x5
	.uleb128 0xcb
	.long	.LASF202
	.byte	0x5
	.uleb128 0xcc
	.long	.LASF203
	.byte	0x5
	.uleb128 0xcd
	.long	.LASF204
	.byte	0x5
	.uleb128 0xce
	.long	.LASF205
	.byte	0x5
	.uleb128 0xcf
	.long	.LASF206
	.byte	0x5
	.uleb128 0xd0
	.long	.LASF207
	.byte	0x5
	.uleb128 0xd1
	.long	.LASF208
	.byte	0x5
	.uleb128 0xd2
	.long	.LASF209
	.byte	0x5
	.uleb128 0xd3
	.long	.LASF210
	.byte	0x5
	.uleb128 0xd4
	.long	.LASF211
	.byte	0x5
	.uleb128 0xd5
	.long	.LASF212
	.byte	0x5
	.uleb128 0xd6
	.long	.LASF213
	.byte	0x5
	.uleb128 0xd7
	.long	.LASF214
	.byte	0x5
	.uleb128 0xd8
	.long	.LASF215
	.byte	0x5
	.uleb128 0xd9
	.long	.LASF216
	.byte	0x5
	.uleb128 0xda
	.long	.LASF217
	.byte	0x5
	.uleb128 0xdb
	.long	.LASF218
	.byte	0x5
	.uleb128 0xdc
	.long	.LASF219
	.byte	0x5
	.uleb128 0xdd
	.long	.LASF220
	.byte	0x5
	.uleb128 0xde
	.long	.LASF221
	.byte	0x5
	.uleb128 0xdf
	.long	.LASF222
	.byte	0x5
	.uleb128 0xe0
	.long	.LASF223
	.byte	0x5
	.uleb128 0xe1
	.long	.LASF224
	.byte	0x5
	.uleb128 0xe2
	.long	.LASF225
	.byte	0x5
	.uleb128 0xe3
	.long	.LASF226
	.byte	0x5
	.uleb128 0xe4
	.long	.LASF227
	.byte	0x5
	.uleb128 0xe5
	.long	.LASF228
	.byte	0x5
	.uleb128 0xe6
	.long	.LASF229
	.byte	0x5
	.uleb128 0xe7
	.long	.LASF230
	.byte	0x5
	.uleb128 0xe8
	.long	.LASF231
	.byte	0x5
	.uleb128 0xe9
	.long	.LASF232
	.byte	0x5
	.uleb128 0xea
	.long	.LASF233
	.byte	0x5
	.uleb128 0xeb
	.long	.LASF234
	.byte	0x5
	.uleb128 0xec
	.long	.LASF235
	.byte	0x5
	.uleb128 0xed
	.long	.LASF236
	.byte	0x5
	.uleb128 0xee
	.long	.LASF237
	.byte	0x5
	.uleb128 0xef
	.long	.LASF238
	.byte	0x5
	.uleb128 0xf0
	.long	.LASF239
	.byte	0x5
	.uleb128 0xf1
	.long	.LASF240
	.byte	0x5
	.uleb128 0xf2
	.long	.LASF241
	.byte	0x5
	.uleb128 0xf3
	.long	.LASF242
	.byte	0x5
	.uleb128 0xf4
	.long	.LASF243
	.byte	0x5
	.uleb128 0xf5
	.long	.LASF244
	.byte	0x5
	.uleb128 0xf6
	.long	.LASF245
	.byte	0x5
	.uleb128 0xf7
	.long	.LASF246
	.byte	0x5
	.uleb128 0xf8
	.long	.LASF247
	.byte	0x5
	.uleb128 0xf9
	.long	.LASF248
	.byte	0x5
	.uleb128 0xfa
	.long	.LASF249
	.byte	0x5
	.uleb128 0xfb
	.long	.LASF250
	.byte	0x5
	.uleb128 0xfc
	.long	.LASF251
	.byte	0x5
	.uleb128 0xfd
	.long	.LASF252
	.byte	0x5
	.uleb128 0xfe
	.long	.LASF253
	.byte	0x5
	.uleb128 0xff
	.long	.LASF254
	.byte	0x5
	.uleb128 0x100
	.long	.LASF255
	.byte	0x5
	.uleb128 0x101
	.long	.LASF256
	.byte	0x5
	.uleb128 0x102
	.long	.LASF257
	.byte	0x5
	.uleb128 0x103
	.long	.LASF258
	.byte	0x5
	.uleb128 0x104
	.long	.LASF259
	.byte	0x5
	.uleb128 0x105
	.long	.LASF260
	.byte	0x5
	.uleb128 0x106
	.long	.LASF261
	.byte	0x5
	.uleb128 0x107
	.long	.LASF262
	.byte	0x5
	.uleb128 0x108
	.long	.LASF263
	.byte	0x5
	.uleb128 0x109
	.long	.LASF264
	.byte	0x5
	.uleb128 0x10a
	.long	.LASF265
	.byte	0x5
	.uleb128 0x10b
	.long	.LASF266
	.byte	0x5
	.uleb128 0x10c
	.long	.LASF267
	.byte	0x5
	.uleb128 0x10d
	.long	.LASF268
	.byte	0x5
	.uleb128 0x10e
	.long	.LASF269
	.byte	0x5
	.uleb128 0x10f
	.long	.LASF270
	.byte	0x5
	.uleb128 0x110
	.long	.LASF271
	.byte	0x5
	.uleb128 0x111
	.long	.LASF272
	.byte	0x5
	.uleb128 0x112
	.long	.LASF273
	.byte	0x5
	.uleb128 0x113
	.long	.LASF274
	.byte	0x5
	.uleb128 0x114
	.long	.LASF275
	.byte	0x5
	.uleb128 0x115
	.long	.LASF276
	.byte	0x5
	.uleb128 0x116
	.long	.LASF277
	.byte	0x5
	.uleb128 0x117
	.long	.LASF278
	.byte	0x5
	.uleb128 0x118
	.long	.LASF279
	.byte	0x5
	.uleb128 0x119
	.long	.LASF280
	.byte	0x5
	.uleb128 0x11a
	.long	.LASF281
	.byte	0x5
	.uleb128 0x11b
	.long	.LASF282
	.byte	0x5
	.uleb128 0x11c
	.long	.LASF283
	.byte	0x5
	.uleb128 0x11d
	.long	.LASF284
	.byte	0x5
	.uleb128 0x11e
	.long	.LASF285
	.byte	0x5
	.uleb128 0x11f
	.long	.LASF286
	.byte	0x5
	.uleb128 0x120
	.long	.LASF287
	.byte	0x5
	.uleb128 0x121
	.long	.LASF288
	.byte	0x5
	.uleb128 0x122
	.long	.LASF289
	.byte	0x5
	.uleb128 0x123
	.long	.LASF290
	.byte	0x5
	.uleb128 0x124
	.long	.LASF291
	.byte	0x5
	.uleb128 0x125
	.long	.LASF292
	.byte	0x5
	.uleb128 0x126
	.long	.LASF293
	.byte	0x5
	.uleb128 0x127
	.long	.LASF294
	.byte	0x5
	.uleb128 0x128
	.long	.LASF295
	.byte	0x5
	.uleb128 0x129
	.long	.LASF296
	.byte	0x5
	.uleb128 0x12a
	.long	.LASF297
	.byte	0x5
	.uleb128 0x12b
	.long	.LASF298
	.byte	0x5
	.uleb128 0x12c
	.long	.LASF299
	.byte	0x5
	.uleb128 0x12d
	.long	.LASF300
	.byte	0x5
	.uleb128 0x12e
	.long	.LASF301
	.byte	0x5
	.uleb128 0x12f
	.long	.LASF302
	.byte	0x5
	.uleb128 0x130
	.long	.LASF303
	.byte	0x5
	.uleb128 0x131
	.long	.LASF304
	.byte	0x5
	.uleb128 0x132
	.long	.LASF305
	.byte	0x5
	.uleb128 0x133
	.long	.LASF306
	.byte	0x5
	.uleb128 0x134
	.long	.LASF307
	.byte	0x5
	.uleb128 0x135
	.long	.LASF308
	.byte	0x5
	.uleb128 0x136
	.long	.LASF309
	.byte	0x5
	.uleb128 0x137
	.long	.LASF310
	.byte	0x5
	.uleb128 0x138
	.long	.LASF311
	.byte	0x5
	.uleb128 0x139
	.long	.LASF312
	.byte	0x5
	.uleb128 0x13a
	.long	.LASF313
	.byte	0x5
	.uleb128 0x13b
	.long	.LASF314
	.byte	0x5
	.uleb128 0x13c
	.long	.LASF315
	.byte	0x5
	.uleb128 0x13d
	.long	.LASF316
	.byte	0x5
	.uleb128 0x13e
	.long	.LASF317
	.byte	0x5
	.uleb128 0x13f
	.long	.LASF318
	.byte	0x5
	.uleb128 0x140
	.long	.LASF319
	.byte	0x5
	.uleb128 0x141
	.long	.LASF320
	.byte	0x5
	.uleb128 0x142
	.long	.LASF321
	.byte	0x5
	.uleb128 0x143
	.long	.LASF322
	.byte	0x5
	.uleb128 0x144
	.long	.LASF323
	.byte	0x5
	.uleb128 0x145
	.long	.LASF324
	.byte	0x5
	.uleb128 0x146
	.long	.LASF325
	.byte	0x5
	.uleb128 0x147
	.long	.LASF326
	.byte	0x5
	.uleb128 0x148
	.long	.LASF327
	.byte	0x5
	.uleb128 0x149
	.long	.LASF328
	.byte	0x5
	.uleb128 0x14a
	.long	.LASF329
	.byte	0x5
	.uleb128 0x14b
	.long	.LASF330
	.byte	0x5
	.uleb128 0x14c
	.long	.LASF331
	.byte	0x5
	.uleb128 0x14d
	.long	.LASF332
	.byte	0x5
	.uleb128 0x1
	.long	.LASF333
	.byte	0x5
	.uleb128 0x2
	.long	.LASF334
	.byte	0x5
	.uleb128 0x3
	.long	.LASF335
	.byte	0x5
	.uleb128 0x4
	.long	.LASF336
	.file 4 "/usr/include/stdc-predef.h"
	.byte	0x3
	.uleb128 0x5
	.uleb128 0x4
	.byte	0x7
	.long	.Ldebug_macro2
	.byte	0x4
	.byte	0x3
	.uleb128 0x1a
	.uleb128 0x2
	.byte	0x7
	.long	.Ldebug_macro3
	.byte	0x4
	.byte	0x3
	.uleb128 0x1b
	.uleb128 0x3
	.byte	0x7
	.long	.Ldebug_macro4
	.byte	0x4
	.file 5 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/cgc_stdlib.h"
	.byte	0x3
	.uleb128 0x1c
	.uleb128 0x5
	.byte	0x7
	.long	.Ldebug_macro5
	.byte	0x4
	.file 6 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/cgc_stdint.h"
	.byte	0x3
	.uleb128 0x1d
	.uleb128 0x6
	.byte	0x5
	.uleb128 0x1b
	.long	.LASF384
	.byte	0x4
	.file 7 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/cgc_mymath.h"
	.byte	0x3
	.uleb128 0x1e
	.uleb128 0x7
	.byte	0x5
	.uleb128 0x1b
	.long	.LASF385
	.byte	0x4
	.byte	0x5
	.uleb128 0x21
	.long	.LASF386
	.byte	0x4
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stdcpredef.h.19.006d14bbbe0dc07ba9b1ce3fdc8e40d3,comdat
.Ldebug_macro2:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x13
	.long	.LASF337
	.byte	0x5
	.uleb128 0x26
	.long	.LASF338
	.byte	0x5
	.uleb128 0x2e
	.long	.LASF339
	.byte	0x5
	.uleb128 0x3a
	.long	.LASF340
	.byte	0x5
	.uleb128 0x3d
	.long	.LASF341
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.libcgc.h.2.1ca842f70535d048924a5ff19c40f3ba,comdat
.Ldebug_macro3:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x2
	.long	.LASF342
	.byte	0x5
	.uleb128 0x4
	.long	.LASF343
	.byte	0x5
	.uleb128 0x5
	.long	.LASF344
	.byte	0x5
	.uleb128 0x6
	.long	.LASF345
	.byte	0x5
	.uleb128 0xb
	.long	.LASF346
	.byte	0x5
	.uleb128 0x1a
	.long	.LASF347
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF348
	.byte	0x5
	.uleb128 0x22
	.long	.LASF349
	.byte	0x5
	.uleb128 0x26
	.long	.LASF350
	.byte	0x5
	.uleb128 0x2a
	.long	.LASF351
	.byte	0x5
	.uleb128 0x2e
	.long	.LASF352
	.byte	0x5
	.uleb128 0x31
	.long	.LASF353
	.byte	0x5
	.uleb128 0x35
	.long	.LASF354
	.byte	0x5
	.uleb128 0x3b
	.long	.LASF355
	.byte	0x5
	.uleb128 0x42
	.long	.LASF356
	.byte	0x5
	.uleb128 0x45
	.long	.LASF357
	.byte	0x5
	.uleb128 0x48
	.long	.LASF358
	.byte	0x5
	.uleb128 0x50
	.long	.LASF359
	.byte	0x5
	.uleb128 0x51
	.long	.LASF360
	.byte	0x5
	.uleb128 0x52
	.long	.LASF361
	.byte	0x5
	.uleb128 0x53
	.long	.LASF362
	.byte	0x5
	.uleb128 0x54
	.long	.LASF363
	.byte	0x5
	.uleb128 0x55
	.long	.LASF364
	.byte	0x5
	.uleb128 0x58
	.long	.LASF365
	.byte	0x5
	.uleb128 0x59
	.long	.LASF366
	.byte	0x5
	.uleb128 0x5a
	.long	.LASF367
	.byte	0x5
	.uleb128 0x5b
	.long	.LASF368
	.byte	0x5
	.uleb128 0x5c
	.long	.LASF369
	.byte	0x5
	.uleb128 0x5d
	.long	.LASF370
	.byte	0x5
	.uleb128 0x5f
	.long	.LASF371
	.byte	0x5
	.uleb128 0x60
	.long	.LASF372
	.byte	0x5
	.uleb128 0x61
	.long	.LASF373
	.byte	0x5
	.uleb128 0x62
	.long	.LASF374
	.byte	0x5
	.uleb128 0x63
	.long	.LASF375
	.byte	0x5
	.uleb128 0x64
	.long	.LASF376
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.cgc_stdarg.h.27.628e2a77b8197ebc205e6b227a4902bd,comdat
.Ldebug_macro4:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1b
	.long	.LASF377
	.byte	0x5
	.uleb128 0x22
	.long	.LASF378
	.byte	0x5
	.uleb128 0x23
	.long	.LASF379
	.byte	0x5
	.uleb128 0x24
	.long	.LASF380
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.cgc_stdlib.h.27.88ff704b8b47df49cfc97b2f92fbc251,comdat
.Ldebug_macro5:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1b
	.long	.LASF381
	.byte	0x5
	.uleb128 0x1d
	.long	.LASF382
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF383
	.byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF231:
	.string	"__FLT128_EPSILON__ 1.92592994438723585305597794258492732e-34F128"
.LASF99:
	.string	"__SIG_ATOMIC_MAX__ 0x7fffffff"
.LASF221:
	.string	"__FLT64_HAS_QUIET_NAN__ 1"
.LASF277:
	.string	"__DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD"
.LASF206:
	.string	"__FLT32_HAS_INFINITY__ 1"
.LASF147:
	.string	"__FLT_EVAL_METHOD__ 2"
.LASF212:
	.string	"__FLT64_MAX_EXP__ 1024"
.LASF154:
	.string	"__FLT_MIN_10_EXP__ (-37)"
.LASF259:
	.string	"__FLT64X_EPSILON__ 1.08420217248550443400745280086994171e-19F64x"
.LASF240:
	.string	"__FLT32X_MAX_EXP__ 1024"
.LASF133:
	.string	"__INT_FAST16_WIDTH__ 32"
.LASF302:
	.string	"__GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1"
.LASF276:
	.string	"__DEC64_EPSILON__ 1E-15DD"
.LASF175:
	.string	"__DBL_DENORM_MIN__ ((double)4.94065645841246544176568792868221372e-324L)"
.LASF194:
	.string	"__FLT32_MANT_DIG__ 24"
.LASF334:
	.string	"LINUX 1"
.LASF123:
	.string	"__UINT8_C(c) c"
.LASF364:
	.string	"CGC_EPIPE 6"
.LASF333:
	.string	"FORTIFY_SOURCE 0"
.LASF242:
	.string	"__FLT32X_DECIMAL_DIG__ 17"
.LASF167:
	.string	"__DBL_MIN_EXP__ (-1021)"
.LASF72:
	.string	"__has_include_next(STR) __has_include_next__(STR)"
.LASF368:
	.string	"FD_SET CGC_FD_SET"
.LASF420:
	.string	"fraction_digit"
.LASF318:
	.string	"__i686__ 1"
.LASF243:
	.string	"__FLT32X_MAX__ 1.79769313486231570814527423731704357e+308F32x"
.LASF229:
	.string	"__FLT128_MAX__ 1.18973149535723176508575932662800702e+4932F128"
.LASF307:
	.string	"__SIZEOF_WINT_T__ 4"
.LASF412:
	.string	"int_arg"
.LASF6:
	.string	"__GNUC_MINOR__ 4"
.LASF389:
	.string	"unsigned int"
.LASF216:
	.string	"__FLT64_MIN__ 2.22507385850720138309023271733240406e-308F64"
.LASF89:
	.string	"__LONG_LONG_WIDTH__ 64"
.LASF292:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1"
.LASF27:
	.string	"__SIZEOF_SIZE_T__ 4"
.LASF42:
	.string	"__CHAR16_TYPE__ short unsigned int"
.LASF401:
	.string	"cgc_sprintf"
.LASF31:
	.string	"__ORDER_BIG_ENDIAN__ 4321"
.LASF5:
	.string	"__GNUC__ 8"
.LASF165:
	.string	"__DBL_MANT_DIG__ 53"
.LASF60:
	.string	"__UINT_LEAST64_TYPE__ long long unsigned int"
.LASF76:
	.string	"__INT_MAX__ 0x7fffffff"
.LASF12:
	.string	"__ATOMIC_RELEASE 3"
.LASF37:
	.string	"__PTRDIFF_TYPE__ int"
.LASF46:
	.string	"__INT16_TYPE__ short int"
.LASF332:
	.string	"__DECIMAL_BID_FORMAT__ 1"
.LASF180:
	.string	"__LDBL_DIG__ 18"
.LASF254:
	.string	"__FLT64X_MAX_EXP__ 16384"
.LASF10:
	.string	"__ATOMIC_SEQ_CST 5"
.LASF23:
	.string	"__SIZEOF_SHORT__ 2"
.LASF110:
	.string	"__INT_LEAST8_MAX__ 0x7f"
.LASF53:
	.string	"__INT_LEAST8_TYPE__ signed char"
.LASF208:
	.string	"__FLT64_MANT_DIG__ 53"
.LASF97:
	.string	"__UINTMAX_C(c) c ## ULL"
.LASF79:
	.string	"__WCHAR_MAX__ 0x7fffffffL"
.LASF347:
	.string	"STD_SIZE_T unsigned int"
.LASF341:
	.string	"__STDC_NO_THREADS__ 1"
.LASF33:
	.string	"__BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__"
.LASF270:
	.string	"__DEC32_SUBNORMAL_MIN__ 0.000001E-95DF"
.LASF327:
	.string	"linux 1"
.LASF197:
	.string	"__FLT32_MIN_10_EXP__ (-37)"
.LASF375:
	.string	"ENOSYS CGC_ENOSYS"
.LASF414:
	.string	"string_arg"
.LASF80:
	.string	"__WCHAR_MIN__ (-__WCHAR_MAX__ - 1)"
.LASF402:
	.string	"cgc_printf"
.LASF113:
	.string	"__INT_LEAST16_MAX__ 0x7fff"
.LASF74:
	.string	"__SCHAR_MAX__ 0x7f"
.LASF284:
	.string	"__DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL"
.LASF209:
	.string	"__FLT64_DIG__ 15"
.LASF18:
	.string	"__PIE__ 2"
.LASF311:
	.string	"i386 1"
.LASF84:
	.string	"__SIZE_MAX__ 0xffffffffU"
.LASF248:
	.string	"__FLT32X_HAS_INFINITY__ 1"
.LASF234:
	.string	"__FLT128_HAS_INFINITY__ 1"
.LASF57:
	.string	"__UINT_LEAST8_TYPE__ unsigned char"
.LASF343:
	.string	"STDIN 0"
.LASF64:
	.string	"__INT_FAST64_TYPE__ long long int"
.LASF235:
	.string	"__FLT128_HAS_QUIET_NAN__ 1"
.LASF394:
	.string	"signed char"
.LASF55:
	.string	"__INT_LEAST32_TYPE__ int"
.LASF115:
	.string	"__INT_LEAST16_WIDTH__ 16"
.LASF232:
	.string	"__FLT128_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966F128"
.LASF365:
	.string	"FD_SETSIZE CGC_FD_SETSIZE"
.LASF70:
	.string	"__UINTPTR_TYPE__ unsigned int"
.LASF205:
	.string	"__FLT32_HAS_DENORM__ 1"
.LASF329:
	.string	"__unix__ 1"
.LASF289:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1"
.LASF405:
	.string	"character_count"
.LASF252:
	.string	"__FLT64X_MIN_EXP__ (-16381)"
.LASF136:
	.string	"__INT_FAST64_MAX__ 0x7fffffffffffffffLL"
.LASF419:
	.string	"tx_count"
.LASF427:
	.string	"cgc_putc"
.LASF152:
	.string	"__FLT_DIG__ 6"
.LASF132:
	.string	"__INT_FAST16_MAX__ 0x7fffffff"
.LASF290:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1"
.LASF17:
	.string	"__pie__ 2"
.LASF267:
	.string	"__DEC32_MIN__ 1E-95DF"
.LASF425:
	.string	"count"
.LASF217:
	.string	"__FLT64_EPSILON__ 2.22044604925031308084726333618164062e-16F64"
.LASF399:
	.string	"long long unsigned int"
.LASF391:
	.string	"__gnuc_va_list"
.LASF145:
	.string	"__GCC_IEC_559 2"
.LASF224:
	.string	"__FLT128_MIN_EXP__ (-16381)"
.LASF83:
	.string	"__PTRDIFF_MAX__ 0x7fffffff"
.LASF207:
	.string	"__FLT32_HAS_QUIET_NAN__ 1"
.LASF124:
	.string	"__UINT_LEAST16_MAX__ 0xffff"
.LASF200:
	.string	"__FLT32_DECIMAL_DIG__ 9"
.LASF403:
	.string	"large_buff"
.LASF122:
	.string	"__UINT_LEAST8_MAX__ 0xff"
.LASF279:
	.string	"__DEC128_MIN_EXP__ (-6142)"
.LASF102:
	.string	"__INT8_MAX__ 0x7f"
.LASF409:
	.string	"zero_padding"
.LASF291:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1"
.LASF226:
	.string	"__FLT128_MAX_EXP__ 16384"
.LASF128:
	.string	"__UINT_LEAST64_MAX__ 0xffffffffffffffffULL"
.LASF150:
	.string	"__FLT_RADIX__ 2"
.LASF26:
	.string	"__SIZEOF_LONG_DOUBLE__ 12"
.LASF378:
	.string	"va_start(v,l) __builtin_va_start(v,l)"
.LASF178:
	.string	"__DBL_HAS_QUIET_NAN__ 1"
.LASF190:
	.string	"__LDBL_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951L"
.LASF220:
	.string	"__FLT64_HAS_INFINITY__ 1"
.LASF138:
	.string	"__UINT_FAST8_MAX__ 0xff"
.LASF315:
	.string	"__ATOMIC_HLE_RELEASE 131072"
.LASF183:
	.string	"__LDBL_MAX_EXP__ 16384"
.LASF330:
	.string	"unix 1"
.LASF406:
	.string	"temp_buf"
.LASF429:
	.string	"/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/new_printf.c"
.LASF299:
	.string	"__GCC_ATOMIC_INT_LOCK_FREE 2"
.LASF94:
	.string	"__INTMAX_MAX__ 0x7fffffffffffffffLL"
.LASF251:
	.string	"__FLT64X_DIG__ 18"
.LASF121:
	.string	"__INT_LEAST64_WIDTH__ 64"
.LASF222:
	.string	"__FLT128_MANT_DIG__ 113"
.LASF30:
	.string	"__ORDER_LITTLE_ENDIAN__ 1234"
.LASF308:
	.string	"__SIZEOF_PTRDIFF_T__ 4"
.LASF109:
	.string	"__UINT64_MAX__ 0xffffffffffffffffULL"
.LASF422:
	.string	"weight"
.LASF278:
	.string	"__DEC128_MANT_DIG__ 34"
.LASF188:
	.string	"__LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L"
.LASF47:
	.string	"__INT32_TYPE__ int"
.LASF261:
	.string	"__FLT64X_HAS_DENORM__ 1"
.LASF266:
	.string	"__DEC32_MAX_EXP__ 97"
.LASF8:
	.string	"__VERSION__ \"8.4.0\""
.LASF407:
	.string	"width"
.LASF339:
	.string	"__STDC_IEC_559_COMPLEX__ 1"
.LASF359:
	.string	"CGC_EBADF 1"
.LASF336:
	.string	"errno __cgc_errno"
.LASF253:
	.string	"__FLT64X_MIN_10_EXP__ (-4931)"
.LASF340:
	.string	"__STDC_ISO_10646__ 201706L"
.LASF227:
	.string	"__FLT128_MAX_10_EXP__ 4932"
.LASF230:
	.string	"__FLT128_MIN__ 3.36210314311209350626267781732175260e-4932F128"
.LASF131:
	.string	"__INT_FAST8_WIDTH__ 8"
.LASF211:
	.string	"__FLT64_MIN_10_EXP__ (-307)"
.LASF370:
	.string	"FD_ISSET CGC_FD_ISSET"
.LASF201:
	.string	"__FLT32_MAX__ 3.40282346638528859811704183484516925e+38F32"
.LASF353:
	.string	"CGC_FD_SETSIZE 1024"
.LASF62:
	.string	"__INT_FAST16_TYPE__ int"
.LASF385:
	.string	"__MYMATH_H__ "
.LASF310:
	.string	"__i386__ 1"
.LASF50:
	.string	"__UINT16_TYPE__ short unsigned int"
.LASF223:
	.string	"__FLT128_DIG__ 33"
.LASF90:
	.string	"__WCHAR_WIDTH__ 32"
.LASF294:
	.string	"__GCC_ATOMIC_CHAR_LOCK_FREE 2"
.LASF246:
	.string	"__FLT32X_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F32x"
.LASF367:
	.string	"FD_ZERO CGC_FD_ZERO"
.LASF78:
	.string	"__LONG_LONG_MAX__ 0x7fffffffffffffffLL"
.LASF48:
	.string	"__INT64_TYPE__ long long int"
.LASF156:
	.string	"__FLT_MAX_10_EXP__ 38"
.LASF192:
	.string	"__LDBL_HAS_INFINITY__ 1"
.LASF245:
	.string	"__FLT32X_EPSILON__ 2.22044604925031308084726333618164062e-16F32x"
.LASF236:
	.string	"__FLT32X_MANT_DIG__ 53"
.LASF288:
	.string	"__NO_INLINE__ 1"
.LASF151:
	.string	"__FLT_MANT_DIG__ 24"
.LASF172:
	.string	"__DBL_MAX__ ((double)1.79769313486231570814527423731704357e+308L)"
.LASF214:
	.string	"__FLT64_DECIMAL_DIG__ 17"
.LASF313:
	.string	"__SIZEOF_FLOAT128__ 16"
.LASF196:
	.string	"__FLT32_MIN_EXP__ (-125)"
.LASF187:
	.string	"__LDBL_MAX__ 1.18973149535723176502126385303097021e+4932L"
.LASF139:
	.string	"__UINT_FAST16_MAX__ 0xffffffffU"
.LASF66:
	.string	"__UINT_FAST16_TYPE__ unsigned int"
.LASF158:
	.string	"__FLT_MAX__ 3.40282346638528859811704183484516925e+38F"
.LASF168:
	.string	"__DBL_MIN_10_EXP__ (-307)"
.LASF392:
	.string	"char"
.LASF73:
	.string	"__GXX_ABI_VERSION 1013"
.LASF182:
	.string	"__LDBL_MIN_10_EXP__ (-4931)"
.LASF381:
	.string	"__STDLIB_H__ "
.LASF195:
	.string	"__FLT32_DIG__ 6"
.LASF219:
	.string	"__FLT64_HAS_DENORM__ 1"
.LASF321:
	.string	"__code_model_32__ 1"
.LASF247:
	.string	"__FLT32X_HAS_DENORM__ 1"
.LASF349:
	.string	"CGC_FLAG_PAGE_ADDRESS 0x4347C000"
.LASF361:
	.string	"CGC_EINVAL 3"
.LASF119:
	.string	"__INT_LEAST64_MAX__ 0x7fffffffffffffffLL"
.LASF371:
	.string	"EBADF CGC_EBADF"
.LASF257:
	.string	"__FLT64X_MAX__ 1.18973149535723176502126385303097021e+4932F64x"
.LASF297:
	.string	"__GCC_ATOMIC_WCHAR_T_LOCK_FREE 2"
.LASF354:
	.string	"CGC__NFDBITS (8 * sizeof(_fd_mask))"
.LASF9:
	.string	"__ATOMIC_RELAXED 0"
.LASF112:
	.string	"__INT_LEAST8_WIDTH__ 8"
.LASF106:
	.string	"__UINT8_MAX__ 0xff"
.LASF107:
	.string	"__UINT16_MAX__ 0xffff"
.LASF363:
	.string	"CGC_ENOSYS 5"
.LASF377:
	.string	"__STDARG_H__ "
.LASF108:
	.string	"__UINT32_MAX__ 0xffffffffU"
.LASF98:
	.string	"__INTMAX_WIDTH__ 64"
.LASF268:
	.string	"__DEC32_MAX__ 9.999999E96DF"
.LASF54:
	.string	"__INT_LEAST16_TYPE__ short int"
.LASF198:
	.string	"__FLT32_MAX_EXP__ 128"
.LASF324:
	.string	"__gnu_linux__ 1"
.LASF111:
	.string	"__INT8_C(c) c"
.LASF295:
	.string	"__GCC_ATOMIC_CHAR16_T_LOCK_FREE 2"
.LASF300:
	.string	"__GCC_ATOMIC_LONG_LOCK_FREE 2"
.LASF237:
	.string	"__FLT32X_DIG__ 15"
.LASF393:
	.string	"va_list"
.LASF396:
	.string	"long long int"
.LASF28:
	.string	"__CHAR_BIT__ 8"
.LASF173:
	.string	"__DBL_MIN__ ((double)2.22507385850720138309023271733240406e-308L)"
.LASF143:
	.string	"__INTPTR_WIDTH__ 32"
.LASF293:
	.string	"__GCC_ATOMIC_BOOL_LOCK_FREE 2"
.LASF19:
	.string	"__FINITE_MATH_ONLY__ 0"
.LASF215:
	.string	"__FLT64_MAX__ 1.79769313486231570814527423731704357e+308F64"
.LASF174:
	.string	"__DBL_EPSILON__ ((double)2.22044604925031308084726333618164062e-16L)"
.LASF322:
	.string	"__SEG_FS 1"
.LASF316:
	.string	"__GCC_ASM_FLAG_OUTPUTS__ 1"
.LASF331:
	.string	"__ELF__ 1"
.LASF244:
	.string	"__FLT32X_MIN__ 2.22507385850720138309023271733240406e-308F32x"
.LASF262:
	.string	"__FLT64X_HAS_INFINITY__ 1"
.LASF114:
	.string	"__INT16_C(c) c"
.LASF304:
	.string	"__GCC_HAVE_DWARF2_CFI_ASM 1"
.LASF369:
	.string	"FD_CLR CGC_FD_CLR"
.LASF269:
	.string	"__DEC32_EPSILON__ 1E-6DF"
.LASF134:
	.string	"__INT_FAST32_MAX__ 0x7fffffff"
.LASF263:
	.string	"__FLT64X_HAS_QUIET_NAN__ 1"
.LASF163:
	.string	"__FLT_HAS_INFINITY__ 1"
.LASF418:
	.string	"digit"
.LASF413:
	.string	"float_arg"
.LASF105:
	.string	"__INT64_MAX__ 0x7fffffffffffffffLL"
.LASF0:
	.string	"__STDC__ 1"
.LASF21:
	.string	"__SIZEOF_LONG__ 4"
.LASF169:
	.string	"__DBL_MAX_EXP__ 1024"
.LASF14:
	.string	"__ATOMIC_CONSUME 1"
.LASF345:
	.string	"STDERR 2"
.LASF135:
	.string	"__INT_FAST32_WIDTH__ 32"
.LASF39:
	.string	"__WINT_TYPE__ unsigned int"
.LASF77:
	.string	"__LONG_MAX__ 0x7fffffffL"
.LASF103:
	.string	"__INT16_MAX__ 0x7fff"
.LASF85:
	.string	"__SCHAR_WIDTH__ 8"
.LASF127:
	.string	"__UINT32_C(c) c ## U"
.LASF25:
	.string	"__SIZEOF_DOUBLE__ 8"
.LASF7:
	.string	"__GNUC_PATCHLEVEL__ 0"
.LASF82:
	.string	"__WINT_MIN__ 0U"
.LASF179:
	.string	"__LDBL_MANT_DIG__ 64"
.LASF280:
	.string	"__DEC128_MAX_EXP__ 6145"
.LASF2:
	.string	"__STDC_UTF_16__ 1"
.LASF189:
	.string	"__LDBL_EPSILON__ 1.08420217248550443400745280086994171e-19L"
.LASF344:
	.string	"STDOUT 1"
.LASF410:
	.string	"left_justification"
.LASF61:
	.string	"__INT_FAST8_TYPE__ signed char"
.LASF68:
	.string	"__UINT_FAST64_TYPE__ long long unsigned int"
.LASF376:
	.string	"EPIPE CGC_EPIPE"
.LASF146:
	.string	"__GCC_IEC_559_COMPLEX 2"
.LASF306:
	.string	"__SIZEOF_WCHAR_T__ 4"
.LASF346:
	.string	"NULL (0)"
.LASF225:
	.string	"__FLT128_MIN_10_EXP__ (-4931)"
.LASF34:
	.string	"__FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__"
.LASF400:
	.string	"done"
.LASF93:
	.string	"__SIZE_WIDTH__ 32"
.LASF264:
	.string	"__DEC32_MANT_DIG__ 7"
.LASF204:
	.string	"__FLT32_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F32"
.LASF272:
	.string	"__DEC64_MIN_EXP__ (-382)"
.LASF100:
	.string	"__SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)"
.LASF104:
	.string	"__INT32_MAX__ 0x7fffffff"
.LASF88:
	.string	"__LONG_WIDTH__ 32"
.LASF11:
	.string	"__ATOMIC_ACQUIRE 2"
.LASF125:
	.string	"__UINT16_C(c) c"
.LASF415:
	.string	"output_strlen"
.LASF323:
	.string	"__SEG_GS 1"
.LASF356:
	.string	"CGC_FD_SET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] |= (1 << (b & (CGC__NFDBITS - 1))))"
.LASF317:
	.string	"__i686 1"
.LASF335:
	.string	"NPATCHED 1"
.LASF41:
	.string	"__UINTMAX_TYPE__ long long unsigned int"
.LASF348:
	.string	"PAGE_SIZE 4096"
.LASF101:
	.string	"__SIG_ATOMIC_WIDTH__ 32"
.LASF424:
	.string	"cgc_int_to_hex"
.LASF423:
	.string	"cgc_float_to_str"
.LASF75:
	.string	"__SHRT_MAX__ 0x7fff"
.LASF408:
	.string	"precision"
.LASF32:
	.string	"__ORDER_PDP_ENDIAN__ 3412"
.LASF58:
	.string	"__UINT_LEAST16_TYPE__ short unsigned int"
.LASF157:
	.string	"__FLT_DECIMAL_DIG__ 9"
.LASF213:
	.string	"__FLT64_MAX_10_EXP__ 308"
.LASF181:
	.string	"__LDBL_MIN_EXP__ (-16381)"
.LASF91:
	.string	"__WINT_WIDTH__ 32"
.LASF283:
	.string	"__DEC128_EPSILON__ 1E-33DL"
.LASF258:
	.string	"__FLT64X_MIN__ 3.36210314311209350626267781732175260e-4932F64x"
.LASF130:
	.string	"__INT_FAST8_MAX__ 0x7f"
.LASF285:
	.string	"__REGISTER_PREFIX__ "
.LASF203:
	.string	"__FLT32_EPSILON__ 1.19209289550781250000000000000000000e-7F32"
.LASF395:
	.string	"short int"
.LASF350:
	.string	"offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)"
.LASF273:
	.string	"__DEC64_MAX_EXP__ 385"
.LASF309:
	.string	"__i386 1"
.LASF239:
	.string	"__FLT32X_MIN_10_EXP__ (-307)"
.LASF388:
	.string	"long int"
.LASF43:
	.string	"__CHAR32_TYPE__ unsigned int"
.LASF255:
	.string	"__FLT64X_MAX_10_EXP__ 4932"
.LASF380:
	.string	"va_arg(v,l) __builtin_va_arg(v,l)"
.LASF281:
	.string	"__DEC128_MIN__ 1E-6143DL"
.LASF238:
	.string	"__FLT32X_MIN_EXP__ (-1021)"
.LASF65:
	.string	"__UINT_FAST8_TYPE__ unsigned char"
.LASF117:
	.string	"__INT32_C(c) c"
.LASF193:
	.string	"__LDBL_HAS_QUIET_NAN__ 1"
.LASF45:
	.string	"__INT8_TYPE__ signed char"
.LASF81:
	.string	"__WINT_MAX__ 0xffffffffU"
.LASF325:
	.string	"__linux 1"
.LASF372:
	.string	"EFAULT CGC_EFAULT"
.LASF411:
	.string	"pad_len"
.LASF51:
	.string	"__UINT32_TYPE__ unsigned int"
.LASF360:
	.string	"CGC_EFAULT 2"
.LASF141:
	.string	"__UINT_FAST64_MAX__ 0xffffffffffffffffULL"
.LASF140:
	.string	"__UINT_FAST32_MAX__ 0xffffffffU"
.LASF362:
	.string	"CGC_ENOMEM 4"
.LASF120:
	.string	"__INT64_C(c) c ## LL"
.LASF383:
	.string	"FREE_FLAG 2"
.LASF22:
	.string	"__SIZEOF_LONG_LONG__ 8"
.LASF49:
	.string	"__UINT8_TYPE__ unsigned char"
.LASF86:
	.string	"__SHRT_WIDTH__ 16"
.LASF379:
	.string	"va_end(v) __builtin_va_end(v)"
.LASF404:
	.string	"cgc_vsprintf"
.LASF56:
	.string	"__INT_LEAST64_TYPE__ long long int"
.LASF355:
	.string	"CGC_FD_ZERO(set) do { int __i; for (__i = 0; __i < (CGC_FD_SETSIZE / CGC__NFDBITS); __i++) (set)->_fd_bits[__i] = 0; } while (0)"
.LASF35:
	.string	"__SIZEOF_POINTER__ 4"
.LASF421:
	.string	"in_fraction"
.LASF275:
	.string	"__DEC64_MAX__ 9.999999999999999E384DD"
.LASF250:
	.string	"__FLT64X_MANT_DIG__ 64"
.LASF92:
	.string	"__PTRDIFF_WIDTH__ 32"
.LASF373:
	.string	"EINVAL CGC_EINVAL"
.LASF161:
	.string	"__FLT_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F"
.LASF87:
	.string	"__INT_WIDTH__ 32"
.LASF186:
	.string	"__LDBL_DECIMAL_DIG__ 21"
.LASF303:
	.string	"__GCC_ATOMIC_POINTER_LOCK_FREE 2"
.LASF129:
	.string	"__UINT64_C(c) c ## ULL"
.LASF417:
	.string	"cgc_vprintf"
.LASF286:
	.string	"__USER_LABEL_PREFIX__ "
.LASF387:
	.string	"long unsigned int"
.LASF296:
	.string	"__GCC_ATOMIC_CHAR32_T_LOCK_FREE 2"
.LASF1:
	.string	"__STDC_VERSION__ 199901L"
.LASF328:
	.string	"__unix 1"
.LASF351:
	.string	"SSIZE_MAX ((cgc_ssize_t)((~((cgc_size_t)0ULL))>>1))"
.LASF96:
	.string	"__UINTMAX_MAX__ 0xffffffffffffffffULL"
.LASF314:
	.string	"__ATOMIC_HLE_ACQUIRE 65536"
.LASF4:
	.string	"__STDC_HOSTED__ 1"
.LASF142:
	.string	"__INTPTR_MAX__ 0x7fffffff"
.LASF357:
	.string	"CGC_FD_CLR(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] &= ~(1 << (b & (CGC__NFDBITS - 1))))"
.LASF71:
	.string	"__has_include(STR) __has_include__(STR)"
.LASF366:
	.string	"_NFDBITS CGC__NFDBITS"
.LASF199:
	.string	"__FLT32_MAX_10_EXP__ 38"
.LASF342:
	.string	"_LIBCGC_H "
.LASF301:
	.string	"__GCC_ATOMIC_LLONG_LOCK_FREE 2"
.LASF155:
	.string	"__FLT_MAX_EXP__ 128"
.LASF13:
	.string	"__ATOMIC_ACQ_REL 4"
.LASF397:
	.string	"unsigned char"
.LASF265:
	.string	"__DEC32_MIN_EXP__ (-94)"
.LASF159:
	.string	"__FLT_MIN__ 1.17549435082228750796873653722224568e-38F"
.LASF69:
	.string	"__INTPTR_TYPE__ int"
.LASF149:
	.string	"__DEC_EVAL_METHOD__ 2"
.LASF386:
	.string	"F32_PRECISION 0.00001"
.LASF118:
	.string	"__INT_LEAST32_WIDTH__ 32"
.LASF67:
	.string	"__UINT_FAST32_TYPE__ unsigned int"
.LASF16:
	.string	"__PIC__ 2"
.LASF36:
	.string	"__SIZE_TYPE__ unsigned int"
.LASF320:
	.string	"__pentiumpro__ 1"
.LASF382:
	.string	"INUSE_FLAG 1"
.LASF228:
	.string	"__FLT128_DECIMAL_DIG__ 36"
.LASF428:
	.string	"GNU C99 8.4.0 -m32 -mtune=generic -march=i686 -g3 -g -O0 -std=gnu99 -fno-builtin -fno-stack-protector"
.LASF298:
	.string	"__GCC_ATOMIC_SHORT_LOCK_FREE 2"
.LASF256:
	.string	"__FLT64X_DECIMAL_DIG__ 21"
.LASF59:
	.string	"__UINT_LEAST32_TYPE__ unsigned int"
.LASF160:
	.string	"__FLT_EPSILON__ 1.19209289550781250000000000000000000e-7F"
.LASF210:
	.string	"__FLT64_MIN_EXP__ (-1021)"
.LASF374:
	.string	"ENOMEM CGC_ENOMEM"
.LASF177:
	.string	"__DBL_HAS_INFINITY__ 1"
.LASF148:
	.string	"__FLT_EVAL_METHOD_TS_18661_3__ 2"
.LASF63:
	.string	"__INT_FAST32_TYPE__ int"
.LASF164:
	.string	"__FLT_HAS_QUIET_NAN__ 1"
.LASF20:
	.string	"__SIZEOF_INT__ 4"
.LASF40:
	.string	"__INTMAX_TYPE__ long long int"
.LASF338:
	.string	"__STDC_IEC_559__ 1"
.LASF95:
	.string	"__INTMAX_C(c) c ## LL"
.LASF337:
	.string	"_STDC_PREDEF_H 1"
.LASF312:
	.string	"__SIZEOF_FLOAT80__ 12"
.LASF52:
	.string	"__UINT64_TYPE__ long long unsigned int"
.LASF430:
	.string	"/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/build/SCUBA_Dive_Logging"
.LASF249:
	.string	"__FLT32X_HAS_QUIET_NAN__ 1"
.LASF170:
	.string	"__DBL_MAX_10_EXP__ 308"
.LASF398:
	.string	"short unsigned int"
.LASF15:
	.string	"__pic__ 2"
.LASF287:
	.string	"__GNUC_STDC_INLINE__ 1"
.LASF24:
	.string	"__SIZEOF_FLOAT__ 4"
.LASF29:
	.string	"__BIGGEST_ALIGNMENT__ 16"
.LASF431:
	.string	"__builtin_va_list"
.LASF358:
	.string	"CGC_FD_ISSET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] & (1 << (b & (CGC__NFDBITS - 1))))"
.LASF153:
	.string	"__FLT_MIN_EXP__ (-125)"
.LASF282:
	.string	"__DEC128_MAX__ 9.999999999999999999999999999999999E6144DL"
.LASF352:
	.string	"SIZE_MAX (~((cgc_size_t)0ULL))"
.LASF416:
	.string	"double"
.LASF126:
	.string	"__UINT_LEAST32_MAX__ 0xffffffffU"
.LASF241:
	.string	"__FLT32X_MAX_10_EXP__ 308"
.LASF144:
	.string	"__UINTPTR_MAX__ 0xffffffffU"
.LASF176:
	.string	"__DBL_HAS_DENORM__ 1"
.LASF326:
	.string	"__linux__ 1"
.LASF218:
	.string	"__FLT64_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F64"
.LASF38:
	.string	"__WCHAR_TYPE__ long int"
.LASF3:
	.string	"__STDC_UTF_32__ 1"
.LASF116:
	.string	"__INT_LEAST32_MAX__ 0x7fffffff"
.LASF390:
	.string	"cgc_size_t"
.LASF384:
	.string	"__STDINT_H__ "
.LASF184:
	.string	"__LDBL_MAX_10_EXP__ 4932"
.LASF274:
	.string	"__DEC64_MIN__ 1E-383DD"
.LASF202:
	.string	"__FLT32_MIN__ 1.17549435082228750796873653722224568e-38F32"
.LASF319:
	.string	"__pentiumpro 1"
.LASF305:
	.string	"__PRAGMA_REDEFINE_EXTNAME 1"
.LASF44:
	.string	"__SIG_ATOMIC_TYPE__ int"
.LASF260:
	.string	"__FLT64X_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951F64x"
.LASF426:
	.string	"cgc_int_to_str"
.LASF233:
	.string	"__FLT128_HAS_DENORM__ 1"
.LASF171:
	.string	"__DBL_DECIMAL_DIG__ 17"
.LASF191:
	.string	"__LDBL_HAS_DENORM__ 1"
.LASF166:
	.string	"__DBL_DIG__ 15"
.LASF271:
	.string	"__DEC64_MANT_DIG__ 16"
.LASF162:
	.string	"__FLT_HAS_DENORM__ 1"
.LASF137:
	.string	"__INT_FAST64_WIDTH__ 64"
.LASF185:
	.string	"__DECIMAL_DIG__ 21"
	.ident	"GCC: (Ubuntu 8.4.0-1ubuntu1~18.04) 8.4.0"
	.section	.note.GNU-stack,"",@progbits
