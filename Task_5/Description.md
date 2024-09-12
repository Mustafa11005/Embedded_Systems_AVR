((AVR Project: Dual SSD Counter with DIP Switch Control))

Overview:

This AVR project is a dual SSD (Seven-Segment Display) counter that displays a two-digit number from 00 to 99. The project utilizes the AVR microcontroller to control the two SSD displays and read the state of a DIP switch. The DIP switch is used to increment or decrement the count.

Features

- Two SSD displays show a two-digit number from 00 to 99
- A single DIP switch controls the count:
- When the DIP switch is pressed, the count increments or decrements
- The count wraps around from 99 to 00 when incremented from 99, and from 00 to 99 when decremented from 00

Hardware Requirements:

- AVR microcontroller
- Two SSD display modules
- One DIP switch
- Breadboard and jumper wires for connections

Software Components:

- main.c: The main program file that initializes the SSD displays, DIP switch, and implements the counting logic
- STDTYPES.h, BIT_MATH.h, DIO_interface.h, SSD_interface.h, SWITCH_interface.h, LED_interface.h: Header files for standard data types, bit manipulation, digital input/output, SSD interface, switch interface, and LED interface, respectively

How to Use?

1- Connect the two SSD display modules to the AVR microcontroller according to the datasheet
2- Connect the DIP switch to the AVR microcontroller according to the datasheet
3- Compile and upload the main.c program to the AVR microcontroller
4- Press the DIP switch to increment or decrement the count
5- The two SSD displays will show the current two-digit number