EXTERN(vector_table)
ENTRY(reset_handler)

/* Generate a link error if heap and stack don't fit into RAM */
_min_heap_size  = 0x600;    /* required amount of heap  */
_min_stack_size = 0x400;    /* required amount of stack */

MEMORY
{
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 8K
    rom (rx) : ORIGIN = 0x08002000, LENGTH = 64K
}
SECTIONS
{
    /* Flash Data */
    /* Vector table, code & readonly data */
    .text : 
    {
        *(.vectors)
        *(.text*)
        . = ALIGN(4);
        *(.rodata*)
        . = ALIGN(4);
    } >rom
    
    /* C/C++ initialization */
    .preinit_array : 
    {
        . = ALIGN(4);
        __preinit_array_start = .;
        KEEP (*(.preinit_array))
        __preinit_array_end = .;
    } >rom
    .init_array : 
    {
        . = ALIGN(4);
        __init_array_start = .;
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array))
        __init_array_end = .;
    } >rom
    .fini_array : {
        . = ALIGN(4);
        __fini_array_start = .;
        KEEP (*(.fini_array))
        KEEP (*(SORT(.fini_array.*)))
        __fini_array_end = .;
    } >rom

    /* Arm frame table and indexs apparently for stack unwinding */
    /* Can probably get rid of it */
    .ARM.extab : 
    {
        *(.ARM.extab*)
    } >rom
    .ARM.exidx : 
    {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } >rom

    . = ALIGN(4);

    /* End of text */
    _etext = .;

    /* RAM Data */
    /* Initialized data cpoied to RAM */
    .data : 
    {
        /* Start address of data in flash */
        _data = .;
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } >ram AT >rom
    /* Address in RAM to load data */
    _data_loadaddr = LOADADDR(.data);
    
    /* Uninitialized data zero'd section of RAM */
    .bss : 
    {
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } >ram

    . = ALIGN(4);

    /* End of data */
    PROVIDE (end = .);

    /* Check that there is enough RAM left */
    ._user_heap_stack :
    {
        . = ALIGN(8);
        . = . + _min_heap_size;
        . = . + _min_stack_size;
        . = ALIGN(8);
    } >ram

    /DISCARD/ : { *(.eh_frame) }
/* 
    /* Remove information from the standard libraries */
    /DISCARD/ :
    {
        libc.a ( * )
        libm.a ( * )
        libgcc.a ( * )
    }

    .ARM.attributes 0 : { *(.ARM.attributes) } */

}
PROVIDE(_stack = ORIGIN(ram) + LENGTH(ram));
