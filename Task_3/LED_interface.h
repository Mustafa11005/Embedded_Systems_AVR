/*
    Layer: HAL
    SWC: LED
    Date: 7 SEP 2024
    Version: 1.0
    Author: Mustafa Tamer Mansour EL-Sherif
*/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

void LEDInitialize(u8 Copy_u8PortNum, u8 Copy_u8PinNum);

void LEDInitializeAll(u8 Copy_u8PortNum);

void LED_voidOn(u8 Copy_u8PortNum, u8 Copy_u8PinNum);

void LED_voidOff(u8 Copy_u8PortNum, u8 Copy_u8PinNum);

void LED_voidAllOn(u8 Copy_u8PortNum);

void LED_voidAllOff(u8 Copy_u8PortNum);

void LED_voidToggel(u8 Copy_u8PortNum, u8 Copy_u8PinNum);

#define ON      1
#define OFF     0

#endif
