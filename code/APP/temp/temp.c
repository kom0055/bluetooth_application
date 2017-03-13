#include "temp.h"
#include "sdrcv.h"
void temp_init(){	//IO�˿�ʱ�ӳ�ʼ������
	GPIO_InitTypeDef GPIO_InitStructure;	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Pin=temp;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIO_temp,&GPIO_InitStructure);
}
void TEMPININT()	 //��������
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=temp;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIO_temp,&GPIO_InitStructure);	
}
void TEMPOUTINT()	 //�������
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=temp;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIO_temp,&GPIO_InitStructure);	
}
void tempinit()
{
	delay_ms(2000);//�ȴ�2����Խ�����ȶ��׶Σ��������κ�ָ��
	TEMPOUTINT();//���
	temp_L;
	delay_ms(20);//��ʱ20ms	
	TEMPININT();//����
	//temp_H;
	delay_us(40);
	TEMPININT();//����
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
	//TEMPININT();	 //��������	
	for(i=0;i<8;i++)
	{
		value<<=1;
		if(GPIO_ReadInputDataBit(GPIO_temp,temp)==0) 
			
			while(GPIO_ReadInputDataBit(GPIO_temp,temp)==0);
			if(GPIO_ReadInputDataBit(GPIO_temp,temp)==1)
				delay_us(40);
		if(GPIO_ReadInputDataBit(GPIO_temp,temp)==1)
		value|=0x01;//������ �Ӹ�λ��ʼ
		while(GPIO_ReadInputDataBit(GPIO_temp,temp)==1);
	}
	 //printf("��һλ��%d,and%d\r\n",value,test);
	return value;	
}




