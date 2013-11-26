// DAC.c
// Runs on LM3S1968
// Driver for DAC connected to PD0-3
// Phillip Lemons
// March 30, 2013
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC2_GPIOD      0x00000008  // port D Clock Gating Control

#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define SYSCTL_RCGC2_GPIOF      0x00000020  // port D Clock Gating Control

#define DAC_OUT									(*((volatile unsigned long *)0x4000703C))
#define DAC_OUT6								(*((volatile unsigned long *)0x400250FC))

#include "lm3s1968.h"

// **************DAC_Init*********************
// Initialize DAC
// PD0-PD3 are set to output (PD0 is connected to R, PD1 => 2R, PD2 => 4R, PD3 => 8R)
// Input: none
// Output: none
void DAC_Init(void) {
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOD; // activate port D
  delay = SYSCTL_RCGC2_R;      					// allow time for clock to stabilize
	GPIO_PORTD_DIR_R |= 0x0F;   					// PF0-3 set to out
	GPIO_PORTD_AFSEL_R &= ~0x0F; 					// Turn off alternate functions PF0-3
	GPIO_PORTD_DEN_R |= 0x0F;	 						// Enable PF0-3
	
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOG;
	delay = SYSCTL_RCGC2_R;
	GPIO_PORTG_DIR_R |= 0x04;   					// PD0-3 set to out
	GPIO_PORTG_AFSEL_R &= ~0x04; 					// Turn off alternate functions PD0-3
	GPIO_PORTG_DEN_R |= 0x04;

}

void DAC_Out(long output) {
	DAC_OUT = output;
}

void DAC_Init6(void) {
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // activate port F
  delay = SYSCTL_RCGC2_R;      					// allow time for clock to stabilize
	GPIO_PORTF_DIR_R |= 0x3F;   					// PF0-5 set to out
	GPIO_PORTF_AFSEL_R &= ~0x3F; 					// Turn off alternate functions PF0-5
	GPIO_PORTF_DEN_R |= 0x3F;	 						// Enable PF0-5
}

void DAC_Out6(long output) {
	DAC_OUT6 = output;
}
