((AVR Project: SSD Counter with Push-Button Control))

Overview:

This AVR project is a simple SSD (Seven-Segment Display) counter that increments or decrements its count based on the state of two push-button switches. The project utilizes the AVR microcontroller to control the SSD display and read the push-button inputs.

Features:

- SSD display shows a count from 0 to 9
- Two push-button switches control the count:
    ---> Push-button 1 increments the count when pressed
    ---> Push-button 2 decrements the count when pressed
- The count wraps around from 9 to 0 when incremented from 9, and from 0 to 9 when decremented from 0

Hardware Requirements:

- AVR microcontroller
- SSD display module
- Two push-button switches
- Breadboard and jumper wires for connections

Software Components:

- main.c: The main program file that initializes the SSD display, push-button switches, and implements the counting logic
- STDTYPES.h, BIT_MATH.h, DIO_interface.h, SSD_interface.h, SWITCH_interface.h, LED_interface.h: Header files for standard data types, bit manipulation, digital input/output, SSD interface, switch interface, and LED interface, respectively

How to Use:

1- Connect the SSD display module to the AVR microcontroller according to the datasheet
2- Connect the two push-button switches to the AVR microcontroller according to the datasheet
3- Compile and upload the main.c program to the AVR microcontroller
4- Press push-button 1 to increment the count, and push-button 2 to decrement the count
5- The SSD display will show the current count