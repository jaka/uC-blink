OUTPUT_ARCH(arm)
OUTPUT_FORMAT(elf32-littlearm)
ENTRY(__startup)

MEMORY
{
  flash	(rx)	: ORIGIN = 0x08000000, LENGTH = 128K
  sram	(rwx)	: ORIGIN = 0x20000000, LENGTH = 16K
}

_estack = ORIGIN(sram) + LENGTH(sram);

SECTIONS {

  . = ORIGIN(flash);

  .vectors : 
  {
    * (.vectors)
  } > flash

  .text :
  {
    . = ALIGN(4);
    * (.text)
    * (.text*)
  } > flash

}
