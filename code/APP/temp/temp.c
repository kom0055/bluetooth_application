#include "temp.h"
#include "sdrcv.h"
void temp_init(){	//IO端口时钟初始化函数
	GPIO_InitTypeDef GPIO_InitStructure;	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Pin=temp;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIO_temp,&GPIO_InitStructure);
}
void TEMPININT()	 //输入配置
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=temp;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIO_temp,&GPIO_InitStructure);	
}
void TEMPOUTINT()	 //输出配置
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=temp;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIO_temp,&GPIO_InitStructure);	
}
void tempinit()
{
	delay_ms(2000);//等待2秒以越过不稳定阶段，不发送任何指令
	TEMPOUTINT();//输出
	temp_L;
	delay_ms(20);//延时20ms	
	TEMPININT();//输入
	//temp_H;
	delay_us(40);
	TEMPININT();//输入
	if(GPIO_ReadInputDataBit(GPIO_temp,temp)==0) {
	/*	delay_us(80);
		if(GPIO_ReadInputDataBit(GPIO_temp,temp)==1){
		delay_us(80);
		}  */
	while(GPIO_ReadInputDataBit(GPIO_temp,temp)==0);
	while(GPIO_ReadInputDataBit(GPIO_temp,temp)==1);
	}

}
u8 temprd()
{
	u8 i=0,value=0;
	//TEMPININT();	 //输入配置	
	for(i=0;i<8;i++)
	{
		value<<=1;
		if(GPIO_ReadInputDataBit(GPIO_temp,temp)==0) 
			
			while(GPIO_ReadInputDataBit(GPIO_temp,temp)==0);
			if(GPIO_ReadInputDataBit(GPIO_temp,temp)==1)
				delay_us(40);
		if(GPIO_ReadInputDataBit(GPIO_temp,temp)==1)
		value|=0x01;//读数据 从高位开始
		while(GPIO_ReadInputDataBit(GPIO_temp,temp)==1);
	}
	 //printf("第一位是%d,and%d\r\n",value,test);
	return value;	
}




