	.file	"malloc.c"
	.text
.Ltext0:
	.comm	g_memManager,4,4
	.globl	cgc_calloc
	.type	cgc_calloc, @function
cgc_calloc:
.LFB0:
	.file 1 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/malloc.c"
	.loc 1 41 1
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
	.loc 1 42 16
	movl	8(%ebp), %eax
	imull	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	.loc 1 45 18
	subl	$12, %esp
	pushl	-12(%ebp)
	call	cgc_malloc
	addl	$16, %esp
	movl	%eax, -16(%ebp)
	.loc 1 47 5
	subl	$4, %esp
	pushl	-12(%ebp)
	pushl	$0
	pushl	-16(%ebp)
	call	cgc_memset@PLT
	addl	$16, %esp
	.loc 1 49 12
	movl	-16(%ebp), %eax
	.loc 1 50 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	cgc_calloc, .-cgc_calloc
	.globl	cgc_add_free_list
	.type	cgc_add_free_list, @function
cgc_add_free_list:
.LFB1:
	.loc 1 53 1
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
	.loc 1 55 16
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, -12(%ebp)
	.loc 1 58 20
	movl	-12(%ebp), %eax
	andl	$4095, %eax
	.loc 1 58 8
	testl	%eax, %eax
	je	.L4
	.loc 1 60 32
	movl	-12(%ebp), %eax
	shrl	$12, %eax
	.loc 1 60 19
	addl	$1, %eax
	movl	%eax, -12(%ebp)
	.loc 1 61 19
	sall	$12, -12(%ebp)
.L4:
	.loc 1 66 10
	subl	$4, %esp
	leal	-24(%ebp), %eax
	pushl	%eax
	pushl	$0
	pushl	-12(%ebp)
	call	cgc_allocate@PLT
	addl	$16, %esp
	.loc 1 66 8
	testl	%eax, %eax
	je	.L5
	.loc 1 69 9
	subl	$12, %esp
	pushl	$-2
	call	cgc__terminate@PLT
.L5:
	.loc 1 73 22
	movl	-24(%ebp), %eax
	movl	%eax, -16(%ebp)
	.loc 1 74 72
	movl	-24(%ebp), %eax
	movl	-12(%ebp), %edx
	subl	$8, %edx
	.loc 1 74 22
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
	.loc 1 76 42
	movl	-12(%ebp), %eax
	leal	-4(%eax), %edx
	.loc 1 76 30
	movl	-16(%ebp), %eax
	movl	%edx, (%eax)
	.loc 1 79 25
	movl	-20(%ebp), %eax
	movl	$0, 4(%eax)
	.loc 1 80 39
	movl	g_memManager@GOT(%ebx), %eax
	movl	(%eax), %edx
	.loc 1 80 25
	movl	-20(%ebp), %eax
	movl	%edx, (%eax)
	.loc 1 81 28
	movl	g_memManager@GOT(%ebx), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%eax)
	.loc 1 83 12
	movl	-16(%ebp), %eax
	.loc 1 84 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	cgc_add_free_list, .-cgc_add_free_list
	.section	.rodata
.LC0:
	.string	"Footer != in malloc"
	.text
	.globl	cgc_malloc
	.type	cgc_malloc, @function
cgc_malloc:
.LFB2:
	.loc 1 87 1
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
	.loc 1 89 8
	cmpl	$7, 8(%ebp)
	ja	.L8
	.loc 1 90 20
	movl	$8, 8(%ebp)
	jmp	.L9
.L8:
	.loc 1 91 26
	movl	8(%ebp), %eax
	andl	$3, %eax
	.loc 1 91 13
	testl	%eax, %eax
	je	.L9
	.loc 1 93 34
	movl	8(%ebp), %eax
	shrl	$2, %eax
	.loc 1 93 20
	addl	$1, %eax
	movl	%eax, 8(%ebp)
	.loc 1 94 20
	sall	$2, 8(%ebp)
.L9:
	.loc 1 100 14
	movl	g_memManager@GOT(%ebx), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
.L23:
.LBB2:
	.loc 1 104 12
	cmpl	$0, -12(%ebp)
	jne	.L10
	.loc 1 107 24
	subl	$12, %esp
	pushl	8(%ebp)
	call	cgc_add_free_list
	addl	$16, %esp
	movl	%eax, -12(%ebp)
.L10:
	.loc 1 110 26
	movl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	.loc 1 111 90
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 111 103
	andl	$-4, %eax
	.loc 1 111 110
	leal	-4(%eax), %edx
	.loc 1 111 26
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
	.loc 1 114 28
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 114 12
	cmpl	%eax, 8(%ebp)
	ja	.L11
