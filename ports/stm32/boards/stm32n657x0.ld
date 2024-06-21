/*
    GNU linker script for STM32N657x0
*/

/* Specify the memory areas */
/* TODO */
MEMORY
{
    FLASH (rx)      : ORIGIN = 0x34180400, LENGTH = 384K    /* AXISRAM1_S (for common_basic.ld) */
    RAM (xrw)       : ORIGIN = 0x341e0000, LENGTH = 128K    /* AXISRAM1_S */
    FLASH_APP (rx)  : ORIGIN = 0x70080000, LENGTH = 1536K   /* external flash */
}

/* produce a link error if there is not this amount of RAM for these sections */
_minimum_stack_size = 2K;
_minimum_heap_size = 16K;

/* Define the stack.  The stack is full descending so begins just above last byte
   of RAM.  Note that EABI requires the stack to be 8-byte aligned for a call. */
_estack = ORIGIN(RAM) + LENGTH(RAM) - _estack_reserve;
_sstack = _estack - 16K; /* tunable */

/* RAM extents for the garbage collector */
_ram_start = ORIGIN(RAM);
_ram_end = ORIGIN(RAM) + LENGTH(RAM);
_heap_start = _ebss; /* heap starts just after statically allocated memory */
_heap_end = _sstack;
