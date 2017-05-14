OPTS	= -Os -mmcu=$(MCU_TARGET) -g
CFLAGS	= -Wall -Werror -Wextra -pedantic -std=c99
LDFLAS	=
LIBS	=

CC	:= avr-gcc
OBJCOPY	:= avr-objcopy

MCU_TARGET := atmega8
TARGET	:= usbasp-blink

SRC	= blink.c
OBJ	= $(patsubst %.c,%.o,$(SRC))

all: build

build: $(TARGET).hex

clean:
	rm -f $(OBJ)
	rm -f $(TARGET).elf
	rm -f $(TARGET).hex

flash:
	avrdude -c usbasp -p m8 -U flash:w:$(TARGET).hex

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(OPTS) $(LDFLAGS) -o $@ $^ $(LIBS)

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.o: %.c
	$(CC) $(CFLAGS) $(OPTS) -c -o $@ $<
