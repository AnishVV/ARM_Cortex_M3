// Main.c
// Runs on LM3S1968
// Calls the other data files.
// Anish Vaghasia & Phillip Lemons
// June 27, 2011


#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "Sound.h"
#include "Piano.h"
#include "Test.h"
#include "lm3s1968.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts


int main(void){       // bus clock at 50 MHz
	Sound_Init();
  SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
                 SYSCTL_XTAL_8MHZ);
	PortGInit();
  EnableInterrupts();
	Piano_Init();
	Test_Music();
	//Test_Scale();
  while(1)
	{ 
		char PrevNote;
		char note = Piano_Read();
		if(note != PrevNote)
		{
			if(note == 'Z')
			{
				Test_Music();
			}
			else if(note == 'Y')
			{
				Test_Scale();
			}
			else
			{
				Sound_Play(note);
				PrevNote = note;
			}
		}
	}
}


/*
int main(void){
	unsigned long Data;
	PLL_Init();
	DAC_Init();
	for(;;) {
		DAC_Out(Data);
		Data = 0x0F&(Data+1);
	}
}
*/
