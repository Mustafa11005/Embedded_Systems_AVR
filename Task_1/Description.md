AVR Switch-LED-SSD Counter

A simple AVR-based project that demonstrates a counter using a switch, LED, and SSD (Seven-Segment Display).

Features:

- Counts up to 9 using a switch input
- Displays the count on a SSD
- Toggles an LED on and off with each switch press
- Uses a pull-up resistor for switch debouncing

Functionality:

- Reads the state of a switch connected to PORTB, PIN0
- Increments a counter variable when the switch is pressed
- Displays the current count on a SSD connected to PORTA and PORTC, PIN7
- Toggles an LED connected to PORTD, PIN0 on and off with each switch press

Technical Details:

- Written in C programming language for AVR microcontrollers
- Uses the AVR-GCC compiler
- Includes delay functions for switch debouncing and LED toggling
- Follows standard AVR coding conventions and best practices

Hardware Requirements:

- AVR microcontroller (e.g. ATmega32)
- SSD (Seven-Segment Display)
- LED
- Switch
- Pull-up resistor
- Breadboard and jumper wires

Usage:

1- Connect the hardware components as described above.
2- Compile the program using AVR-GCC.
3- Upload the program to the AVR microcontroller using a programmer 
(e.g. AVRISP).
4- Press the switch to increment the counter and toggle the LED.

Note:

- This project is demonstrated in Proteus 

- This project is intended for educational purposes only and should not be used in a production environment without proper testing and validation.