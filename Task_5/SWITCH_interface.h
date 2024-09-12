/*
    Layer: HAL
    SWC: SWITCH
    Date: 9 SEP 2024
    Version: 1.0
    Author: Mustafa Tamer Mansour EL-Sherif
*/

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

typedef struct{
    u8 CtrlPort;
    u8 CtrlPin;
}SWITCH_t;

void SWITCH_u8ButtonInitialize(SWITCH_t Copy_tSwitch);

u8 SWITCH_u8ButtonRead(SWITCH_t Copy_tSwitch);

void SWITCH_voidButtonEnablePullup(SWITCH_t Copy_tSwitch);

u8 SWITCH_u8ToggelVar(SWITCH_t Copy_tSwitch, u8 Copy_u8PrevState);

#define SWITCH_ON    1
#define SWITCH_OFF   0
#define	TRUE 	1
#define FALSE	0

#endif
