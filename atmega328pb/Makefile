#!/usr/bin/make -f

OPTS	= -Os -mmcu=$(MCU_TARGET)
CFLAGS	= -Wall -Werror -Wextra -pedantic -std=c99
LDFLAS	=
LIBS	=

CC	:= avr-gcc
OBJCOPY	:= avr-objcopy

MCU_TARGET	:= atmega328pb
PROGRAMMER_MCU	:= m328pb
PROGRAMMER	:= usbasp

SRC	:= blink.c
OBJ	:= $(patsubst %.c,%.o,$(SRC))
NAME	= $(MCU_TARGET)-blink

all: build

build: $(NAME).hex

clean:
	rm -f $(OBJ)
	rm -f $(NAME).elf
	rm -f $(NAME).hex

flash: $(NAME).hex
	avrdude -c $(PROGRAMMER) -p $(PROGRAMMER_MCU) -B 3 -U flash:w:$<

$(NAME).elf: $(OBJ)
	$(CC) $(CFLAGS) $(OPTS) $(LDFLAGS) -o $@ $^ $(LIBS)

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.o: %.c
	$(CC) $(CFLAGS) $(OPTS) -c -o $@ $<
