/*******************************************************************************
*                 
*                 		       普中科技
--------------------------------------------------------------------------------
* 实 验 名		 : IIC AT24C02实验
* 实验说明       : 通过printf打印IIC读写数据，读取的数据是写入数据加1结果，只要按下复位按键即可在串口上显示
* 连接方式       : 
* 注    意		 : 	所用函数在头文件.c文件内
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
	printf_init();	//printf初始化
	temp_init();

	while(1){
		printf("开始 \r\n");
		tempinit();
	   	a=temprd();
		b=temprd();
	   	c=temprd();
	   	d=temprd();
	   	e=temprd();
		//printf("a=%u,b=%u,c=%u,d=%u,e=%u \r\n",a,b,c,d,e);
		//value=(a&0xf0)*10+(a&0x0f);
		//printf("当前湿度为：%d %%RH\r\n",value);
		//value=(c&0xf0)*10+(c&0x0f);
		//printf("当前温度为：%d ℃\r\n",value);
	if((a+b+c+d)==e)  {
	   	//value=(a&0xf0)*10+(a&0x0f);
		printf("当前湿度为：%u %%RH\r\n",a);
		//value=(c&0xf0)*10+(c&0x0f);
		printf("当前温度为：%u ℃\r\n",c);
		} else
		printf("当前测量无效，待重新测量 \r\n ");
		
		delay_us(50);
		delay_ms(1000);
	}

}



