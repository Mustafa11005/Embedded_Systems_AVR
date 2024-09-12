/*
    Layer: HAL
    SWC: DIO
    Date: 7 SEP 2024
    Version: 1.0
    Author: Mustafa Tamer Mansour EL-Sherif
*/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef struct{
    u8 DataPort;
    u8 CtrlPort;
    u8 CtrlPin;
    u8 Type;
}SSD_t;

void SSD_voidEnableDisable(SSD_t Copy_tSeven, u8 Copy_u8Mode);
void SSD_voidDisplayNum(SSD_t Copy_tSeven, u8 Copy_u8Num);

#define COMMON_CATHODE  0
#define COMMON_ANODE    1

#define ENABLE      1
#define DISABLE     0

#define NULL -1





#endif
