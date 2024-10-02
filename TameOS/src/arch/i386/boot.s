/* Constants for multiboot header */
.set ALIGN,    1<<0             /* align loaded modules on page boundaries */
.set MEMINFO,  1<<1             /* provide memory map */
.set FLAGS,    ALIGN | MEMINFO  /* multiboot 'flag' field */
.set MAGIC,    0x1BADB002       /* magic number */
.set CHECKSUM, -(MAGIC + FLAGS) /* checksum */

/* Multiboot header */
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/* Provide a stack */
.section .bss
.align 16
stack_bottom:
.skip 16384 /* 16 KiB */
stack_top:

.section .text
.global _start
.type _start, @function
/* Once the kernel loaded, the bootloader will jump to
   this position... */
_start:
    
    /* Set up stack */
    mov $stack_top, %esp

    /* Enter high-level kernel */
    call kernel_main

    /* Nothing more to do; go in an infinite loop */
    cli
1:  hlt
    jmp 1b

/* Size of start symbol */
.size _start, . - _start
