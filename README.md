**STM32F401 GPIO Driver (Bare-Metal)**
📌 **Overview**

This project implements a custom bare-metal GPIO driver for the STM32F401RE microcontroller using direct register-level programming.
No HAL or CMSIS libraries are used — all peripheral control is done through memory-mapped registers.

The project also includes a binary counter application where 8 LEDs display incrementing values controlled by a push button.

🎯 **Objectives**

Understand ARM Cortex-M4 architecture

Learn memory-mapped register programming

Develop reusable embedded C drivers

Implement GPIO without abstraction libraries

Practice bit manipulation and hardware debugging

🛠 **Features**

Peripheral clock enable/disable

GPIO initialization (Mode, Speed, Output Type, Pull-up/Pull-down)

Read single pin

Write single pin

Write entire port

Toggle output pin

Binary counter demo application

🔌 Hardware Setup

STM32F401RE microcontroller

8 LEDs connected to GPIOB (PB0–PB7)

Push button connected to GPIOA (PA0)

Current limiting resistors for LEDs

Tested in Proteus simulation.

🚀 **How It Works**

GPIOB pins 0–7 are configured as output.

GPIOA pin 0 is configured as input with pull-down.

When the button is pressed:

Counter increments

Binary value is written to GPIOB

LEDs display the binary output

📚 **Learning Outcome**

This project strengthens understanding of:

Low-level driver development

Register configuration (MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR)

Embedded C programming

Microcontroller hardware interfacing

🔮 **Future Improvements
**
Interrupt-based button handling (EXTI)

Timer-based debouncing

BSRR register optimization

Modular driver expansion for other peripherals

📄** License**

This project is licensed under the MIT License
