/*******************************************************************************
*                 
*                 		       ���пƼ�
--------------------------------------------------------------------------------
* ʵ �� ��		 : IIC AT24C02ʵ��
* ʵ��˵��       : ͨ��printf��ӡIIC��д���ݣ���ȡ��������д�����ݼ�1�����ֻҪ���¸�λ���������ڴ�������ʾ
* ���ӷ�ʽ       : 
* ע    ��		 : 	���ú�����ͷ�ļ�.c�ļ���
*******************************************************************************/


#include "public.h"
//#include "printf.h"
#include "temp.h"
#include "systick.h"
#include "sdrcv.h"

/****************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
int main()
{	

	u8 a,b,c,d,e;
	int value;
	printf_init();	//printf��ʼ��
	temp_init();

	while(1){
		printf("��ʼ \r\n");
		tempinit();
	   	a=temprd();
		b=temprd();
	   	c=temprd();
	   	d=temprd();
	   	e=temprd();
		//printf("a=%u,b=%u,c=%u,d=%u,e=%u \r\n",a,b,c,d,e);
		//value=(a&0xf0)*10+(a&0x0f);
		//printf("��ǰʪ��Ϊ��%d %%RH\r\n",value);
		//value=(c&0xf0)*10+(c&0x0f);
		//printf("��ǰ�¶�Ϊ��%d ��\r\n",value);
	if((a+b+c+d)==e)  {
	   	//value=(a&0xf0)*10+(a&0x0f);
		printf("��ǰʪ��Ϊ��%u %%RH\r\n",a);
		//value=(c&0xf0)*10+(c&0x0f);
		printf("��ǰ�¶�Ϊ��%u ��\r\n",c);
		} else
		printf("��ǰ������Ч�������²��� \r\n ");
		
		delay_us(50);
		delay_ms(1000);
	}

}



