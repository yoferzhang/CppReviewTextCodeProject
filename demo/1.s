	.file	"1.cpp"
.lcomm __ZStL8__ioinit,1,1
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "x:%d y:%d \12\0"
LC1:
	.ascii "a:%c b:%c \12\0"
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$96, %esp
	movl	$___gxx_personality_sj0, 52(%esp)
	movl	$LLSDA959, 56(%esp)
	leal	60(%esp), %eax
	movl	%ebp, (%eax)
	movl	$L5, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	call	___main
	movl	$10, 92(%esp)
	movl	$20, 88(%esp)
	leal	88(%esp), %eax
	movl	%eax, 4(%esp)
	leal	92(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 32(%esp)
	call	__Z6myswapIiEvRT_S1_ // 41 call 117
	movl	88(%esp), %edx
	movl	92(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movb	$97, 87(%esp)
	movb	$98, 86(%esp)
	leal	86(%esp), %eax
	movl	%eax, 4(%esp)
	leal	87(%esp), %eax
	movl	%eax, (%esp)
	movl	$2, 32(%esp)
	call	__Z6myswapIcEvRT_S1_ // 55 call 145
	movb	86(%esp), %al
	movsbl	%al, %edx
	movb	87(%esp), %al
	movsbl	%al, %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$0, %eax
	movl	%eax, 24(%esp)
	jmp	L8
L5:
	movl	36(%esp), %edx
	movl	32(%esp), %eax
	testl	%eax, %eax
	je	L6
	cmpl	$1, %eax
	je	L7
		.word	0x0b0f
L6:
	movl	%edx, %eax
	movl	%eax, (%esp)
	movl	$-1, 32(%esp)
	call	__Unwind_SjLj_Resume
L7:
	movl	%edx, %eax
	movl	%eax, (%esp)
	movl	$-1, 32(%esp)
	call	__Unwind_SjLj_Resume
L8:
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	24(%esp), %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA959:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE959-LLSDACSB959
LLSDACSB959:
	.uleb128 0
	.uleb128 0
	.uleb128 0x1
	.uleb128 0
LLSDACSE959:
	.text
	.section .rdata,"dr"
	.align 4
LC2:
	.ascii "hello ....\316\322\312\307\304\243\260\345\272\257\312\375 \273\266\323\255 calll \316\322\0"
	.section	.text$_Z6myswapIiEvRT_S1_,"x"
	.linkonce discard
	.globl	__Z6myswapIiEvRT_S1_
	.def	__Z6myswapIiEvRT_S1_;	.scl	2;	.type	32;	.endef
__Z6myswapIiEvRT_S1_: // 117
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	leave
	ret
	.section	.text$_Z6myswapIcEvRT_S1_,"x"
	.linkonce discard
	.globl	__Z6myswapIcEvRT_S1_
	.def	__Z6myswapIcEvRT_S1_;	.scl	2;	.type	32;	.endef
__Z6myswapIcEvRT_S1_: // 145
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movb	$0, -9(%ebp)
	movl	8(%ebp), %eax
	movb	(%eax), %al
	movb	%al, -9(%ebp)
	movl	12(%ebp), %eax
	movb	(%eax), %dl
	movl	8(%ebp), %eax
	movb	%dl, (%eax)
	movl	12(%ebp), %eax
	movb	-9(%ebp), %dl
	movb	%dl, (%eax)
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	leave
	ret
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	ret
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L12
	cmpl	$65535, 12(%ebp)
	jne	L12
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L12:
	leave
	ret
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
