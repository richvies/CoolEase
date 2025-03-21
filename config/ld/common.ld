EXTERN(vector_table)
ENTRY(reset_handler)

_stack = ORIGIN(ram) + LENGTH(ram);
_min_heap_size = 0x400;
_min_stack_size = 0x400;
