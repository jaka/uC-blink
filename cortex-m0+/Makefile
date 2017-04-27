CFLAGS	:= -mcpu=cortex-m0plus -mlittle-endian -mthumb -nostdlib -g
LIBS	:=

CC	:= arm-none-eabi-gcc
OBJCOPY	:= arm-none-eabi-objcopy

TARGET	:= blink

all:	$(TARGET).srec

$(TARGET).elf: $(TARGET).ld $(TARGET).c
	$(CC) $(CFLAGS) -T $(TARGET).ld -o $@ $(TARGET).c $(LIBS)

%.srec: %.elf
	$(OBJCOPY) -O srec $< $@

clean:
	rm $(TARGET).elf
