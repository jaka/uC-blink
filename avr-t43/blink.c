#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

ISR (TIMER0_OVF_vect)
{
  PORTB ^= _BV(PB2);
}

void setup(void)
{
  TCCR0B |= _BV(CS02);

  TCNT0 = 0;
  TIMSK0 = _BV(TOIE0);

  sei();
}

int main(void)
{
  DDRB = _BV(PB2); /* pin 2 port B */
  setup();

  for (;;)
    sleep_mode();

   return 0;
}
