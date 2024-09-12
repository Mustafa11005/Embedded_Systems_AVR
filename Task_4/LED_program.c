/*
    Layer: HAL
    SWC: LED
    Date: 8 SEP 2024
    Version: 1.0
    Author: Mustafa Tamer Mansour EL-Sherif
 */

#include "STDTYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

void LEDInitialize(u8 Copy_u8PortNum, u8 Copy_u8PinNum){
	DIO_voidSetPinDirection(Copy_u8PortNum,Copy_u8PinNum,PIN_OUT);
}

void LEDInitializeAll(u8 Copy_u8PortNum){
	DIO_voidSetPortDirection(Copy_u8PortNum,PORT_OUT);
}

void LED_voidOn(u8 Copy_u8PortNum, u8 Copy_u8PinNum){
	DIO_voidSetPinValue(Copy_u8PortNum, Copy_u8PinNum, PIN_HIGH);
}

void LED_voidOff(u8 Copy_u8PortNum, u8 Copy_u8PinNum){
	DIO_voidSetPinValue(Copy_u8PortNum, Copy_u8PinNum, PIN_LOW);
}

void LED_voidAllOn(u8 Copy_u8PortNum){
	DIO_voidSetPortValue(Copy_u8PortNum, PORT_HIGH);
}

void LED_voidAllOff(u8 Copy_u8PortNum){
	DIO_voidSetPortValue(Copy_u8PortNum, PORT_LOW);
}

void LED_voidToggel(u8 Copy_u8PortNum, u8 Copy_u8PinNum){
	DIO_voidTogglePin(Copy_u8PortNum, Copy_u8PinNum);
}
