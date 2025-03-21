INCLUDE mem_offset.ld

MEMORY
{
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 8K
    rom (rx) : ORIGIN = 0x08000000, LENGTH = OFFSET
}

INCLUDE common.ld
INCLUDE sections.ld