.LBB3:
	.loc 1 117 19
	movl	-12(%ebp), %eax
	addl	$4, %eax
	movl	%eax, -24(%ebp)
	.loc 1 120 55
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 120 24
	subl	8(%ebp), %eax
	movl	%eax, -28(%ebp)
	.loc 1 123 40
	movl	-16(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	.loc 1 126 41
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	orl	$1, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movl	%edx, (%eax)
	.loc 1 128 16
	cmpl	$11, -28(%ebp)
	jbe	.L12
.LBB4:
	.loc 1 131 45
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	.loc 1 131 23
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -32(%ebp)
	.loc 1 133 34
	movl	-32(%ebp), %eax
	movl	%eax, -36(%ebp)
	.loc 1 134 63
	movl	-28(%ebp), %eax
	leal	-4(%eax), %edx
	.loc 1 134 45
	movl	-36(%ebp), %eax
	movl	%edx, (%eax)
	.loc 1 136 34
	movl	-20(%ebp), %eax
	movl	%eax, -40(%ebp)
	.loc 1 138 65
	movl	-36(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 138 78
	andl	$-4, %eax
	.loc 1 138 85
	leal	-4(%eax), %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	.loc 1 138 20
	cmpl	%eax, -20(%ebp)
	je	.L13
	.loc 1 140 21
	subl	$12, %esp
	leal	.LC0@GOTOFF(%ebx), %eax
	pushl	%eax
	call	cgc_printf@PLT
	addl	$16, %esp
	.loc 1 141 21
	subl	$12, %esp
	pushl	$-3
	call	cgc__terminate@PLT
.L13:
	.loc 1 145 34
	movl	g_memManager@GOT(%ebx), %eax
	movl	(%eax), %eax
	.loc 1 145 20
	cmpl	%eax, -12(%ebp)
	jne	.L14
	.loc 1 147 44
	movl	g_memManager@GOT(%ebx), %eax
	movl	-36(%ebp), %edx
	movl	%edx, (%eax)
	.loc 1 149 41
	movl	-40(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 149 24
	testl	%eax, %eax
	je	.L16
	.loc 1 150 70
	movl	-40(%ebp), %eax
	movl	(%eax), %edx
	.loc 1 150 116
	movl	-40(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 150 124
	movl	(%eax), %eax
	.loc 1 150 137
	andl	$-4, %eax
	.loc 1 150 144
	subl	$4, %eax
	.loc 1 150 27
	addl	%eax, %edx
	.loc 1 150 179
	movl	-36(%ebp), %eax
	movl	%eax, 4(%edx)
	jmp	.L16
.L14:
	.loc 1 155 41
	movl	-40(%ebp), %eax
	movl	4(%eax), %eax
	.loc 1 155 24
	testl	%eax, %eax
	je	.L17
	.loc 1 156 70
	movl	-40(%ebp), %eax
	movl	4(%eax), %edx
	.loc 1 156 116
	movl	-40(%ebp), %eax
	movl	4(%eax), %eax
	.loc 1 156 124
	movl	(%eax), %eax
	.loc 1 156 137
	andl	$-4, %eax
	.loc 1 156 144
	subl	$4, %eax
	.loc 1 156 27
	addl	%eax, %edx
	.loc 1 156 179
	movl	-32(%ebp), %eax
	movl	%eax, (%edx)
.L17:
	.loc 1 158 41
	movl	-40(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 158 24
	testl	%eax, %eax
	je	.L16
	.loc 1 159 70
	movl	-40(%ebp), %eax
	movl	(%eax), %edx
	.loc 1 159 116
	movl	-40(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 159 124
	movl	(%eax), %eax
	.loc 1 159 137
	andl	$-4, %eax
	.loc 1 159 144
	subl	$4, %eax
	.loc 1 159 27
	addl	%eax, %edx
	.loc 1 159 179
	movl	-32(%ebp), %eax
	movl	%eax, 4(%edx)
.L16:
	.loc 1 163 45
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	orl	$2, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movl	%edx, (%eax)
.LBE4:
	jmp	.L18
.L12:
	.loc 1 168 34
	movl	g_memManager@GOT(%ebx), %eax
	movl	(%eax), %eax
	.loc 1 168 20
	cmpl	%eax, -12(%ebp)
	jne	.L19
	.loc 1 170 68
	movl	-20(%ebp), %eax
	movl	(%eax), %edx
	.loc 1 170 44
	movl	g_memManager@GOT(%ebx), %eax
	movl	%edx, (%eax)
	.loc 1 172 40
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 172 24
	testl	%eax, %eax
	je	.L18
	.loc 1 173 69
	movl	-20(%ebp), %eax
	movl	(%eax), %edx
	.loc 1 173 114
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 173 122
	movl	(%eax), %eax
	.loc 1 173 135
	andl	$-4, %eax
	.loc 1 173 142
	subl	$4, %eax
	.loc 1 173 27
	addl	%edx, %eax
	.loc 1 173 177
	movl	$0, 4(%eax)
	jmp	.L18
.L19:
	.loc 1 178 40
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	.loc 1 178 24
	testl	%eax, %eax
	je	.L21
	.loc 1 179 69
	movl	-20(%ebp), %eax
	movl	4(%eax), %edx
	.loc 1 179 114
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	.loc 1 179 122
	movl	(%eax), %eax
	.loc 1 179 135
	andl	$-4, %eax
	.loc 1 179 142
	subl	$4, %eax
	.loc 1 179 27
	addl	%eax, %edx
	.loc 1 179 193
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 179 177
	movl	%eax, (%edx)
.L21:
	.loc 1 181 40
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 181 24
	testl	%eax, %eax
	je	.L18
	.loc 1 182 69
	movl	-20(%ebp), %eax
	movl	(%eax), %edx
	.loc 1 182 114
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 182 122
	movl	(%eax), %eax
	.loc 1 182 135
	andl	$-4, %eax
	.loc 1 182 142
	subl	$4, %eax
	.loc 1 182 27
	addl	%eax, %edx
	.loc 1 182 193
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	.loc 1 182 177
	movl	%eax, 4(%edx)
.L18:
	.loc 1 188 13
	movl	-12(%ebp), %eax
	addl	$4, %eax
	subl	$4, %esp
	pushl	8(%ebp)
	pushl	$0
	pushl	%eax
	call	cgc_memset@PLT
	addl	$16, %esp
	.loc 1 191 29
	movl	-12(%ebp), %eax
	addl	$4, %eax
	jmp	.L24
.L11:
.LBE3:
	.loc 1 195 18
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
.LBE2:
	.loc 1 103 5
	jmp	.L23
.L24:
	.loc 1 197 1 discriminator 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	cgc_malloc, .-cgc_malloc
	.globl	cgc_free
	.type	cgc_free, @function
cgc_free:
.LFB3:
	.loc 1 200 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	.loc 1 204 22
	movl	8(%ebp), %edx
	subl	$4, %edx
	movl	%edx, -12(%ebp)
	.loc 1 207 20
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	.loc 1 207 33
	andl	$1, %edx
	.loc 1 207 8
	testl	%edx, %edx
	jne	.L26
	.loc 1 210 9
	subl	$12, %esp
	pushl	$-2
	movl	%eax, %ebx
	call	cgc__terminate@PLT
.L26:
	.loc 1 214 19
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	.loc 1 214 32
	andl	$2, %edx
	.loc 1 214 8
	testl	%edx, %edx
	je	.L27
.LBB5:
	.loc 1 216 56
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	.loc 1 216 69
	movl	%edx, %ecx
	andl	$-4, %ecx
	.loc 1 216 26
	movl	8(%ebp), %edx
	addl	%ecx, %edx
	movl	%edx, -16(%ebp)
	.loc 1 219 25
	movl	-16(%ebp), %edx
	movl	(%edx), %edx
	.loc 1 219 38
	andl	$1, %edx
	.loc 1 219 12
	testl	%edx, %edx
	jne	.L27
.LBB6:
	.loc 1 222 48
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	.loc 1 222 61
	movl	%edx, %ecx
	andl	$-4, %ecx
	.loc 1 222 81
	movl	-16(%ebp), %edx
	movl	(%edx), %edx
	.loc 1 222 94
	andl	$-4, %edx
	.loc 1 222 69
	addl	%ecx, %edx
	.loc 1 222 24
	addl	$4, %edx
	movl	%edx, -20(%ebp)
	.loc 1 226 34
	movl	-12(%ebp), %edx
	movl	-20(%ebp), %ecx
	movl	%ecx, (%edx)
	.loc 1 229 28
	movl	-16(%ebp), %edx
	movl	(%edx), %edx
	.loc 1 229 41
	andl	$2, %edx
	.loc 1 229 16
	testl	%edx, %edx
	je	.L28
	.loc 1 230 39
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, %ecx
	orl	$2, %ecx
	movl	-12(%ebp), %edx
	movl	%ecx, (%edx)
.L28:
	.loc 1 233 30
	movl	g_memManager@GOT(%eax), %edx
	movl	(%edx), %edx
	.loc 1 233 16
	cmpl	%edx, -16(%ebp)
	jne	.L29
.LBB7:
	.loc 1 235 40
	movl	g_memManager@GOT(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	.loc 1 237 97
	movl	-20(%ebp), %eax
	leal	-4(%eax), %edx
	.loc 1 237 34
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -24(%ebp)
	.loc 1 239 30
	movl	-24(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 239 20
	testl	%eax, %eax
	je	.L35
	.loc 1 240 59
	movl	-24(%ebp), %eax
	movl	(%eax), %edx
	.loc 1 240 98
	movl	-24(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 240 106
	movl	(%eax), %eax
	.loc 1 240 119
	andl	$-4, %eax
	.loc 1 240 126
	subl	$4, %eax
	.loc 1 240 23
	addl	%eax, %edx
	.loc 1 240 161
	movl	-12(%ebp), %eax
	movl	%eax, 4(%edx)
.LBE7:
	.loc 1 255 13
	jmp	.L35
.L29:
.LBB8:
	.loc 1 244 97
	movl	-20(%ebp), %eax
	leal	-4(%eax), %edx
	.loc 1 244 34
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -28(%ebp)
	.loc 1 247 30
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	.loc 1 247 20
	testl	%eax, %eax
	je	.L32
	.loc 1 248 59
	movl	-28(%ebp), %eax
	movl	4(%eax), %edx
	.loc 1 248 98
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	.loc 1 248 106
	movl	(%eax), %eax
	.loc 1 248 119
	andl	$-4, %eax
	.loc 1 248 126
	subl	$4, %eax
	.loc 1 248 23
	addl	%eax, %edx
	.loc 1 248 161
	movl	-12(%ebp), %eax
	movl	%eax, (%edx)
.L32:
	.loc 1 250 30
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 250 20
	testl	%eax, %eax
	je	.L35
	.loc 1 251 59
	movl	-28(%ebp), %eax
	movl	(%eax), %edx
	.loc 1 251 98
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	.loc 1 251 106
	movl	(%eax), %eax
	.loc 1 251 119
	andl	$-4, %eax
	.loc 1 251 126
	subl	$4, %eax
	.loc 1 251 23
	addl	%eax, %edx
	.loc 1 251 161
	movl	-12(%ebp), %eax
	movl	%eax, 4(%edx)
.LBE8:
	.loc 1 255 13
	jmp	.L35
.L27:
.LBE6:
.LBE5:
	.loc 1 260 27
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, %ecx
	andl	$-2, %ecx
	movl	-12(%ebp), %edx
	movl	%ecx, (%edx)
	.loc 1 262 82
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	.loc 1 262 95
	andl	$-4, %edx
	.loc 1 262 102
	leal	-4(%edx), %ecx
	.loc 1 262 22
	movl	-12(%ebp), %edx
	addl	%ecx, %edx
	movl	%edx, -32(%ebp)
	.loc 1 264 35
	movl	g_memManager@GOT(%eax), %edx
	movl	(%edx), %ecx
	.loc 1 264 21
	movl	-32(%ebp), %edx
	movl	%ecx, (%edx)
	.loc 1 265 21
	movl	-32(%ebp), %edx
	movl	$0, 4(%edx)
	.loc 1 267 22
	movl	g_memManager@GOT(%eax), %edx
	movl	(%edx), %edx
	.loc 1 267 8
	testl	%edx, %edx
	je	.L34
	.loc 1 268 51
	movl	g_memManager@GOT(%eax), %edx
	movl	(%edx), %ecx
	.loc 1 268 97
	movl	g_memManager@GOT(%eax), %edx
	movl	(%edx), %edx
	.loc 1 268 108
	movl	(%edx), %edx
	.loc 1 268 121
	andl	$-4, %edx
	.loc 1 268 128
	subl	$4, %edx
	addl	%edx, %ecx
	.loc 1 268 163
	movl	-12(%ebp), %edx
	movl	%edx, 4(%ecx)
.L34:
	.loc 1 271 28
	movl	g_memManager@GOT(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	.loc 1 274 5
	nop
	jmp	.L25
.L35:
.LBB10:
.LBB9:
	.loc 1 255 13
	nop
.L25:
.LBE9:
.LBE10:
	.loc 1 275 1
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	cgc_free, .-cgc_free
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB4:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE4:
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LFB5:
	.cfi_startproc
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE5:
	.text
.Letext0:
	.file 2 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/include/libcgc.h"
	.file 3 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/include/cgc_malloc.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x31b
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF431
	.byte	0xc
	.long	.LASF432
	.long	.LASF433
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.long	.Ldebug_macro0
	.uleb128 0x2
	.long	.LASF394
	.byte	0x2
	.byte	0x13
	.byte	0x17
	.long	0x35
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF390
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.long	.LASF391
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF392
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF393
	.uleb128 0x5
	.long	.LASF396
	.byte	0x4
	.byte	0x3
	.byte	0x24
	.byte	0x10
	.long	0x73
	.uleb128 0x6
	.long	.LASF398
	.byte	0x3
	.byte	0x26
	.byte	0x10
	.long	0x29
	.byte	0
	.byte	0
	.uleb128 0x2
	.long	.LASF395
	.byte	0x3
	.byte	0x27
	.byte	0x3
	.long	0x58
	.uleb128 0x5
	.long	.LASF397
	.byte	0x8
	.byte	0x3
	.byte	0x2a
	.byte	0x10
	.long	0xa7
	.uleb128 0x6
	.long	.LASF399
	.byte	0x3
	.byte	0x2c
	.byte	0x1e
	.long	0xa7
	.byte	0
	.uleb128 0x6
	.long	.LASF400
	.byte	0x3
	.byte	0x2d
	.byte	0x1e
	.long	0xa7
	.byte	0x4
	.byte	0
	.uleb128 0x7
	.byte	0x4
	.long	0x58
	.uleb128 0x2
	.long	.LASF401
	.byte	0x3
	.byte	0x2e
	.byte	0x3
	.long	0x7f
	.uleb128 0x5
	.long	.LASF402
	.byte	0x4
	.byte	0x3
	.byte	0x30
	.byte	0x10
	.long	0xd4
	.uleb128 0x6
	.long	.LASF403
	.byte	0x3
	.byte	0x32
	.byte	0xb
	.long	0xd4
	.byte	0
	.byte	0
	.uleb128 0x8
	.byte	0x4
	.uleb128 0x2
	.long	.LASF404
	.byte	0x3
	.byte	0x33
	.byte	0x3
	.long	0xb9
	.uleb128 0x9
	.long	.LASF434
	.byte	0x1
	.byte	0x26
	.byte	0x10
	.long	0xd6
	.uleb128 0x5
	.byte	0x3
	.long	g_memManager
	.uleb128 0xa
	.long	.LASF425
	.byte	0x1
	.byte	0xc7
	.byte	0x6
	.long	.LFB3
	.long	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x199
	.uleb128 0xb
	.long	.LASF409
	.byte	0x1
	.byte	0xc7
	.byte	0x16
	.long	0xd4
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xc
	.long	.LASF405
	.byte	0x1
	.byte	0xcc
	.byte	0x16
	.long	0x199
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xd
	.long	.LASF406
	.byte	0x1
	.value	0x106
	.byte	0x16
	.long	0x19f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xe
	.long	.Ldebug_ranges0+0
	.uleb128 0xc
	.long	.LASF407
	.byte	0x1
	.byte	0xd8
	.byte	0x1a
	.long	0x199
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xe
	.long	.Ldebug_ranges0+0x18
	.uleb128 0xc
	.long	.LASF408
	.byte	0x1
	.byte	0xde
	.byte	0x18
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xf
	.long	.LBB7
	.long	.LBE7-.LBB7
	.long	0x17d
	.uleb128 0xc
	.long	.LASF406
	.byte	0x1
	.byte	0xed
	.byte	0x22
	.long	0x19f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.byte	0
	.uleb128 0x10
	.long	.LBB8
	.long	.LBE8-.LBB8
	.uleb128 0xc
	.long	.LASF406
	.byte	0x1
	.byte	0xf4
	.byte	0x22
	.long	0x19f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x7
	.byte	0x4
	.long	0x73
	.uleb128 0x7
	.byte	0x4
	.long	0xad
	.uleb128 0x11
	.long	.LASF418
	.byte	0x1
	.byte	0x56
	.byte	0x7
	.long	0xd4
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x265
	.uleb128 0xb
	.long	.LASF398
	.byte	0x1
	.byte	0x56
	.byte	0x1e
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xc
	.long	.LASF410
	.byte	0x1
	.byte	0x62
	.byte	0xb
	.long	0xd4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x10
	.long	.LBB2
	.long	.LBE2-.LBB2
	.uleb128 0xc
	.long	.LASF411
	.byte	0x1
	.byte	0x6e
	.byte	0x1a
	.long	0x199
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xc
	.long	.LASF412
	.byte	0x1
	.byte	0x6f
	.byte	0x1a
	.long	0x19f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x10
	.long	.LBB3
	.long	.LBE3-.LBB3
	.uleb128 0xc
	.long	.LASF413
	.byte	0x1
	.byte	0x75
	.byte	0x13
	.long	0xd4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xc
	.long	.LASF414
	.byte	0x1
	.byte	0x78
	.byte	0x18
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x10
	.long	.LBB4
	.long	.LBE4-.LBB4
	.uleb128 0xc
	.long	.LASF415
	.byte	0x1
	.byte	0x83
	.byte	0x17
	.long	0xd4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xc
	.long	.LASF416
	.byte	0x1
	.byte	0x85
	.byte	0x22
	.long	0x199
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0xc
	.long	.LASF417
	.byte	0x1
	.byte	0x88
	.byte	0x22
	.long	0x19f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x11
	.long	.LASF419
	.byte	0x1
	.byte	0x34
	.byte	0x7
	.long	0xd4
	.long	.LFB1
	.long	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x2cb
	.uleb128 0xb
	.long	.LASF420
	.byte	0x1
	.byte	0x34
	.byte	0x25
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xc
	.long	.LASF421
	.byte	0x1
	.byte	0x37
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xc
	.long	.LASF422
	.byte	0x1
	.byte	0x40
	.byte	0xb
	.long	0xd4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xc
	.long	.LASF423
	.byte	0x1
	.byte	0x49
	.byte	0x16
	.long	0x199
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xc
	.long	.LASF424
	.byte	0x1
	.byte	0x4a
	.byte	0x16
	.long	0x19f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.byte	0
	.uleb128 0x12
	.long	.LASF426
	.byte	0x1
	.byte	0x28
	.byte	0x7
	.long	0xd4
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xb
	.long	.LASF427
	.byte	0x1
	.byte	0x28
	.byte	0x1e
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xb
	.long	.LASF428
	.byte	0x1
	.byte	0x28
	.byte	0x30
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xc
	.long	.LASF429
	.byte	0x1
	.byte	0x2a
	.byte	0x10
	.long	0x29
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xc
	.long	.LASF430
	.byte	0x1
	.byte	0x2b
	.byte	0xb
	.long	0xd4
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
	.uleb128 0x6
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
	.uleb128 0x7
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
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
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xa
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
	.uleb128 0xb
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
	.uleb128 0xc
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
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0xf
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
	.uleb128 0x10
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x11
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
	.uleb128 0x12
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
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.long	.LBB5-.Ltext0
	.long	.LBE5-.Ltext0
	.long	.LBB10-.Ltext0
	.long	.LBE10-.Ltext0
	.long	0
	.long	0
	.long	.LBB6-.Ltext0
	.long	.LBE6-.Ltext0
	.long	.LBB9-.Ltext0
	.long	.LBE9-.Ltext0
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
	.file 5 "/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/cgc_stdlib.h"
	.byte	0x3
	.uleb128 0x1a
	.uleb128 0x5
	.byte	0x7
	.long	.Ldebug_macro3
	.byte	0x3
	.uleb128 0x20
	.uleb128 0x2
	.byte	0x7
	.long	.Ldebug_macro4
	.byte	0x4
	.byte	0x4
	.byte	0x3
	.uleb128 0x1b
	.uleb128 0x3
	.byte	0x7
	.long	.Ldebug_macro5
	.byte	0x4
	.byte	0x5
	.uleb128 0x1d
	.long	.LASF384
	.byte	0x5
	.uleb128 0x1f
	.long	.LASF385
	.byte	0x5
	.uleb128 0x20
	.long	.LASF386
	.byte	0x5
	.uleb128 0x22
	.long	.LASF387
	.byte	0x5
	.uleb128 0x23
	.long	.LASF388
	.byte	0x5
	.uleb128 0x24
	.long	.LASF389
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
	.long	.LASF342
	.byte	0x5
	.uleb128 0x1d
	.long	.LASF343
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF344
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.libcgc.h.2.1ca842f70535d048924a5ff19c40f3ba,comdat
.Ldebug_macro4:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x2
	.long	.LASF345
	.byte	0x5
	.uleb128 0x4
	.long	.LASF346
	.byte	0x5
	.uleb128 0x5
	.long	.LASF347
	.byte	0x5
	.uleb128 0x6
	.long	.LASF348
	.byte	0x5
	.uleb128 0xb
	.long	.LASF349
	.byte	0x5
	.uleb128 0x1a
	.long	.LASF350
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF351
	.byte	0x5
	.uleb128 0x22
	.long	.LASF352
	.byte	0x5
	.uleb128 0x26
	.long	.LASF353
	.byte	0x5
	.uleb128 0x2a
	.long	.LASF354
	.byte	0x5
	.uleb128 0x2e
	.long	.LASF355
	.byte	0x5
	.uleb128 0x31
	.long	.LASF356
	.byte	0x5
	.uleb128 0x35
	.long	.LASF357
	.byte	0x5
	.uleb128 0x3b
	.long	.LASF358
	.byte	0x5
	.uleb128 0x42
	.long	.LASF359
	.byte	0x5
	.uleb128 0x45
	.long	.LASF360
	.byte	0x5
	.uleb128 0x48
	.long	.LASF361
	.byte	0x5
	.uleb128 0x50
	.long	.LASF362
	.byte	0x5
	.uleb128 0x51
	.long	.LASF363
	.byte	0x5
	.uleb128 0x52
	.long	.LASF364
	.byte	0x5
	.uleb128 0x53
	.long	.LASF365
	.byte	0x5
	.uleb128 0x54
	.long	.LASF366
	.byte	0x5
	.uleb128 0x55
	.long	.LASF367
	.byte	0x5
	.uleb128 0x58
	.long	.LASF368
	.byte	0x5
	.uleb128 0x59
	.long	.LASF369
	.byte	0x5
	.uleb128 0x5a
	.long	.LASF370
	.byte	0x5
	.uleb128 0x5b
	.long	.LASF371
	.byte	0x5
	.uleb128 0x5c
	.long	.LASF372
	.byte	0x5
	.uleb128 0x5d
	.long	.LASF373
	.byte	0x5
	.uleb128 0x5f
	.long	.LASF374
	.byte	0x5
	.uleb128 0x60
	.long	.LASF375
	.byte	0x5
	.uleb128 0x61
	.long	.LASF376
	.byte	0x5
	.uleb128 0x62
	.long	.LASF377
	.byte	0x5
	.uleb128 0x63
	.long	.LASF378
	.byte	0x5
	.uleb128 0x64
	.long	.LASF379
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.cgc_malloc.h.27.8e20c265000e1b186a70e4820fe3d8a9,comdat
.Ldebug_macro5:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1b
	.long	.LASF380
	.byte	0x5
	.uleb128 0x20
	.long	.LASF381
	.byte	0x5
	.uleb128 0x21
	.long	.LASF382
	.byte	0x5
	.uleb128 0x22
	.long	.LASF383
	.byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF391:
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
.LASF123:
	.string	"__UINT8_C(c) c"
.LASF367:
	.string	"CGC_EPIPE 6"
.LASF333:
	.string	"FORTIFY_SOURCE 0"
.LASF242:
	.string	"__FLT32X_DECIMAL_DIG__ 17"
.LASF404:
	.string	"tMallocManager"
.LASF167:
	.string	"__DBL_MIN_EXP__ (-1021)"
.LASF72:
	.string	"__has_include_next(STR) __has_include_next__(STR)"
.LASF371:
	.string	"FD_SET CGC_FD_SET"
.LASF318:
	.string	"__i686__ 1"
.LASF243:
	.string	"__FLT32X_MAX__ 1.79769313486231570814527423731704357e+308F32x"
.LASF307:
	.string	"__SIZEOF_WINT_T__ 4"
.LASF383:
	.string	"MALLOC_BUCKET_COUNT (16)"
.LASF359:
	.string	"CGC_FD_SET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] |= (1 << (b & (CGC__NFDBITS - 1))))"
.LASF6:
	.string	"__GNUC_MINOR__ 4"
.LASF340:
	.string	"__STDC_ISO_10646__ 201706L"
.LASF411:
	.string	"pFreeCurHeader"
.LASF392:
	.string	"unsigned int"
.LASF420:
	.string	"request_size"
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
.LASF434:
	.string	"g_memManager"
.LASF165:
	.string	"__DBL_MANT_DIG__ 53"
.LASF422:
	.string	"pAllocLocation"
.LASF201:
	.string	"__FLT32_MAX__ 3.40282346638528859811704183484516925e+38F32"
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
.LASF350:
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
.LASF80:
	.string	"__WCHAR_MIN__ (-__WCHAR_MAX__ - 1)"
.LASF3:
	.string	"__STDC_UTF_32__ 1"
.LASF113:
	.string	"__INT_LEAST16_MAX__ 0x7fff"
.LASF74:
	.string	"__SCHAR_MAX__ 0x7f"
.LASF284:
	.string	"__DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL"
.LASF380:
	.string	"__MALLOC_H__ "
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
.LASF412:
	.string	"pFreeCurFooter"
.LASF64:
	.string	"__INT_FAST64_TYPE__ long long int"
.LASF235:
	.string	"__FLT128_HAS_QUIET_NAN__ 1"
.LASF229:
	.string	"__FLT128_MAX__ 1.18973149535723176508575932662800702e+4932F128"
.LASF55:
	.string	"__INT_LEAST32_TYPE__ int"
.LASF115:
	.string	"__INT_LEAST16_WIDTH__ 16"
.LASF368:
	.string	"FD_SETSIZE CGC_FD_SETSIZE"
.LASF406:
	.string	"pItemFtr"
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
.LASF132:
	.string	"__INT_FAST16_MAX__ 0x7fffffff"
.LASF17:
	.string	"__pie__ 2"
.LASF267:
	.string	"__DEC32_MIN__ 1E-95DF"
.LASF427:
	.string	"count"
.LASF217:
	.string	"__FLT64_EPSILON__ 2.22044604925031308084726333618164062e-16F64"
.LASF349:
	.string	"NULL (0)"
.LASF145:
	.string	"__GCC_IEC_559 2"
.LASF224:
	.string	"__FLT128_MIN_EXP__ (-16381)"
.LASF83:
	.string	"__PTRDIFF_MAX__ 0x7fffffff"
.LASF207:
	.string	"__FLT32_HAS_QUIET_NAN__ 1"
.LASF403:
	.string	"pFreeList"
.LASF124:
	.string	"__UINT_LEAST16_MAX__ 0xffff"
.LASF200:
	.string	"__FLT32_DECIMAL_DIG__ 9"
.LASF381:
	.string	"MALLOC_INUSE_FLAG_BIT (1)"
.LASF122:
	.string	"__UINT_LEAST8_MAX__ 0xff"
.LASF279:
	.string	"__DEC128_MIN_EXP__ (-6142)"
.LASF424:
	.string	"pNewAllocFtr"
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
.LASF178:
	.string	"__DBL_HAS_QUIET_NAN__ 1"
.LASF388:
	.string	"CLEAR_BIT(val,bit) (val &= ~(bit))"
.LASF190:
	.string	"__LDBL_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951L"
.LASF396:
	.string	"MALLOC_ALLOC_HDR"
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
.LASF70:
	.string	"__UINTPTR_TYPE__ unsigned int"
.LASF275:
	.string	"__DEC64_MAX__ 9.999999999999999E384DD"
.LASF299:
	.string	"__GCC_ATOMIC_INT_LOCK_FREE 2"
.LASF94:
	.string	"__INTMAX_MAX__ 0x7fffffffffffffffLL"
.LASF81:
	.string	"__WINT_MAX__ 0xffffffffU"
.LASF251:
	.string	"__FLT64X_DIG__ 18"
.LASF413:
	.string	"pClaimAllocation"
.LASF121:
	.string	"__INT_LEAST64_WIDTH__ 64"
.LASF222:
	.string	"__FLT128_MANT_DIG__ 113"
.LASF30:
	.string	"__ORDER_LITTLE_ENDIAN__ 1234"
.LASF308:
	.string	"__SIZEOF_PTRDIFF_T__ 4"
.LASF164:
	.string	"__FLT_HAS_QUIET_NAN__ 1"
.LASF47:
	.string	"__INT32_TYPE__ int"
.LASF346:
	.string	"STDIN 0"
.LASF261:
	.string	"__FLT64X_HAS_DENORM__ 1"
.LASF266:
	.string	"__DEC32_MAX_EXP__ 97"
.LASF8:
	.string	"__VERSION__ \"8.4.0\""
.LASF5:
	.string	"__GNUC__ 8"
.LASF339:
	.string	"__STDC_IEC_559_COMPLEX__ 1"
.LASF362:
	.string	"CGC_EBADF 1"
.LASF336:
	.string	"errno __cgc_errno"
.LASF253:
	.string	"__FLT64X_MIN_10_EXP__ (-4931)"
.LASF99:
	.string	"__SIG_ATOMIC_MAX__ 0x7fffffff"
.LASF416:
	.string	"pNewChunkHeader"
.LASF60:
	.string	"__UINT_LEAST64_TYPE__ long long unsigned int"
.LASF227:
	.string	"__FLT128_MAX_10_EXP__ 4932"
.LASF230:
	.string	"__FLT128_MIN__ 3.36210314311209350626267781732175260e-4932F128"
.LASF211:
	.string	"__FLT64_MIN_10_EXP__ (-307)"
.LASF373:
	.string	"FD_ISSET CGC_FD_ISSET"
.LASF172:
	.string	"__DBL_MAX__ ((double)1.79769313486231570814527423731704357e+308L)"
.LASF417:
	.string	"pNewChunkFooter"
.LASF356:
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
.LASF370:
	.string	"FD_ZERO CGC_FD_ZERO"
.LASF78:
	.string	"__LONG_LONG_MAX__ 0x7fffffffffffffffLL"
.LASF48:
	.string	"__INT64_TYPE__ long long int"
.LASF156:
	.string	"__FLT_MAX_10_EXP__ 38"
.LASF245:
	.string	"__FLT32X_EPSILON__ 2.22044604925031308084726333618164062e-16F32x"
.LASF386:
	.string	"FREE_BLOCK_PREV(block) (((tMallocAllocFtr *)((void *)block + (((tMallocAllocHdr *)block)->alloc_size & ~0x3)-sizeof(tMallocAllocHdr)))->pPrev)"
.LASF419:
	.string	"cgc_add_free_list"
.LASF288:
	.string	"__NO_INLINE__ 1"
.LASF151:
	.string	"__FLT_MANT_DIG__ 24"
.LASF214:
	.string	"__FLT64_DECIMAL_DIG__ 17"
.LASF291:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1"
.LASF196:
	.string	"__FLT32_MIN_EXP__ (-125)"
.LASF432:
	.string	"/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/SCUBA_Dive_Logging/lib/malloc.c"
.LASF63:
	.string	"__INT_FAST32_TYPE__ int"
.LASF139:
	.string	"__UINT_FAST16_MAX__ 0xffffffffU"
.LASF66:
	.string	"__UINT_FAST16_TYPE__ unsigned int"
.LASF158:
	.string	"__FLT_MAX__ 3.40282346638528859811704183484516925e+38F"
.LASF168:
	.string	"__DBL_MIN_10_EXP__ (-307)"
.LASF393:
	.string	"char"
.LASF73:
	.string	"__GXX_ABI_VERSION 1013"
.LASF182:
	.string	"__LDBL_MIN_10_EXP__ (-4931)"
.LASF342:
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
.LASF352:
	.string	"CGC_FLAG_PAGE_ADDRESS 0x4347C000"
.LASF364:
	.string	"CGC_EINVAL 3"
.LASF119:
	.string	"__INT_LEAST64_MAX__ 0x7fffffffffffffffLL"
.LASF374:
	.string	"EBADF CGC_EBADF"
.LASF257:
	.string	"__FLT64X_MAX__ 1.18973149535723176502126385303097021e+4932F64x"
.LASF297:
	.string	"__GCC_ATOMIC_WCHAR_T_LOCK_FREE 2"
.LASF425:
	.string	"cgc_free"
.LASF357:
	.string	"CGC__NFDBITS (8 * sizeof(_fd_mask))"
.LASF9:
	.string	"__ATOMIC_RELAXED 0"
.LASF112:
	.string	"__INT_LEAST8_WIDTH__ 8"
.LASF106:
	.string	"__UINT8_MAX__ 0xff"
.LASF429:
	.string	"allocation_size"
.LASF366:
	.string	"CGC_ENOSYS 5"
.LASF108:
	.string	"__UINT32_MAX__ 0xffffffffU"
.LASF98:
	.string	"__INTMAX_WIDTH__ 64"
.LASF268:
	.string	"__DEC32_MAX__ 9.999999E96DF"
.LASF43:
	.string	"__CHAR32_TYPE__ unsigned int"
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
.LASF215:
	.string	"__FLT64_MAX__ 1.79769313486231570814527423731704357e+308F64"
.LASF378:
	.string	"ENOSYS CGC_ENOSYS"
.LASF316:
	.string	"__GCC_ASM_FLAG_OUTPUTS__ 1"
.LASF280:
	.string	"__DEC128_MAX_EXP__ 6145"
.LASF415:
	.string	"pNewChunk"
.LASF402:
	.string	"MALLOC_MANAGER"
.LASF114:
	.string	"__INT16_C(c) c"
.LASF397:
	.string	"MALLOC_ALLOC_FTR"
.LASF372:
	.string	"FD_CLR CGC_FD_CLR"
.LASF109:
	.string	"__UINT64_MAX__ 0xffffffffffffffffULL"
.LASF270:
	.string	"__DEC32_SUBNORMAL_MIN__ 0.000001E-95DF"
.LASF134:
	.string	"__INT_FAST32_MAX__ 0x7fffffff"
.LASF263:
	.string	"__FLT64X_HAS_QUIET_NAN__ 1"
.LASF395:
	.string	"tMallocAllocHdr"
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
.LASF348:
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
.LASF428:
	.string	"obj_size"
.LASF430:
	.string	"pMemBuffer"
.LASF2:
	.string	"__STDC_UTF_16__ 1"
.LASF189:
	.string	"__LDBL_EPSILON__ 1.08420217248550443400745280086994171e-19L"
.LASF347:
	.string	"STDOUT 1"
.LASF192:
	.string	"__LDBL_HAS_INFINITY__ 1"
.LASF68:
	.string	"__UINT_FAST64_TYPE__ long long unsigned int"
.LASF379:
	.string	"EPIPE CGC_EPIPE"
.LASF146:
	.string	"__GCC_IEC_559_COMPLEX 2"
.LASF387:
	.string	"SET_BIT(val,bit) (val |= (bit))"
.LASF306:
	.string	"__SIZEOF_WCHAR_T__ 4"
.LASF410:
	.string	"pFreeCur"
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
.LASF323:
	.string	"__SEG_GS 1"
.LASF317:
	.string	"__i686 1"
.LASF319:
	.string	"__pentiumpro 1"
.LASF41:
	.string	"__UINTMAX_TYPE__ long long unsigned int"
.LASF400:
	.string	"pPrev"
.LASF351:
	.string	"PAGE_SIZE 4096"
.LASF101:
	.string	"__SIG_ATOMIC_WIDTH__ 32"
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
.LASF353:
	.string	"offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)"
.LASF273:
	.string	"__DEC64_MAX_EXP__ 385"
.LASF309:
	.string	"__i386 1"
.LASF239:
	.string	"__FLT32X_MIN_10_EXP__ (-307)"
.LASF389:
	.string	"IS_BIT_SET(val,bit) (val & (bit))"
.LASF67:
	.string	"__UINT_FAST32_TYPE__ unsigned int"
.LASF277:
	.string	"__DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD"
.LASF262:
	.string	"__FLT64X_HAS_INFINITY__ 1"
.LASF281:
	.string	"__DEC128_MIN__ 1E-6143DL"
.LASF238:
	.string	"__FLT32X_MIN_EXP__ (-1021)"
.LASF384:
	.string	"ALLOC_PAGE_SIZE (4096)"
.LASF244:
	.string	"__FLT32X_MIN__ 2.22507385850720138309023271733240406e-308F32x"
.LASF65:
	.string	"__UINT_FAST8_TYPE__ unsigned char"
.LASF117:
	.string	"__INT32_C(c) c"
.LASF107:
	.string	"__UINT16_MAX__ 0xffff"
.LASF193:
	.string	"__LDBL_HAS_QUIET_NAN__ 1"
.LASF45:
	.string	"__INT8_TYPE__ signed char"
.LASF131:
	.string	"__INT_FAST8_WIDTH__ 8"
.LASF325:
	.string	"__linux 1"
.LASF375:
	.string	"EFAULT CGC_EFAULT"
.LASF51:
	.string	"__UINT32_TYPE__ unsigned int"
.LASF363:
	.string	"CGC_EFAULT 2"
.LASF141:
	.string	"__UINT_FAST64_MAX__ 0xffffffffffffffffULL"
.LASF140:
	.string	"__UINT_FAST32_MAX__ 0xffffffffU"
.LASF365:
	.string	"CGC_ENOMEM 4"
.LASF120:
	.string	"__INT64_C(c) c ## LL"
.LASF231:
	.string	"__FLT128_EPSILON__ 1.92592994438723585305597794258492732e-34F128"
.LASF344:
	.string	"FREE_FLAG 2"
.LASF22:
	.string	"__SIZEOF_LONG_LONG__ 8"
.LASF49:
	.string	"__UINT8_TYPE__ unsigned char"
.LASF86:
	.string	"__SHRT_WIDTH__ 16"
.LASF56:
	.string	"__INT_LEAST64_TYPE__ long long int"
.LASF358:
	.string	"CGC_FD_ZERO(set) do { int __i; for (__i = 0; __i < (CGC_FD_SETSIZE / CGC__NFDBITS); __i++) (set)->_fd_bits[__i] = 0; } while (0)"
.LASF35:
	.string	"__SIZEOF_POINTER__ 4"
.LASF250:
	.string	"__FLT64X_MANT_DIG__ 64"
.LASF407:
	.string	"pNeighbor"
.LASF92:
	.string	"__PTRDIFF_WIDTH__ 32"
.LASF376:
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
.LASF409:
	.string	"pItem"
.LASF385:
	.string	"FREE_BLOCK_NEXT(block) (((tMallocAllocFtr *)((void *)block + (((tMallocAllocHdr *)block)->alloc_size & ~0x3)-sizeof(tMallocAllocHdr)))->pNext)"
.LASF322:
	.string	"__SEG_FS 1"
.LASF286:
	.string	"__USER_LABEL_PREFIX__ "
.LASF390:
	.string	"long unsigned int"
.LASF401:
	.string	"tMallocAllocFtr"
.LASF296:
	.string	"__GCC_ATOMIC_CHAR32_T_LOCK_FREE 2"
.LASF1:
	.string	"__STDC_VERSION__ 199901L"
.LASF328:
	.string	"__unix 1"
.LASF354:
	.string	"SSIZE_MAX ((cgc_ssize_t)((~((cgc_size_t)0ULL))>>1))"
.LASF96:
	.string	"__UINTMAX_MAX__ 0xffffffffffffffffULL"
.LASF28:
	.string	"__CHAR_BIT__ 8"
.LASF314:
	.string	"__ATOMIC_HLE_ACQUIRE 65536"
.LASF4:
	.string	"__STDC_HOSTED__ 1"
.LASF142:
	.string	"__INTPTR_MAX__ 0x7fffffff"
.LASF360:
	.string	"CGC_FD_CLR(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] &= ~(1 << (b & (CGC__NFDBITS - 1))))"
.LASF71:
	.string	"__has_include(STR) __has_include__(STR)"
.LASF163:
	.string	"__FLT_HAS_INFINITY__ 1"
.LASF369:
	.string	"_NFDBITS CGC__NFDBITS"
.LASF199:
	.string	"__FLT32_MAX_10_EXP__ 38"
.LASF345:
	.string	"_LIBCGC_H "
.LASF301:
	.string	"__GCC_ATOMIC_LLONG_LOCK_FREE 2"
.LASF155:
	.string	"__FLT_MAX_EXP__ 128"
.LASF414:
	.string	"size_remaining"
.LASF265:
	.string	"__DEC32_MIN_EXP__ (-94)"
.LASF159:
	.string	"__FLT_MIN__ 1.17549435082228750796873653722224568e-38F"
.LASF69:
	.string	"__INTPTR_TYPE__ int"
.LASF149:
	.string	"__DEC_EVAL_METHOD__ 2"
.LASF118:
	.string	"__INT_LEAST32_WIDTH__ 32"
.LASF278:
	.string	"__DEC128_MANT_DIG__ 34"
.LASF16:
	.string	"__PIC__ 2"
.LASF36:
	.string	"__SIZE_TYPE__ unsigned int"
.LASF320:
	.string	"__pentiumpro__ 1"
.LASF343:
	.string	"INUSE_FLAG 1"
.LASF228:
	.string	"__FLT128_DECIMAL_DIG__ 36"
.LASF418:
	.string	"cgc_malloc"
.LASF431:
	.string	"GNU C99 8.4.0 -m32 -mtune=generic -march=i686 -g3 -g -O0 -std=gnu99 -fno-builtin -fno-stack-protector"
.LASF298:
	.string	"__GCC_ATOMIC_SHORT_LOCK_FREE 2"
.LASF256:
	.string	"__FLT64X_DECIMAL_DIG__ 21"
.LASF59:
	.string	"__UINT_LEAST32_TYPE__ unsigned int"
.LASF160:
	.string	"__FLT_EPSILON__ 1.19209289550781250000000000000000000e-7F"
.LASF377:
	.string	"ENOMEM CGC_ENOMEM"
.LASF177:
	.string	"__DBL_HAS_INFINITY__ 1"
.LASF148:
	.string	"__FLT_EVAL_METHOD_TS_18661_3__ 2"
.LASF304:
	.string	"__GCC_HAVE_DWARF2_CFI_ASM 1"
.LASF408:
	.string	"coalesceSize"
.LASF210:
	.string	"__FLT64_MIN_EXP__ (-1021)"
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
.LASF426:
	.string	"cgc_calloc"
.LASF52:
	.string	"__UINT64_TYPE__ long long unsigned int"
.LASF433:
	.string	"/home/pdreiter/Data/APR_eval/GenProg/trans.src-v24.cb_eval/build/SCUBA_Dive_Logging"
.LASF249:
	.string	"__FLT32X_HAS_QUIET_NAN__ 1"
.LASF170:
	.string	"__DBL_MAX_10_EXP__ 308"
.LASF382:
	.string	"MALLOC_NEXT_FLAG_BIT (2)"
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
.LASF361:
	.string	"CGC_FD_ISSET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] & (1 << (b & (CGC__NFDBITS - 1))))"
.LASF153:
	.string	"__FLT_MIN_EXP__ (-125)"
.LASF313:
	.string	"__SIZEOF_FLOAT128__ 16"
.LASF282:
	.string	"__DEC128_MAX__ 9.999999999999999999999999999999999E6144DL"
.LASF421:
	.string	"grow_size"
.LASF355:
	.string	"SIZE_MAX (~((cgc_size_t)0ULL))"
.LASF126:
	.string	"__UINT_LEAST32_MAX__ 0xffffffffU"
.LASF405:
	.string	"pItemHdr"
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
.LASF13:
	.string	"__ATOMIC_ACQ_REL 4"
.LASF399:
	.string	"pNext"
.LASF116:
	.string	"__INT_LEAST32_MAX__ 0x7fffffff"
.LASF394:
	.string	"cgc_size_t"
.LASF398:
	.string	"alloc_size"
.LASF184:
	.string	"__LDBL_MAX_10_EXP__ 4932"
.LASF274:
	.string	"__DEC64_MIN__ 1E-383DD"
.LASF202:
	.string	"__FLT32_MIN__ 1.17549435082228750796873653722224568e-38F32"
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
.LASF423:
	.string	"pNewAllocHdr"
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
