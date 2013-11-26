// Sound.c
// Runs on LM3S1968
// Driver for sounds
// Phillip Lemons & Anish Vaghasia
// March 30, 2013

#include "DAC.h"
#include "PLL.h"
#include "hw_types.h"
#include "sysctl.h"
#include "lm3s1968.h"

#define NVIC_SYS_PRI3_R         (*((volatile unsigned long *)0xE000ED20))  // Sys. Handlers 12 to 15 Priority
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))


volatile unsigned long Counts = 0;

// **************SysTick_Init*********************
// Initialize Systick periodic interrupts
// Input: interrupt period
//        Units of period are 20ns
//        Maximum is 2^24-1
//        Minimum is determined by length of ISR
// Output: none
void SysTick_Init(unsigned long period){
  Counts = 0;
  NVIC_ST_CTRL_R = 0;         // disable SysTick during setup
  NVIC_ST_RELOAD_R = period-1;// reload value
  NVIC_ST_CURRENT_R = 0;      // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; // priority 2
                              // enable SysTick with core clock and interrupts
  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC+NVIC_ST_CTRL_INTEN;
}

//**************SysTick ISR*************************
// Outputs sine wave value to DAC
// Executes every 20ns*(period)
// To play at 440Hz period = 1136
const unsigned char wave[100] = {
	7,8,8,9,9,10,10,11,11,12,12,12,13,13,13,14,14,14,14,14,15,15,15,15,15,15,15,15,15,15,15,14,14,14,14,14,13,13,13,
	12,12,12,11,11,10,10,9,9,8,8,7,7,7,6,6,5,5,4,4,3,3,3,2,2,2,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,2,2,2,3,3,3,
	4,4,5,5,6,6,7,7};

void SysTick_Handler(void){
	static long i=0;
	GPIO_PORTE_DATA_R ^= 0x08;
	GPIO_PORTG_DATA_R ^= 0x04;
	DAC_Out(wave[i]);
	i = (i+1)%100;
	Counts = Counts+1;
	//GPIO_PORTE_DATA_R &= ~0x08;
}

// **************Sound_Init*********************
// Initializes everything needed to produce sound
// Calls DAC_Init, PLL_Init
// Input: none
// Output: none
void Sound_Init(void) {
	DAC_Init();
	PLL_Init();

}

const unsigned int freq_arr[19] = {440, 220, 494, 247, 523, 262, 587, 294, 659, 330, 698, 349, 783, 392,
																	 196, 175, 165, 147, 130}; //freq of [A4, B4, C5, D5, E5, F5, G5]
void Sound_Play(char note) {
	long freq;
	long period;
	switch(note) {
		case('A'):
			freq = freq_arr[0]; break;
		case('a'):
			freq = freq_arr[1]; break;
		case('B'):
			freq = freq_arr[2]; break;
		case('b'):
			freq = freq_arr[3]; break;
		case('C'):
			freq = freq_arr[4]; break;
		case('c'):
			freq = freq_arr[5]; break;
		case('D'):
			freq = freq_arr[6]; break;
		case('d'):
			freq = freq_arr[7]; break;
		case('E'):
			freq = freq_arr[8]; break;
		case('e'):
			freq = freq_arr[9]; break;
		case('F'):
			freq = freq_arr[10]; break;
		case('f'):
			freq = freq_arr[11]; break;
		case('G'):
			freq = freq_arr[12]; break;
		case('g'):
			freq = freq_arr[13]; break;
		case('z'):
			freq = freq_arr[14]; break;
		case('y'):
			freq = freq_arr[15]; break;
		case('x'):
			freq = freq_arr[16]; break;
		case('w'):
			freq = freq_arr[17]; break;
		case('v'):
			freq = freq_arr[18]; break;
		case('S'):
			freq = 0; break;
		default:
			freq = 0; break;
	}
	if(freq!=0) 
	{
		period = 1000000000/(100*freq*20); // period = 1e9/(wave.length*freq*20)
	} 
	else
	{
		period = 0;
	}
	SysTick_Init(period);
}

void PortGInit()
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOG; // activate port G
  delay = SYSCTL_RCGC2_R;      					// allow time for clock to stabilize
	GPIO_PORTG_DIR_R |= 0x04;							// PG2 set to out
  GPIO_PORTG_DIR_R &= ~0x08;       			// PG3 set to in
	GPIO_PORTG_AFSEL_R &= ~0x0C; 					// Turn off alternate functions PG2 & 3
	GPIO_PORTG_DEN_R |= 0x0C;	 						// Enable PG2 & 3
}
