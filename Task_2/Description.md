AVR DIP Switch-LED Controller

A simple AVR-based project that demonstrates a DIP switch-LED controller.

Features:

- Reads the state of 8 DIP switches connected to PORTB
- Controls 8 LEDs connected to PORTA based on the DIP switch states
- Uses pull-up resistors for switch debouncing

Functionality:

- Reads the state of each DIP switch and stores it in a variable
- Uses the switch state to control the corresponding LED
- If a switch is pressed (i.e. its state is LOW), the corresponding LED is turned ON
- If a switch is not pressed (i.e. its state is HIGH), the corresponding LED is turned OFF

Technical Details:

- Written in C programming language for AVR microcontrollers
- Uses the AVR-GCC compiler
- Includes delay functions for switch debouncing
- Follows standard AVR coding conventions and best practices

Hardware Requirements:

- AVR microcontroller (e.g. ATmega32)
- 8 DIP switches
- 8 LEDs
- Breadboard and jumper wires

Usage:

1- Connect the hardware components as described above.
2- Compile the program using AVR-GCC.
3- Upload the program to the AVR microcontroller using a programmer 
(e.g. AVRISP).
4- Press the DIP switches to control the LEDs.
Note

- This Task is explained more in Proteus
- This project is intended for educational purposes only and should not be used in a production environment without proper testing and validation.