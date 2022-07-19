	.file	"edit_dives.c"
	.text
.Ltext0:
	.section	.rodata
.LC0:
	.string	"\n"
.LC1:
	.string	"Dive Log is empty\n"
.LC2:
	.string	"Enter Dive # to edit: "
.LC3:
	.string	"Editing dive number @d\n"
.LC4:
	.string	"Invalid dive number entered\n"
	.text
	.globl	cgc_edit_dives
	.type	cgc_edit_dives, @function
cgc_edit_dives:
.LFB0:
	.file 1 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/src/edit_dives.c"
	.loc 1 30 40
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$1044, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	.loc 1 36 12
	movl	8(%ebp), %eax
	movl	156(%eax), %eax
	movl	%eax, -12(%ebp)
	.loc 1 38 6
	movl	$1, -16(%ebp)
	.loc 1 39 6
	movl	$0, -20(%ebp)
	.loc 1 41 5
	cmpl	$0, -12(%ebp)
	jne	.L2
	.loc 1 43 3
	subl	$12, %esp
	leal	.LC0@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 44 3
	subl	$12, %esp
	leal	.LC1@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 45 10
	movl	$0, %eax
	jmp	.L10
.L2:
	.loc 1 48 2
	subl	$12, %esp
	pushl	8(%ebp)
	call	cgc_list_dives@PLT
	addl	$16, %esp
	.loc 1 50 2
	subl	$12, %esp
	leal	.LC0@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 51 2
	subl	$12, %esp
	leal	.LC2@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 53 10
	subl	$8, %esp
	pushl	$1024
	leal	-1048(%ebp), %eax
	pushl	%eax
	call	cgc_getline@PLT
	addl	$16, %esp
	.loc 1 53 9
	movl	%eax, -24(%ebp)
	.loc 1 55 5
	cmpl	$0, -24(%ebp)
	jne	.L4
	.loc 1 56 10
	movl	$0, %eax
	jmp	.L10
.L4:
	.loc 1 58 22
	subl	$12, %esp
	leal	-1048(%ebp), %eax
	pushl	%eax
	call	cgc_atoi@PLT
	addl	$16, %esp
	movl	%eax, -20(%ebp)
	.loc 1 60 12
	movl	8(%ebp), %eax
	movl	156(%eax), %eax
	movl	%eax, -12(%ebp)
	.loc 1 61 13
	movl	$1, -16(%ebp)
	.loc 1 63 8
	jmp	.L5
.L7:
	.loc 1 64 3
	addl	$1, -16(%ebp)
	.loc 1 65 12
	movl	-12(%ebp), %eax
	movl	124(%eax), %eax
	movl	%eax, -12(%ebp)
