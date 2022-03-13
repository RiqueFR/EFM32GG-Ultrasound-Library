## Ultrasonic Library to EFM32GG

This is a library for using with the HC-SR04 ultrasonic sensor and the EFM32GG microcontroler. To use it you need to set a SysTick of 1 microsecond, and in a SysTick_Handler, increment a variable 'ticks'. That variable is used in the function that returns the distance in centimeters.

The Ultrasound library uses the hans-jorg's GPIO and CLOCK library, so you need the files: gpio.c, gpio.h, clock_efm32gg2.c and clock_efm32gg2.h, for it to work properlly. You may need the files: em_device.h, startup_efm32gg.c and system_efm32gg.c, but this has not been tested. You can also use the Makefile from hans-jorg to compile the Ultrosound Library.

## Links

[hans-jorg EFM32GG-Codes](https://github.com/hans-jorg/efm32gg-stk3700-gcc-cmsis)