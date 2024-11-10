MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
  .text :
  {
    KEEP(*(.isr_vector))
    *(.text)
    *(.text.*)
  } > FLASH

  .data : AT (LOADADDR(.text) + SIZEOF(.text))
  {
    *(.data)
  } > RAM

  .bss :
  {
    *(.bss)
    *(COMMON)
  } > RAM

  . = ALIGN(4);
  . = . + 0x4;
  __stack_size = 0x400;
  .stack :
  {
    . = . + __stack_size;
    . = ALIGN(4);
  } > RAM
}
