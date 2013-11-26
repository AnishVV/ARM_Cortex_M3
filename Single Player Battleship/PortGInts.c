// PortGInts.c
// Used to setup and execute interrupts on up,down,left,right buttons
// PG3:Up,PG4:Down,PG5:Left,PG6:Right
// Phillip Lemons
// 4/19/13

#include "lm3s1968.h"
#include "Output.h"
#include "Grid.h"
#include "Display.h"
#include "Utils.h"
#include <stdio.h>

volatile unsigned long Counts1 = 0;

// Initiates Port G with interrupts
// PG3-7 are input (PG3->Up,PG4->Down,PG5->Left,PG6->Right,PG7->Select)
void PortGInts_Init()
{
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOG; // activate port D
  Counts1 = 0;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // activate port D
  Counts1 = 0;
  GPIO_PORTG_DIR_R |= 0x04;   					// make PG2 out
  GPIO_PORTG_DEN_R |= 0x04;   					// enable digital I/O on PG2
	GPIO_PORTG_AFSEL_R &= ~0x04; 					// Turn off alternate functions PG2
	
	GPIO_PORTF_DIR_R &= 0x80;   					// make PG2 out
	GPIO_PORTF_AFSEL_R &= ~0x80; 					// Turn off alternate functions PG2
  GPIO_PORTF_DEN_R |= 0x80;   					// enable digital I/O on PG2
	
	GPIO_PORTG_DIR_R &= ~0xF8;						// Set PG3-7 to output
	GPIO_PORTG_AFSEL_R &= ~0xF8;					// Disable alternate functions on PG3-7
	GPIO_PORTG_PUR_R |= 0xF8;							// Enable pull-up register on PG3-7
	GPIO_PORTG_IS_R &= ~0xF8;							// Set pins to detect edges
	GPIO_PORTG_IBE_R &= ~0xF8;						// Set pins to detect single edge
	GPIO_PORTG_IEV_R |= ~0xF8;						// Set pins to detect low edges
	GPIO_PORTG_IM_R |= 0xF8;							// Enable interrupts on PG3-7
	GPIO_PORTG_DEN_R |= 0xF8;   					// enable digital I/O on PG3-7
	NVIC_PRI7_R = (NVIC_PRI7_R&0x00FFFFFF)|0xA0000000; // priority 2
	NVIC_EN0_R |= 0x80000000;							// Enable interrupts for Port G
}

// Turns PortG interrupts off
void PortGInts_DisableInterrupts()
{
	NVIC_EN0_R &= ~0x80000000;
}

// Turns PortG interrupts on
void PortGInts_EnableInterrupts()
{
	NVIC_EN0_R |= 0x80000000;
}

// Called everytime one of the buttons is pushed
void GPIOPortG_Handler()
{
	int input;
	input = (GPIO_PORTG_RIS_R&0xF8)>>3;
	GPIO_PORTG_DATA_R ^= 0x04;
	Delay1(2500000);							// This is to deal with button bouncing
	GPIO_PORTG_ICR_R |= 0xF8;			// Acknowledge interrupt
	if(Turn > 0)
	{
		if(input == 0x01)
		{
			//code for up button
			Display_MoveCursor(UP);
		} else if (input == 0x02) {
			//code for down button
			Display_MoveCursor(DOWN);
		} else if (input == 0x04) {
			//code fore left button
			Display_MoveCursor(LEFT);
		} else if (input == 0x08) {
			//code for right button
			Display_MoveCursor(RIGHT);
		} else if (input == 0x10) {
			//code for select button
			Grid_Attack();
		} else {
			//Wat?
			Grid_PlaceTile(ENEMY, TILE_MISS, 0,0);
			Display_Grid(ENEMY);
		}
}
}
