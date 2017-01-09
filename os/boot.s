.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .text
.global _start
.type _start, @function
_start:
	call kernel_main

	cli
	hlt
.hang:
	jmp .hang
.global idt_load
.extern idtp
idt_load:
	lidt (idtp)
	ret

# set up interrupts
.global _isr0
.global _isr1
.global _isr2
.global _isr3
.global _isr4
.global _isr5
.global _isr6
.global _isr7
.global _isr8
.global _isr9
.global _isr10
.global _isr11
.global _isr12
.global _isr13
.global _isr14
.global _isr15
.global _isr16
.global _isr17
.global _isr18
.global _isr19
.global _isr20
.global _isr21
.global _isr22
.global _isr23
.global _isr24
.global _isr25
.global _isr26
.global _isr27
.global _isr28
.global _isr29
.global _isr30
.global _isr31

# 0: Divide By Zero Exception
_isr0:
	cli
	push 0
	push 0
	jmp isr_common_stub

# 1: Debug Exception
_isr1:
	cli
	push 0
	push 1
	jmp isr_common_stub

# 8: Double Fault Exception
_isr8:
	cli
	push 8
	jmp isr_common_stub

.extern _fault_handler

# This is our common ISR stub. It saves the processor state, sets
# up for kernel mode segments, calls the C-level fault handler,
# and finally restores the stack frame.
isr_common_stub:
	pusha
	push %ds
	push %es
	push %fs
	push %gs
	mov $0x10, %ax # Load the Kernel Data Segment descriptor!
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %esp, %eax # Push us the stack
	push %eax
	mov $_fault_handler, %eax
	call *%eax       # A special call, preserves the 'eip' register
	pop %eax
	pop %gs
	pop %fs
	pop %es
	pop %ds
	popa
	add $8, %esp # Cleans up the pushed error code and pushed ISR number
	iret           # pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP

# set up the segement registers
.global gdt_flush
.extern gdtp
gdt_flush:
	lgdt (gdtp)
	mov $0x10, %ax # offset of the data segment in out gdt
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss
	jmp $0x08, $flush2 # use a far jump to set our CS segement register
flush2:
	ret
