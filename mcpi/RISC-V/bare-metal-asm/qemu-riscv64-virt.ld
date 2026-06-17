MEMORY
{
  ram (rwxai) : ORIGIN = 0x80000000, LENGTH = 0x8000000 /* 128 MB RAM */
}

SECTIONS
{
  /* Code section */
  .text :
  {
    *(.text*)       /* Include all .text sections */
    *(.rodata*)     /* Include read-only data */
  } > ram           /* Place in RAM */

  /* Initialized data section */
  .data :
  {
    *(.data*)       /* Include all .data sections */
  } > ram AT > ram

  /* Uninitialized data section */
  .bss :
  {
    *(.bss*)        /* Include all .bss sections */
    *(COMMON)       /* Include common symbols */
  } > ram

  /* Define stack memory region */
  _stack_top = ORIGIN(ram) + LENGTH(ram); /* Top of stack (end of RAM) */
  _stack_bottom = _stack_top - 0x1000;   /* Allocate 4 KB for the stack */

  /* Symbols for program start and end */
  _start = ORIGIN(ram);
  _end = _stack_bottom;
}