.L5:
	.loc 1 63 8
	movl	-16(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jge	.L6
	.loc 1 63 42 discriminator 1
	cmpl	$0, -12(%ebp)
	jne	.L7
.L6:
	.loc 1 69 5
	movl	-16(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jne	.L8
	.loc 1 69 38 discriminator 1
	cmpl	$0, -12(%ebp)
	je	.L8
	.loc 1 70 3
	subl	$8, %esp
	pushl	-20(%ebp)
	leal	.LC3@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 73 3
	subl	$12, %esp
	pushl	-12(%ebp)
	call	cgc_update_dive
	addl	$16, %esp
	jmp	.L9
.L8:
	.loc 1 77 3
	subl	$12, %esp
	leal	.LC4@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
.L9:
	.loc 1 81 9
	movl	$0, %eax
.L10:
	.loc 1 82 1 discriminator 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	cgc_edit_dives, .-cgc_edit_dives
	.section	.rodata
.LC5:
	.string	"Dive Site"
.LC6:
	.string	" (@s)"
.LC7:
	.string	": "
.LC8:
	.string	"Date"
.LC9:
	.string	"Time"
.LC10:
	.string	" "
.LC11:
	.string	"Location (area/city)"
.LC12:
	.string	"Max Depth in ft"
.LC13:
	.string	" (@d)"
.LC14:
	.string	"Avg Depth in ft"
.LC15:
	.string	"Dive Duration (mins)"
.LC16:
	.string	"O2 Percentage"
.LC17:
	.string	"Pressure In (psi)"
.LC18:
	.string	"Pressure Out (psi)"
	.text
	.globl	cgc_update_dive
	.type	cgc_update_dive, @function
cgc_update_dive:
.LFB1:
	.loc 1 85 42
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$2084, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	.loc 1 92 2
	subl	$12, %esp
	leal	.LC5@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 94 26
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	.loc 1 94 5
	testb	%al, %al
	je	.L12
	.loc 1 95 27
	movl	8(%ebp), %eax
	.loc 1 95 3
	subl	$8, %esp
	pushl	%eax
	leal	.LC6@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
.L12:
	.loc 1 97 2
	subl	$12, %esp
	leal	.LC7@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 99 8
	subl	$8, %esp
	pushl	$26
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_getline@PLT
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 101 5
	cmpl	$0, -12(%ebp)
	je	.L13
	.loc 1 102 19
	movl	8(%ebp), %eax
	.loc 1 102 3
	subl	$4, %esp
	pushl	$26
	leal	-1036(%ebp), %edx
	pushl	%edx
	pushl	%eax
	call	cgc_strncpy@PLT
	addl	$16, %esp
.L13:
	.loc 1 105 2
	subl	$12, %esp
	leal	.LC8@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 107 21
	movl	8(%ebp), %eax
	movzbl	26(%eax), %eax
	.loc 1 107 5
	testb	%al, %al
	je	.L14
	.loc 1 108 27
	movl	8(%ebp), %eax
	addl	$26, %eax
	.loc 1 108 3
	subl	$8, %esp
	pushl	%eax
	leal	.LC6@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
.L14:
	.loc 1 110 2
	subl	$12, %esp
	leal	.LC7@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 112 8
	subl	$8, %esp
	pushl	$11
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_getline@PLT
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 114 5
	cmpl	$0, -12(%ebp)
	je	.L15
	.loc 1 115 19
	movl	8(%ebp), %eax
	leal	26(%eax), %edx
	.loc 1 115 3
	subl	$4, %esp
	pushl	$11
	leal	-1036(%ebp), %eax
	pushl	%eax
	pushl	%edx
	call	cgc_strncpy@PLT
	addl	$16, %esp
.L15:
	.loc 1 117 2
	subl	$12, %esp
	leal	.LC9@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 119 21
	movl	8(%ebp), %eax
	movzbl	37(%eax), %eax
	.loc 1 119 5
	testb	%al, %al
	je	.L16
	.loc 1 120 27
	movl	8(%ebp), %eax
	addl	$37, %eax
	.loc 1 120 3
	subl	$8, %esp
	pushl	%eax
	leal	.LC6@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
.L16:
	.loc 1 122 2
	subl	$12, %esp
	leal	.LC7@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 124 8
	subl	$8, %esp
	pushl	$9
	leal	-2060(%ebp), %eax
	pushl	%eax
	call	cgc_getline@PLT
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 126 5
	cmpl	$0, -12(%ebp)
	je	.L17
	.loc 1 127 19
	movl	8(%ebp), %eax
	leal	37(%eax), %edx
	.loc 1 127 3
	subl	$4, %esp
	pushl	$9
	leal	-2060(%ebp), %eax
	pushl	%eax
	pushl	%edx
	call	cgc_strncpy@PLT
	addl	$16, %esp
.L17:
	.loc 1 129 2
	subl	$4, %esp
	pushl	$1
	leal	.LC10@GOTOFF(%ebx), %eax
	pushl	%eax
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_strncat@PLT
	addl	$16, %esp
	.loc 1 130 2
	subl	$12, %esp
	leal	-2060(%ebp), %eax
	pushl	%eax
	call	cgc_strlen@PLT
	addl	$16, %esp
	subl	$4, %esp
	pushl	%eax
	leal	-2060(%ebp), %eax
	pushl	%eax
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_strncat@PLT
	addl	$16, %esp
	.loc 1 133 20
	subl	$8, %esp
	leal	-2088(%ebp), %eax
	pushl	%eax
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_str2datetime@PLT
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 133 18
	movl	8(%ebp), %eax
	movl	%edx, 48(%eax)
	.loc 1 135 2
	subl	$12, %esp
	leal	.LC11@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 137 20
	movl	8(%ebp), %eax
	movzbl	92(%eax), %eax
	.loc 1 137 5
	testb	%al, %al
	je	.L18
	.loc 1 138 27
	movl	8(%ebp), %eax
	addl	$92, %eax
	.loc 1 138 3
	subl	$8, %esp
	pushl	%eax
	leal	.LC6@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
.L18:
	.loc 1 140 2
	subl	$12, %esp
	leal	.LC7@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 145 8
	subl	$8, %esp
	pushl	$1024
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_getline@PLT
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 148 5
	cmpl	$0, -12(%ebp)
	je	.L19
	.loc 1 149 19
	movl	8(%ebp), %eax
	leal	92(%eax), %edx
	.loc 1 149 3
	subl	$4, %esp
	pushl	-12(%ebp)
	leal	-1036(%ebp), %eax
	pushl	%eax
	pushl	%edx
	call	cgc_strncpy@PLT
	addl	$16, %esp
.L19:
	.loc 1 151 2
	subl	$12, %esp
	leal	.LC12@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 153 10
	movl	8(%ebp), %eax
	movl	52(%eax), %eax
	.loc 1 153 5
	testl	%eax, %eax
	je	.L20
	.loc 1 154 3
	movl	8(%ebp), %eax
	movl	52(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	leal	.LC13@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
.L20:
	.loc 1 156 2
	subl	$12, %esp
	leal	.LC7@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 158 8
	subl	$8, %esp
	pushl	$1024
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_getline@PLT
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 160 5
	cmpl	$0, -12(%ebp)
	je	.L21
	.loc 1 161 20
	subl	$12, %esp
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_atoi@PLT
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 161 18
	movl	8(%ebp), %eax
	movl	%edx, 52(%eax)
.L21:
	.loc 1 163 2
	subl	$12, %esp
	leal	.LC14@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 165 10
	movl	8(%ebp), %eax
	movl	56(%eax), %eax
	.loc 1 165 5
	testl	%eax, %eax
	je	.L22
	.loc 1 166 3
	movl	8(%ebp), %eax
	movl	56(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	leal	.LC13@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
.L22:
	.loc 1 168 2
	subl	$12, %esp
	leal	.LC7@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 170 8
	subl	$8, %esp
	pushl	$1024
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_getline@PLT
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 172 5
	cmpl	$0, -12(%ebp)
	je	.L23
	.loc 1 173 19
	subl	$12, %esp
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_atoi@PLT
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 173 18
	movl	8(%ebp), %eax
	movl	%edx, 56(%eax)
.L23:
	.loc 1 175 2
	subl	$12, %esp
	leal	.LC15@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 177 10
	movl	8(%ebp), %eax
	movl	60(%eax), %eax
	.loc 1 177 5
	testl	%eax, %eax
	je	.L24
	.loc 1 178 3
	movl	8(%ebp), %eax
	movl	60(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	leal	.LC13@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
.L24:
	.loc 1 180 2
	subl	$12, %esp
	leal	.LC7@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 182 8
	subl	$8, %esp
	pushl	$13
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_getline@PLT
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 184 5
	cmpl	$0, -12(%ebp)
	je	.L25
	.loc 1 185 23
	subl	$12, %esp
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_atoi@PLT
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 185 21
	movl	8(%ebp), %eax
	movl	%edx, 60(%eax)
.L25:
	.loc 1 187 2
	subl	$12, %esp
	leal	.LC16@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 189 10
	movl	8(%ebp), %eax
	movl	72(%eax), %eax
	.loc 1 189 5
	testl	%eax, %eax
	je	.L26
	.loc 1 190 3
	movl	8(%ebp), %eax
	movl	72(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	leal	.LC13@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
.L26:
	.loc 1 192 2
	subl	$12, %esp
	leal	.LC7@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 194 8
	subl	$8, %esp
	pushl	$11
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_getline@PLT
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 196 5
	cmpl	$0, -12(%ebp)
	je	.L27
	.loc 1 197 20
	subl	$12, %esp
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_atoi@PLT
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 197 19
	movl	8(%ebp), %eax
	movl	%edx, 72(%eax)
.L27:
	.loc 1 199 2
	subl	$12, %esp
	leal	.LC17@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 201 10
	movl	8(%ebp), %eax
	movl	64(%eax), %eax
	.loc 1 201 5
	testl	%eax, %eax
	je	.L28
	.loc 1 202 3
	movl	8(%ebp), %eax
	movl	64(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	leal	.LC13@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
.L28:
	.loc 1 204 2
	subl	$12, %esp
	leal	.LC7@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 206 8
	subl	$8, %esp
	pushl	$20
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_getline@PLT
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 208 5
	cmpl	$0, -12(%ebp)
	je	.L29
	.loc 1 209 21
	subl	$12, %esp
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_atoi@PLT
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 209 20
	movl	8(%ebp), %eax
	movl	%edx, 64(%eax)
.L29:
	.loc 1 211 2
	subl	$12, %esp
	leal	.LC18@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 213 10
	movl	8(%ebp), %eax
	movl	68(%eax), %eax
	.loc 1 213 5
	testl	%eax, %eax
	je	.L30
	.loc 1 214 3
	movl	8(%ebp), %eax
	movl	68(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	leal	.LC13@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
.L30:
	.loc 1 216 2
	subl	$12, %esp
	leal	.LC7@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 218 8
	subl	$8, %esp
	pushl	$11
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_getline@PLT
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 220 5
	cmpl	$0, -12(%ebp)
	je	.L31
	.loc 1 221 22
	subl	$12, %esp
	leal	-1036(%ebp), %eax
	pushl	%eax
	call	cgc_atoi@PLT
	addl	$16, %esp
	movl	%eax, %edx
	.loc 1 221 21
	movl	8(%ebp), %eax
	movl	%edx, 68(%eax)
.L31:
	.loc 1 223 9
	movl	$0, %eax
	.loc 1 225 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	cgc_update_dive, .-cgc_update_dive
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LFB2:
	.cfi_startproc
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE2:
	.text
.Letext0:
	.file 2 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/include/cgc_dates.h"
	.file 3 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/include/cgc_service.h"
	.file 4 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/include/libcgc.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x461
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF438
	.byte	0xc
	.long	.LASF439
	.long	.LASF440
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.long	.Ldebug_macro0
	.uleb128 0x2
	.long	.LASF388
	.byte	0x2
	.byte	0x1e
	.byte	0x17
	.long	0x35
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF386
	.uleb128 0x4
	.byte	0x1c
	.byte	0x2
	.byte	0x20
	.byte	0x9
	.long	0xa1
	.uleb128 0x5
	.long	.LASF383
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
	.long	.LASF384
	.byte	0x2
	.byte	0x24
	.byte	0xf
	.long	0xa1
	.byte	0x8
	.uleb128 0x5
	.long	.LASF385
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
	.long	.LASF387
	.uleb128 0x2
	.long	.LASF389
	.byte	0x2
	.byte	0x2a
	.byte	0x3
	.long	0x3c
	.uleb128 0x2
	.long	.LASF390
	.byte	0x3
	.byte	0x20
	.byte	0x17
	.long	0x35
	.uleb128 0x4
	.byte	0x99
	.byte	0x3
	.byte	0x22
	.byte	0x9
	.long	0x13f
	.uleb128 0x5
	.long	.LASF391
	.byte	0x3
	.byte	0x24
	.byte	0xa
	.long	0x13f
	.byte	0
	.uleb128 0x5
	.long	.LASF392
	.byte	0x3
	.byte	0x25
	.byte	0xa
	.long	0x13f
	.byte	0x15
	.uleb128 0x5
	.long	.LASF393
	.byte	0x3
	.byte	0x26
	.byte	0xa
	.long	0x156
	.byte	0x2a
	.uleb128 0x5
	.long	.LASF394
	.byte	0x3
	.byte	0x27
	.byte	0xa
	.long	0x166
	.byte	0x3a
	.uleb128 0x5
	.long	.LASF395
	.byte	0x3
	.byte	0x28
	.byte	0xa
	.long	0x176
	.byte	0x58
	.uleb128 0x5
	.long	.LASF396
	.byte	0x3
	.byte	0x29
	.byte	0xa
	.long	0x186
	.byte	0x6c
	.uleb128 0x6
	.string	"zip"
	.byte	0x3
	.byte	0x2a
	.byte	0xa
	.long	0x196
	.byte	0x6f
	.uleb128 0x5
	.long	.LASF397
	.byte	0x3
	.byte	0x2b
	.byte	0xa
	.long	0x176
	.byte	0x7a
	.uleb128 0x5
	.long	.LASF398
	.byte	0x3
	.byte	0x2c
	.byte	0xa
	.long	0x196
	.byte	0x8e
	.byte	0
	.uleb128 0x7
	.long	0x14f
	.long	0x14f
	.uleb128 0x8
	.long	0xa1
	.byte	0x14
	.byte	0
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF399
	.uleb128 0x7
	.long	0x14f
	.long	0x166
	.uleb128 0x8
	.long	0xa1
	.byte	0xf
	.byte	0
	.uleb128 0x7
	.long	0x14f
	.long	0x176
	.uleb128 0x8
	.long	0xa1
	.byte	0x1d
	.byte	0
	.uleb128 0x7
	.long	0x14f
	.long	0x186
	.uleb128 0x8
	.long	0xa1
	.byte	0x13
	.byte	0
	.uleb128 0x7
	.long	0x14f
	.long	0x196
	.uleb128 0x8
	.long	0xa1
	.byte	0x2
	.byte	0
	.uleb128 0x7
	.long	0x14f
	.long	0x1a6
	.uleb128 0x8
	.long	0xa1
	.byte	0xa
	.byte	0
	.uleb128 0x2
	.long	.LASF400
	.byte	0x3
	.byte	0x2e
	.byte	0x3
	.long	0xc0
	.uleb128 0x9
	.long	.LASF405
	.byte	0xc
	.byte	0x3
	.byte	0x30
	.byte	0x10
	.long	0x1e7
	.uleb128 0x5
	.long	.LASF401
	.byte	0x3
	.byte	0x32
	.byte	0x13
	.long	0xb4
	.byte	0
	.uleb128 0x5
	.long	.LASF402
	.byte	0x3
	.byte	0x33
	.byte	0x12
	.long	0xa1
	.byte	0x4
	.uleb128 0x5
	.long	.LASF403
	.byte	0x3
	.byte	0x34
	.byte	0x17
	.long	0x1e7
	.byte	0x8
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.long	0x1b2
	.uleb128 0x2
	.long	.LASF404
	.byte	0x3
	.byte	0x36
	.byte	0x3
	.long	0x1b2
	.uleb128 0x9
	.long	.LASF406
	.byte	0x80
	.byte	0x3
	.byte	0x38
	.byte	0x10
	.long	0x2d7
	.uleb128 0x5
	.long	.LASF407
	.byte	0x3
	.byte	0x3a
	.byte	0xa
	.long	0x2d7
	.byte	0
	.uleb128 0x5
	.long	.LASF408
	.byte	0x3
	.byte	0x3b
	.byte	0xa
	.long	0x196
	.byte	0x1a
	.uleb128 0x5
	.long	.LASF409
	.byte	0x3
	.byte	0x3c
	.byte	0xa
	.long	0x2e7
	.byte	0x25
	.uleb128 0x5
	.long	.LASF401
	.byte	0x3
	.byte	0x3d
	.byte	0xc
	.long	0x29
	.byte	0x30
	.uleb128 0x5
	.long	.LASF410
	.byte	0x3
	.byte	0x3e
	.byte	0x12
	.long	0xa1
	.byte	0x34
	.uleb128 0x5
	.long	.LASF411
	.byte	0x3
	.byte	0x3f
	.byte	0x12
	.long	0xa1
	.byte	0x38
	.uleb128 0x5
	.long	.LASF412
	.byte	0x3
	.byte	0x40
	.byte	0x12
	.long	0xa1
	.byte	0x3c
	.uleb128 0x5
	.long	.LASF413
	.byte	0x3
	.byte	0x41
	.byte	0x12
	.long	0xa1
	.byte	0x40
	.uleb128 0x5
	.long	.LASF414
	.byte	0x3
	.byte	0x42
	.byte	0x12
	.long	0xa1
	.byte	0x44
	.uleb128 0x5
	.long	.LASF415
	.byte	0x3
	.byte	0x43
	.byte	0x12
	.long	0xa1
	.byte	0x48
	.uleb128 0x5
	.long	.LASF416
	.byte	0x3
	.byte	0x44
	.byte	0xa
	.long	0x2f7
	.byte	0x4c
	.uleb128 0x5
	.long	.LASF417
	.byte	0x3
	.byte	0x45
	.byte	0x12
	.long	0xa1
	.byte	0x54
	.uleb128 0x5
	.long	.LASF418
	.byte	0x3
	.byte	0x46
	.byte	0x12
	.long	0xa1
	.byte	0x58
	.uleb128 0x5
	.long	.LASF419
	.byte	0x3
	.byte	0x47
	.byte	0xa
	.long	0x2d7
	.byte	0x5c
	.uleb128 0x5
	.long	.LASF420
	.byte	0x3
	.byte	0x48
	.byte	0x15
	.long	0x307
	.byte	0x78
	.uleb128 0x5
	.long	.LASF403
	.byte	0x3
	.byte	0x49
	.byte	0x16
	.long	0x30d
	.byte	0x7c
	.byte	0
	.uleb128 0x7
	.long	0x14f
	.long	0x2e7
	.uleb128 0x8
	.long	0xa1
	.byte	0x19
	.byte	0
	.uleb128 0x7
	.long	0x14f
	.long	0x2f7
	.uleb128 0x8
	.long	0xa1
	.byte	0x8
	.byte	0
	.uleb128 0x7
	.long	0x14f
	.long	0x307
	.uleb128 0x8
	.long	0xa1
	.byte	0x5
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.long	0x1ed
	.uleb128 0xa
	.byte	0x4
	.long	0x1f9
	.uleb128 0x2
	.long	.LASF421
	.byte	0x3
	.byte	0x4c
	.byte	0x3
	.long	0x1f9
	.uleb128 0x4
	.byte	0xa0
	.byte	0x3
	.byte	0x4e
	.byte	0x9
	.long	0x343
	.uleb128 0x5
	.long	.LASF422
	.byte	0x3
	.byte	0x50
	.byte	0x15
	.long	0x1a6
	.byte	0
	.uleb128 0x5
	.long	.LASF423
	.byte	0x3
	.byte	0x51
	.byte	0x14
	.long	0x343
	.byte	0x9c
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.long	0x313
	.uleb128 0x2
	.long	.LASF424
	.byte	0x3
	.byte	0x53
	.byte	0x3
	.long	0x31f
	.uleb128 0xb
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.long	.LASF425
	.byte	0x4
	.byte	0x13
	.byte	0x17
	.long	0x35
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.long	.LASF426
	.uleb128 0xc
	.long	.LASF430
	.byte	0x1
	.byte	0x55
	.byte	0x5
	.long	0x355
	.long	.LFB1
	.long	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x3d7
	.uleb128 0xd
	.long	.LASF432
	.byte	0x1
	.byte	0x55
	.byte	0x24
	.long	0x343
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xe
	.long	.LASF427
	.byte	0x1
	.byte	0x58
	.byte	0x6
	.long	0x3d7
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1044
	.uleb128 0xe
	.long	.LASF428
	.byte	0x1
	.byte	0x59
	.byte	0x6
	.long	0x3d7
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2068
	.uleb128 0xe
	.long	.LASF429
	.byte	0x1
	.byte	0x5a
	.byte	0xc
	.long	0x35c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xf
	.string	"tm"
	.byte	0x1
	.byte	0x84
	.byte	0x17
	.long	0xa8
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2096
	.byte	0
	.uleb128 0x7
	.long	0x14f
	.long	0x3e8
	.uleb128 0x10
	.long	0xa1
	.value	0x3ff
	.byte	0
	.uleb128 0xc
	.long	.LASF431
	.byte	0x1
	.byte	0x1e
	.byte	0x5
	.long	0x355
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.long	0x45e
	.uleb128 0xd
	.long	.LASF433
	.byte	0x1
	.byte	0x1e
	.byte	0x22
	.long	0x45e
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xf
	.string	"buf"
	.byte	0x1
	.byte	0x20
	.byte	0x7
	.long	0x3d7
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1056
	.uleb128 0xe
	.long	.LASF434
	.byte	0x1
	.byte	0x21
	.byte	0x6
	.long	0x355
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xe
	.long	.LASF435
	.byte	0x1
	.byte	0x23
	.byte	0x11
	.long	0x343
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xe
	.long	.LASF436
	.byte	0x1
	.byte	0x26
	.byte	0x6
	.long	0x355
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xe
	.long	.LASF437
	.byte	0x1
	.byte	0x27
	.byte	0x6
	.long	0x355
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.long	0x349
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
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
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
	.uleb128 0xa
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
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
	.uleb128 0xc
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
	.uleb128 0xd
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
	.uleb128 0xe
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
	.uleb128 0xf
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
	.uleb128 0x10
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
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
	.file 5 "/usr/include/stdc-predef.h"
	.byte	0x3
	.uleb128 0x5
	.uleb128 0x5
	.byte	0x7
	.long	.Ldebug_macro2
	.byte	0x4
	.byte	0x3
	.uleb128 0x1a
	.uleb128 0x3
	.byte	0x5
	.uleb128 0x1c
	.long	.LASF342
	.byte	0x3
	.uleb128 0x1e
	.uleb128 0x2
	.byte	0x5
	.uleb128 0x1c
	.long	.LASF343
	.byte	0x4
	.byte	0x4
	.file 6 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/include/cgc_menu.h"
	.byte	0x3
	.uleb128 0x1b
	.uleb128 0x6
	.byte	0x5
	.uleb128 0x1c
	.long	.LASF344
	.byte	0x4
	.file 7 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/cgc_stdlib.h"
	.byte	0x3
	.uleb128 0x1c
	.uleb128 0x7
	.byte	0x7
	.long	.Ldebug_macro3
	.byte	0x3
	.uleb128 0x20
	.uleb128 0x4
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
	.long	.LASF345
	.byte	0x5
	.uleb128 0x1d
	.long	.LASF346
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF347
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.libcgc.h.2.1ca842f70535d048924a5ff19c40f3ba,comdat
.Ldebug_macro4:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x2
	.long	.LASF348
	.byte	0x5
	.uleb128 0x4
	.long	.LASF349
	.byte	0x5
	.uleb128 0x5
	.long	.LASF350
	.byte	0x5
	.uleb128 0x6
	.long	.LASF351
	.byte	0x5
	.uleb128 0xb
	.long	.LASF352
	.byte	0x5
	.uleb128 0x1a
	.long	.LASF353
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF354
	.byte	0x5
	.uleb128 0x22
	.long	.LASF355
	.byte	0x5
	.uleb128 0x26
	.long	.LASF356
	.byte	0x5
	.uleb128 0x2a
	.long	.LASF357
	.byte	0x5
	.uleb128 0x2e
	.long	.LASF358
	.byte	0x5
	.uleb128 0x31
	.long	.LASF359
	.byte	0x5
	.uleb128 0x35
	.long	.LASF360
	.byte	0x5
	.uleb128 0x3b
	.long	.LASF361
	.byte	0x5
	.uleb128 0x42
	.long	.LASF362
	.byte	0x5
	.uleb128 0x45
	.long	.LASF363
	.byte	0x5
	.uleb128 0x48
	.long	.LASF364
	.byte	0x5
	.uleb128 0x50
	.long	.LASF365
	.byte	0x5
	.uleb128 0x51
	.long	.LASF366
	.byte	0x5
	.uleb128 0x52
	.long	.LASF367
	.byte	0x5
	.uleb128 0x53
	.long	.LASF368
	.byte	0x5
	.uleb128 0x54
	.long	.LASF369
	.byte	0x5
	.uleb128 0x55
	.long	.LASF370
	.byte	0x5
	.uleb128 0x58
	.long	.LASF371
	.byte	0x5
	.uleb128 0x59
	.long	.LASF372
	.byte	0x5
	.uleb128 0x5a
	.long	.LASF373
	.byte	0x5
	.uleb128 0x5b
	.long	.LASF374
	.byte	0x5
	.uleb128 0x5c
	.long	.LASF375
	.byte	0x5
	.uleb128 0x5d
	.long	.LASF376
	.byte	0x5
	.uleb128 0x5f
	.long	.LASF377
	.byte	0x5
	.uleb128 0x60
	.long	.LASF378
	.byte	0x5
	.uleb128 0x61
	.long	.LASF379
	.byte	0x5
	.uleb128 0x62
	.long	.LASF380
	.byte	0x5
	.uleb128 0x63
	.long	.LASF381
	.byte	0x5
	.uleb128 0x64
	.long	.LASF382
	.byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF99:
	.string	"__SIG_ATOMIC_MAX__ 0x7fffffff"
.LASF221:
	.string	"__FLT64_HAS_QUIET_NAN__ 1"
.LASF187:
	.string	"__LDBL_MAX__ 1.18973149535723176502126385303097021e+4932L"
.LASF394:
	.string	"street"
.LASF206:
	.string	"__FLT32_HAS_INFINITY__ 1"
.LASF436:
	.string	"dive_count"
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
.LASF370:
	.string	"CGC_EPIPE 6"
.LASF333:
	.string	"FORTIFY_SOURCE 0"
.LASF242:
	.string	"__FLT32X_DECIMAL_DIG__ 17"
.LASF167:
	.string	"__DBL_MIN_EXP__ (-1021)"
.LASF72:
	.string	"__has_include_next(STR) __has_include_next__(STR)"
.LASF374:
	.string	"FD_SET CGC_FD_SET"
.LASF318:
	.string	"__i686__ 1"
.LASF243:
	.string	"__FLT32X_MAX__ 1.79769313486231570814527423731704357e+308F32x"
.LASF307:
	.string	"__SIZEOF_WINT_T__ 4"
.LASF427:
	.string	"buffer"
.LASF395:
	.string	"city"
.LASF362:
	.string	"CGC_FD_SET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] |= (1 << (b & (CGC__NFDBITS - 1))))"
.LASF430:
	.string	"cgc_update_dive"
.LASF6:
	.string	"__GNUC_MINOR__ 4"
.LASF43:
	.string	"__CHAR32_TYPE__ unsigned int"
.LASF387:
	.string	"unsigned int"
.LASF403:
	.string	"next"
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
.LASF137:
	.string	"__INT_FAST64_WIDTH__ 64"
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
.LASF433:
	.string	"Info"
.LASF254:
	.string	"__FLT64X_MAX_EXP__ 16384"
.LASF10:
	.string	"__ATOMIC_SEQ_CST 5"
.LASF23:
	.string	"__SIZEOF_SHORT__ 2"
.LASF421:
	.string	"dive_log_type"
.LASF69:
	.string	"__INTPTR_TYPE__ int"
.LASF53:
	.string	"__INT_LEAST8_TYPE__ signed char"
.LASF208:
	.string	"__FLT64_MANT_DIG__ 53"
.LASF97:
	.string	"__UINTMAX_C(c) c ## ULL"
.LASF79:
	.string	"__WCHAR_MAX__ 0x7fffffffL"
.LASF353:
	.string	"STD_SIZE_T unsigned int"
.LASF341:
	.string	"__STDC_NO_THREADS__ 1"
.LASF33:
	.string	"__BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__"
.LASF188:
	.string	"__LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L"
.LASF327:
	.string	"linux 1"
.LASF197:
	.string	"__FLT32_MIN_10_EXP__ (-37)"
.LASF176:
	.string	"__DBL_HAS_DENORM__ 1"
.LASF80:
	.string	"__WCHAR_MIN__ (-__WCHAR_MAX__ - 1)"
.LASF3:
	.string	"__STDC_UTF_32__ 1"
.LASF437:
	.string	"dive_number_to_edit"
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
.LASF248:
	.string	"__FLT32X_HAS_INFINITY__ 1"
.LASF234:
	.string	"__FLT128_HAS_INFINITY__ 1"
.LASF57:
	.string	"__UINT_LEAST8_TYPE__ unsigned char"
.LASF349:
	.string	"STDIN 0"
.LASF64:
	.string	"__INT_FAST64_TYPE__ long long int"
.LASF235:
	.string	"__FLT128_HAS_QUIET_NAN__ 1"
.LASF411:
	.string	"avg_depth"
.LASF229:
	.string	"__FLT128_MAX__ 1.18973149535723176508575932662800702e+4932F128"
.LASF414:
	.string	"pressure_out"
.LASF251:
	.string	"__FLT64X_DIG__ 18"
.LASF115:
	.string	"__INT_LEAST16_WIDTH__ 16"
.LASF371:
	.string	"FD_SETSIZE CGC_FD_SETSIZE"
.LASF70:
	.string	"__UINTPTR_TYPE__ unsigned int"
.LASF205:
	.string	"__FLT32_HAS_DENORM__ 1"
.LASF329:
	.string	"__unix__ 1"
.LASF289:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1"
.LASF252:
	.string	"__FLT64X_MIN_EXP__ (-16381)"
.LASF136:
	.string	"__INT_FAST64_MAX__ 0x7fffffffffffffffLL"
.LASF152:
	.string	"__FLT_DIG__ 6"
.LASF293:
	.string	"__GCC_ATOMIC_BOOL_LOCK_FREE 2"
.LASF422:
	.string	"diver"
.LASF17:
	.string	"__pie__ 2"
.LASF344:
	.string	"MENU_H "
.LASF267:
	.string	"__DEC32_MIN__ 1E-95DF"
.LASF429:
	.string	"count"
.LASF217:
	.string	"__FLT64_EPSILON__ 2.22044604925031308084726333618164062e-16F64"
.LASF402:
	.string	"depth"
.LASF352:
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
.LASF291:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1"
.LASF316:
	.string	"__GCC_ASM_FLAG_OUTPUTS__ 1"
.LASF428:
	.string	"buf2"
.LASF226:
	.string	"__FLT128_MAX_EXP__ 16384"
.LASF128:
	.string	"__UINT_LEAST64_MAX__ 0xffffffffffffffffULL"
.LASF150:
	.string	"__FLT_RADIX__ 2"
.LASF26:
	.string	"__SIZEOF_LONG_DOUBLE__ 12"
.LASF393:
	.string	"phone"
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
.LASF434:
	.string	"rcv_cnt"
.LASF275:
	.string	"__DEC64_MAX__ 9.999999999999999E384DD"
.LASF398:
	.string	"cert_date"
.LASF299:
	.string	"__GCC_ATOMIC_INT_LOCK_FREE 2"
.LASF94:
	.string	"__INTMAX_MAX__ 0x7fffffffffffffffLL"
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
.LASF278:
	.string	"__DEC128_MANT_DIG__ 34"
.LASF47:
	.string	"__INT32_TYPE__ int"
.LASF413:
	.string	"pressure_in"
.LASF261:
	.string	"__FLT64X_HAS_DENORM__ 1"
.LASF266:
	.string	"__DEC32_MAX_EXP__ 97"
.LASF8:
	.string	"__VERSION__ \"8.4.0\""
.LASF339:
	.string	"__STDC_IEC_559_COMPLEX__ 1"
.LASF365:
	.string	"CGC_EBADF 1"
.LASF336:
	.string	"errno __cgc_errno"
.LASF253:
	.string	"__FLT64X_MIN_10_EXP__ (-4931)"
.LASF392:
	.string	"first_name"
.LASF340:
	.string	"__STDC_ISO_10646__ 201706L"
.LASF383:
	.string	"month"
.LASF230:
	.string	"__FLT128_MIN__ 3.36210314311209350626267781732175260e-4932F128"
.LASF158:
	.string	"__FLT_MAX__ 3.40282346638528859811704183484516925e+38F"
.LASF131:
	.string	"__INT_FAST8_WIDTH__ 8"
.LASF211:
	.string	"__FLT64_MIN_10_EXP__ (-307)"
.LASF376:
	.string	"FD_ISSET CGC_FD_ISSET"
.LASF172:
	.string	"__DBL_MAX__ ((double)1.79769313486231570814527423731704357e+308L)"
.LASF359:
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
.LASF373:
	.string	"FD_ZERO CGC_FD_ZERO"
.LASF78:
	.string	"__LONG_LONG_MAX__ 0x7fffffffffffffffLL"
.LASF48:
	.string	"__INT64_TYPE__ long long int"
.LASF156:
	.string	"__FLT_MAX_10_EXP__ 38"
.LASF245:
	.string	"__FLT32X_EPSILON__ 2.22044604925031308084726333618164062e-16F32x"
.LASF385:
	.string	"hour"
.LASF288:
	.string	"__NO_INLINE__ 1"
.LASF151:
	.string	"__FLT_MANT_DIG__ 24"
.LASF255:
	.string	"__FLT64X_MAX_10_EXP__ 4932"
.LASF313:
	.string	"__SIZEOF_FLOAT128__ 16"
.LASF196:
	.string	"__FLT32_MIN_EXP__ (-125)"
.LASF139:
	.string	"__UINT_FAST16_MAX__ 0xffffffffU"
.LASF66:
	.string	"__UINT_FAST16_TYPE__ unsigned int"
.LASF168:
	.string	"__DBL_MIN_10_EXP__ (-307)"
.LASF399:
	.string	"char"
.LASF73:
	.string	"__GXX_ABI_VERSION 1013"
.LASF182:
	.string	"__LDBL_MIN_10_EXP__ (-4931)"
.LASF412:
	.string	"dive_length"
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
.LASF355:
	.string	"CGC_FLAG_PAGE_ADDRESS 0x4347C000"
.LASF367:
	.string	"CGC_EINVAL 3"
.LASF377:
	.string	"EBADF CGC_EBADF"
.LASF257:
	.string	"__FLT64X_MAX__ 1.18973149535723176502126385303097021e+4932F64x"
.LASF297:
	.string	"__GCC_ATOMIC_WCHAR_T_LOCK_FREE 2"
.LASF360:
	.string	"CGC__NFDBITS (8 * sizeof(_fd_mask))"
.LASF9:
	.string	"__ATOMIC_RELAXED 0"
.LASF420:
	.string	"data"
.LASF112:
	.string	"__INT_LEAST8_WIDTH__ 8"
.LASF106:
	.string	"__UINT8_MAX__ 0xff"
.LASF107:
	.string	"__UINT16_MAX__ 0xffff"
.LASF369:
	.string	"CGC_ENOSYS 5"
.LASF389:
	.string	"datetime_struct_type"
.LASF98:
	.string	"__INTMAX_WIDTH__ 64"
.LASF268:
	.string	"__DEC32_MAX__ 9.999999E96DF"
.LASF388:
	.string	"time_t"
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
.LASF110:
	.string	"__INT_LEAST8_MAX__ 0x7f"
.LASF345:
	.string	"__STDLIB_H__ "
.LASF397:
	.string	"padi_number"
.LASF300:
	.string	"__GCC_ATOMIC_LONG_LOCK_FREE 2"
.LASF237:
	.string	"__FLT32X_DIG__ 15"
.LASF236:
	.string	"__FLT32X_MANT_DIG__ 53"
.LASF418:
	.string	"bincount"
.LASF342:
	.string	"SERVICE_H "
.LASF28:
	.string	"__CHAR_BIT__ 8"
.LASF173:
	.string	"__DBL_MIN__ ((double)2.22507385850720138309023271733240406e-308L)"
.LASF143:
	.string	"__INTPTR_WIDTH__ 32"
.LASF108:
	.string	"__UINT32_MAX__ 0xffffffffU"
.LASF404:
	.string	"dive_data_type"
.LASF19:
	.string	"__FINITE_MATH_ONLY__ 0"
.LASF215:
	.string	"__FLT64_MAX__ 1.79769313486231570814527423731704357e+308F64"
.LASF381:
	.string	"ENOSYS CGC_ENOSYS"
.LASF323:
	.string	"__SEG_GS 1"
.LASF409:
	.string	"dive_time"
.LASF331:
	.string	"__ELF__ 1"
.LASF244:
	.string	"__FLT32X_MIN__ 2.22507385850720138309023271733240406e-308F32x"
.LASF114:
	.string	"__INT16_C(c) c"
.LASF304:
	.string	"__GCC_HAVE_DWARF2_CFI_ASM 1"
.LASF375:
	.string	"FD_CLR CGC_FD_CLR"
.LASF435:
	.string	"next_dive"
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
.LASF351:
	.string	"STDERR 2"
.LASF343:
	.string	"DATES_H "
.LASF135:
	.string	"__INT_FAST32_WIDTH__ 32"
.LASF410:
	.string	"max_depth"
.LASF415:
	.string	"O2_percent"
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
.LASF405:
	.string	"dive_data"
.LASF408:
	.string	"dive_date"
.LASF82:
	.string	"__WINT_MIN__ 0U"
.LASF179:
	.string	"__LDBL_MANT_DIG__ 64"
.LASF180:
	.string	"__LDBL_DIG__ 18"
.LASF280:
	.string	"__DEC128_MAX_EXP__ 6145"
.LASF2:
	.string	"__STDC_UTF_16__ 1"
.LASF189:
	.string	"__LDBL_EPSILON__ 1.08420217248550443400745280086994171e-19L"
.LASF406:
	.string	"dive_log"
.LASF350:
	.string	"STDOUT 1"
.LASF192:
	.string	"__LDBL_HAS_INFINITY__ 1"
.LASF68:
	.string	"__UINT_FAST64_TYPE__ long long unsigned int"
.LASF382:
	.string	"EPIPE CGC_EPIPE"
.LASF146:
	.string	"__GCC_IEC_559_COMPLEX 2"
.LASF306:
	.string	"__SIZEOF_WCHAR_T__ 4"
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
.LASF56:
	.string	"__INT_LEAST64_TYPE__ long long int"
.LASF317:
	.string	"__i686 1"
.LASF319:
	.string	"__pentiumpro 1"
.LASF41:
	.string	"__UINTMAX_TYPE__ long long unsigned int"
.LASF391:
	.string	"last_name"
.LASF354:
	.string	"PAGE_SIZE 4096"
.LASF101:
	.string	"__SIG_ATOMIC_WIDTH__ 32"
.LASF424:
	.string	"logbook_type"
.LASF75:
	.string	"__SHRT_MAX__ 0x7fff"
.LASF32:
	.string	"__ORDER_PDP_ENDIAN__ 3412"
.LASF58:
	.string	"__UINT_LEAST16_TYPE__ short unsigned int"
.LASF157:
	.string	"__FLT_DECIMAL_DIG__ 9"
.LASF213:
	.string	"__FLT64_MAX_10_EXP__ 308"
.LASF423:
	.string	"dives"
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
.LASF356:
	.string	"offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)"
.LASF273:
	.string	"__DEC64_MAX_EXP__ 385"
.LASF309:
	.string	"__i386 1"
.LASF239:
	.string	"__FLT32X_MIN_10_EXP__ (-307)"
.LASF426:
	.string	"long int"
.LASF274:
	.string	"__DEC64_MIN__ 1E-383DD"
.LASF277:
	.string	"__DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD"
.LASF400:
	.string	"diver_info_type"
.LASF262:
	.string	"__FLT64X_HAS_INFINITY__ 1"
.LASF281:
	.string	"__DEC128_MIN__ 1E-6143DL"
.LASF238:
	.string	"__FLT32X_MIN_EXP__ (-1021)"
.LASF65:
	.string	"__UINT_FAST8_TYPE__ unsigned char"
.LASF117:
	.string	"__INT32_C(c) c"
.LASF363:
	.string	"CGC_FD_CLR(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] &= ~(1 << (b & (CGC__NFDBITS - 1))))"
.LASF193:
	.string	"__LDBL_HAS_QUIET_NAN__ 1"
.LASF45:
	.string	"__INT8_TYPE__ signed char"
.LASF81:
	.string	"__WINT_MAX__ 0xffffffffU"
.LASF325:
	.string	"__linux 1"
.LASF378:
	.string	"EFAULT CGC_EFAULT"
.LASF51:
	.string	"__UINT32_TYPE__ unsigned int"
.LASF366:
	.string	"CGC_EFAULT 2"
.LASF141:
	.string	"__UINT_FAST64_MAX__ 0xffffffffffffffffULL"
.LASF140:
	.string	"__UINT_FAST32_MAX__ 0xffffffffU"
.LASF368:
	.string	"CGC_ENOMEM 4"
.LASF120:
	.string	"__INT64_C(c) c ## LL"
.LASF231:
	.string	"__FLT128_EPSILON__ 1.92592994438723585305597794258492732e-34F128"
.LASF347:
	.string	"FREE_FLAG 2"
.LASF22:
	.string	"__SIZEOF_LONG_LONG__ 8"
.LASF49:
	.string	"__UINT8_TYPE__ unsigned char"
.LASF86:
	.string	"__SHRT_WIDTH__ 16"
.LASF432:
	.string	"dive"
.LASF361:
	.string	"CGC_FD_ZERO(set) do { int __i; for (__i = 0; __i < (CGC_FD_SETSIZE / CGC__NFDBITS); __i++) (set)->_fd_bits[__i] = 0; } while (0)"
.LASF35:
	.string	"__SIZEOF_POINTER__ 4"
.LASF250:
	.string	"__FLT64X_MANT_DIG__ 64"
.LASF92:
	.string	"__PTRDIFF_WIDTH__ 32"
.LASF379:
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
.LASF286:
	.string	"__USER_LABEL_PREFIX__ "
.LASF386:
	.string	"long unsigned int"
.LASF296:
	.string	"__GCC_ATOMIC_CHAR32_T_LOCK_FREE 2"
.LASF1:
	.string	"__STDC_VERSION__ 199901L"
.LASF328:
	.string	"__unix 1"
.LASF357:
	.string	"SSIZE_MAX ((cgc_ssize_t)((~((cgc_size_t)0ULL))>>1))"
.LASF96:
	.string	"__UINTMAX_MAX__ 0xffffffffffffffffULL"
.LASF314:
	.string	"__ATOMIC_HLE_ACQUIRE 65536"
.LASF4:
	.string	"__STDC_HOSTED__ 1"
.LASF142:
	.string	"__INTPTR_MAX__ 0x7fffffff"
.LASF384:
	.string	"year"
.LASF71:
	.string	"__has_include(STR) __has_include__(STR)"
.LASF372:
	.string	"_NFDBITS CGC__NFDBITS"
.LASF199:
	.string	"__FLT32_MAX_10_EXP__ 38"
.LASF348:
	.string	"_LIBCGC_H "
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
.LASF119:
	.string	"__INT_LEAST64_MAX__ 0x7fffffffffffffffLL"
.LASF149:
	.string	"__DEC_EVAL_METHOD__ 2"
.LASF118:
	.string	"__INT_LEAST32_WIDTH__ 32"
.LASF67:
	.string	"__UINT_FAST32_TYPE__ unsigned int"
.LASF417:
	.string	"water_temp"
.LASF16:
	.string	"__PIC__ 2"
.LASF55:
	.string	"__INT_LEAST32_TYPE__ int"
.LASF36:
	.string	"__SIZE_TYPE__ unsigned int"
.LASF320:
	.string	"__pentiumpro__ 1"
.LASF346:
	.string	"INUSE_FLAG 1"
.LASF228:
	.string	"__FLT128_DECIMAL_DIG__ 36"
.LASF396:
	.string	"state"
.LASF438:
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
.LASF380:
	.string	"ENOMEM CGC_ENOMEM"
.LASF177:
	.string	"__DBL_HAS_INFINITY__ 1"
.LASF148:
	.string	"__FLT_EVAL_METHOD_TS_18661_3__ 2"
.LASF63:
	.string	"__INT_FAST32_TYPE__ int"
.LASF401:
	.string	"timestamp"
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
.LASF440:
	.string	"/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/build/SCUBA_Dive_Logging"
.LASF249:
	.string	"__FLT32X_HAS_QUIET_NAN__ 1"
.LASF170:
	.string	"__DBL_MAX_10_EXP__ 308"
.LASF390:
	.string	"datetime_type"
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
.LASF214:
	.string	"__FLT64_DECIMAL_DIG__ 17"
.LASF364:
	.string	"CGC_FD_ISSET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] & (1 << (b & (CGC__NFDBITS - 1))))"
.LASF153:
	.string	"__FLT_MIN_EXP__ (-125)"
.LASF282:
	.string	"__DEC128_MAX__ 9.999999999999999999999999999999999E6144DL"
.LASF419:
	.string	"location"
.LASF358:
	.string	"SIZE_MAX (~((cgc_size_t)0ULL))"
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
.LASF218:
	.string	"__FLT64_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F64"
.LASF38:
	.string	"__WCHAR_TYPE__ long int"
.LASF431:
	.string	"cgc_edit_dives"
.LASF116:
	.string	"__INT_LEAST32_MAX__ 0x7fffffff"
.LASF425:
	.string	"cgc_size_t"
.LASF407:
	.string	"dive_site_name"
.LASF184:
	.string	"__LDBL_MAX_10_EXP__ 4932"
.LASF416:
	.string	"water_type"
.LASF201:
	.string	"__FLT32_MAX__ 3.40282346638528859811704183484516925e+38F32"
.LASF174:
	.string	"__DBL_EPSILON__ ((double)2.22044604925031308084726333618164062e-16L)"
.LASF171:
	.string	"__DBL_DECIMAL_DIG__ 17"
.LASF330:
	.string	"unix 1"
.LASF305:
	.string	"__PRAGMA_REDEFINE_EXTNAME 1"
.LASF44:
	.string	"__SIG_ATOMIC_TYPE__ int"
.LASF260:
	.string	"__FLT64X_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951F64x"
.LASF233:
	.string	"__FLT128_HAS_DENORM__ 1"
.LASF39:
	.string	"__WINT_TYPE__ unsigned int"
.LASF191:
	.string	"__LDBL_HAS_DENORM__ 1"
.LASF166:
	.string	"__DBL_DIG__ 15"
.LASF271:
	.string	"__DEC64_MANT_DIG__ 16"
.LASF162:
	.string	"__FLT_HAS_DENORM__ 1"
.LASF439:
	.string	"/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/src/edit_dives.c"
.LASF185:
	.string	"__DECIMAL_DIG__ 21"
	.ident	"GCC: (Ubuntu 8.4.0-1ubuntu1~18.04) 8.4.0"
	.section	.note.GNU-stack,"",@progbits
