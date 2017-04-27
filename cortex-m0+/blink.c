#include <stdint.h>

typedef void (*pointer)(void);

extern uint32_t _estack;
void __startup(void);

pointer vector_table[] __attribute__ ((section(".vectors"))) = {
    (pointer)&_estack,
    __startup
};

void on(void) {
  *((uint32_t *)0x400ff048) = (4 << 24);
}

void __startup(void) {

  *((uint32_t *)0x400ff054) =  (4 << 24); // (1 << 25)

  on();

  while (1);

}
