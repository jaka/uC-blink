OPTS += -mlittle-endian -mthumb -mcpu=cortex-m0plus
CFLAGS += -g -O0 -Wall -Werror -Wextra -pedantic -std=c99 -ffunction-sections -fdata-sections -finline-functions
LDFLAGS += -nostdlib --gc-sections
LIBS =

PREFIX := arm-none-eabi
CC := $(PREFIX)-gcc
LD := $(PREFIX)-ld
OBJCOPY := $(PREFIX)-objcopy

SRC := main.o
OBJ := $(patsubst %.c,%.o,$(SRC)) startup.o
NAME := blink

all: $(NAME).bin

%.o: %.c
	$(CC) $(OPTS) $(CFLAGS) -o $@ -c $^

$(NAME).elf: $(OBJ)
	$(LD) $(LDFLAGS) -T startup.ld -o $@ $^

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f $(OBJ)
	rm -f $(NAME).elf
	rm -f $(NAME).bin
