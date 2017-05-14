#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

volatile uint8_t count;

/* Interrupt Service Routine */

ISR (TIMER0_OVF_vect) {
  /* Timer0 je dosegel overflow. */

  count++;
  if ( count == 40 ) {
    PORTC ^= _BV(PC0);
    count = 0;
  }

}

void setup(void) {

    /* Vrednost števca Timer0 se bo povečala na vsakih FCPU/1024. */
    TCCR0 |= _BV(CS02) | _BV(CS00);

    /* Nastavi začetno vrednost števca Timer0. */
    TCNT0 = 0;

    /* Omogoči Timer Overflow Interrupt za Timer0. */
    TIMSK = _BV(TOIE0);

    /* Pin PC0 predstavlja izhod. */
    DDRC = _BV(PC0);

    /* Omogoči prekinitve. */
    sei();

}

int main(void) {

    count = 0;
    setup();

    /* Ponavljaj. Program nam poganjajo prekinitve. */
    for (;;)
        sleep_mode();

    return(0);
}
