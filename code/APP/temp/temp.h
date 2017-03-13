#ifndef _temp_H
#define _temp_H
#include "stm32f10x.h"
#include "systick.h"

#define temp GPIO_Pin_0  //PG11¹Ü½Å
#define GPIO_temp  GPIOA
#define temp_H GPIO_SetBits(GPIO_temp,temp)
#define temp_L GPIO_ResetBits(GPIO_temp,temp)


void temp_init(void);
void TEMPININT(void);
void tempinit(void);
u8 temprd(void);

#endif
