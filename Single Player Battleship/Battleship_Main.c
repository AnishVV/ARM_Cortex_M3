// Battleship.c
// Runs on LM3S1968
// Phillip Lemons and Anish Vaghasia
// 04/23/13

#include "hw_types.h"
#include "sysctl.h"
#include "lm3s1968.h"
#include "PLL.h"
void EnableInterrupts(void);  // Enable interrupts

#include "Art/Art.h"
#include "ADC.h"
#include "PortGInts.h"
#include "Grid.h"
#include "Display.h"
#include "UART.h"
#include "SysTickInts.h"
#include "Utils.h"
#include <stdio.h>
#include "GameSound.h"


void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode



int main(void){
	int winner;
	long adcin;
	int ships;
	Sound_Init();
	//DisableInterrupts();							// Disables interrupts while everything is being intialized
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);
																			// Initiate modules (except grid)
	ADC_Init(1);
	Display_Init();										// 						|
	PortGInts_Init();									//  					|
	//SysTick_Init(10000);  						//  				------
	Display_Cover();									// Displays the main cover art
	EnableInterrupts();
	printf("  Please Hit Start\n");		// Prompts user to push select
	while((GPIO_PORTF_DATA_R&0x80)!=0x80) // waits for user to push start
	{}
	Delay1(25000000);
	Seed(NVIC_ST_CURRENT_R);					// Seeds random number generator
	SysTick_Stop();	
	Display_Clear();
	while((GPIO_PORTF_DATA_R&0x80)!=0x80){
		int prev_ships;
		adcin = ADC_In();
		if(adcin<1500/3) ships = 1;
		else if(adcin<3000/3) ships = 2;
		else ships = 3;
		if(prev_ships!=ships) {
			prev_ships = ships;
			Display_Clear();
			Display_Menu(ships);
		}
	}
	EnableInterrupts();
	Grid_Init(ships);
	Grid_SetHasAttacked(0);
	Display_Clear();
	Music = 1;
	SysTick_Init(100);
	while(1)
	{	
		Turn = 1;
		Display_Grid(ENEMY);
		while(!Grid_HasAttacked()){}
		if(Grid_CheckEndGame(ENEMY))
		{
			winner=FRIEND;
			break;
		}
		Display_Grid(ENEMY);
		Grid_SetHasAttacked(0);
		Turn = -1;
		Delay1(25000000);               // Delays for 3s??
		
		Display_Grid(FRIEND);
		Delay1(45000000/2);
		Grid_AIAttack();
		if(Grid_CheckEndGame(FRIEND))
		{
			winner=ENEMY;
			break;
		}
		Display_Grid(FRIEND);
		Delay1(45000000/2);
	}
	Display_Clear();
	Display_Winner(winner);
	while(1);
}




//************************************SOUND TEST************************************
/*

#include "GameSound.h"
#include "DAC.h"





int main(){
	Sound_Init();
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
                 SYSCTL_XTAL_8MHZ);
	EnableInterrupts();
	SFX = 3;
	SysTick_Init(4535);
		while(SFX == 3){
	}
	GPIO_PORTG_DATA_R ^= 0x04;
	while(1) {};
	//SFX = 1;
	
}


*/
