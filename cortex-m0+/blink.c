#include <stdint.h>

typedef void (*pointer)(void);

extern uint32_t _estack;
void __startup(void);

pointer vector_table[] __attribute__ ((section(".vectors"))) =
{
    (pointer)&_estack,
    __startup
};

void wdog_disable()
{
  /* Unlock watchdog. */
  *((volatile uint16_t *)0x40052002) = 0x20C5;
  *((volatile uint16_t *)0x40052002) = 0x28D9;

  /* Disable watchdog. */
  *((volatile uint8_t *)0x40052000) = 0x00;
  *((volatile uint8_t *)0x40052001) = 0x00;
  *((volatile uint16_t *)0x40052004) = 0xFFFF;
  *((volatile uint16_t *)0x40052006) = 0x0000;
}

void on(void) {
  *((uint32_t *)0x400ff048) = (2 << 24);
}

void off(void) {
  *((uint32_t *)0x400ff044) = (2 << 24);
}

#define DELAY 0xFFFFF

void __startup(void)
{
  volatile unsigned int i;

  /* Watchdog is enabled by default. We must disable it. */
  wdog_disable();

  *((uint32_t *)0x400ff054) = 2 << 24;

  while (1) {

    on();
    for (i = DELAY; i; i--);

    off();
    for (i = DELAY; i; i--);

  }

}
