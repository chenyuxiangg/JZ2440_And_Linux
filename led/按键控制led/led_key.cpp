/*
* D10: GPF4(GPFCON[9:8]), D11: GPF5(GPFCON(11:10)),
* D12: GPF6(GPFCON[13:12])

*按键初始时是高电平，按下时低电平，松开时高电平
*s2(GPF0:GPFCON[1:0],GPFDAT[0])-->D12 ,s3(GPF2:GPFCON[5:4],GPFDAT[2])-->D11, s4(GPG3:GPGCON[7:6],GPGDAT[3])-->D10
*/

#define GPFCON (*((unsigned int*)0x56000050))
#define GPFDAT (*((unsigned int*)0x56000054))
#define GPGCON (*((unsigned int*)0x56000060))
#define GPGDAT (*((unsigned int*)0x56000064))
#define INIT_LED {GPFCON &= ~(3<<8 | 3<<10 | 3<<12);GPFCON |= (1<<8 | 1<<10 | 1<<12);}
#define INIT_KEY {GPFCON &= ~(3<<0 | 3<<4);GPGCON &= ~(3<<6);}

int main(int argc,char* argv[])
{
	INIT_LED;
	//循环点亮led
	while(1) {
		if ((GPFDAT>>0) & 1) {
			//松开，熄灭D12
			GPFDAT |= (1<<6);
			}
		else {
			GPFDAT &= ~(1<<6);
			}

		if ((GPFDAT>>2) & 1) {
			GPFDAT |= (1<<5);
			}
		else {
			GPFDAT &= ~(1<<5);
			}

		if ((GPGDAT>>3) & 1) {
			GPFDAT |= (1<<4);
			}
		else {
			GPFDAT &= ~(1<<4);
			}
		}
	
	return 0;
 } 
