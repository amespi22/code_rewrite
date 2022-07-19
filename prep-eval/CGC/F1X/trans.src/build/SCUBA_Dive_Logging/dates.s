	.file	"dates.c"
	.text
.Ltext0:
	.globl	cgc_datetime2time_t
	.type	cgc_datetime2time_t, @function
cgc_datetime2time_t:
.LFB0:
	.file 1 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/src/dates.c"
	.loc 1 31 54
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 34 8
	movl	$0, -16(%ebp)
	.loc 1 37 11
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	.loc 1 37 8
	cmpl	$1969, %eax
	ja	.L2
	.loc 1 38 16
	movl	$0, %eax
	jmp	.L3
.L2:
	.loc 1 41 11
	movl	$1970, -12(%ebp)
	.loc 1 41 5
	jmp	.L4
.L5:
	.loc 1 42 24 discriminator 3
	movl	-12(%ebp), %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_leap_year
	addl	$16, %esp
	.loc 1 42 22 discriminator 3
	addl	$365, %eax
	.loc 1 42 15 discriminator 3
	addl	%eax, -16(%ebp)
	.loc 1 41 32 discriminator 3
	addl	$1, -12(%ebp)
.L4:
	.loc 1 41 24 discriminator 1
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	.loc 1 41 20 discriminator 1
	movl	-12(%ebp), %eax
	.loc 1 41 5 discriminator 1
	cmpl	%eax, %edx
	ja	.L5
	.loc 1 46 16
	movl	8(%ebp), %eax
	movl	24(%eax), %edx
	.loc 1 46 11
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	subl	$1, %eax
	movl	%eax, -16(%ebp)
	.loc 1 50 11
	movl	-16(%ebp), %eax
	imull	$86400, %eax, %eax
	movl	%eax, -16(%ebp)
	.loc 1 52 16
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	.loc 1 52 22
	imull	$3600, %eax, %eax
	.loc 1 52 11
	addl	%eax, -16(%ebp)
	.loc 1 54 16
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	.loc 1 54 21
	imull	$60, %eax, %eax
	.loc 1 54 11
	addl	%eax, -16(%ebp)
	.loc 1 56 16
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	.loc 1 56 11
	addl	%eax, -16(%ebp)
	.loc 1 58 12
	movl	-16(%ebp), %eax
.L3:
	.loc 1 60 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	cgc_datetime2time_t, .-cgc_datetime2time_t
	.globl	cgc_time_t2datetime
	.type	cgc_time_t2datetime, @function
cgc_time_t2datetime:
.LFB1:
	.loc 1 63 65
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$80, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 71 5
	movl	$0, -80(%ebp)
	movl	$31, -76(%ebp)
	movl	$59, -72(%ebp)
	movl	$90, -68(%ebp)
	movl	$120, -64(%ebp)
	movl	$151, -60(%ebp)
	movl	$181, -56(%ebp)
	movl	$212, -52(%ebp)
	movl	$243, -48(%ebp)
	movl	$273, -44(%ebp)
	movl	$304, -40(%ebp)
	movl	$334, -36(%ebp)
	movl	$365, -32(%ebp)
	.loc 1 74 17
	movl	8(%ebp), %ecx
	movl	$-1037155065, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$16, %eax
	imull	$86400, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -20(%ebp)
	.loc 1 76 26
	movl	-20(%ebp), %ecx
	movl	$-2004318071, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$5, %eax
	imull	$60, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	.loc 1 76 12
	movl	12(%ebp), %edx
	movl	%eax, 20(%edx)
	.loc 1 77 26
	movl	-20(%ebp), %eax
	movl	$-2004318071, %edx
	mull	%edx
	movl	%edx, %ecx
	shrl	$5, %ecx
	.loc 1 77 31
	movl	$-2004318071, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$5, %eax
	imull	$60, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	.loc 1 77 12
	movl	12(%ebp), %edx
	movl	%eax, 16(%edx)
	.loc 1 78 27
	movl	-20(%ebp), %eax
	movl	$-1851608123, %edx
	mull	%edx
	shrl	$11, %edx
	.loc 1 78 13
	movl	12(%ebp), %eax
	movl	%edx, 12(%eax)
	.loc 1 84 26
	movl	8(%ebp), %eax
	movl	$-1037155065, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$16, %eax
	movl	%eax, -24(%ebp)
	.loc 1 85 25
	movl	$0, -12(%ebp)
	.loc 1 88 11
	movl	$1970, -16(%ebp)
	.loc 1 88 5
	jmp	.L7
.L8:
	.loc 1 89 38 discriminator 3
	movl	-16(%ebp), %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_leap_year
	addl	$16, %esp
	.loc 1 89 36 discriminator 3
	addl	$365, %eax
	.loc 1 89 29 discriminator 3
	addl	%eax, -12(%ebp)
	.loc 1 88 64 discriminator 3
	addl	$1, -16(%ebp)
