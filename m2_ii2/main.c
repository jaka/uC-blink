#include <stdint.h>

void on(void) {
  *((uint32_t *)0x50000018) = 0x10;
}

void off(void) {
  *((uint32_t *)0x50000018) = 0x100000;
}

#define DELAY 0xffff

int main(void)
{
  volatile uint32_t i;

  *((uint32_t *)0x4002102C) |= 0x1;
  *((uint32_t *)0x50000000) = 0xebfffdff;

  while (1) {

    on();
    for (i = DELAY; i; i--);

    off();
    for (i = DELAY; i; i--);

  }

  return 0;
}
