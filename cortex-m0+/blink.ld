
OUTPUT_ARCH(arm)
OUTPUT_FORMAT("elf32-littlearm")
ENTRY(__startup)

MEMORY
{
  flash	(rx)	: ORIGIN = 0x00000000, LENGTH = 64K
  sram	(rwx)	: ORIGIN = 0x1FFFFC00, LENGTH = 4K
}

_estack = ORIGIN(sram) + LENGTH(sram);

SECTIONS {
  . = ORIGIN(flash);

  .text : 
  {

    . = ALIGN(4);
    * (.vectors);
    * (.text);

  } > flash

  .data :
  {
    . = ALIGN(4);
    _sdata = .;
    *(.data)
    *(.data*)

    . = ALIGN(4);
    _edata = .;
  } > sram

}
