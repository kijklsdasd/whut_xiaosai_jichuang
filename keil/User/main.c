#include "main.h"
#include "gpio.h"
#include <string.h>
#include <stdint.h>

#define CS 		GPIO_1_out
#define SCK 	GPIO_2_out
#define MOSI 	GPIO_3_out
#define MISO 	GPIO_4_out
void soft_SPI_Write_MODE00(unsigned char write_data);
int main(void)
{ 
		GPIO_en=1;
//		GPIO_1_out=0;
//		GPIO_1_out=1;
//		GPIO_1_out=0;
    while(1){
		soft_SPI_Write_MODE00('m');
		soft_SPI_Write_MODE00('0');
    }
}

void soft_SPI_Write_MODE00(unsigned char write_data)
{
    
  unsigned char i=0;
	CS=0;
	SCK=0;                //SCK空闲时为低电平
    
    for (i = 0; i < 8; i++) //写入数据，从高位开始
    {
        if (write_data & 0x80)
        {
            MOSI=1;
        }
        else
        {
            MOSI=0;
        }
        SCK=1; //时钟拉高 上升沿传输一位数据
        write_data<<=1;
        SCK=0; //时钟拉低等待下一位数据的传输
    }
    CS=1;		//片选拉高结束通讯
}

