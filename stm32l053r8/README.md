```
openocd -f /usr/share/openocd/scripts/interface/stlink-v2-1.cfg -f /usr/share/openocd/scripts/target/stm32l0.cfg -c init -c "reset halt"
```

```
arm-none-eabi-gdb --eval-command="target extended-remote localhost:3333"
```
```
load blink.elf
run
```
