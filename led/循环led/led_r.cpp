/*
* led1: GPF4(GPFCON[9:8]), led2: GPF5(GPFCON(11:10)),
* led4: GPF6(GPFCON[13:12])
*/

#define GPFCON (*((unsigned int*)0x56000050))
#define GPFDAT (*((unsigned int*)0x56000054))
#define INIT_LED (GPFCON &= ~(3<<8 | 3<<10 | 3<<12);GPFCON |= (1<<8 | 1<<10 | 1<<12))

void delay(unsigned int d)
{
	while (d--);
}

int main(int argc,char* argv[])
{
	INIT_LED;
	//循环点亮led
	while(1) {
	//led1 on
	GPFDAT |= (7<<4);
	GPFDAT &= ~(1<<4);
	delay(10000);

	//led2 on
	GPFDAT |= (7<<4);
	GPFDAT &= ~(1<<5);
	delay(10000);

	//led4 on
	GPFDAT |= (7<<4);
	GPFDAT &= ~(1<<6);
	delay(10000);
		}
	
	return 0;
 } 
