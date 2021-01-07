#include <stdint.h>

struct __vector_table {
  uint32_t *start_sp;
  void (*irq[15])(void);
};

extern uint32_t _estack;
extern int main(void);
 
/* STARTUP */

void __startup(void) {
  main();
}

/* VECTOR TABLE */

struct __vector_table vector_table __attribute__ ((section(".vectors"))) =
{
  &_estack,
  {
    __startup
  }
};


