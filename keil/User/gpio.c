#include "gpio.h"

void my_delay(void)
{
	int i,j;
	for(i=5000;i>0;i--)
	{
		for(j=10000;j>0;j--) ;
	}
}

