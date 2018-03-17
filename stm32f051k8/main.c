#include <stdint.h>

void on(void) {
  *((uint32_t *)0x48000018) = 0x1000;
}

void off(void) {
  *((uint32_t *)0x48000018) = 0x10000000;
}

#define DELAY 0xffff

int main(void)
{
  volatile uint32_t i;

  *((uint32_t *)0x40021014) |= 0x20000;
  *((uint32_t *)0x48000000) |= 0x1000000;

  while (1) {

    on();
    for (i = DELAY; i; i--);

    off();
    for (i = DELAY; i; i--);

  }

  return 0;
}
