# stm32_project1

blink

## upload
```cmd
C:\Users\qinhu\.platformio\packages\tool-openocd\bin\openocd -d3 -s C:\Users\qinhu\.platformio\packages\tool-openocd/openocd/scripts -f openocd.cfg -c "program {.pio\build\disco_f429zi\firmware.elf}  verify reset; shutdown;"
```

## 问题
当调整延时为1000时，烧录时提示checksum failed导致失败
