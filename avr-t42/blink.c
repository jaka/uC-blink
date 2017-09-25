#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

ISR (TIMER0_OVF_vect)
{
  PORTD ^= _BV(PD5);
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

  DDRD = _BV(PD5); /* pin 5 port D */
  setup();

  for (;;)
    sleep_mode();

   return 0;
}
