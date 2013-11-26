// DAC.c
// Runs on LM3S1968
// Driver for DAC connected to PD0-3
// Phillip Lemons & Anish Vaghasia
// March 30, 2013
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define DAC_OUT									(*((volatile unsigned long *)0x4000703C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC2_GPIOD      0x00000008  // port D Clock Gating Control

// **************DAC_Init*********************
// Initialize DAC
// PD0-PD3 are set to output (PD0 is connected to R, PD1 => 2R, PD2 => 4R, PD3 => 8R)
// Input: none
// Output: none
void DAC_Init(void) {
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOD; // activate port D
  delay = SYSCTL_RCGC2_R;      					// allow time for clock to stabilize
	GPIO_PORTD_DIR_R |= 0x0F;   					// PD0-3 set to out
	GPIO_PORTD_AFSEL_R &= ~0x0F; 					// Turn off alternate functions PD0-3
	GPIO_PORTD_DEN_R |= 0x0F;	 						// Enable PD0-3
}

void DAC_Out(long output) {
	DAC_OUT = output;
}
