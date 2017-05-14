# blink: avr usbasp atmega8

USBasp v2.0 is a cheap ISP programmer that is built on ATMEGA8 MCU and is supported in _avrdude_, but it can be also used as an „Arduino platform.“

In this simple example a timer is used to repeatedly turn on-board LED on and off.

First, create a _hex_ file by issuing command `make` (requires installed _gcc-avr_). Then close jumper JP2 on target USBasp board and connect it with supplied ribbon cable to another USBasp, acting as a programmer. Finally, insert the programmer into computer's USB port and execute `make flash`. After successful flash, a LED on target board will start blinking.
