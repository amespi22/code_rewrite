	.file	"stdlib.c"
	.text
.Ltext0:
	.globl	cgc_memcpy
	.type	cgc_memcpy, @function
cgc_memcpy:
.LFB0:
	.file 1 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/stdlib.c"
	.loc 1 31 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 32 20
	movl	$0, -4(%ebp)
	.loc 1 34 15
	jmp	.L2
.L3:
	.loc 1 35 52
	movl	12(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	.loc 1 35 30
	movl	8(%ebp), %ecx
	movl	-4(%ebp), %edx
	addl	%ecx, %edx
	.loc 1 35 52
	movzbl	(%eax), %eax
	.loc 1 35 38
	movb	%al, (%edx)
	.loc 1 36 22
	addl	$1, -4(%ebp)
.L2:
	.loc 1 34 15
	movl	-4(%ebp), %eax
	cmpl	16(%ebp), %eax
	jb	.L3
	.loc 1 39 16
	movl	-4(%ebp), %eax
	.loc 1 40 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	cgc_memcpy, .-cgc_memcpy
	.globl	cgc_islower
	.type	cgc_islower, @function
cgc_islower:
.LFB1:
	.loc 1 43 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 44 12
	cmpl	$96, 8(%ebp)
	jle	.L6
	.loc 1 44 24 discriminator 1
	cmpl	$122, 8(%ebp)
	jg	.L6
	.loc 1 45 24
	movl	$1, %eax
	jmp	.L7
.L6:
	.loc 1 47 24
	movl	$0, %eax
.L7:
	.loc 1 48 1
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	cgc_islower, .-cgc_islower
	.globl	cgc_isupper
	.type	cgc_isupper, @function
cgc_isupper:
.LFB2:
	.loc 1 51 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 52 12
	cmpl	$64, 8(%ebp)
	jle	.L9
	.loc 1 52 24 discriminator 1
	cmpl	$90, 8(%ebp)
	jg	.L9
	.loc 1 53 24
	movl	$1, %eax
	jmp	.L10
.L9:
	.loc 1 55 24
	movl	$0, %eax
.L10:
	.loc 1 56 1
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	cgc_isupper, .-cgc_isupper
	.globl	cgc_isalpha
	.type	cgc_isalpha, @function
cgc_isalpha:
.LFB3:
	.loc 1 59 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 60 16
	pushl	8(%ebp)
	call	cgc_islower
	addl	$4, %esp
	movl	%eax, %ebx
	.loc 1 60 35
	pushl	8(%ebp)
	call	cgc_isupper
	addl	$4, %esp
	.loc 1 60 33
	orl	%ebx, %eax
	.loc 1 61 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	cgc_isalpha, .-cgc_isalpha
	.globl	cgc_isalnum
	.type	cgc_isalnum, @function
cgc_isalnum:
.LFB4:
	.loc 1 64 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 65 16
	pushl	8(%ebp)
	call	cgc_isalpha
	addl	$4, %esp
	movl	%eax, %ebx
	.loc 1 65 35
	subl	$12, %esp
	pushl	8(%ebp)
	call	cgc_isdigit
	addl	$16, %esp
	.loc 1 65 33
	orl	%ebx, %eax
	.loc 1 66 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	cgc_isalnum, .-cgc_isalnum
	.globl	cgc_isspace
	.type	cgc_isspace, @function
cgc_isspace:
.LFB5:
	.loc 1 69 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 70 8
	cmpl	$32, 8(%ebp)
	je	.L16
	.loc 1 70 19 discriminator 1
	cmpl	$9, 8(%ebp)
	je	.L16
	.loc 1 71 20
	cmpl	$10, 8(%ebp)
	je	.L16
	.loc 1 72 20
	cmpl	$11, 8(%ebp)
	je	.L16
	.loc 1 73 20
	cmpl	$12, 8(%ebp)
	je	.L16
	.loc 1 74 20
	cmpl	$13, 8(%ebp)
	jne	.L17
.L16:
	.loc 1 76 16
	movl	$1, %eax
	jmp	.L18
.L17:
	.loc 1 78 16
	movl	$0, %eax
.L18:
	.loc 1 79 1
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	cgc_isspace, .-cgc_isspace
	.globl	cgc_isdigit
	.type	cgc_isdigit, @function
cgc_isdigit:
.LFB6:
	.loc 1 82 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 83 8
	cmpl	$47, 8(%ebp)
	jle	.L20
	.loc 1 83 19 discriminator 1
	cmpl	$57, 8(%ebp)
	jg	.L20
	.loc 1 84 16
	movl	$1, %eax
	jmp	.L21
.L20:
	.loc 1 86 16
	movl	$0, %eax
.L21:
	.loc 1 87 1
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE6:
	.size	cgc_isdigit, .-cgc_isdigit
	.globl	cgc_isnan
	.type	cgc_isnan, @function
cgc_isnan:
.LFB7:
	.loc 1 90 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	.loc 1 91 12
	fldl	-8(%ebp)
	fldl	-8(%ebp)
	fucomip	%st(1), %st
	fstp	%st(0)
	setp	%al
	movzbl	%al, %eax
	.loc 1 92 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE7:
	.size	cgc_isnan, .-cgc_isnan
	.globl	cgc_isinf
	.type	cgc_isinf, @function
cgc_isinf:
.LFB8:
	.loc 1 95 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	.loc 1 96 12
	fldl	-8(%ebp)
	fxam
	fnstsw	%ax
	fstp	%st(0)
	andb	$69, %ah
	cmpb	$5, %ah
	sete	%al
	movzbl	%al, %eax
	.loc 1 97 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE8:
	.size	cgc_isinf, .-cgc_isinf
	.globl	cgc_atof
	.type	cgc_atof, @function
cgc_atof:
.LFB9:
	.loc 1 100 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	.loc 1 101 8
	cmpl	$0, 8(%ebp)
	jne	.L27
	.loc 1 102 16
	fldz
	jmp	.L28
.L27:
	.loc 1 104 12
	fldz
	fstpl	-16(%ebp)
	.loc 1 105 12
	fldl	.LC1@GOTOFF(%ebx)
	fstpl	-24(%ebp)
	.loc 1 106 9
	movl	$1, -28(%ebp)
	.loc 1 110 11
	jmp	.L29
.L30:
	.loc 1 111 12
	addl	$1, 8(%ebp)
.L29:
	.loc 1 110 29
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 110 13
	movsbl	%al, %eax
	pushl	%eax
	call	cgc_isspace
	addl	$4, %esp
	.loc 1 110 11
	testl	%eax, %eax
	jne	.L30
	.loc 1 113 10
	movl	$0, -32(%ebp)
	.loc 1 115 10
	jmp	.L31
.L46:
	.loc 1 117 17
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 117 12
	cmpb	$45, %al
	jne	.L32
	.loc 1 119 16
	cmpl	$0, -32(%ebp)
	je	.L33
	.loc 1 120 24
	fldz
	jmp	.L28
.L33:
	.loc 1 122 18
	movl	$-1, -28(%ebp)
	.loc 1 123 17
	addl	$1, -32(%ebp)
	jmp	.L34
.L32:
	.loc 1 125 22
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 125 17
	cmpb	$43, %al
	jne	.L35
	.loc 1 127 16
	cmpl	$0, -32(%ebp)
	je	.L36
	.loc 1 128 24
	fldz
	jmp	.L28
.L36:
	.loc 1 130 17
	addl	$1, -32(%ebp)
	jmp	.L34
.L35:
	.loc 1 132 22
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 132 17
	cmpb	$46, %al
	jne	.L37
	.loc 1 134 16
	cmpl	$0, -32(%ebp)
	je	.L38
	.loc 1 134 28 discriminator 1
	cmpl	$1, -32(%ebp)
	jne	.L39
.L38:
	.loc 1 135 22
	movl	$2, -32(%ebp)
	jmp	.L34
.L39:
	.loc 1 137 24
	fldz
	jmp	.L28
.L37:
	.loc 1 139 32
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 139 19
	movsbl	%al, %eax
	pushl	%eax
	call	cgc_isdigit
	addl	$4, %esp
	.loc 1 139 17
	testl	%eax, %eax
	je	.L47
	.loc 1 141 16
	cmpl	$0, -32(%ebp)
	je	.L41
	.loc 1 141 28 discriminator 1
	cmpl	$1, -32(%ebp)
	jne	.L42
.L41:
	.loc 1 144 22
	movl	$1, -32(%ebp)
	.loc 1 145 28
	fldl	-16(%ebp)
	fldl	.LC2@GOTOFF(%ebx)
	fmulp	%st, %st(1)
	.loc 1 145 39
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	.loc 1 145 44
	subl	$48, %eax
	.loc 1 145 36
	movl	%eax, -44(%ebp)
	fildl	-44(%ebp)
	.loc 1 145 21
	faddp	%st, %st(1)
	fstpl	-16(%ebp)
	jmp	.L34
.L42:
	.loc 1 147 21
	cmpl	$2, -32(%ebp)
	jne	.L44
	.loc 1 149 26
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	.loc 1 149 31
	subl	$48, %eax
	.loc 1 149 38
	movl	%eax, -44(%ebp)
	fildl	-44(%ebp)
	fmull	-24(%ebp)
	.loc 1 149 21
	fldl	-16(%ebp)
	faddp	%st, %st(1)
	fstpl	-16(%ebp)
	.loc 1 150 23
	fldl	-24(%ebp)
	fldl	.LC2@GOTOFF(%ebx)
	fdivrp	%st, %st(1)
	fstpl	-24(%ebp)
	jmp	.L34
.L44:
	.loc 1 155 24
	fldz
	jmp	.L28
.L34:
	.loc 1 161 12
	addl	$1, 8(%ebp)
.L31:
	.loc 1 115 15
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 115 10
	testb	%al, %al
	jne	.L46
	jmp	.L45
.L47:
	.loc 1 159 13
	nop
.L45:
	.loc 1 164 18
	fildl	-28(%ebp)
	fmull	-16(%ebp)
.L28:
	.loc 1 165 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE9:
	.size	cgc_atof, .-cgc_atof
	.globl	cgc_atoi
	.type	cgc_atoi, @function
cgc_atoi:
.LFB10:
	.loc 1 169 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 170 8
	cmpl	$0, 8(%ebp)
	jne	.L49
	.loc 1 171 16
	movl	$0, %eax
	jmp	.L50
.L49:
	.loc 1 173 9
	movl	$0, -4(%ebp)
	.loc 1 174 9
	movl	$1, -8(%ebp)
	.loc 1 176 9
	movl	$0, -16(%ebp)
	.loc 1 179 11
	jmp	.L51
.L52:
	.loc 1 180 12
	addl	$1, 8(%ebp)
.L51:
	.loc 1 179 29
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 179 13
	movsbl	%al, %eax
	pushl	%eax
	call	cgc_isspace
	addl	$4, %esp
	.loc 1 179 11
	testl	%eax, %eax
	jne	.L52
	.loc 1 182 10
	movl	$0, -12(%ebp)
	.loc 1 184 10
	jmp	.L53
.L65:
	.loc 1 186 17
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 186 12
	cmpb	$45, %al
	jne	.L54
	.loc 1 188 16
	cmpl	$0, -12(%ebp)
	je	.L55
	.loc 1 189 24
	movl	$0, %eax
	jmp	.L50
.L55:
	.loc 1 191 18
	movl	$-1, -8(%ebp)
	.loc 1 192 17
	addl	$1, -12(%ebp)
	jmp	.L56
.L54:
	.loc 1 194 22
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 194 17
	cmpb	$43, %al
	jne	.L57
	.loc 1 196 16
	cmpl	$0, -12(%ebp)
	je	.L58
	.loc 1 197 24
	movl	$0, %eax
	jmp	.L50
.L58:
	.loc 1 199 17
	addl	$1, -12(%ebp)
	jmp	.L56
.L57:
	.loc 1 201 32
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 201 19
	movsbl	%al, %eax
	pushl	%eax
	call	cgc_isdigit
	addl	$4, %esp
	.loc 1 201 17
	testl	%eax, %eax
	je	.L66
	.loc 1 203 16
	cmpl	$0, -12(%ebp)
	je	.L60
	.loc 1 203 28 discriminator 1
	cmpl	$1, -12(%ebp)
	jne	.L61
.L60:
	.loc 1 206 22
	movl	$1, -12(%ebp)
	.loc 1 207 46
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	.loc 1 207 55
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	.loc 1 207 60
	subl	$48, %eax
	.loc 1 207 30
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	.loc 1 209 28
	addl	$1, -16(%ebp)
	.loc 1 211 20
	cmpl	$10, -16(%ebp)
	jne	.L56
	.loc 1 212 21
	jmp	.L63
.L61:
	.loc 1 217 24
	movl	$0, %eax
	jmp	.L50
.L56:
	.loc 1 223 12
	addl	$1, 8(%ebp)
.L53:
	.loc 1 184 15
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 184 10
	testb	%al, %al
	jne	.L65
	jmp	.L63
.L66:
	.loc 1 221 13
	nop
.L63:
	.loc 1 226 18
	movl	-8(%ebp), %eax
	imull	-4(%ebp), %eax
.L50:
	.loc 1 227 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE10:
	.size	cgc_atoi, .-cgc_atoi
	.globl	cgc_strcpy
	.type	cgc_strcpy, @function
cgc_strcpy:
.LFB11:
	.loc 1 230 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 233 13
	movl	$0, -4(%ebp)
.L70:
	.loc 1 235 17
	movl	12(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	.loc 1 235 12
	testb	%al, %al
	je	.L73
	.loc 1 238 22
	movl	12(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	.loc 1 238 13
	movl	8(%ebp), %ecx
	movl	-4(%ebp), %edx
	addl	%ecx, %edx
	.loc 1 238 22
	movzbl	(%eax), %eax
	.loc 1 238 17
	movb	%al, (%edx)
	.loc 1 233 21
	addl	$1, -4(%ebp)
	.loc 1 235 12
	jmp	.L70
.L73:
	.loc 1 236 13
	nop
	.loc 1 240 9
	movl	8(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	.loc 1 240 13
	movb	$0, (%eax)
	.loc 1 242 12
	movl	8(%ebp), %eax
	.loc 1 243 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE11:
	.size	cgc_strcpy, .-cgc_strcpy
	.globl	cgc_strncpy
	.type	cgc_strncpy, @function
cgc_strncpy:
.LFB12:
	.loc 1 246 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 249 13
	movl	$0, -4(%ebp)
	.loc 1 249 5
	jmp	.L75
.L77:
	.loc 1 250 22 discriminator 4
	movl	12(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	.loc 1 250 13 discriminator 4
	movl	8(%ebp), %ecx
	movl	-4(%ebp), %edx
	addl	%ecx, %edx
	.loc 1 250 22 discriminator 4
	movzbl	(%eax), %eax
	.loc 1 250 17 discriminator 4
	movb	%al, (%edx)
	.loc 1 249 44 discriminator 4
	addl	$1, -4(%ebp)
.L75:
	.loc 1 249 5 discriminator 1
	movl	-4(%ebp), %eax
	cmpl	16(%ebp), %eax
	jnb	.L78
	.loc 1 249 30 discriminator 3
	movl	12(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	.loc 1 249 24 discriminator 3
	testb	%al, %al
	jne	.L77
	.loc 1 251 5
	jmp	.L78
.L79:
	.loc 1 252 13 discriminator 2
	movl	8(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	.loc 1 252 17 discriminator 2
	movb	$0, (%eax)
	.loc 1 251 21 discriminator 2
	addl	$1, -4(%ebp)
.L78:
	.loc 1 251 5 discriminator 1
	movl	-4(%ebp), %eax
	cmpl	16(%ebp), %eax
	jb	.L79
	.loc 1 254 12
	movl	8(%ebp), %eax
	.loc 1 255 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE12:
	.size	cgc_strncpy, .-cgc_strncpy
	.globl	cgc_bzero
	.type	cgc_bzero, @function
cgc_bzero:
.LFB13:
	.loc 1 258 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 259 16
	movl	$0, -4(%ebp)
	.loc 1 260 20
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	.loc 1 262 8
	cmpl	$0, 8(%ebp)
	je	.L88
	.loc 1 266 8
	cmpl	$0, 12(%ebp)
	je	.L89
	.loc 1 270 17
	movl	$0, -4(%ebp)
	.loc 1 270 5
	jmp	.L85
.L86:
	.loc 1 271 10 discriminator 3
	movl	-8(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	.loc 1 271 18 discriminator 3
	movb	$0, (%eax)
	.loc 1 270 40 discriminator 3
	addl	$1, -4(%ebp)
.L85:
	.loc 1 270 5 discriminator 1
	movl	-4(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	.L86
	.loc 1 274 1
	jmp	.L83
.L88:
	.loc 1 263 9
	nop
	jmp	.L83
.L89:
	.loc 1 267 9
	nop
.L83:
	.loc 1 275 5
	nop
	.loc 1 276 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE13:
	.size	cgc_bzero, .-cgc_bzero
	.globl	cgc_memset
	.type	cgc_memset, @function
cgc_memset:
.LFB14:
	.loc 1 279 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 280 20
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	.loc 1 281 11
	jmp	.L91
.L92:
	.loc 1 282 10
	movl	-4(%ebp), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	.loc 1 282 16
	movl	12(%ebp), %edx
	.loc 1 282 14
	movb	%dl, (%eax)
.L91:
	.loc 1 281 11
	subl	$1, 16(%ebp)
	cmpl	$0, 16(%ebp)
	jne	.L92
	.loc 1 283 6
	movl	-4(%ebp), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	.loc 1 283 12
	movl	12(%ebp), %edx
	.loc 1 283 10
	movb	%dl, (%eax)
	.loc 1 284 11
	movl	8(%ebp), %eax
	.loc 1 285 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE14:
	.size	cgc_memset, .-cgc_memset
	.globl	cgc_strcmp
	.type	cgc_strcmp, @function
cgc_strcmp:
.LFB15:
	.loc 1 288 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 289 11
	jmp	.L95
.L97:
	.loc 1 291 9
	addl	$1, 8(%ebp)
	.loc 1 291 14
	addl	$1, 12(%ebp)
.L95:
	.loc 1 289 13
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 289 11
	testb	%al, %al
	je	.L96
	.loc 1 289 21 discriminator 1
	movl	8(%ebp), %eax
	movzbl	(%eax), %edx
	.loc 1 289 28 discriminator 1
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 289 17 discriminator 1
	cmpb	%al, %dl
	je	.L97
.L96:
	.loc 1 293 13
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %edx
	.loc 1 293 42
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	.loc 1 293 40
	subl	%eax, %edx
	movl	%edx, %eax
	.loc 1 294 1
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE15:
	.size	cgc_strcmp, .-cgc_strcmp
	.globl	cgc_strncat
	.type	cgc_strncat, @function
cgc_strncat:
.LFB16:
	.loc 1 297 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 298 27
	subl	$12, %esp
	pushl	8(%ebp)
	call	cgc_strlen
	addl	$16, %esp
	movl	%eax, -16(%ebp)
	.loc 1 301 8
	cmpl	$0, 8(%ebp)
	je	.L100
	.loc 1 301 21 discriminator 1
	cmpl	$0, 12(%ebp)
	jne	.L101
.L100:
	.loc 1 303 13
	movl	8(%ebp), %eax
	jmp	.L102
.L101:
	.loc 1 305 12
	movl	$0, -12(%ebp)
	.loc 1 305 5
	jmp	.L103
.L105:
	.loc 1 307 29 discriminator 4
	movl	12(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	.loc 1 307 20 discriminator 4
	movl	-16(%ebp), %ecx
	movl	-12(%ebp), %edx
	addl	%edx, %ecx
	.loc 1 307 11 discriminator 4
	movl	8(%ebp), %edx
	addl	%ecx, %edx
	.loc 1 307 29 discriminator 4
	movzbl	(%eax), %eax
	.loc 1 307 24 discriminator 4
	movb	%al, (%edx)
	.loc 1 305 43 discriminator 4
	addl	$1, -12(%ebp)
.L103:
	.loc 1 305 5 discriminator 1
	movl	-12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jnb	.L104
	.loc 1 305 29 discriminator 3
	movl	12(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	.loc 1 305 23 discriminator 3
	testb	%al, %al
	jne	.L105
.L104:
	.loc 1 309 18
	movl	-16(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	.loc 1 309 9
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 309 22
	movb	$0, (%eax)
	.loc 1 311 11
	movl	8(%ebp), %eax
.L102:
	.loc 1 312 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE16:
	.size	cgc_strncat, .-cgc_strncat
	.globl	cgc_flush_input
	.type	cgc_flush_input, @function
cgc_flush_input:
.LFB17:
	.loc 1 314 29
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$1184, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
.L111:
	.loc 1 324 9
	pushl	$128
	leal	-140(%ebp), %eax
	pushl	%eax
	call	cgc_bzero
	addl	$8, %esp
	.loc 1 325 35
	movl	8(%ebp), %eax
	shrl	$5, %eax
	.loc 1 325 61
	movl	-140(%ebp,%eax,4), %edx
	.loc 1 325 74
	movl	8(%ebp), %ecx
	andl	$31, %ecx
	.loc 1 325 67
	movl	$1, %esi
	sall	%cl, %esi
	movl	%esi, %ecx
	.loc 1 325 61
	orl	%ecx, %edx
	movl	%edx, -140(%ebp,%eax,4)
	.loc 1 327 19
	movl	$0, -152(%ebp)
	.loc 1 328 20
	movl	$10, -148(%ebp)
	.loc 1 330 15
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	subl	$12, %esp
	leal	-144(%ebp), %eax
	pushl	%eax
	leal	-152(%ebp), %eax
	pushl	%eax
	pushl	$0
	leal	-140(%ebp), %eax
	pushl	%eax
	pushl	%edx
	call	cgc_fdwait@PLT
	addl	$32, %esp
	movl	%eax, -12(%ebp)
	.loc 1 331 12
	cmpl	$0, -12(%ebp)
	je	.L107
	.loc 1 332 20
	movl	-12(%ebp), %eax
	jmp	.L112
.L107:
	.loc 1 335 40
	movl	8(%ebp), %eax
	shrl	$5, %eax
	.loc 1 335 36
	movl	-140(%ebp,%eax,4), %eax
	.loc 1 335 78
	movl	8(%ebp), %edx
	andl	$31, %edx
	.loc 1 335 71
	movl	$1, %esi
	movl	%edx, %ecx
	sall	%cl, %esi
	movl	%esi, %edx
	.loc 1 335 66
	andl	%edx, %eax
	.loc 1 335 12
	testl	%eax, %eax
	je	.L114
	.loc 1 338 13
	leal	-1180(%ebp), %eax
	pushl	%eax
	pushl	$1024
	leal	-1176(%ebp), %eax
	pushl	%eax
	pushl	8(%ebp)
	call	cgc_receive@PLT
	addl	$16, %esp
	.loc 1 324 9
	jmp	.L111
.L114:
	.loc 1 336 13
	nop
	.loc 1 342 12
	movl	$0, %eax
.L112:
	.loc 1 343 1 discriminator 1
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
.LFE17:
	.size	cgc_flush_input, .-cgc_flush_input
	.globl	cgc_getline
	.type	cgc_getline, @function
cgc_getline:
.LFB18:
	.loc 1 345 55
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 348 13
	subl	$4, %esp
	pushl	12(%ebp)
	pushl	$10
	pushl	8(%ebp)
	call	cgc_receive_until
	addl	$16, %esp
	.loc 1 348 11
	movl	%eax, -12(%ebp)
	.loc 1 350 14
	movl	12(%ebp), %eax
	.loc 1 350 8
	cmpl	%eax, -12(%ebp)
	jne	.L116
	.loc 1 351 15
	movl	12(%ebp), %eax
	leal	-1(%eax), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 351 22
	movb	$0, (%eax)
	jmp	.L117
.L116:
	.loc 1 353 15
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 353 22
	movb	$0, (%eax)
.L117:
	.loc 1 356 12
	movl	-12(%ebp), %eax
	.loc 1 358 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE18:
	.size	cgc_getline, .-cgc_getline
	.globl	cgc_receive_until
	.type	cgc_receive_until, @function
cgc_receive_until:
.LFB19:
	.loc 1 360 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	movl	12(%ebp), %eax
	movb	%al, -28(%ebp)
	.loc 1 361 16
	movl	$0, -12(%ebp)
	.loc 1 362 16
	movl	$0, -16(%ebp)
	.loc 1 363 10
	movb	$0, -17(%ebp)
	.loc 1 365 10
	jmp	.L120
.L124:
	.loc 1 366 12
	movl	8(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	.loc 1 366 18
	movb	$0, (%eax)
	.loc 1 368 14
	leal	-16(%ebp), %eax
	pushl	%eax
	pushl	$1
	leal	-17(%ebp), %eax
	pushl	%eax
	pushl	$0
	call	cgc_receive@PLT
	addl	$16, %esp
	.loc 1 368 12
	testl	%eax, %eax
	je	.L121
	.loc 1 369 17
	movl	$0, -12(%ebp)
	.loc 1 370 13
	jmp	.L122
.L121:
	.loc 1 373 16
	movzbl	-17(%ebp), %eax
	.loc 1 373 12
	cmpb	%al, -28(%ebp)
	je	.L127
	.loc 1 378 12
	movl	8(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	.loc 1 378 18
	movzbl	-17(%ebp), %eax
	movb	%al, (%edx)
	.loc 1 379 12
	addl	$1, -12(%ebp)
.L120:
	.loc 1 365 10
	movl	-12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jb	.L124
	.loc 1 381 1
	jmp	.L122
.L127:
	.loc 1 375 13
	nop
.L122:
	.loc 1 383 8
	movl	-12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jne	.L125
	.loc 1 384 9
	subl	$12, %esp
	pushl	$0
	call	cgc_flush_input
	addl	$16, %esp
.L125:
	.loc 1 386 12
	movl	-12(%ebp), %eax
	.loc 1 387 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE19:
	.size	cgc_receive_until, .-cgc_receive_until
	.globl	cgc_receive_bytes
	.type	cgc_receive_bytes, @function
cgc_receive_bytes:
.LFB20:
	.loc 1 390 1
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
	.loc 1 391 12
	movl	$0, -12(%ebp)
	.loc 1 392 12
	movl	$0, -16(%ebp)
	.loc 1 393 12
	movl	$0, -20(%ebp)
	.loc 1 395 15
	movl	12(%ebp), %eax
	subl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	.loc 1 397 10
	jmp	.L129
.L132:
	.loc 1 399 35
	movl	8(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	.loc 1 399 14
	leal	-20(%ebp), %eax
	pushl	%eax
	pushl	-16(%ebp)
	pushl	%edx
	pushl	$0
	call	cgc_receive@PLT
	addl	$16, %esp
	.loc 1 399 12
	testl	%eax, %eax
	jne	.L130
	.loc 1 401 22
	movl	-20(%ebp), %eax
	subl	%eax, -16(%ebp)
	.loc 1 402 18
	movl	-20(%ebp), %eax
	addl	%eax, -12(%ebp)
	jmp	.L129
.L130:
	.loc 1 407 19
	movl	$-1, %eax
	jmp	.L133
.L129:
	.loc 1 397 10
	cmpl	$0, -16(%ebp)
	jne	.L132
	.loc 1 412 8
	movl	$0, %eax
.L133:
	.loc 1 414 1 discriminator 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE20:
	.size	cgc_receive_bytes, .-cgc_receive_bytes
	.globl	cgc_strcat
	.type	cgc_strcat, @function
cgc_strcat:
.LFB21:
	.loc 1 417 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 418 16
	movl	$0, -12(%ebp)
	.loc 1 419 16
	movl	$0, -16(%ebp)
	.loc 1 421 8
	cmpl	$0, 8(%ebp)
	je	.L141
	.loc 1 421 22 discriminator 1
	cmpl	$0, 12(%ebp)
	je	.L141
	.loc 1 425 13
	subl	$12, %esp
	pushl	8(%ebp)
	call	cgc_strlen
	addl	$16, %esp
	movl	%eax, -16(%ebp)
	.loc 1 427 5
	jmp	.L138
.L139:
	.loc 1 428 26 discriminator 2
	movl	12(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	.loc 1 428 13 discriminator 2
	movl	8(%ebp), %ecx
	movl	-16(%ebp), %edx
	addl	%ecx, %edx
	.loc 1 428 26 discriminator 2
	movzbl	(%eax), %eax
	.loc 1 428 21 discriminator 2
	movb	%al, (%edx)
	.loc 1 427 40 discriminator 2
	addl	$1, -16(%ebp)
	.loc 1 427 50 discriminator 2
	addl	$1, -12(%ebp)
.L138:
	.loc 1 427 16 discriminator 1
	movl	12(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	.loc 1 427 5 discriminator 1
	testb	%al, %al
	jne	.L139
	.loc 1 431 12
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	jmp	.L137
.L141:
	.loc 1 422 9
	nop
.L137:
	.loc 1 433 12
	movl	-12(%ebp), %eax
	.loc 1 434 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE21:
	.size	cgc_strcat, .-cgc_strcat
	.globl	cgc_strlen
	.type	cgc_strlen, @function
cgc_strlen:
.LFB22:
	.loc 1 437 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 438 16
	movl	$0, -4(%ebp)
	.loc 1 440 8
	cmpl	$0, 8(%ebp)
	je	.L148
	.loc 1 444 11
	jmp	.L145
.L146:
	.loc 1 444 35 discriminator 2
	addl	$1, -4(%ebp)
.L145:
	.loc 1 444 16 discriminator 1
	movl	8(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	.loc 1 444 11 discriminator 1
	testb	%al, %al
	jne	.L146
	.loc 1 446 1
	jmp	.L144
.L148:
	.loc 1 441 9
	nop
.L144:
	.loc 1 447 12
	movl	-4(%ebp), %eax
	.loc 1 448 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE22:
	.size	cgc_strlen, .-cgc_strlen
	.globl	cgc_itoa
	.type	cgc_itoa, @function
cgc_itoa:
.LFB23:
	.loc 1 451 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 452 16
	movl	$0, -4(%ebp)
	.loc 1 453 16
	movl	$0, -8(%ebp)
	.loc 1 454 16
	movl	$0, -12(%ebp)
	.loc 1 456 8
	cmpl	$0, 8(%ebp)
	je	.L156
	.loc 1 461 10
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
.L152:
	.loc 1 463 12 discriminator 1
	addl	$1, -8(%ebp)
	.loc 1 464 14 discriminator 1
	movl	-12(%ebp), %eax
	movl	$-858993459, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$3, %eax
	movl	%eax, -12(%ebp)
	.loc 1 465 5 discriminator 1
	cmpl	$0, -12(%ebp)
	jne	.L152
	.loc 1 468 8
	movl	-8(%ebp), %eax
	cmpl	16(%ebp), %eax
	jnb	.L157
	.loc 1 472 12
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
	.loc 1 475 8
	subl	$1, -8(%ebp)
.L154:
	.loc 1 478 25 discriminator 1
	movl	12(%ebp), %ecx
	movl	$-858993459, %edx
	movl	%ecx, %eax
	mull	%edx
	shrl	$3, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	.loc 1 478 31 discriminator 1
	movl	%edx, %eax
	leal	48(%eax), %ecx
	.loc 1 478 12 discriminator 1
	movl	8(%ebp), %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	.loc 1 478 31 discriminator 1
	movl	%ecx, %edx
	.loc 1 478 18 discriminator 1
	movb	%dl, (%eax)
	.loc 1 479 13 discriminator 1
	movl	12(%ebp), %eax
	movl	$-858993459, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$3, %eax
	movl	%eax, 12(%ebp)
	.loc 1 480 12 discriminator 1
	subl	$1, -8(%ebp)
	.loc 1 481 5 discriminator 1
	cmpl	$0, 12(%ebp)
	jne	.L154
	.loc 1 483 8
	movl	8(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	.loc 1 483 17
	movb	$0, (%eax)
	jmp	.L151
.L156:
	.loc 1 457 9
	nop
	jmp	.L151
.L157:
	.loc 1 469 9
	nop
.L151:
	.loc 1 485 12
	movl	-4(%ebp), %eax
	.loc 1 486 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE23:
	.size	cgc_itoa, .-cgc_itoa
	.section	.rodata
.LC3:
	.string	"\n"
	.text
	.globl	cgc_puts
	.type	cgc_puts, @function
cgc_puts:
.LFB24:
	.loc 1 489 1
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
	.loc 1 491 5
	pushl	8(%ebp)
	call	cgc_strlen
	addl	$4, %esp
	movl	%eax, %edx
	leal	-12(%ebp), %eax
	pushl	%eax
	pushl	%edx
	pushl	8(%ebp)
	pushl	$1
	call	cgc_transmit@PLT
	addl	$16, %esp
	.loc 1 492 5
	leal	-12(%ebp), %eax
	pushl	%eax
	pushl	$1
	leal	.LC3@GOTOFF(%ebx), %eax
	pushl	%eax
	pushl	$1
	call	cgc_transmit@PLT
	addl	$16, %esp
	.loc 1 493 1
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE24:
	.size	cgc_puts, .-cgc_puts
	.globl	cgc_strchr
	.type	cgc_strchr, @function
cgc_strchr:
.LFB25:
	.loc 1 495 40
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 496 8
	jmp	.L160
.L163:
	.loc 1 497 7
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	.loc 1 497 6
	cmpl	%eax, 12(%ebp)
	jne	.L161
	.loc 1 498 11
	movl	8(%ebp), %eax
	jmp	.L162
.L161:
	.loc 1 500 4
	addl	$1, 8(%ebp)
.L160:
	.loc 1 496 9
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 496 8
	testb	%al, %al
	jne	.L163
	.loc 1 502 6
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	.loc 1 502 5
	cmpl	%eax, 12(%ebp)
	jne	.L164
	.loc 1 503 10
	movl	8(%ebp), %eax
	jmp	.L162
.L164:
	.loc 1 505 8
	movl	$0, %eax
.L162:
	.loc 1 506 1
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE25:
	.size	cgc_strchr, .-cgc_strchr
	.globl	cgc_token
	.bss
	.align 4
	.type	cgc_token, @object
	.size	cgc_token, 4
cgc_token:
	.zero	4
	.globl	cgc_prev_str
	.align 4
	.type	cgc_prev_str, @object
	.size	cgc_prev_str, 4
cgc_prev_str:
	.zero	4
	.globl	cgc_prev_str_len
	.align 4
	.type	cgc_prev_str_len, @object
	.size	cgc_prev_str_len, 4
cgc_prev_str_len:
	.zero	4
	.globl	cgc_prev_str_ptr
	.align 4
	.type	cgc_prev_str_ptr, @object
	.size	cgc_prev_str_ptr, 4
cgc_prev_str_ptr:
	.zero	4
	.text
	.globl	cgc_strtok
	.type	cgc_strtok, @function
cgc_strtok:
.LFB26:
	.loc 1 512 48
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
	.loc 1 519 5
	cmpl	$0, 12(%ebp)
	jne	.L166
	.loc 1 520 9
	movl	$0, %eax
	jmp	.L167
.L166:
	.loc 1 524 5
	cmpl	$0, 8(%ebp)
	jne	.L168
	.loc 1 525 20
	movl	cgc_prev_str@GOTOFF(%ebx), %eax
	.loc 1 525 6
	testl	%eax, %eax
	jne	.L169
	.loc 1 526 10
	movl	$0, %eax
	jmp	.L167
.L169:
	.loc 1 529 39
	movl	cgc_prev_str@GOTOFF(%ebx), %edx
	movl	cgc_prev_str_len@GOTOFF(%ebx), %eax
	addl	%eax, %edx
	.loc 1 529 24
	movl	cgc_prev_str_ptr@GOTOFF(%ebx), %eax
	.loc 1 529 6
	cmpl	%eax, %edx
	ja	.L170
	.loc 1 530 10
	movl	$0, %eax
	jmp	.L167
.L168:
	.loc 1 534 7
	movl	cgc_prev_str@GOTOFF(%ebx), %eax
	.loc 1 534 6
	testl	%eax, %eax
	je	.L170
	.loc 1 535 4
	movl	cgc_prev_str_len@GOTOFF(%ebx), %edx
	movl	cgc_prev_str@GOTOFF(%ebx), %eax
	subl	$8, %esp
	pushl	%edx
	pushl	%eax
	call	cgc_deallocate@PLT
	addl	$16, %esp
	.loc 1 536 17
	movl	$0, cgc_prev_str@GOTOFF(%ebx)
	.loc 1 537 21
	movl	$0, cgc_prev_str_len@GOTOFF(%ebx)
	.loc 1 538 21
	movl	$0, cgc_prev_str_ptr@GOTOFF(%ebx)
.L170:
	.loc 1 543 19
	movl	cgc_prev_str@GOTOFF(%ebx), %eax
	.loc 1 543 5
	testl	%eax, %eax
	jne	.L171
	.loc 1 544 7
	subl	$12, %esp
	pushl	8(%ebp)
	call	cgc_strlen
	addl	$16, %esp
	.loc 1 544 6
	cmpl	$4096, %eax
	jbe	.L172
	.loc 1 546 10
	movl	$0, %eax
	jmp	.L167
.L172:
	.loc 1 548 22
	subl	$12, %esp
	pushl	8(%ebp)
	call	cgc_strlen
	addl	$16, %esp
	.loc 1 548 20
	movl	%eax, cgc_prev_str_len@GOTOFF(%ebx)
	.loc 1 549 7
	movl	cgc_prev_str_len@GOTOFF(%ebx), %eax
	subl	$4, %esp
	leal	cgc_prev_str@GOTOFF(%ebx), %edx
	pushl	%edx
	pushl	$0
	pushl	%eax
	call	cgc_allocate@PLT
	addl	$16, %esp
	.loc 1 549 6
	testl	%eax, %eax
	je	.L173
	.loc 1 550 10
	movl	$0, %eax
	jmp	.L167
.L173:
	.loc 1 552 3
	movl	cgc_prev_str@GOTOFF(%ebx), %eax
	subl	$8, %esp
	pushl	8(%ebp)
	pushl	%eax
	call	cgc_strcpy
	addl	$16, %esp
	.loc 1 553 20
	movl	cgc_prev_str@GOTOFF(%ebx), %eax
	movl	%eax, cgc_prev_str_ptr@GOTOFF(%ebx)
.L171:
	.loc 1 556 6
	movl	cgc_prev_str_ptr@GOTOFF(%ebx), %eax
	movl	%eax, 8(%ebp)
	.loc 1 559 8
	jmp	.L174
.L176:
	.loc 1 560 6
	addl	$1, 8(%ebp)
.L174:
	.loc 1 559 30
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 559 9
	movsbl	%al, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	12(%ebp)
	call	cgc_strchr
	addl	$16, %esp
	.loc 1 559 8
	testl	%eax, %eax
	je	.L175
	.loc 1 559 56 discriminator 1
	movl	cgc_prev_str@GOTOFF(%ebx), %edx
	movl	cgc_prev_str_len@GOTOFF(%ebx), %eax
	addl	%edx, %eax
	.loc 1 559 35 discriminator 1
	cmpl	%eax, 8(%ebp)
	jb	.L176
.L175:
	.loc 1 562 25
	movl	cgc_prev_str@GOTOFF(%ebx), %edx
	movl	cgc_prev_str_len@GOTOFF(%ebx), %eax
	addl	%edx, %eax
	.loc 1 562 5
	cmpl	%eax, 8(%ebp)
	jb	.L177
	.loc 1 563 9
	movl	$0, %eax
	jmp	.L167
.L177:
	.loc 1 567 8
	movl	8(%ebp), %eax
	movl	%eax, -20(%ebp)
	.loc 1 568 12
	subl	$12, %esp
	pushl	8(%ebp)
	call	cgc_strlen
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 568 6
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	.loc 1 569 9
	movl	$0, -16(%ebp)
	.loc 1 569 2
	jmp	.L178
.L180:
	.loc 1 570 35
	movl	-16(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	.loc 1 570 12
	movsbl	%al, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	-20(%ebp)
	call	cgc_strchr
	addl	$16, %esp
	movl	%eax, -24(%ebp)
	.loc 1 570 6
	cmpl	$0, -24(%ebp)
	je	.L179
	.loc 1 571 7
	cmpl	$0, -24(%ebp)
	je	.L179
	.loc 1 571 17 discriminator 1
	movl	-24(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jnb	.L179
	.loc 1 572 9
	movl	-24(%ebp), %eax
	movl	%eax, -12(%ebp)
.L179:
	.loc 1 569 46 discriminator 2
	addl	$1, -16(%ebp)
.L178:
	.loc 1 569 18 discriminator 1
	subl	$12, %esp
	pushl	12(%ebp)
	call	cgc_strlen
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 569 16 discriminator 1
	movl	-16(%ebp), %eax
	.loc 1 569 2 discriminator 1
	cmpl	%eax, %edx
	ja	.L180
	.loc 1 578 12
	movl	-20(%ebp), %eax
	movl	%eax, cgc_token@GOTOFF(%ebx)
	.loc 1 579 7
	movl	-12(%ebp), %eax
	movb	$0, (%eax)
	.loc 1 581 24
	movl	-12(%ebp), %eax
	addl	$1, %eax
	.loc 1 581 19
	movl	%eax, cgc_prev_str_ptr@GOTOFF(%ebx)
	.loc 1 583 8
	movl	cgc_token@GOTOFF(%ebx), %eax
.L167:
	.loc 1 584 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE26:
	.size	cgc_strtok, .-cgc_strtok
	.globl	cgc_write
	.type	cgc_write, @function
cgc_write:
.LFB27:
	.loc 1 587 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 590 2
	leal	-12(%ebp), %edx
	pushl	%edx
	pushl	12(%ebp)
	pushl	8(%ebp)
	pushl	$1
	movl	%eax, %ebx
	call	cgc_transmit@PLT
	addl	$16, %esp
	.loc 1 592 12
	movl	-12(%ebp), %eax
	.loc 1 592 5
	cmpl	%eax, 12(%ebp)
	je	.L182
	.loc 1 593 9
	movl	$-1, %eax
	jmp	.L184
.L182:
	.loc 1 595 8
	movl	-12(%ebp), %eax
.L184:
	.loc 1 597 1 discriminator 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE27:
	.size	cgc_write, .-cgc_write
	.globl	cgc_strdup
	.type	cgc_strdup, @function
cgc_strdup:
.LFB28:
	.loc 1 600 1
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
	.loc 1 603 12
	cmpl	$0, 8(%ebp)
	jne	.L186
	.loc 1 604 23
	movl	$0, %eax
	jmp	.L189
.L186:
	.loc 1 607 26
	pushl	8(%ebp)
	call	cgc_strlen
	addl	$4, %esp
	.loc 1 607 13
	leal	1(%eax), %edx
	subl	$4, %esp
	leal	-12(%ebp), %eax
	pushl	%eax
	pushl	$0
	pushl	%edx
	call	cgc_allocate@PLT
	addl	$16, %esp
	.loc 1 607 12
	testl	%eax, %eax
	je	.L188
	.loc 1 608 23
	movl	$0, %eax
	jmp	.L189
.L188:
	.loc 1 611 27
	subl	$12, %esp
	pushl	8(%ebp)
	call	cgc_strlen
	addl	$16, %esp
	.loc 1 611 9
	leal	1(%eax), %edx
	movl	-12(%ebp), %eax
	subl	$8, %esp
	pushl	%edx
	pushl	%eax
	call	cgc_bzero
	addl	$16, %esp
	.loc 1 612 9
	movl	-12(%ebp), %eax
	subl	$8, %esp
	pushl	8(%ebp)
	pushl	%eax
	call	cgc_strcpy
	addl	$16, %esp
	.loc 1 614 15
	movl	-12(%ebp), %eax
.L189:
	.loc 1 615 1 discriminator 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE28:
	.size	cgc_strdup, .-cgc_strdup
	.section	.rodata
	.align 8
.LC1:
	.long	2576980378
	.long	1069128089
	.align 8
.LC2:
	.long	0
	.long	1076101120
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB29:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE29:
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LFB30:
	.cfi_startproc
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE30:
	.text
.Letext0:
	.file 2 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/include/libcgc.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0xa31
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF453
	.byte	0xc
	.long	.LASF454
	.long	.LASF455
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.long	.Ldebug_macro0
	.uleb128 0x2
	.long	.LASF383
	.byte	0x2
	.byte	0x13
	.byte	0x17
	.long	0x35
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF381
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.long	.LASF382
	.uleb128 0x2
	.long	.LASF384
	.byte	0x2
	.byte	0x33
	.byte	0x12
	.long	0x3c
	.uleb128 0x4
	.byte	0x80
	.byte	0x2
	.byte	0x37
	.byte	0x9
	.long	0x66
	.uleb128 0x5
	.long	.LASF387
	.byte	0x2
	.byte	0x38
	.byte	0xe
	.long	0x66
	.byte	0
	.byte	0
	.uleb128 0x6
	.long	0x43
	.long	0x76
	.uleb128 0x7
	.long	0x76
	.byte	0x1f
	.byte	0
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF385
	.uleb128 0x2
	.long	.LASF386
	.byte	0x2
	.byte	0x39
	.byte	0x3
	.long	0x4f
	.uleb128 0x8
	.long	.LASF456
	.byte	0x8
	.byte	0x2
	.byte	0x4b
	.byte	0x8
	.long	0xb1
	.uleb128 0x5
	.long	.LASF388
	.byte	0x2
	.byte	0x4c
	.byte	0x9
	.long	0xb1
	.byte	0
	.uleb128 0x5
	.long	.LASF389
	.byte	0x2
	.byte	0x4d
	.byte	0x9
	.long	0xb1
	.byte	0x4
	.byte	0
	.uleb128 0x9
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF390
	.uleb128 0xa
	.long	0xb8
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF391
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF392
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF393
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF394
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF395
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF396
	.uleb128 0xb
	.long	.LASF397
	.byte	0x1
	.value	0x1fc
	.byte	0x7
	.long	0x101
	.uleb128 0x5
	.byte	0x3
	.long	cgc_token
	.uleb128 0xc
	.byte	0x4
	.long	0xb8
	.uleb128 0xb
	.long	.LASF398
	.byte	0x1
	.value	0x1fd
	.byte	0x7
	.long	0x101
	.uleb128 0x5
	.byte	0x3
	.long	cgc_prev_str
	.uleb128 0xb
	.long	.LASF399
	.byte	0x1
	.value	0x1fe
	.byte	0xe
	.long	0x76
	.uleb128 0x5
	.byte	0x3
	.long	cgc_prev_str_len
	.uleb128 0xb
	.long	.LASF400
	.byte	0x1
	.value	0x1ff
	.byte	0x7
	.long	0x101
	.uleb128 0x5
	.byte	0x3
	.long	cgc_prev_str_ptr
	.uleb128 0xd
	.long	.LASF401
	.byte	0x1
	.value	0x257
	.byte	0x7
	.long	0x101
	.long	.LFB28
	.long	.LFE28-.LFB28
	.uleb128 0x1
	.byte	0x9c
	.long	0x17a
	.uleb128 0xe
	.string	"s"
	.byte	0x1
	.value	0x257
	.byte	0x18
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xf
	.long	.LASF404
	.byte	0x1
	.value	0x259
	.byte	0xf
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xd
	.long	.LASF402
	.byte	0x1
	.value	0x24a
	.byte	0xc
	.long	0x29
	.long	.LFB27
	.long	.LFE27-.LFB27
	.uleb128 0x1
	.byte	0x9c
	.long	0x1c6
	.uleb128 0xe
	.string	"buf"
	.byte	0x1
	.value	0x24a
	.byte	0x23
	.long	0x1c6
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x10
	.long	.LASF403
	.byte	0x1
	.value	0x24a
	.byte	0x33
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xf
	.long	.LASF405
	.byte	0x1
	.value	0x24c
	.byte	0xd
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xc
	.byte	0x4
	.long	0x1cc
	.uleb128 0x11
	.uleb128 0xd
	.long	.LASF406
	.byte	0x1
	.value	0x200
	.byte	0x7
	.long	0x101
	.long	.LFB26
	.long	.LFE26-.LFB26
	.uleb128 0x1
	.byte	0x9c
	.long	0x245
	.uleb128 0xe
	.string	"str"
	.byte	0x1
	.value	0x200
	.byte	0x18
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x10
	.long	.LASF407
	.byte	0x1
	.value	0x200
	.byte	0x29
	.long	0x245
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xf
	.long	.LASF408
	.byte	0x1
	.value	0x201
	.byte	0x8
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x12
	.string	"end"
	.byte	0x1
	.value	0x202
	.byte	0x8
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x12
	.string	"t"
	.byte	0x1
	.value	0x203
	.byte	0x8
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x12
	.string	"i"
	.byte	0x1
	.value	0x204
	.byte	0x6
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0xc
	.byte	0x4
	.long	0xbf
	.uleb128 0x13
	.long	.LASF409
	.byte	0x1
	.value	0x1ef
	.byte	0x7
	.long	0x101
	.long	.LFB25
	.long	.LFE25-.LFB25
	.uleb128 0x1
	.byte	0x9c
	.long	0x283
	.uleb128 0xe
	.string	"s"
	.byte	0x1
	.value	0x1ef
	.byte	0x1e
	.long	0x245
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xe
	.string	"c"
	.byte	0x1
	.value	0x1ef
	.byte	0x25
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.byte	0
	.uleb128 0x14
	.long	.LASF430
	.byte	0x1
	.value	0x1e8
	.byte	0x6
	.long	.LFB24
	.long	.LFE24-.LFB24
	.uleb128 0x1
	.byte	0x9c
	.long	0x2b9
	.uleb128 0xe
	.string	"t"
	.byte	0x1
	.value	0x1e8
	.byte	0x16
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xf
	.long	.LASF405
	.byte	0x1
	.value	0x1ea
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x13
	.long	.LASF410
	.byte	0x1
	.value	0x1c2
	.byte	0xc
	.long	0x29
	.long	.LFB23
	.long	.LFE23-.LFB23
	.uleb128 0x1
	.byte	0x9c
	.long	0x342
	.uleb128 0xe
	.string	"out"
	.byte	0x1
	.value	0x1c2
	.byte	0x1c
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xe
	.string	"val"
	.byte	0x1
	.value	0x1c2
	.byte	0x2c
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xe
	.string	"max"
	.byte	0x1
	.value	0x1c2
	.byte	0x3c
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0xf
	.long	.LASF411
	.byte	0x1
	.value	0x1c4
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x12
	.string	"end"
	.byte	0x1
	.value	0x1c5
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0xf
	.long	.LASF412
	.byte	0x1
	.value	0x1c6
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x15
	.string	"end"
	.byte	0x1
	.value	0x1e4
	.byte	0x1
	.long	.L151
	.byte	0
	.uleb128 0x13
	.long	.LASF413
	.byte	0x1
	.value	0x1b4
	.byte	0xc
	.long	0x29
	.long	.LFB22
	.long	.LFE22-.LFB22
	.uleb128 0x1
	.byte	0x9c
	.long	0x38b
	.uleb128 0xe
	.string	"str"
	.byte	0x1
	.value	0x1b4
	.byte	0x1f
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xf
	.long	.LASF411
	.byte	0x1
	.value	0x1b6
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x15
	.string	"end"
	.byte	0x1
	.value	0x1be
	.byte	0x1
	.long	.L144
	.byte	0
	.uleb128 0xd
	.long	.LASF414
	.byte	0x1
	.value	0x1a0
	.byte	0xc
	.long	0x29
	.long	.LFB21
	.long	.LFE21-.LFB21
	.uleb128 0x1
	.byte	0x9c
	.long	0x3f4
	.uleb128 0x10
	.long	.LASF415
	.byte	0x1
	.value	0x1a0
	.byte	0x1e
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xe
	.string	"src"
	.byte	0x1
	.value	0x1a0
	.byte	0x2a
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xf
	.long	.LASF411
	.byte	0x1
	.value	0x1a2
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xf
	.long	.LASF408
	.byte	0x1
	.value	0x1a3
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x15
	.string	"end"
	.byte	0x1
	.value	0x1b0
	.byte	0x1
	.long	.L137
	.byte	0
	.uleb128 0xd
	.long	.LASF416
	.byte	0x1
	.value	0x185
	.byte	0x5
	.long	0xb1
	.long	.LFB20
	.long	.LFE20-.LFB20
	.uleb128 0x1
	.byte	0x9c
	.long	0x460
	.uleb128 0x10
	.long	.LASF417
	.byte	0x1
	.value	0x185
	.byte	0x27
	.long	0x460
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x10
	.long	.LASF405
	.byte	0x1
	.value	0x185
	.byte	0x3a
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xf
	.long	.LASF403
	.byte	0x1
	.value	0x187
	.byte	0xc
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xf
	.long	.LASF418
	.byte	0x1
	.value	0x188
	.byte	0xc
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xf
	.long	.LASF419
	.byte	0x1
	.value	0x189
	.byte	0xc
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.byte	0
	.uleb128 0xc
	.byte	0x4
	.long	0xd9
	.uleb128 0xd
	.long	.LASF420
	.byte	0x1
	.value	0x167
	.byte	0xc
	.long	0x29
	.long	.LFB19
	.long	.LFE19-.LFB19
	.uleb128 0x1
	.byte	0x9c
	.long	0x4ec
	.uleb128 0xe
	.string	"dst"
	.byte	0x1
	.value	0x167
	.byte	0x25
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x10
	.long	.LASF407
	.byte	0x1
	.value	0x167
	.byte	0x2f
	.long	0xb8
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0xe
	.string	"max"
	.byte	0x1
	.value	0x167
	.byte	0x41
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x12
	.string	"len"
	.byte	0x1
	.value	0x169
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x12
	.string	"rx"
	.byte	0x1
	.value	0x16a
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x12
	.string	"c"
	.byte	0x1
	.value	0x16b
	.byte	0xa
	.long	0xb8
	.uleb128 0x2
	.byte	0x91
	.sleb128 -25
	.uleb128 0x15
	.string	"end"
	.byte	0x1
	.value	0x17d
	.byte	0x1
	.long	.L122
	.byte	0
	.uleb128 0xd
	.long	.LASF421
	.byte	0x1
	.value	0x159
	.byte	0xc
	.long	0x29
	.long	.LFB18
	.long	.LFE18-.LFB18
	.uleb128 0x1
	.byte	0x9c
	.long	0x538
	.uleb128 0x10
	.long	.LASF417
	.byte	0x1
	.value	0x159
	.byte	0x1f
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xe
	.string	"len"
	.byte	0x1
	.value	0x159
	.byte	0x32
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xf
	.long	.LASF403
	.byte	0x1
	.value	0x15a
	.byte	0x5
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xd
	.long	.LASF422
	.byte	0x1
	.value	0x13a
	.byte	0x5
	.long	0xb1
	.long	.LFB17
	.long	.LFE17-.LFB17
	.uleb128 0x1
	.byte	0x9c
	.long	0x5c7
	.uleb128 0xe
	.string	"fd"
	.byte	0x1
	.value	0x13a
	.byte	0x19
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xf
	.long	.LASF423
	.byte	0x1
	.value	0x13b
	.byte	0x10
	.long	0x7d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -148
	.uleb128 0x12
	.string	"err"
	.byte	0x1
	.value	0x13c
	.byte	0x9
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xf
	.long	.LASF424
	.byte	0x1
	.value	0x13d
	.byte	0x9
	.long	0xb1
	.uleb128 0x3
	.byte	0x91
	.sleb128 -152
	.uleb128 0x12
	.string	"tv"
	.byte	0x1
	.value	0x13e
	.byte	0x18
	.long	0x89
	.uleb128 0x3
	.byte	0x91
	.sleb128 -160
	.uleb128 0xf
	.long	.LASF417
	.byte	0x1
	.value	0x13f
	.byte	0xa
	.long	0x5c7
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1184
	.uleb128 0xf
	.long	.LASF425
	.byte	0x1
	.value	0x140
	.byte	0x10
	.long	0x29
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1188
	.byte	0
	.uleb128 0x6
	.long	0xb8
	.long	0x5d8
	.uleb128 0x16
	.long	0x76
	.value	0x3ff
	.byte	0
	.uleb128 0xd
	.long	.LASF426
	.byte	0x1
	.value	0x128
	.byte	0x7
	.long	0x101
	.long	.LFB16
	.long	.LFE16-.LFB16
	.uleb128 0x1
	.byte	0x9c
	.long	0x640
	.uleb128 0x10
	.long	.LASF415
	.byte	0x1
	.value	0x128
	.byte	0x1b
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xe
	.string	"src"
	.byte	0x1
	.value	0x128
	.byte	0x2d
	.long	0x245
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xe
	.string	"n"
	.byte	0x1
	.value	0x128
	.byte	0x3d
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0xf
	.long	.LASF427
	.byte	0x1
	.value	0x12a
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x12
	.string	"i"
	.byte	0x1
	.value	0x12b
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x13
	.long	.LASF428
	.byte	0x1
	.value	0x11f
	.byte	0x5
	.long	0xb1
	.long	.LFB15
	.long	.LFE15-.LFB15
	.uleb128 0x1
	.byte	0x9c
	.long	0x67a
	.uleb128 0xe
	.string	"s1"
	.byte	0x1
	.value	0x11f
	.byte	0x1d
	.long	0x245
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xe
	.string	"s2"
	.byte	0x1
	.value	0x11f
	.byte	0x2d
	.long	0x245
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.byte	0
	.uleb128 0x13
	.long	.LASF429
	.byte	0x1
	.value	0x116
	.byte	0x7
	.long	0x6ce
	.long	.LFB14
	.long	.LFE14-.LFB14
	.uleb128 0x1
	.byte	0x9c
	.long	0x6ce
	.uleb128 0xe
	.string	"s"
	.byte	0x1
	.value	0x116
	.byte	0x18
	.long	0x6ce
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xe
	.string	"c"
	.byte	0x1
	.value	0x116
	.byte	0x1f
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xe
	.string	"n"
	.byte	0x1
	.value	0x116
	.byte	0x2d
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x12
	.string	"t"
	.byte	0x1
	.value	0x118
	.byte	0x14
	.long	0x460
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0x17
	.byte	0x4
	.uleb128 0x18
	.long	.LASF431
	.byte	0x1
	.value	0x101
	.byte	0x6
	.long	.LFB13
	.long	.LFE13-.LFB13
	.uleb128 0x1
	.byte	0x9c
	.long	0x733
	.uleb128 0x10
	.long	.LASF432
	.byte	0x1
	.value	0x101
	.byte	0x17
	.long	0x6ce
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xe
	.string	"len"
	.byte	0x1
	.value	0x101
	.byte	0x28
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xf
	.long	.LASF433
	.byte	0x1
	.value	0x103
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x12
	.string	"c"
	.byte	0x1
	.value	0x104
	.byte	0x14
	.long	0x460
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x15
	.string	"end"
	.byte	0x1
	.value	0x112
	.byte	0x1
	.long	.L83
	.byte	0
	.uleb128 0x19
	.long	.LASF434
	.byte	0x1
	.byte	0xf5
	.byte	0x7
	.long	0x101
	.long	.LFB12
	.long	.LFE12-.LFB12
	.uleb128 0x1
	.byte	0x9c
	.long	0x786
	.uleb128 0x1a
	.long	.LASF415
	.byte	0x1
	.byte	0xf5
	.byte	0x1a
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x1b
	.string	"src"
	.byte	0x1
	.byte	0xf5
	.byte	0x2c
	.long	0x245
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x1b
	.string	"n"
	.byte	0x1
	.byte	0xf5
	.byte	0x3c
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x1c
	.string	"i"
	.byte	0x1
	.byte	0xf7
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0x19
	.long	.LASF435
	.byte	0x1
	.byte	0xe5
	.byte	0x7
	.long	0x101
	.long	.LFB11
	.long	.LFE11-.LFB11
	.uleb128 0x1
	.byte	0x9c
	.long	0x7cc
	.uleb128 0x1a
	.long	.LASF415
	.byte	0x1
	.byte	0xe5
	.byte	0x19
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x1b
	.string	"src"
	.byte	0x1
	.byte	0xe5
	.byte	0x25
	.long	0x101
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x1c
	.string	"i"
	.byte	0x1
	.byte	0xe7
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0x1d
	.long	.LASF436
	.byte	0x1
	.byte	0xa8
	.byte	0x5
	.long	0xb1
	.long	.LFB10
	.long	.LFE10-.LFB10
	.uleb128 0x1
	.byte	0x9c
	.long	0x832
	.uleb128 0x1b
	.string	"str"
	.byte	0x1
	.byte	0xa8
	.byte	0x1a
	.long	0x245
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x1e
	.long	.LASF437
	.byte	0x1
	.byte	0xad
	.byte	0x9
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x1e
	.long	.LASF438
	.byte	0x1
	.byte	0xae
	.byte	0x9
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x1e
	.long	.LASF439
	.byte	0x1
	.byte	0xaf
	.byte	0x9
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x1e
	.long	.LASF440
	.byte	0x1
	.byte	0xb0
	.byte	0x9
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x1d
	.long	.LASF441
	.byte	0x1
	.byte	0x63
	.byte	0x8
	.long	0x898
	.long	.LFB9
	.long	.LFE9-.LFB9
	.uleb128 0x1
	.byte	0x9c
	.long	0x898
	.uleb128 0x1b
	.string	"str"
	.byte	0x1
	.byte	0x63
	.byte	0x1d
	.long	0x245
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x1c
	.string	"val"
	.byte	0x1
	.byte	0x68
	.byte	0xc
	.long	0x898
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x1e
	.long	.LASF442
	.byte	0x1
	.byte	0x69
	.byte	0xc
	.long	0x898
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x1e
	.long	.LASF438
	.byte	0x1
	.byte	0x6a
	.byte	0x9
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x1e
	.long	.LASF439
	.byte	0x1
	.byte	0x6b
	.byte	0x9
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.byte	0
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.long	.LASF443
	.uleb128 0x19
	.long	.LASF444
	.byte	0x1
	.byte	0x5e
	.byte	0x5
	.long	0xb1
	.long	.LFB8
	.long	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.long	0x8c9
	.uleb128 0x1b
	.string	"val"
	.byte	0x1
	.byte	0x5e
	.byte	0x17
	.long	0x898
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.uleb128 0x19
	.long	.LASF445
	.byte	0x1
	.byte	0x59
	.byte	0x5
	.long	0xb1
	.long	.LFB7
	.long	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.long	0x8f3
	.uleb128 0x1b
	.string	"val"
	.byte	0x1
	.byte	0x59
	.byte	0x17
	.long	0x898
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.uleb128 0x19
	.long	.LASF446
	.byte	0x1
	.byte	0x51
	.byte	0x5
	.long	0xb1
	.long	.LFB6
	.long	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0x91b
	.uleb128 0x1b
	.string	"c"
	.byte	0x1
	.byte	0x51
	.byte	0x16
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.uleb128 0x19
	.long	.LASF447
	.byte	0x1
	.byte	0x44
	.byte	0x5
	.long	0xb1
	.long	.LFB5
	.long	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0x943
	.uleb128 0x1b
	.string	"c"
	.byte	0x1
	.byte	0x44
	.byte	0x16
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.uleb128 0x1d
	.long	.LASF448
	.byte	0x1
	.byte	0x3f
	.byte	0x5
	.long	0xb1
	.long	.LFB4
	.long	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x96b
	.uleb128 0x1b
	.string	"c"
	.byte	0x1
	.byte	0x3f
	.byte	0x16
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.uleb128 0x1d
	.long	.LASF449
	.byte	0x1
	.byte	0x3a
	.byte	0x5
	.long	0xb1
	.long	.LFB3
	.long	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x993
	.uleb128 0x1b
	.string	"c"
	.byte	0x1
	.byte	0x3a
	.byte	0x16
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.uleb128 0x19
	.long	.LASF450
	.byte	0x1
	.byte	0x32
	.byte	0x5
	.long	0xb1
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x9bb
	.uleb128 0x1b
	.string	"c"
	.byte	0x1
	.byte	0x32
	.byte	0x16
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.uleb128 0x19
	.long	.LASF451
	.byte	0x1
	.byte	0x2a
	.byte	0x5
	.long	0xb1
	.long	.LFB1
	.long	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x9e3
	.uleb128 0x1b
	.string	"c"
	.byte	0x1
	.byte	0x2a
	.byte	0x16
	.long	0xb1
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.uleb128 0x1f
	.long	.LASF452
	.byte	0x1
	.byte	0x1e
	.byte	0x5
	.long	0xb1
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x1a
	.long	.LASF415
	.byte	0x1
	.byte	0x1e
	.byte	0x17
	.long	0x6ce
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x1b
	.string	"src"
	.byte	0x1
	.byte	0x1e
	.byte	0x23
	.long	0x6ce
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x1b
	.string	"n"
	.byte	0x1
	.byte	0x1e
	.byte	0x33
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x1e
	.long	.LASF433
	.byte	0x1
	.byte	0x20
	.byte	0x14
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
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
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xd
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
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
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
	.uleb128 0xa
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
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
	.uleb128 0x3f
	.uleb128 0x19
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
	.uleb128 0xe
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
	.uleb128 0xf
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
	.uleb128 0x10
	.uleb128 0x5
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
	.uleb128 0x11
	.uleb128 0x26
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x12
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
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
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
	.uleb128 0x15
	.uleb128 0xa
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x18
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
	.uleb128 0x19
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
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
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
	.uleb128 0x1b
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
	.uleb128 0x1c
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
	.uleb128 0x1d
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
	.uleb128 0x1e
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
	.uleb128 0x1f
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
	.uleb128 0x2117
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
	.file 3 "/usr/include/stdc-predef.h"
	.byte	0x3
	.uleb128 0x5
	.uleb128 0x3
	.byte	0x7
	.long	.Ldebug_macro2
	.byte	0x4
	.byte	0x3
	.uleb128 0x1a
	.uleb128 0x2
	.byte	0x7
	.long	.Ldebug_macro3
	.byte	0x4
	.file 4 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/cgc_stdlib.h"
	.byte	0x3
	.uleb128 0x1b
	.uleb128 0x4
	.byte	0x7
	.long	.Ldebug_macro4
	.byte	0x4
	.file 5 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/cgc_stdint.h"
	.byte	0x3
	.uleb128 0x1c
	.uleb128 0x5
	.byte	0x5
	.uleb128 0x1b
	.long	.LASF380
	.byte	0x4
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
	.section	.debug_macro,"G",@progbits,wm4.cgc_stdlib.h.27.88ff704b8b47df49cfc97b2f92fbc251,comdat
.Ldebug_macro4:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1b
	.long	.LASF377
	.byte	0x5
	.uleb128 0x1d
	.long	.LASF378
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF379
	.byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF441:
	.string	"cgc_atof"
.LASF436:
	.string	"cgc_atoi"
.LASF187:
	.string	"__LDBL_MAX__ 1.18973149535723176502126385303097021e+4932L"
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
.LASF449:
	.string	"cgc_isalpha"
.LASF276:
	.string	"__DEC64_EPSILON__ 1E-15DD"
.LASF175:
	.string	"__DBL_DENORM_MIN__ ((double)4.94065645841246544176568792868221372e-324L)"
.LASF194:
	.string	"__FLT32_MANT_DIG__ 24"
.LASF390:
	.string	"char"
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
.LASF318:
	.string	"__i686__ 1"
.LASF243:
	.string	"__FLT32X_MAX__ 1.79769313486231570814527423731704357e+308F32x"
.LASF307:
	.string	"__SIZEOF_WINT_T__ 4"
.LASF417:
	.string	"buffer"
.LASF356:
	.string	"CGC_FD_SET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] |= (1 << (b & (CGC__NFDBITS - 1))))"
.LASF6:
	.string	"__GNUC_MINOR__ 4"
.LASF402:
	.string	"cgc_write"
.LASF419:
	.string	"rxbytes"
.LASF43:
	.string	"__CHAR32_TYPE__ unsigned int"
.LASF385:
	.string	"unsigned int"
.LASF216:
	.string	"__FLT64_MIN__ 2.22507385850720138309023271733240406e-308F64"
.LASF89:
	.string	"__LONG_LONG_WIDTH__ 64"
.LASF398:
	.string	"cgc_prev_str"
.LASF42:
	.string	"__CHAR16_TYPE__ short unsigned int"
.LASF375:
	.string	"ENOSYS CGC_ENOSYS"
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
.LASF269:
	.string	"__DEC32_EPSILON__ 1E-6DF"
.LASF180:
	.string	"__LDBL_DIG__ 18"
.LASF400:
	.string	"cgc_prev_str_ptr"
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
.LASF387:
	.string	"_fd_bits"
.LASF97:
	.string	"__UINTMAX_C(c) c ## ULL"
.LASF301:
	.string	"__GCC_ATOMIC_LLONG_LOCK_FREE 2"
.LASF79:
	.string	"__WCHAR_MAX__ 0x7fffffffL"
.LASF347:
	.string	"STD_SIZE_T unsigned int"
.LASF33:
	.string	"__BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__"
.LASF270:
	.string	"__DEC32_SUBNORMAL_MIN__ 0.000001E-95DF"
.LASF327:
	.string	"linux 1"
.LASF197:
	.string	"__FLT32_MIN_10_EXP__ (-37)"
.LASF176:
	.string	"__DBL_HAS_DENORM__ 1"
.LASF371:
	.string	"EBADF CGC_EBADF"
.LASF80:
	.string	"__WCHAR_MIN__ (-__WCHAR_MAX__ - 1)"
.LASF3:
	.string	"__STDC_UTF_32__ 1"
.LASF367:
	.string	"FD_ZERO CGC_FD_ZERO"
.LASF113:
	.string	"__INT_LEAST16_MAX__ 0x7fff"
.LASF74:
	.string	"__SCHAR_MAX__ 0x7f"
.LASF284:
	.string	"__DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL"
.LASF209:
	.string	"__FLT64_DIG__ 15"
.LASF61:
	.string	"__INT_FAST8_TYPE__ signed char"
.LASF18:
	.string	"__PIE__ 2"
.LASF311:
	.string	"i386 1"
.LASF84:
	.string	"__SIZE_MAX__ 0xffffffffU"
.LASF234:
	.string	"__FLT128_HAS_INFINITY__ 1"
.LASF57:
	.string	"__UINT_LEAST8_TYPE__ unsigned char"
.LASF450:
	.string	"cgc_isupper"
.LASF362:
	.string	"CGC_ENOMEM 4"
.LASF343:
	.string	"STDIN 0"
.LASF73:
	.string	"__GXX_ABI_VERSION 1013"
.LASF292:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1"
.LASF64:
	.string	"__INT_FAST64_TYPE__ long long int"
.LASF235:
	.string	"__FLT128_HAS_QUIET_NAN__ 1"
.LASF229:
	.string	"__FLT128_MAX__ 1.18973149535723176508575932662800702e+4932F128"
.LASF251:
	.string	"__FLT64X_DIG__ 18"
.LASF115:
	.string	"__INT_LEAST16_WIDTH__ 16"
.LASF429:
	.string	"cgc_memset"
.LASF365:
	.string	"FD_SETSIZE CGC_FD_SETSIZE"
.LASF407:
	.string	"delim"
.LASF205:
	.string	"__FLT32_HAS_DENORM__ 1"
.LASF405:
	.string	"size"
.LASF289:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1"
.LASF252:
	.string	"__FLT64X_MIN_EXP__ (-16381)"
.LASF136:
	.string	"__INT_FAST64_MAX__ 0x7fffffffffffffffLL"
.LASF152:
	.string	"__FLT_DIG__ 6"
.LASF121:
	.string	"__INT_LEAST64_WIDTH__ 64"
.LASF293:
	.string	"__GCC_ATOMIC_BOOL_LOCK_FREE 2"
.LASF17:
	.string	"__pie__ 2"
.LASF267:
	.string	"__DEC32_MIN__ 1E-95DF"
.LASF403:
	.string	"count"
.LASF433:
	.string	"index"
.LASF384:
	.string	"_fd_mask"
.LASF416:
	.string	"cgc_receive_bytes"
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
.LASF396:
	.string	"long long unsigned int"
.LASF279:
	.string	"__DEC128_MIN_EXP__ (-6142)"
.LASF444:
	.string	"cgc_isinf"
.LASF430:
	.string	"cgc_puts"
.LASF102:
	.string	"__INT8_MAX__ 0x7f"
.LASF439:
	.string	"part"
.LASF283:
	.string	"__DEC128_EPSILON__ 1E-33DL"
.LASF316:
	.string	"__GCC_ASM_FLAG_OUTPUTS__ 1"
.LASF226:
	.string	"__FLT128_MAX_EXP__ 16384"
.LASF128:
	.string	"__UINT_LEAST64_MAX__ 0xffffffffffffffffULL"
.LASF150:
	.string	"__FLT_RADIX__ 2"
.LASF26:
	.string	"__SIZEOF_LONG_DOUBLE__ 12"
.LASF202:
	.string	"__FLT32_MIN__ 1.17549435082228750796873653722224568e-38F32"
.LASF178:
	.string	"__DBL_HAS_QUIET_NAN__ 1"
.LASF190:
	.string	"__LDBL_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951L"
.LASF231:
	.string	"__FLT128_EPSILON__ 1.92592994438723585305597794258492732e-34F128"
.LASF220:
	.string	"__FLT64_HAS_INFINITY__ 1"
.LASF138:
	.string	"__UINT_FAST8_MAX__ 0xff"
.LASF315:
	.string	"__ATOMIC_HLE_RELEASE 131072"
.LASF183:
	.string	"__LDBL_MAX_EXP__ 16384"
.LASF425:
	.string	"rcv_cnt"
.LASF426:
	.string	"cgc_strncat"
.LASF70:
	.string	"__UINTPTR_TYPE__ unsigned int"
.LASF275:
	.string	"__DEC64_MAX__ 9.999999999999999E384DD"
.LASF299:
	.string	"__GCC_ATOMIC_INT_LOCK_FREE 2"
.LASF94:
	.string	"__INTMAX_MAX__ 0x7fffffffffffffffLL"
.LASF424:
	.string	"ready_fd"
.LASF222:
	.string	"__FLT128_MANT_DIG__ 113"
.LASF30:
	.string	"__ORDER_LITTLE_ENDIAN__ 1234"
.LASF308:
	.string	"__SIZEOF_PTRDIFF_T__ 4"
.LASF305:
	.string	"__PRAGMA_REDEFINE_EXTNAME 1"
.LASF432:
	.string	"buff"
.LASF278:
	.string	"__DEC128_MANT_DIG__ 34"
.LASF188:
	.string	"__LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L"
.LASF352:
	.string	"SIZE_MAX (~((cgc_size_t)0ULL))"
.LASF386:
	.string	"cgc_fd_set"
.LASF47:
	.string	"__INT32_TYPE__ int"
.LASF409:
	.string	"cgc_strchr"
.LASF397:
	.string	"cgc_token"
.LASF261:
	.string	"__FLT64X_HAS_DENORM__ 1"
.LASF266:
	.string	"__DEC32_MAX_EXP__ 97"
.LASF8:
	.string	"__VERSION__ \"8.4.0\""
.LASF359:
	.string	"CGC_EBADF 1"
.LASF336:
	.string	"errno __cgc_errno"
.LASF253:
	.string	"__FLT64X_MIN_10_EXP__ (-4931)"
.LASF99:
	.string	"__SIG_ATOMIC_MAX__ 0x7fffffff"
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
.LASF172:
	.string	"__DBL_MAX__ ((double)1.79769313486231570814527423731704357e+308L)"
.LASF389:
	.string	"tv_usec"
.LASF353:
	.string	"CGC_FD_SETSIZE 1024"
.LASF62:
	.string	"__INT_FAST16_TYPE__ int"
.LASF223:
	.string	"__FLT128_DIG__ 33"
.LASF50:
	.string	"__UINT16_TYPE__ short unsigned int"
.LASF90:
	.string	"__WCHAR_WIDTH__ 32"
.LASF287:
	.string	"__GNUC_STDC_INLINE__ 1"
.LASF246:
	.string	"__FLT32X_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F32x"
.LASF29:
	.string	"__BIGGEST_ALIGNMENT__ 16"
.LASF78:
	.string	"__LONG_LONG_MAX__ 0x7fffffffffffffffLL"
.LASF48:
	.string	"__INT64_TYPE__ long long int"
.LASF156:
	.string	"__FLT_MAX_10_EXP__ 38"
.LASF245:
	.string	"__FLT32X_EPSILON__ 2.22044604925031308084726333618164062e-16F32x"
.LASF445:
	.string	"cgc_isnan"
.LASF288:
	.string	"__NO_INLINE__ 1"
.LASF355:
	.string	"CGC_FD_ZERO(set) do { int __i; for (__i = 0; __i < (CGC_FD_SETSIZE / CGC__NFDBITS); __i++) (set)->_fd_bits[__i] = 0; } while (0)"
.LASF151:
	.string	"__FLT_MANT_DIG__ 24"
.LASF214:
	.string	"__FLT64_DECIMAL_DIG__ 17"
.LASF285:
	.string	"__REGISTER_PREFIX__ "
.LASF52:
	.string	"__UINT64_TYPE__ long long unsigned int"
.LASF196:
	.string	"__FLT32_MIN_EXP__ (-125)"
.LASF454:
	.string	"/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/stdlib.c"
.LASF139:
	.string	"__UINT_FAST16_MAX__ 0xffffffffU"
.LASF66:
	.string	"__UINT_FAST16_TYPE__ unsigned int"
.LASF198:
	.string	"__FLT32_MAX_EXP__ 128"
.LASF168:
	.string	"__DBL_MIN_10_EXP__ (-307)"
.LASF431:
	.string	"cgc_bzero"
.LASF182:
	.string	"__LDBL_MIN_10_EXP__ (-4931)"
.LASF377:
	.string	"__STDLIB_H__ "
.LASF195:
	.string	"__FLT32_DIG__ 6"
.LASF219:
	.string	"__FLT64_HAS_DENORM__ 1"
.LASF321:
	.string	"__code_model_32__ 1"
.LASF335:
	.string	"NPATCHED 1"
.LASF247:
	.string	"__FLT32X_HAS_DENORM__ 1"
.LASF349:
	.string	"CGC_FLAG_PAGE_ADDRESS 0x4347C000"
.LASF361:
	.string	"CGC_EINVAL 3"
.LASF254:
	.string	"__FLT64X_MAX_EXP__ 16384"
.LASF119:
	.string	"__INT_LEAST64_MAX__ 0x7fffffffffffffffLL"
.LASF257:
	.string	"__FLT64X_MAX__ 1.18973149535723176502126385303097021e+4932F64x"
.LASF272:
	.string	"__DEC64_MIN_EXP__ (-382)"
.LASF354:
	.string	"CGC__NFDBITS (8 * sizeof(_fd_mask))"
.LASF112:
	.string	"__INT_LEAST8_WIDTH__ 8"
.LASF106:
	.string	"__UINT8_MAX__ 0xff"
.LASF107:
	.string	"__UINT16_MAX__ 0xffff"
.LASF363:
	.string	"CGC_ENOSYS 5"
.LASF98:
	.string	"__INTMAX_WIDTH__ 64"
.LASF268:
	.string	"__DEC32_MAX__ 9.999999E96DF"
.LASF54:
	.string	"__INT_LEAST16_TYPE__ short int"
.LASF422:
	.string	"cgc_flush_input"
.LASF324:
	.string	"__gnu_linux__ 1"
.LASF294:
	.string	"__GCC_ATOMIC_CHAR_LOCK_FREE 2"
.LASF111:
	.string	"__INT8_C(c) c"
.LASF295:
	.string	"__GCC_ATOMIC_CHAR16_T_LOCK_FREE 2"
.LASF310:
	.string	"__i386__ 1"
.LASF421:
	.string	"cgc_getline"
.LASF300:
	.string	"__GCC_ATOMIC_LONG_LOCK_FREE 2"
.LASF237:
	.string	"__FLT32X_DIG__ 15"
.LASF404:
	.string	"retval"
.LASF236:
	.string	"__FLT32X_MANT_DIG__ 53"
.LASF393:
	.string	"long long int"
.LASF255:
	.string	"__FLT64X_MAX_10_EXP__ 4932"
.LASF173:
	.string	"__DBL_MIN__ ((double)2.22507385850720138309023271733240406e-308L)"
.LASF143:
	.string	"__INTPTR_WIDTH__ 32"
.LASF108:
	.string	"__UINT32_MAX__ 0xffffffffU"
.LASF19:
	.string	"__FINITE_MATH_ONLY__ 0"
.LASF215:
	.string	"__FLT64_MAX__ 1.79769313486231570814527423731704357e+308F64"
.LASF406:
	.string	"cgc_strtok"
.LASF322:
	.string	"__SEG_FS 1"
.LASF451:
	.string	"cgc_islower"
.LASF420:
	.string	"cgc_receive_until"
.LASF280:
	.string	"__DEC128_MAX_EXP__ 6145"
.LASF440:
	.string	"digit_count"
.LASF244:
	.string	"__FLT32X_MIN__ 2.22507385850720138309023271733240406e-308F32x"
.LASF114:
	.string	"__INT16_C(c) c"
.LASF304:
	.string	"__GCC_HAVE_DWARF2_CFI_ASM 1"
.LASF369:
	.string	"FD_CLR CGC_FD_CLR"
.LASF109:
	.string	"__UINT64_MAX__ 0xffffffffffffffffULL"
.LASF134:
	.string	"__INT_FAST32_MAX__ 0x7fffffff"
.LASF263:
	.string	"__FLT64X_HAS_QUIET_NAN__ 1"
.LASF163:
	.string	"__FLT_HAS_INFINITY__ 1"
.LASF105:
	.string	"__INT64_MAX__ 0x7fffffffffffffffLL"
.LASF442:
	.string	"scale"
.LASF0:
	.string	"__STDC__ 1"
.LASF399:
	.string	"cgc_prev_str_len"
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
.LASF401:
	.string	"cgc_strdup"
.LASF25:
	.string	"__SIZEOF_DOUBLE__ 8"
.LASF7:
	.string	"__GNUC_PATCHLEVEL__ 0"
.LASF452:
	.string	"cgc_memcpy"
.LASF339:
	.string	"__STDC_IEC_559_COMPLEX__ 1"
.LASF82:
	.string	"__WINT_MIN__ 0U"
.LASF179:
	.string	"__LDBL_MANT_DIG__ 64"
.LASF2:
	.string	"__STDC_UTF_16__ 1"
.LASF189:
	.string	"__LDBL_EPSILON__ 1.08420217248550443400745280086994171e-19L"
.LASF344:
	.string	"STDOUT 1"
.LASF192:
	.string	"__LDBL_HAS_INFINITY__ 1"
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
.LASF290:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1"
.LASF93:
	.string	"__SIZE_WIDTH__ 32"
.LASF264:
	.string	"__DEC32_MANT_DIG__ 7"
.LASF331:
	.string	"__ELF__ 1"
.LASF204:
	.string	"__FLT32_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F32"
.LASF100:
	.string	"__SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)"
.LASF410:
	.string	"cgc_itoa"
.LASF104:
	.string	"__INT32_MAX__ 0x7fffffff"
.LASF88:
	.string	"__LONG_WIDTH__ 32"
.LASF11:
	.string	"__ATOMIC_ACQUIRE 2"
.LASF125:
	.string	"__UINT16_C(c) c"
.LASF323:
	.string	"__SEG_GS 1"
.LASF317:
	.string	"__i686 1"
.LASF319:
	.string	"__pentiumpro 1"
.LASF41:
	.string	"__UINTMAX_TYPE__ long long unsigned int"
.LASF427:
	.string	"dest_len"
.LASF428:
	.string	"cgc_strcmp"
.LASF101:
	.string	"__SIG_ATOMIC_WIDTH__ 32"
.LASF75:
	.string	"__SHRT_MAX__ 0x7fff"
.LASF297:
	.string	"__GCC_ATOMIC_WCHAR_T_LOCK_FREE 2"
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
.LASF258:
	.string	"__FLT64X_MIN__ 3.36210314311209350626267781732175260e-4932F64x"
.LASF130:
	.string	"__INT_FAST8_MAX__ 0x7f"
.LASF20:
	.string	"__SIZEOF_INT__ 4"
.LASF203:
	.string	"__FLT32_EPSILON__ 1.19209289550781250000000000000000000e-7F32"
.LASF199:
	.string	"__FLT32_MAX_10_EXP__ 38"
.LASF392:
	.string	"short int"
.LASF350:
	.string	"offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)"
.LASF273:
	.string	"__DEC64_MAX_EXP__ 385"
.LASF309:
	.string	"__i386 1"
.LASF239:
	.string	"__FLT32X_MIN_10_EXP__ (-307)"
.LASF413:
	.string	"cgc_strlen"
.LASF382:
	.string	"long int"
.LASF277:
	.string	"__DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD"
.LASF262:
	.string	"__FLT64X_HAS_INFINITY__ 1"
.LASF411:
	.string	"length"
.LASF281:
	.string	"__DEC128_MIN__ 1E-6143DL"
.LASF238:
	.string	"__FLT32X_MIN_EXP__ (-1021)"
.LASF329:
	.string	"__unix__ 1"
.LASF65:
	.string	"__UINT_FAST8_TYPE__ unsigned char"
.LASF117:
	.string	"__INT32_C(c) c"
.LASF357:
	.string	"CGC_FD_CLR(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] &= ~(1 << (b & (CGC__NFDBITS - 1))))"
.LASF193:
	.string	"__LDBL_HAS_QUIET_NAN__ 1"
.LASF412:
	.string	"temp"
.LASF81:
	.string	"__WINT_MAX__ 0xffffffffU"
.LASF325:
	.string	"__linux 1"
.LASF372:
	.string	"EFAULT CGC_EFAULT"
.LASF51:
	.string	"__UINT32_TYPE__ unsigned int"
.LASF360:
	.string	"CGC_EFAULT 2"
.LASF415:
	.string	"dest"
.LASF141:
	.string	"__UINT_FAST64_MAX__ 0xffffffffffffffffULL"
.LASF140:
	.string	"__UINT_FAST32_MAX__ 0xffffffffU"
.LASF438:
	.string	"sign"
.LASF120:
	.string	"__INT64_C(c) c ## LL"
.LASF334:
	.string	"LINUX 1"
.LASF379:
	.string	"FREE_FLAG 2"
.LASF22:
	.string	"__SIZEOF_LONG_LONG__ 8"
.LASF49:
	.string	"__UINT8_TYPE__ unsigned char"
.LASF86:
	.string	"__SHRT_WIDTH__ 16"
.LASF56:
	.string	"__INT_LEAST64_TYPE__ long long int"
.LASF408:
	.string	"start"
.LASF35:
	.string	"__SIZEOF_POINTER__ 4"
.LASF446:
	.string	"cgc_isdigit"
.LASF217:
	.string	"__FLT64_EPSILON__ 2.22044604925031308084726333618164062e-16F64"
.LASF456:
	.string	"cgc_timeval"
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
.LASF437:
	.string	"integer_part"
.LASF447:
	.string	"cgc_isspace"
.LASF388:
	.string	"tv_sec"
.LASF286:
	.string	"__USER_LABEL_PREFIX__ "
.LASF381:
	.string	"long unsigned int"
.LASF296:
	.string	"__GCC_ATOMIC_CHAR32_T_LOCK_FREE 2"
.LASF1:
	.string	"__STDC_VERSION__ 199901L"
.LASF328:
	.string	"__unix 1"
.LASF351:
	.string	"SSIZE_MAX ((cgc_ssize_t)((~((cgc_size_t)0ULL))>>1))"
.LASF28:
	.string	"__CHAR_BIT__ 8"
.LASF9:
	.string	"__ATOMIC_RELAXED 0"
.LASF4:
	.string	"__STDC_HOSTED__ 1"
.LASF142:
	.string	"__INTPTR_MAX__ 0x7fffffff"
.LASF340:
	.string	"__STDC_ISO_10646__ 201706L"
.LASF71:
	.string	"__has_include(STR) __has_include__(STR)"
.LASF366:
	.string	"_NFDBITS CGC__NFDBITS"
.LASF434:
	.string	"cgc_strncpy"
.LASF342:
	.string	"_LIBCGC_H "
.LASF291:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1"
.LASF155:
	.string	"__FLT_MAX_EXP__ 128"
.LASF13:
	.string	"__ATOMIC_ACQ_REL 4"
.LASF394:
	.string	"unsigned char"
.LASF265:
	.string	"__DEC32_MIN_EXP__ (-94)"
.LASF159:
	.string	"__FLT_MIN__ 1.17549435082228750796873653722224568e-38F"
.LASF69:
	.string	"__INTPTR_TYPE__ int"
.LASF149:
	.string	"__DEC_EVAL_METHOD__ 2"
.LASF435:
	.string	"cgc_strcpy"
.LASF45:
	.string	"__INT8_TYPE__ signed char"
.LASF118:
	.string	"__INT_LEAST32_WIDTH__ 32"
.LASF67:
	.string	"__UINT_FAST32_TYPE__ unsigned int"
.LASF414:
	.string	"cgc_strcat"
.LASF16:
	.string	"__PIC__ 2"
.LASF55:
	.string	"__INT_LEAST32_TYPE__ int"
.LASF36:
	.string	"__SIZE_TYPE__ unsigned int"
.LASF320:
	.string	"__pentiumpro__ 1"
.LASF378:
	.string	"INUSE_FLAG 1"
.LASF228:
	.string	"__FLT128_DECIMAL_DIG__ 36"
.LASF453:
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
.LASF158:
	.string	"__FLT_MAX__ 3.40282346638528859811704183484516925e+38F"
.LASF164:
	.string	"__FLT_HAS_QUIET_NAN__ 1"
.LASF122:
	.string	"__UINT_LEAST8_MAX__ 0xff"
.LASF40:
	.string	"__INTMAX_TYPE__ long long int"
.LASF338:
	.string	"__STDC_IEC_559__ 1"
.LASF95:
	.string	"__INTMAX_C(c) c ## LL"
.LASF341:
	.string	"__STDC_NO_THREADS__ 1"
.LASF337:
	.string	"_STDC_PREDEF_H 1"
.LASF312:
	.string	"__SIZEOF_FLOAT80__ 12"
.LASF448:
	.string	"cgc_isalnum"
.LASF391:
	.string	"signed char"
.LASF455:
	.string	"/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/build/SCUBA_Dive_Logging"
.LASF249:
	.string	"__FLT32X_HAS_QUIET_NAN__ 1"
.LASF170:
	.string	"__DBL_MAX_10_EXP__ 308"
.LASF395:
	.string	"short unsigned int"
.LASF15:
	.string	"__pic__ 2"
.LASF418:
	.string	"remaining"
.LASF24:
	.string	"__SIZEOF_FLOAT__ 4"
.LASF248:
	.string	"__FLT32X_HAS_INFINITY__ 1"
.LASF221:
	.string	"__FLT64_HAS_QUIET_NAN__ 1"
.LASF232:
	.string	"__FLT128_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966F128"
.LASF358:
	.string	"CGC_FD_ISSET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] & (1 << (b & (CGC__NFDBITS - 1))))"
.LASF153:
	.string	"__FLT_MIN_EXP__ (-125)"
.LASF313:
	.string	"__SIZEOF_FLOAT128__ 16"
.LASF282:
	.string	"__DEC128_MAX__ 9.999999999999999999999999999999999E6144DL"
.LASF314:
	.string	"__ATOMIC_HLE_ACQUIRE 65536"
.LASF27:
	.string	"__SIZEOF_SIZE_T__ 4"
.LASF443:
	.string	"double"
.LASF218:
	.string	"__FLT64_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F64"
.LASF126:
	.string	"__UINT_LEAST32_MAX__ 0xffffffffU"
.LASF241:
	.string	"__FLT32X_MAX_10_EXP__ 308"
.LASF144:
	.string	"__UINTPTR_MAX__ 0xffffffffU"
.LASF132:
	.string	"__INT_FAST16_MAX__ 0x7fffffff"
.LASF326:
	.string	"__linux__ 1"
.LASF423:
	.string	"read_fds"
.LASF38:
	.string	"__WCHAR_TYPE__ long int"
.LASF348:
	.string	"PAGE_SIZE 4096"
.LASF116:
	.string	"__INT_LEAST32_MAX__ 0x7fffffff"
.LASF383:
	.string	"cgc_size_t"
.LASF380:
	.string	"__STDINT_H__ "
.LASF184:
	.string	"__LDBL_MAX_10_EXP__ 4932"
.LASF274:
	.string	"__DEC64_MIN__ 1E-383DD"
.LASF201:
	.string	"__FLT32_MAX__ 3.40282346638528859811704183484516925e+38F32"
.LASF174:
	.string	"__DBL_EPSILON__ ((double)2.22044604925031308084726333618164062e-16L)"
.LASF330:
	.string	"unix 1"
.LASF96:
	.string	"__UINTMAX_MAX__ 0xffffffffffffffffULL"
.LASF44:
	.string	"__SIG_ATOMIC_TYPE__ int"
.LASF260:
	.string	"__FLT64X_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951F64x"
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
