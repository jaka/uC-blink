## connect openocd
```
openocd -f /usr/share/openocd/scripts/interface/stlink-v2-1.cfg -f /usr/share/openocd/scripts/target/stm32l0.cfg -f ./d4.conf -c init -c "reset halt"
```