.L7:
	.loc 1 88 5 discriminator 1
	movl	-12(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jbe	.L8
	.loc 1 94 17
	movl	-16(%ebp), %eax
	subl	$1, %eax
	movl	%eax, %edx
	.loc 1 94 14
	movl	12(%ebp), %eax
	movl	%edx, 8(%eax)
	.loc 1 99 36
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_leap_year
	addl	$16, %esp
	.loc 1 99 34
	addl	$365, %eax
	.loc 1 99 26
	subl	%eax, -12(%ebp)
	.loc 1 103 40
	movl	-24(%ebp), %eax
	subl	-12(%ebp), %eax
	.loc 1 103 17
	addl	$1, %eax
	movl	%eax, -28(%ebp)
	.loc 1 106 13
	movl	12(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, 24(%eax)
	.loc 1 109 11
	movl	$0, -16(%ebp)
	.loc 1 109 5
	jmp	.L9
.L10:
	.loc 1 109 93 discriminator 3
	addl	$1, -16(%ebp)
.L9:
	.loc 1 109 40 discriminator 1
	movl	-16(%ebp), %eax
	movl	-80(%ebp,%eax,4), %eax
	movl	%eax, %esi
	.loc 1 109 48 discriminator 1
	cmpl	$1, -16(%ebp)
	setg	%al
	movzbl	%al, %ebx
	.loc 1 109 52 discriminator 1
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_leap_year
	addl	$16, %esp
	.loc 1 109 51 discriminator 1
	imull	%ebx, %eax
	.loc 1 109 43 discriminator 1
	addl	%esi, %eax
	.loc 1 109 5 discriminator 1
	cmpl	%eax, -28(%ebp)
	ja	.L10
	.loc 1 115 14
	movl	-16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	.loc 1 118 56
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 118 63
	subl	$1, %eax
	.loc 1 118 53
	movl	-80(%ebp,%eax,4), %eax
	movl	%eax, %edx
	.loc 1 118 27
	movl	-28(%ebp), %eax
	subl	%edx, %eax
	movl	%eax, %esi
	.loc 1 118 73
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 118 81
	cmpl	$2, %eax
	seta	%al
	movzbl	%al, %ebx
	.loc 1 118 88
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_leap_year
	addl	$16, %esp
	.loc 1 118 86
	imull	%ebx, %eax
	.loc 1 118 67
	subl	%eax, %esi
	movl	%esi, %edx
	.loc 1 118 13
	movl	12(%ebp), %eax
	movl	%edx, 4(%eax)
	.loc 1 120 12
	movl	$0, %eax
	.loc 1 121 1
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
.LFE1:
	.size	cgc_time_t2datetime, .-cgc_time_t2datetime
	.globl	cgc_str2datetime
	.type	cgc_str2datetime, @function
cgc_str2datetime:
.LFB2:
	.loc 1 124 63
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$84, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	.loc 1 130 5
	movl	$0, -84(%ebp)
	movl	$31, -80(%ebp)
	movl	$59, -76(%ebp)
	movl	$90, -72(%ebp)
	movl	$120, -68(%ebp)
	movl	$151, -64(%ebp)
	movl	$181, -60(%ebp)
	movl	$212, -56(%ebp)
	movl	$243, -52(%ebp)
	movl	$273, -48(%ebp)
	movl	$304, -44(%ebp)
	movl	$334, -40(%ebp)
	.loc 1 136 11
	jmp	.L13
.L14:
	.loc 1 137 9
	addl	$1, 8(%ebp)
.L13:
	.loc 1 136 24
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 136 12
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_isspace@PLT
	addl	$16, %esp
	.loc 1 136 11
	testl	%eax, %eax
	jne	.L14
	.loc 1 139 8
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	.loc 1 141 9
	subl	$12, %esp
	pushl	-12(%ebp)
	call	cgc_atoi@PLT
	addl	$16, %esp
	.loc 1 141 8
	movl	%eax, -16(%ebp)
	.loc 1 143 8
	cmpl	$0, -16(%ebp)
	je	.L15
	.loc 1 143 17 discriminator 1
	cmpl	$12, -16(%ebp)
	jbe	.L18
.L15:
	.loc 1 144 15
	movl	$-2, %eax
	jmp	.L42
.L20:
	.loc 1 147 9
	addl	$1, -12(%ebp)
.L18:
	.loc 1 146 12
	movl	-12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 146 11
	cmpb	$47, %al
	je	.L19
	.loc 1 146 25 discriminator 1
	movl	-12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 146 22 discriminator 1
	testb	%al, %al
	jne	.L20
.L19:
	.loc 1 149 5
	addl	$1, -12(%ebp)
	.loc 1 151 10
	subl	$12, %esp
	pushl	-12(%ebp)
	call	cgc_atoi@PLT
	addl	$16, %esp
	.loc 1 151 9
	movl	%eax, -20(%ebp)
	.loc 1 153 8
	cmpl	$0, -20(%ebp)
	jne	.L21
	.loc 1 154 16
	movl	$-2, %eax
	jmp	.L42
.L21:
	.loc 1 156 8
	cmpl	$1, -16(%ebp)
	je	.L22
	.loc 1 156 19 discriminator 2
	cmpl	$3, -16(%ebp)
	je	.L22
	.loc 1 156 31 discriminator 4
	cmpl	$5, -16(%ebp)
	je	.L22
	.loc 1 156 43 discriminator 6
	cmpl	$7, -16(%ebp)
	je	.L22
	.loc 1 156 55 discriminator 8
	cmpl	$8, -16(%ebp)
	je	.L22
	.loc 1 156 67 discriminator 10
	cmpl	$10, -16(%ebp)
	je	.L22
	.loc 1 156 80 discriminator 12
	cmpl	$12, -16(%ebp)
	jne	.L23
.L22:
	.loc 1 156 94 discriminator 13
	cmpl	$31, -20(%ebp)
	jbe	.L23
	.loc 1 157 16
	movl	$-2, %eax
	jmp	.L42
.L23:
	.loc 1 159 8
	cmpl	$4, -16(%ebp)
	je	.L24
	.loc 1 159 19 discriminator 2
	cmpl	$6, -16(%ebp)
	je	.L24
	.loc 1 159 31 discriminator 4
	cmpl	$9, -16(%ebp)
	je	.L24
	.loc 1 159 43 discriminator 6
	cmpl	$11, -16(%ebp)
	jne	.L26
.L24:
	.loc 1 159 57 discriminator 7
	cmpl	$30, -20(%ebp)
	jbe	.L26
	.loc 1 160 16
	movl	$-2, %eax
	jmp	.L42
.L28:
	.loc 1 163 9
	addl	$1, -12(%ebp)
.L26:
	.loc 1 162 12
	movl	-12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 162 11
	cmpb	$47, %al
	je	.L27
	.loc 1 162 25 discriminator 1
	movl	-12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 162 22 discriminator 1
	testb	%al, %al
	jne	.L28
.L27:
	.loc 1 165 5
	addl	$1, -12(%ebp)
	.loc 1 167 10
	subl	$12, %esp
	pushl	-12(%ebp)
	call	cgc_atoi@PLT
	addl	$16, %esp
	.loc 1 167 9
	movl	%eax, -24(%ebp)
	.loc 1 170 8
	cmpl	$1969, -24(%ebp)
	jbe	.L29
	.loc 1 170 21 discriminator 1
	cmpl	$2050, -24(%ebp)
	jbe	.L30
.L29:
	.loc 1 171 16
	movl	$-2, %eax
	jmp	.L42
.L30:
	.loc 1 174 8
	cmpl	$2, -16(%ebp)
	jne	.L31
	.loc 1 174 32 discriminator 1
	subl	$12, %esp
	pushl	-24(%ebp)
	call	cgc_leap_year
	addl	$16, %esp
	.loc 1 174 30 discriminator 1
	addl	$28, %eax
	.loc 1 174 18 discriminator 1
	cmpl	%eax, -20(%ebp)
	jbe	.L31
	.loc 1 175 16
	movl	$-2, %eax
	jmp	.L42
.L31:
	.loc 1 177 14
	movl	12(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, 8(%eax)
	.loc 1 178 13
	movl	12(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, 4(%eax)
	.loc 1 179 15
	movl	12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%eax)
	.loc 1 181 11
	jmp	.L32
.L33:
	.loc 1 182 9
	addl	$1, -12(%ebp)
.L32:
	.loc 1 181 25
	movl	-12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 181 13
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_isspace@PLT
	addl	$16, %esp
	.loc 1 181 11
	testl	%eax, %eax
	je	.L33
	.loc 1 184 11
	jmp	.L34
.L35:
	.loc 1 185 9
	addl	$1, -12(%ebp)
.L34:
	.loc 1 184 24
	movl	-12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 184 12
	movsbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	cgc_isspace@PLT
	addl	$16, %esp
	.loc 1 184 11
	testl	%eax, %eax
	jne	.L35
	.loc 1 187 13
	subl	$12, %esp
	pushl	-12(%ebp)
	call	cgc_atoi@PLT
	addl	$16, %esp
	.loc 1 187 11
	movl	%eax, -28(%ebp)
	.loc 1 190 11
	jmp	.L36
.L38:
	.loc 1 191 9
	addl	$1, -12(%ebp)
.L36:
	.loc 1 190 12
	movl	-12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 190 11
	cmpb	$58, %al
	je	.L37
	.loc 1 190 25 discriminator 1
	movl	-12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 190 22 discriminator 1
	testb	%al, %al
	jne	.L38
.L37:
	.loc 1 193 5
	addl	$1, -12(%ebp)
	.loc 1 195 12
	subl	$12, %esp
	pushl	-12(%ebp)
	call	cgc_atoi@PLT
	addl	$16, %esp
	.loc 1 195 10
	movl	%eax, -32(%ebp)
	.loc 1 198 11
	jmp	.L39
.L41:
	.loc 1 199 5
	addl	$1, -12(%ebp)
.L39:
	.loc 1 198 12
	movl	-12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 198 11
	cmpb	$58, %al
	je	.L40
	.loc 1 198 25 discriminator 1
	movl	-12(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 198 22 discriminator 1
	testb	%al, %al
	jne	.L41
.L40:
	.loc 1 201 5
	addl	$1, -12(%ebp)
	.loc 1 203 12
	subl	$12, %esp
	pushl	-12(%ebp)
	call	cgc_atoi@PLT
	addl	$16, %esp
	.loc 1 203 10
	movl	%eax, -36(%ebp)
	.loc 1 205 14
	movl	12(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, 12(%eax)
	.loc 1 206 13
	movl	12(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, 16(%eax)
	.loc 1 207 13
	movl	12(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%edx, 20(%eax)
	.loc 1 209 15
	movl	12(%ebp), %eax
	movl	4(%eax), %ecx
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	subl	$4, %esp
	pushl	%ecx
	pushl	%edx
	pushl	%eax
	call	cgc_doy
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 209 13
	movl	12(%ebp), %eax
	movl	%edx, 24(%eax)
	.loc 1 211 13
	subl	$12, %esp
	pushl	12(%ebp)
	call	cgc_datetime2time_t
	addl	$16, %esp
.L42:
	.loc 1 213 1 discriminator 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	cgc_str2datetime, .-cgc_str2datetime
	.section	.rodata
.LC0:
	.string	"@d/@d/@d @02d:@02d:@02d"
	.text
	.globl	cgc_print_time_t
	.type	cgc_print_time_t, @function
cgc_print_time_t:
.LFB3:
	.loc 1 216 37
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	.loc 1 220 5
	subl	$8, %esp
	leal	-52(%ebp), %eax
	pushl	%eax
	pushl	8(%ebp)
	call	cgc_time_t2datetime
	addl	$16, %esp
	.loc 1 222 5
	movl	-32(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	-36(%ebp), %edi
	movl	-40(%ebp), %esi
	movl	-44(%ebp), %ecx
	movl	-48(%ebp), %edx
	movl	-52(%ebp), %eax
	subl	$4, %esp
	pushl	-60(%ebp)
	pushl	%edi
	pushl	%esi
	pushl	%ecx
	pushl	%edx
	pushl	%eax
	leal	.LC0@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$32, %esp
	.loc 1 225 1
	nop
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	cgc_print_time_t, .-cgc_print_time_t
	.globl	cgc_print_datetime
	.type	cgc_print_datetime, @function
cgc_print_datetime:
.LFB4:
	.loc 1 227 51
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	call	__x86.get_pc_thunk.dx
	addl	$_GLOBAL_OFFSET_TABLE_, %edx
	.loc 1 229 5
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	movl	16(%eax), %edi
	movl	8(%ebp), %eax
	movl	12(%eax), %esi
	movl	8(%ebp), %eax
	movl	8(%eax), %ebx
	movl	8(%ebp), %eax
	movl	4(%eax), %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	subl	$4, %esp
	pushl	-28(%ebp)
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	pushl	%eax
	leal	.LC0@GOTOFF(%edx), %eax
	pushl	%eax
	movl	%edx, %ebx
	call	cgc_printf@PLT
	addl	$32, %esp
	.loc 1 232 1
	nop
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	cgc_print_datetime, .-cgc_print_datetime
	.section	.rodata
.LC1:
	.string	"@d/@d/@d"
	.text
	.globl	cgc_to_date_str
	.type	cgc_to_date_str, @function
cgc_to_date_str:
.LFB5:
	.loc 1 234 61
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
	.loc 1 236 5
	movl	8(%ebp), %edx
	movl	8(%edx), %ebx
	movl	8(%ebp), %edx
	movl	4(%edx), %ecx
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	subl	$12, %esp
	pushl	%ebx
	pushl	%ecx
	pushl	%edx
	leal	.LC1@GOTOFF(%eax), %edx
	pushl	%edx
	pushl	12(%ebp)
	movl	%eax, %ebx
	call	cgc_sprintf@PLT
	addl	$32, %esp
	.loc 1 237 12
	movl	$0, %eax
	.loc 1 239 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	cgc_to_date_str, .-cgc_to_date_str
	.section	.rodata
.LC2:
	.string	"@02d:@02d:@02d"
	.text
	.globl	cgc_to_time_str
	.type	cgc_to_time_str, @function
cgc_to_time_str:
.LFB6:
	.loc 1 241 61
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
	.loc 1 243 5
	movl	8(%ebp), %edx
	movl	20(%edx), %ebx
	movl	8(%ebp), %edx
	movl	16(%edx), %ecx
	movl	8(%ebp), %edx
	movl	12(%edx), %edx
	subl	$12, %esp
	pushl	%ebx
	pushl	%ecx
	pushl	%edx
	leal	.LC2@GOTOFF(%eax), %edx
	pushl	%edx
	pushl	12(%ebp)
	movl	%eax, %ebx
	call	cgc_sprintf@PLT
	addl	$32, %esp
	.loc 1 244 12
	movl	$0, %eax
	.loc 1 246 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE6:
	.size	cgc_to_time_str, .-cgc_to_time_str
	.globl	cgc_diff_between_dates
	.type	cgc_diff_between_dates, @function
cgc_diff_between_dates:
.LFB7:
	.loc 1 249 54
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 252 8
	movl	$0, %eax
	.loc 1 254 1
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE7:
	.size	cgc_diff_between_dates, .-cgc_diff_between_dates
	.globl	cgc_leap_year
	.type	cgc_leap_year, @function
cgc_leap_year:
.LFB8:
	.loc 1 257 47
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 259 14
	movl	8(%ebp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$7, %eax
	imull	$400, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	.loc 1 259 8
	testl	%eax, %eax
	je	.L52
	.loc 1 259 29 discriminator 2
	movl	8(%ebp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$5, %eax
	imull	$100, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	.loc 1 259 22 discriminator 2
	testl	%eax, %eax
	je	.L53
.L52:
	.loc 1 259 46 discriminator 3
	movl	8(%ebp), %eax
	andl	$3, %eax
	.loc 1 259 38 discriminator 3
	testl	%eax, %eax
	jne	.L53
	.loc 1 260 16
	movl	$1, %eax
	jmp	.L54
.L53:
	.loc 1 262 16
	movl	$0, %eax
.L54:
	.loc 1 264 1
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE8:
	.size	cgc_leap_year, .-cgc_leap_year
	.globl	cgc_doy
	.type	cgc_doy, @function
cgc_doy:
.LFB9:
	.loc 1 267 67
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$64, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 270 5
	movl	$0, -52(%ebp)
	movl	$31, -48(%ebp)
	movl	$59, -44(%ebp)
	movl	$90, -40(%ebp)
	movl	$120, -36(%ebp)
	movl	$151, -32(%ebp)
	movl	$181, -28(%ebp)
	movl	$212, -24(%ebp)
	movl	$243, -20(%ebp)
	movl	$273, -16(%ebp)
	movl	$304, -12(%ebp)
	movl	$334, -8(%ebp)
	.loc 1 272 30
	movl	12(%ebp), %eax
	subl	$1, %eax
	.loc 1 272 24
	movl	-52(%ebp,%eax,4), %eax
	movl	%eax, %edx
	.loc 1 272 8
	movl	16(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	.loc 1 274 8
	cmpl	$2, 12(%ebp)
	jbe	.L56
	.loc 1 275 14
	pushl	8(%ebp)
	call	cgc_leap_year
	addl	$4, %esp
	.loc 1 275 12
	addl	%eax, -4(%ebp)
.L56:
	.loc 1 277 12
	movl	-4(%ebp), %eax
	.loc 1 279 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE9:
	.size	cgc_doy, .-cgc_doy
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB10:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE10:
	.section	.text.__x86.get_pc_thunk.dx,"axG",@progbits,__x86.get_pc_thunk.dx,comdat
	.globl	__x86.get_pc_thunk.dx
	.hidden	__x86.get_pc_thunk.dx
	.type	__x86.get_pc_thunk.dx, @function
__x86.get_pc_thunk.dx:
.LFB11:
	.cfi_startproc
	movl	(%esp), %edx
	ret
	.cfi_endproc
.LFE11:
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LFB12:
	.cfi_startproc
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE12:
	.text
.Letext0:
	.file 2 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/include/cgc_dates.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x40f
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF416
	.byte	0xc
	.long	.LASF417
	.long	.LASF418
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.long	.Ldebug_macro0
	.uleb128 0x2
	.long	.LASF386
	.byte	0x2
	.byte	0x1e
	.byte	0x17
	.long	0x35
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF384
	.uleb128 0x4
	.byte	0x1c
	.byte	0x2
	.byte	0x20
	.byte	0x9
	.long	0xa1
	.uleb128 0x5
	.long	.LASF381
	.byte	0x2
	.byte	0x22
	.byte	0xf
	.long	0xa1
	.byte	0
	.uleb128 0x6
	.string	"day"
	.byte	0x2
	.byte	0x23
	.byte	0xf
	.long	0xa1
	.byte	0x4
	.uleb128 0x5
	.long	.LASF382
	.byte	0x2
	.byte	0x24
	.byte	0xf
	.long	0xa1
	.byte	0x8
	.uleb128 0x5
	.long	.LASF383
	.byte	0x2
	.byte	0x25
	.byte	0xf
	.long	0xa1
	.byte	0xc
	.uleb128 0x6
	.string	"min"
	.byte	0x2
	.byte	0x26
	.byte	0xf
	.long	0xa1
	.byte	0x10
	.uleb128 0x6
	.string	"sec"
	.byte	0x2
	.byte	0x27
	.byte	0xf
	.long	0xa1
	.byte	0x14
	.uleb128 0x6
	.string	"doy"
	.byte	0x2
	.byte	0x28
	.byte	0xf
	.long	0xa1
	.byte	0x18
	.byte	0
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF385
	.uleb128 0x2
	.long	.LASF387
	.byte	0x2
	.byte	0x2a
	.byte	0x3
	.long	0x3c
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.long	.LASF388
	.uleb128 0x7
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF389
	.uleb128 0x8
	.long	.LASF391
	.byte	0x1
	.value	0x10b
	.byte	0xe
	.long	0xa1
	.long	.LFB9
	.long	.LFE9-.LFB9
	.uleb128 0x1
	.byte	0x9c
	.long	0x135
	.uleb128 0x9
	.long	.LASF382
	.byte	0x1
	.value	0x10b
	.byte	0x1f
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x9
	.long	.LASF381
	.byte	0x1
	.value	0x10b
	.byte	0x2e
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xa
	.string	"day"
	.byte	0x1
	.value	0x10b
	.byte	0x3e
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0xb
	.string	"doy"
	.byte	0x1
	.value	0x10d
	.byte	0xe
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0xc
	.long	.LASF390
	.byte	0x1
	.value	0x10e
	.byte	0x5
	.long	0x135
	.uleb128 0x2
	.byte	0x91
	.sleb128 -60
	.byte	0
	.uleb128 0xd
	.long	0xbb
	.long	0x145
	.uleb128 0xe
	.long	0xa1
	.byte	0xb
	.byte	0
	.uleb128 0xf
	.long	.LASF392
	.byte	0x1
	.value	0x101
	.byte	0xe
	.long	0xa1
	.long	.LFB8
	.long	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.long	0x171
	.uleb128 0x9
	.long	.LASF382
	.byte	0x1
	.value	0x101
	.byte	0x29
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.uleb128 0x10
	.long	.LASF393
	.byte	0x1
	.byte	0xf9
	.byte	0x5
	.long	0xbb
	.long	.LFB7
	.long	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.long	0x1aa
	.uleb128 0x11
	.long	.LASF394
	.byte	0x1
	.byte	0xf9
	.byte	0x23
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.string	"end"
	.byte	0x1
	.byte	0xf9
	.byte	0x31
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.byte	0
	.uleb128 0x13
	.long	.LASF395
	.byte	0x1
	.byte	0xf1
	.byte	0x5
	.long	0xbb
	.long	.LFB6
	.long	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0x1e2
	.uleb128 0x12
	.string	"tm"
	.byte	0x1
	.byte	0xf1
	.byte	0x2b
	.long	0x1e2
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x11
	.long	.LASF396
	.byte	0x1
	.byte	0xf1
	.byte	0x35
	.long	0x1e8
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.byte	0
	.uleb128 0x14
	.byte	0x4
	.long	0xa8
	.uleb128 0x14
	.byte	0x4
	.long	0xc2
	.uleb128 0x13
	.long	.LASF397
	.byte	0x1
	.byte	0xea
	.byte	0x5
	.long	0xbb
	.long	.LFB5
	.long	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0x226
	.uleb128 0x12
	.string	"tm"
	.byte	0x1
	.byte	0xea
	.byte	0x2b
	.long	0x1e2
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x11
	.long	.LASF396
	.byte	0x1
	.byte	0xea
	.byte	0x35
	.long	0x1e8
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.byte	0
	.uleb128 0x15
	.long	.LASF398
	.byte	0x1
	.byte	0xe3
	.byte	0x6
	.long	.LFB4
	.long	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x24b
	.uleb128 0x12
	.string	"tm"
	.byte	0x1
	.byte	0xe3
	.byte	0x2f
	.long	0x1e2
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.uleb128 0x15
	.long	.LASF399
	.byte	0x1
	.byte	0xd8
	.byte	0x6
	.long	.LFB3
	.long	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x27f
	.uleb128 0x11
	.long	.LASF400
	.byte	0x1
	.byte	0xd8
	.byte	0x1f
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x16
	.string	"tm"
	.byte	0x1
	.byte	0xda
	.byte	0x1a
	.long	0xa8
	.uleb128 0x2
	.byte	0x91
	.sleb128 -60
	.byte	0
	.uleb128 0x13
	.long	.LASF401
	.byte	0x1
	.byte	0x7c
	.byte	0x8
	.long	0x29
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x330
	.uleb128 0x11
	.long	.LASF402
	.byte	0x1
	.byte	0x7c
	.byte	0x1f
	.long	0x1e8
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.string	"tm"
	.byte	0x1
	.byte	0x7c
	.byte	0x3b
	.long	0x1e2
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x16
	.string	"mon"
	.byte	0x1
	.byte	0x7f
	.byte	0xa
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x17
	.long	.LASF403
	.byte	0x1
	.byte	0x7f
	.byte	0xf
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x17
	.long	.LASF382
	.byte	0x1
	.byte	0x7f
	.byte	0x15
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x17
	.long	.LASF404
	.byte	0x1
	.byte	0x80
	.byte	0xa
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x17
	.long	.LASF405
	.byte	0x1
	.byte	0x80
	.byte	0x11
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x17
	.long	.LASF406
	.byte	0x1
	.byte	0x80
	.byte	0x17
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0x17
	.long	.LASF390
	.byte	0x1
	.byte	0x82
	.byte	0x5
	.long	0x135
	.uleb128 0x3
	.byte	0x91
	.sleb128 -92
	.uleb128 0x16
	.string	"tmp"
	.byte	0x1
	.byte	0x84
	.byte	0x7
	.long	0x1e8
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x13
	.long	.LASF407
	.byte	0x1
	.byte	0x3f
	.byte	0x5
	.long	0xbb
	.long	.LFB1
	.long	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x3c1
	.uleb128 0x11
	.long	.LASF408
	.byte	0x1
	.byte	0x3f
	.byte	0x20
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.string	"tm"
	.byte	0x1
	.byte	0x3f
	.byte	0x3d
	.long	0x1e2
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x17
	.long	.LASF409
	.byte	0x1
	.byte	0x41
	.byte	0xe
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x17
	.long	.LASF410
	.byte	0x1
	.byte	0x42
	.byte	0xe
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x17
	.long	.LASF411
	.byte	0x1
	.byte	0x43
	.byte	0xe
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x17
	.long	.LASF412
	.byte	0x1
	.byte	0x44
	.byte	0xe
	.long	0xa1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x16
	.string	"i"
	.byte	0x1
	.byte	0x45
	.byte	0x5
	.long	0xbb
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x17
	.long	.LASF413
	.byte	0x1
	.byte	0x47
	.byte	0x5
	.long	0x3c1
	.uleb128 0x3
	.byte	0x91
	.sleb128 -88
	.byte	0
	.uleb128 0xd
	.long	0xbb
	.long	0x3d1
	.uleb128 0xe
	.long	0xa1
	.byte	0xc
	.byte	0
	.uleb128 0x18
	.long	.LASF414
	.byte	0x1
	.byte	0x1f
	.byte	0x8
	.long	0x29
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x12
	.string	"tm"
	.byte	0x1
	.byte	0x1f
	.byte	0x32
	.long	0x1e2
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x16
	.string	"i"
	.byte	0x1
	.byte	0x21
	.byte	0x5
	.long	0xbb
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x17
	.long	.LASF415
	.byte	0x1
	.byte	0x22
	.byte	0x8
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
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
	.uleb128 0xd
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
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x7
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
	.uleb128 0x8
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
	.uleb128 0x9
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
	.uleb128 0xa
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
	.uleb128 0xb
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
	.uleb128 0xc
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
	.uleb128 0xd
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xf
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
	.uleb128 0x10
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
	.uleb128 0x11
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
	.uleb128 0x12
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
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
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
	.file 3 "/usr/include/stdc-predef.h"
	.byte	0x3
	.uleb128 0x5
	.uleb128 0x3
	.byte	0x7
	.long	.Ldebug_macro2
	.byte	0x4
	.byte	0x3
	.uleb128 0x1b
	.uleb128 0x2
	.byte	0x5
	.uleb128 0x1c
	.long	.LASF342
	.byte	0x4
	.file 4 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/cgc_stdlib.h"
	.byte	0x3
	.uleb128 0x1c
	.uleb128 0x4
	.byte	0x7
	.long	.Ldebug_macro3
	.file 5 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/include/libcgc.h"
	.byte	0x3
	.uleb128 0x20
	.uleb128 0x5
	.byte	0x7
	.long	.Ldebug_macro4
	.byte	0x4
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
	.section	.debug_macro,"G",@progbits,wm4.cgc_stdlib.h.27.88ff704b8b47df49cfc97b2f92fbc251,comdat
.Ldebug_macro3:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1b
	.long	.LASF343
	.byte	0x5
	.uleb128 0x1d
	.long	.LASF344
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF345
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.libcgc.h.2.1ca842f70535d048924a5ff19c40f3ba,comdat
.Ldebug_macro4:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x2
	.long	.LASF346
	.byte	0x5
	.uleb128 0x4
	.long	.LASF347
	.byte	0x5
	.uleb128 0x5
	.long	.LASF348
	.byte	0x5
	.uleb128 0x6
	.long	.LASF349
	.byte	0x5
	.uleb128 0xb
	.long	.LASF350
	.byte	0x5
	.uleb128 0x1a
	.long	.LASF351
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF352
	.byte	0x5
	.uleb128 0x22
	.long	.LASF353
	.byte	0x5
	.uleb128 0x26
	.long	.LASF354
	.byte	0x5
	.uleb128 0x2a
	.long	.LASF355
	.byte	0x5
	.uleb128 0x2e
	.long	.LASF356
	.byte	0x5
	.uleb128 0x31
	.long	.LASF357
	.byte	0x5
	.uleb128 0x35
	.long	.LASF358
	.byte	0x5
	.uleb128 0x3b
	.long	.LASF359
	.byte	0x5
	.uleb128 0x42
	.long	.LASF360
	.byte	0x5
	.uleb128 0x45
	.long	.LASF361
	.byte	0x5
	.uleb128 0x48
	.long	.LASF362
	.byte	0x5
	.uleb128 0x50
	.long	.LASF363
	.byte	0x5
	.uleb128 0x51
	.long	.LASF364
	.byte	0x5
	.uleb128 0x52
	.long	.LASF365
	.byte	0x5
	.uleb128 0x53
	.long	.LASF366
	.byte	0x5
	.uleb128 0x54
	.long	.LASF367
	.byte	0x5
	.uleb128 0x55
	.long	.LASF368
	.byte	0x5
	.uleb128 0x58
	.long	.LASF369
	.byte	0x5
	.uleb128 0x59
	.long	.LASF370
	.byte	0x5
	.uleb128 0x5a
	.long	.LASF371
	.byte	0x5
	.uleb128 0x5b
	.long	.LASF372
	.byte	0x5
	.uleb128 0x5c
	.long	.LASF373
	.byte	0x5
	.uleb128 0x5d
	.long	.LASF374
	.byte	0x5
	.uleb128 0x5f
	.long	.LASF375
	.byte	0x5
	.uleb128 0x60
	.long	.LASF376
	.byte	0x5
	.uleb128 0x61
	.long	.LASF377
	.byte	0x5
	.uleb128 0x62
	.long	.LASF378
	.byte	0x5
	.uleb128 0x63
	.long	.LASF379
	.byte	0x5
	.uleb128 0x64
	.long	.LASF380
	.byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF388:
	.string	"long int"
.LASF221:
	.string	"__FLT64_HAS_QUIET_NAN__ 1"
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
.LASF276:
	.string	"__DEC64_EPSILON__ 1E-15DD"
.LASF175:
	.string	"__DBL_DENORM_MIN__ ((double)4.94065645841246544176568792868221372e-324L)"
.LASF194:
	.string	"__FLT32_MANT_DIG__ 24"
.LASF334:
	.string	"LINUX 1"
.LASF222:
	.string	"__FLT128_MANT_DIG__ 113"
.LASF368:
	.string	"CGC_EPIPE 6"
.LASF333:
	.string	"FORTIFY_SOURCE 0"
.LASF242:
	.string	"__FLT32X_DECIMAL_DIG__ 17"
.LASF167:
	.string	"__DBL_MIN_EXP__ (-1021)"
.LASF72:
	.string	"__has_include_next(STR) __has_include_next__(STR)"
.LASF372:
	.string	"FD_SET CGC_FD_SET"
.LASF106:
	.string	"__UINT8_MAX__ 0xff"
.LASF243:
	.string	"__FLT32X_MAX__ 1.79769313486231570814527423731704357e+308F32x"
.LASF397:
	.string	"cgc_to_date_str"
.LASF307:
	.string	"__SIZEOF_WINT_T__ 4"
.LASF396:
	.string	"buffer"
.LASF360:
	.string	"CGC_FD_SET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] |= (1 << (b & (CGC__NFDBITS - 1))))"
.LASF417:
	.string	"/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/src/dates.c"
.LASF6:
	.string	"__GNUC_MINOR__ 4"
.LASF340:
	.string	"__STDC_ISO_10646__ 201706L"
.LASF385:
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
.LASF351:
	.string	"STD_SIZE_T unsigned int"
.LASF33:
	.string	"__BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__"
.LASF188:
	.string	"__LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L"
.LASF327:
	.string	"linux 1"
.LASF197:
	.string	"__FLT32_MIN_10_EXP__ (-37)"
.LASF80:
	.string	"__WCHAR_MIN__ (-__WCHAR_MAX__ - 1)"
.LASF3:
	.string	"__STDC_UTF_32__ 1"
.LASF371:
	.string	"FD_ZERO CGC_FD_ZERO"
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
.LASF306:
	.string	"__SIZEOF_WCHAR_T__ 4"
.LASF248:
	.string	"__FLT32X_HAS_INFINITY__ 1"
.LASF57:
	.string	"__UINT_LEAST8_TYPE__ unsigned char"
.LASF347:
	.string	"STDIN 0"
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
.LASF369:
	.string	"FD_SETSIZE CGC_FD_SETSIZE"
.LASF70:
	.string	"__UINTPTR_TYPE__ unsigned int"
.LASF205:
	.string	"__FLT32_HAS_DENORM__ 1"
.LASF411:
	.string	"cum_days_since_epoch"
.LASF289:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1"
.LASF252:
	.string	"__FLT64X_MIN_EXP__ (-16381)"
.LASF136:
	.string	"__INT_FAST64_MAX__ 0x7fffffffffffffffLL"
.LASF415:
	.string	"result"
.LASF152:
	.string	"__FLT_DIG__ 6"
.LASF132:
	.string	"__INT_FAST16_MAX__ 0x7fffffff"
.LASF17:
	.string	"__pie__ 2"
.LASF267:
	.string	"__DEC32_MIN__ 1E-95DF"
.LASF217:
	.string	"__FLT64_EPSILON__ 2.22044604925031308084726333618164062e-16F64"
.LASF350:
	.string	"NULL (0)"
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
.LASF122:
	.string	"__UINT_LEAST8_MAX__ 0xff"
.LASF279:
	.string	"__DEC128_MIN_EXP__ (-6142)"
.LASF102:
	.string	"__INT8_MAX__ 0x7f"
.LASF283:
	.string	"__DEC128_EPSILON__ 1E-33DL"
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
.LASF413:
	.string	"cumulative_days_by_month"
.LASF398:
	.string	"cgc_print_datetime"
.LASF275:
	.string	"__DEC64_MAX__ 9.999999999999999E384DD"
.LASF299:
	.string	"__GCC_ATOMIC_INT_LOCK_FREE 2"
.LASF94:
	.string	"__INTMAX_MAX__ 0x7fffffffffffffffLL"
.LASF81:
	.string	"__WINT_MAX__ 0xffffffffU"
.LASF121:
	.string	"__INT_LEAST64_WIDTH__ 64"
.LASF213:
	.string	"__FLT64_MAX_10_EXP__ 308"
.LASF30:
	.string	"__ORDER_LITTLE_ENDIAN__ 1234"
.LASF308:
	.string	"__SIZEOF_PTRDIFF_T__ 4"
.LASF402:
	.string	"buff"
.LASF278:
	.string	"__DEC128_MANT_DIG__ 34"
.LASF47:
	.string	"__INT32_TYPE__ int"
.LASF261:
	.string	"__FLT64X_HAS_DENORM__ 1"
.LASF266:
	.string	"__DEC32_MAX_EXP__ 97"
.LASF8:
	.string	"__VERSION__ \"8.4.0\""
.LASF407:
	.string	"cgc_time_t2datetime"
.LASF339:
	.string	"__STDC_IEC_559_COMPLEX__ 1"
.LASF363:
	.string	"CGC_EBADF 1"
.LASF336:
	.string	"errno __cgc_errno"
.LASF253:
	.string	"__FLT64X_MIN_10_EXP__ (-4931)"
.LASF99:
	.string	"__SIG_ATOMIC_MAX__ 0x7fffffff"
.LASF381:
	.string	"month"
.LASF230:
	.string	"__FLT128_MIN__ 3.36210314311209350626267781732175260e-4932F128"
.LASF211:
	.string	"__FLT64_MIN_10_EXP__ (-307)"
.LASF374:
	.string	"FD_ISSET CGC_FD_ISSET"
.LASF172:
	.string	"__DBL_MAX__ ((double)1.79769313486231570814527423731704357e+308L)"
.LASF357:
	.string	"CGC_FD_SETSIZE 1024"
.LASF62:
	.string	"__INT_FAST16_TYPE__ int"
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
.LASF277:
	.string	"__DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD"
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
.LASF383:
	.string	"hour"
.LASF288:
	.string	"__NO_INLINE__ 1"
.LASF359:
	.string	"CGC_FD_ZERO(set) do { int __i; for (__i = 0; __i < (CGC_FD_SETSIZE / CGC__NFDBITS); __i++) (set)->_fd_bits[__i] = 0; } while (0)"
.LASF151:
	.string	"__FLT_MANT_DIG__ 24"
.LASF214:
	.string	"__FLT64_DECIMAL_DIG__ 17"
.LASF291:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1"
.LASF196:
	.string	"__FLT32_MIN_EXP__ (-125)"
.LASF139:
	.string	"__UINT_FAST16_MAX__ 0xffffffffU"
.LASF66:
	.string	"__UINT_FAST16_TYPE__ unsigned int"
.LASF158:
	.string	"__FLT_MAX__ 3.40282346638528859811704183484516925e+38F"
.LASF168:
	.string	"__DBL_MIN_10_EXP__ (-307)"
.LASF389:
	.string	"char"
.LASF73:
	.string	"__GXX_ABI_VERSION 1013"
.LASF234:
	.string	"__FLT128_HAS_INFINITY__ 1"
.LASF343:
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
.LASF353:
	.string	"CGC_FLAG_PAGE_ADDRESS 0x4347C000"
.LASF365:
	.string	"CGC_EINVAL 3"
.LASF119:
	.string	"__INT_LEAST64_MAX__ 0x7fffffffffffffffLL"
.LASF405:
	.string	"mins"
.LASF375:
	.string	"EBADF CGC_EBADF"
.LASF257:
	.string	"__FLT64X_MAX__ 1.18973149535723176502126385303097021e+4932F64x"
.LASF297:
	.string	"__GCC_ATOMIC_WCHAR_T_LOCK_FREE 2"
.LASF358:
	.string	"CGC__NFDBITS (8 * sizeof(_fd_mask))"
.LASF9:
	.string	"__ATOMIC_RELAXED 0"
.LASF112:
	.string	"__INT_LEAST8_WIDTH__ 8"
.LASF400:
	.string	"date"
.LASF107:
	.string	"__UINT16_MAX__ 0xffff"
.LASF367:
	.string	"CGC_ENOSYS 5"
.LASF387:
	.string	"datetime_struct_type"
.LASF108:
	.string	"__UINT32_MAX__ 0xffffffffU"
.LASF98:
	.string	"__INTMAX_WIDTH__ 64"
.LASF268:
	.string	"__DEC32_MAX__ 9.999999E96DF"
.LASF386:
	.string	"time_t"
.LASF391:
	.string	"cgc_doy"
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
.LASF406:
	.string	"secs"
.LASF300:
	.string	"__GCC_ATOMIC_LONG_LOCK_FREE 2"
.LASF237:
	.string	"__FLT32X_DIG__ 15"
.LASF236:
	.string	"__FLT32X_MANT_DIG__ 53"
.LASF255:
	.string	"__FLT64X_MAX_10_EXP__ 4932"
.LASF173:
	.string	"__DBL_MIN__ ((double)2.22507385850720138309023271733240406e-308L)"
.LASF143:
	.string	"__INTPTR_WIDTH__ 32"
.LASF293:
	.string	"__GCC_ATOMIC_BOOL_LOCK_FREE 2"
.LASF19:
	.string	"__FINITE_MATH_ONLY__ 0"
.LASF361:
	.string	"CGC_FD_CLR(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] &= ~(1 << (b & (CGC__NFDBITS - 1))))"
.LASF215:
	.string	"__FLT64_MAX__ 1.79769313486231570814527423731704357e+308F64"
.LASF379:
	.string	"ENOSYS CGC_ENOSYS"
.LASF316:
	.string	"__GCC_ASM_FLAG_OUTPUTS__ 1"
.LASF331:
	.string	"__ELF__ 1"
.LASF244:
	.string	"__FLT32X_MIN__ 2.22507385850720138309023271733240406e-308F32x"
.LASF114:
	.string	"__INT16_C(c) c"
.LASF304:
	.string	"__GCC_HAVE_DWARF2_CFI_ASM 1"
.LASF373:
	.string	"FD_CLR CGC_FD_CLR"
.LASF109:
	.string	"__UINT64_MAX__ 0xffffffffffffffffULL"
.LASF270:
	.string	"__DEC32_SUBNORMAL_MIN__ 0.000001E-95DF"
.LASF134:
	.string	"__INT_FAST32_MAX__ 0x7fffffff"
.LASF263:
	.string	"__FLT64X_HAS_QUIET_NAN__ 1"
.LASF163:
	.string	"__FLT_HAS_INFINITY__ 1"
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
.LASF349:
	.string	"STDERR 2"
.LASF342:
	.string	"DATES_H "
.LASF135:
	.string	"__INT_FAST32_WIDTH__ 32"
.LASF146:
	.string	"__GCC_IEC_559_COMPLEX 2"
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
.LASF182:
	.string	"__LDBL_MIN_10_EXP__ (-4931)"
.LASF25:
	.string	"__SIZEOF_DOUBLE__ 8"
.LASF7:
	.string	"__GNUC_PATCHLEVEL__ 0"
.LASF123:
	.string	"__UINT8_C(c) c"
.LASF410:
	.string	"num_days_since_epoch"
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
.LASF348:
	.string	"STDOUT 1"
.LASF61:
	.string	"__INT_FAST8_TYPE__ signed char"
.LASF68:
	.string	"__UINT_FAST64_TYPE__ long long unsigned int"
.LASF380:
	.string	"EPIPE CGC_EPIPE"
.LASF401:
	.string	"cgc_str2datetime"
.LASF403:
	.string	"mday"
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
.LASF392:
	.string	"cgc_leap_year"
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
.LASF412:
	.string	"day_of_year"
.LASF323:
	.string	"__SEG_GS 1"
.LASF317:
	.string	"__i686 1"
.LASF319:
	.string	"__pentiumpro 1"
.LASF41:
	.string	"__UINTMAX_TYPE__ long long unsigned int"
.LASF352:
	.string	"PAGE_SIZE 4096"
.LASF101:
	.string	"__SIG_ATOMIC_WIDTH__ 32"
.LASF75:
	.string	"__SHRT_MAX__ 0x7fff"
.LASF395:
	.string	"cgc_to_time_str"
.LASF58:
	.string	"__UINT_LEAST16_TYPE__ short unsigned int"
.LASF157:
	.string	"__FLT_DECIMAL_DIG__ 9"
.LASF181:
	.string	"__LDBL_MIN_EXP__ (-16381)"
.LASF91:
	.string	"__WINT_WIDTH__ 32"
.LASF258:
	.string	"__FLT64X_MIN__ 3.36210314311209350626267781732175260e-4932F64x"
.LASF130:
	.string	"__INT_FAST8_MAX__ 0x7f"
.LASF285:
	.string	"__REGISTER_PREFIX__ "
.LASF203:
	.string	"__FLT32_EPSILON__ 1.19209289550781250000000000000000000e-7F32"
.LASF354:
	.string	"offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)"
.LASF273:
	.string	"__DEC64_MAX_EXP__ 385"
.LASF309:
	.string	"__i386 1"
.LASF239:
	.string	"__FLT32X_MIN_10_EXP__ (-307)"
.LASF67:
	.string	"__UINT_FAST32_TYPE__ unsigned int"
.LASF43:
	.string	"__CHAR32_TYPE__ unsigned int"
.LASF262:
	.string	"__FLT64X_HAS_INFINITY__ 1"
.LASF399:
	.string	"cgc_print_time_t"
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
.LASF204:
	.string	"__FLT32_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F32"
.LASF193:
	.string	"__LDBL_HAS_QUIET_NAN__ 1"
.LASF45:
	.string	"__INT8_TYPE__ signed char"
.LASF131:
	.string	"__INT_FAST8_WIDTH__ 8"
.LASF325:
	.string	"__linux 1"
.LASF376:
	.string	"EFAULT CGC_EFAULT"
.LASF51:
	.string	"__UINT32_TYPE__ unsigned int"
.LASF364:
	.string	"CGC_EFAULT 2"
.LASF141:
	.string	"__UINT_FAST64_MAX__ 0xffffffffffffffffULL"
.LASF140:
	.string	"__UINT_FAST32_MAX__ 0xffffffffU"
.LASF366:
	.string	"CGC_ENOMEM 4"
.LASF120:
	.string	"__INT64_C(c) c ## LL"
.LASF414:
	.string	"cgc_datetime2time_t"
.LASF231:
	.string	"__FLT128_EPSILON__ 1.92592994438723585305597794258492732e-34F128"
.LASF345:
	.string	"FREE_FLAG 2"
.LASF22:
	.string	"__SIZEOF_LONG_LONG__ 8"
.LASF49:
	.string	"__UINT8_TYPE__ unsigned char"
.LASF86:
	.string	"__SHRT_WIDTH__ 16"
.LASF404:
	.string	"hours"
.LASF56:
	.string	"__INT_LEAST64_TYPE__ long long int"
.LASF390:
	.string	"cumulative_days"
.LASF394:
	.string	"start"
.LASF35:
	.string	"__SIZEOF_POINTER__ 4"
.LASF250:
	.string	"__FLT64X_MANT_DIG__ 64"
.LASF92:
	.string	"__PTRDIFF_WIDTH__ 32"
.LASF377:
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
.LASF322:
	.string	"__SEG_FS 1"
.LASF227:
	.string	"__FLT128_MAX_10_EXP__ 4932"
.LASF312:
	.string	"__SIZEOF_FLOAT80__ 12"
.LASF286:
	.string	"__USER_LABEL_PREFIX__ "
.LASF384:
	.string	"long unsigned int"
.LASF296:
	.string	"__GCC_ATOMIC_CHAR32_T_LOCK_FREE 2"
.LASF1:
	.string	"__STDC_VERSION__ 199901L"
.LASF328:
	.string	"__unix 1"
.LASF355:
	.string	"SSIZE_MAX ((cgc_ssize_t)((~((cgc_size_t)0ULL))>>1))"
.LASF96:
	.string	"__UINTMAX_MAX__ 0xffffffffffffffffULL"
.LASF28:
	.string	"__CHAR_BIT__ 8"
.LASF393:
	.string	"cgc_diff_between_dates"
.LASF4:
	.string	"__STDC_HOSTED__ 1"
.LASF142:
	.string	"__INTPTR_MAX__ 0x7fffffff"
.LASF382:
	.string	"year"
.LASF71:
	.string	"__has_include(STR) __has_include__(STR)"
.LASF370:
	.string	"_NFDBITS CGC__NFDBITS"
.LASF199:
	.string	"__FLT32_MAX_10_EXP__ 38"
.LASF346:
	.string	"_LIBCGC_H "
.LASF318:
	.string	"__i686__ 1"
.LASF301:
	.string	"__GCC_ATOMIC_LLONG_LOCK_FREE 2"
.LASF155:
	.string	"__FLT_MAX_EXP__ 128"
.LASF13:
	.string	"__ATOMIC_ACQ_REL 4"
.LASF265:
	.string	"__DEC32_MIN_EXP__ (-94)"
.LASF159:
	.string	"__FLT_MIN__ 1.17549435082228750796873653722224568e-38F"
.LASF69:
	.string	"__INTPTR_TYPE__ int"
.LASF149:
	.string	"__DEC_EVAL_METHOD__ 2"
.LASF32:
	.string	"__ORDER_PDP_ENDIAN__ 3412"
.LASF409:
	.string	"day_seconds"
.LASF118:
	.string	"__INT_LEAST32_WIDTH__ 32"
.LASF408:
	.string	"epoch"
.LASF16:
	.string	"__PIC__ 2"
.LASF55:
	.string	"__INT_LEAST32_TYPE__ int"
.LASF36:
	.string	"__SIZE_TYPE__ unsigned int"
.LASF320:
	.string	"__pentiumpro__ 1"
.LASF344:
	.string	"INUSE_FLAG 1"
.LASF228:
	.string	"__FLT128_DECIMAL_DIG__ 36"
.LASF416:
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
.LASF378:
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
.LASF341:
	.string	"__STDC_NO_THREADS__ 1"
.LASF337:
	.string	"_STDC_PREDEF_H 1"
.LASF52:
	.string	"__UINT64_TYPE__ long long unsigned int"
.LASF418:
	.string	"/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/build/SCUBA_Dive_Logging"
.LASF249:
	.string	"__FLT32X_HAS_QUIET_NAN__ 1"
.LASF170:
	.string	"__DBL_MAX_10_EXP__ 308"
.LASF15:
	.string	"__pic__ 2"
.LASF287:
	.string	"__GNUC_STDC_INLINE__ 1"
.LASF24:
	.string	"__SIZEOF_FLOAT__ 4"
.LASF29:
	.string	"__BIGGEST_ALIGNMENT__ 16"
.LASF232:
	.string	"__FLT128_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966F128"
.LASF362:
	.string	"CGC_FD_ISSET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] & (1 << (b & (CGC__NFDBITS - 1))))"
.LASF153:
	.string	"__FLT_MIN_EXP__ (-125)"
.LASF313:
	.string	"__SIZEOF_FLOAT128__ 16"
.LASF282:
	.string	"__DEC128_MAX__ 9.999999999999999999999999999999999E6144DL"
.LASF314:
	.string	"__ATOMIC_HLE_ACQUIRE 65536"
.LASF356:
	.string	"SIZE_MAX (~((cgc_size_t)0ULL))"
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
.LASF38:
	.string	"__WCHAR_TYPE__ long int"
.LASF116:
	.string	"__INT_LEAST32_MAX__ 0x7fffffff"
.LASF218:
	.string	"__FLT64_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F64"
.LASF184:
	.string	"__LDBL_MAX_10_EXP__ 4932"
.LASF274:
	.string	"__DEC64_MIN__ 1E-383DD"
.LASF201:
	.string	"__FLT32_MAX__ 3.40282346638528859811704183484516925e+38F32"
.LASF174:
	.string	"__DBL_EPSILON__ ((double)2.22044604925031308084726333618164062e-16L)"
.LASF305:
	.string	"__PRAGMA_REDEFINE_EXTNAME 1"
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
