#ifndef _ds18b20_H
#define _ds18b20_H
#include "stm32f10x.h"
#include "systick.h"

#define dq GPIO_Pin_11  //PG11¹Ü½Å
#define GPIO_ds18b20  GPIOG
#define ds18b20_dq_H GPIO_SetBits(GPIO_ds18b20,dq)
#define ds18b20_dq_L GPIO_ResetBits(GPIO_ds18b20,dq)


void ds18b20_init(void);
void DQIN_INIT(void);
void DQOUT_INIT(void);
 void ds18b20init(void);
 void ds18b20wr(u8 dat);
 u8 ds18b29(void);
 double readtemp(void);

#endif
