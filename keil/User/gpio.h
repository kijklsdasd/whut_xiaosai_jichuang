#ifndef _GPIO_H
#define _GPIO_H
#include <stdint.h>
#define GPIO_1_out 	(*(volatile unsigned *)0X40000110)
#define GPIO_2_out 	(*(volatile unsigned *)0X40000120)
#define GPIO_3_out 	(*(volatile unsigned *)0X40000140)
#define GPIO_4_out 	(*(volatile unsigned *)0X40000180)
	
#define GPIO_in 	(*(volatile unsigned *)0X40000114)
#define GPIO_en 	(*(volatile unsigned *)0x40000118)
void my_delay(void);
#endif
