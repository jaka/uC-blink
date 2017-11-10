#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

ISR (TIMER0_OVF_vect)
{
  PORTD ^= _BV(PD5);
}

int main(void)
{
  TCCR0B |= _BV(CS02);
  TCNT0 = 0;
  TIMSK0 = _BV(TOIE0);

  DDRD = _BV(PD5);
  sei();

  for (;;)
    sleep_mode();

   return 0;
}
