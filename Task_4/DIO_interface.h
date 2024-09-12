/*
    Layer: MCAL
    SWC: DIO
    Date: 7 SEP 2024
    Version: 1.0
    Author: Mustafa Tamer Mansour EL-Sherif
*/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_voidSetPortDirection(u8 Copy_u8PortNum, u8 Copy_u8PortDirection);
void DIO_voidSetPinDirection(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8PinDirection);

void DIO_voidSetPortValue(u8 Copy_u8PortNum, u8 Copy_u8PortValue);
void DIO_voidSetPinValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8PinValue);

u8 DIO_u8GetPinValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum);

void DIO_u8SetInternalPullup(u8 Copy_u8PortNum, u8 Copy_u8PinNum);

void DIO_voidTogglePin(u8 Copy_u8PortNum, u8 Copy_u8PinNum);

void DIO_voidGroundVcc(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8Mode);

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define PORT_u8A    1
#define PORT_u8B    2
#define PORT_u8C    3
#define PORT_u8D    4

#define PIN_OUT     1
#define PIN_IN      0

#define PIN_HIGH    1
#define PIN_LOW     0

#define PORT_HIGH   0XFF
#define PORT_LOW    0X00

#define PORT_OUT    0XFF
#define PORT_IN     0X00

#define GND 0
#define VCC 1

#endif
