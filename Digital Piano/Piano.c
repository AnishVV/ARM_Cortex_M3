//Piano.c
//Anish Vaghasia & Philip Lemons



#include "lm3s1968.h"


void Piano_Init(void)
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE; // activate port E
	delay = SYSCTL_RCGC2_R;      					// allow time for clock to stabilize
	GPIO_PORTE_DIR_R &= ~0x07;   					// PE0-2 set to input
	GPIO_PORTE_DIR_R |= 0x08;							// PE0-2 set to output
	GPIO_PORTE_AFSEL_R &= ~0x0F; 					// Turn off alternate functions PE0-2
	GPIO_PORTE_DEN_R |= 0x0F;	 						// Enable PE0-2
}


char Piano_Read(void)
{
	char note;
	note = GPIO_PORTE_DATA_R;
	note &= 0x07;
	if(note == 0x04)
	{
		return 'A';
	}
	else if(note == 0x02)
	{
		return 'B';
	}
	else if(note == 0x01)
	{
		return 'C';
	}	 
	else if (note == 0x06)
	{
		return 'Z';
	}
	else if (note == 0x03)
	{
		return 'Y';
	}
	else if (note == 0x07)
	{
		return 'S';
	}
	else {
		return 0;
	}
}
