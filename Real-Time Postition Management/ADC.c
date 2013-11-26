// ADC.c
// Runs on LM3S1968
// Provide functions that initialize ADC SS3 to be triggered by
// software and trigger a conversion, wait for it to finish,
// and return the result.
// Anish Vaghasia & Phillip Lemons
// May 21, 2012

/* This example accompanies the book
   "Embedded Systems: Interfacing to the Arm Cortex M3",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2012

 Copyright 2012 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

#include "lm3s1968.h"

// There are many choices to make when using the ADC, and many
// different combinations of settings will all do basically the
// same thing.  For simplicity, this function makes some choices
// for you.  When calling this function, be sure that it does
// not conflict with any other software that may be running on
// the microcontroller.  Particularly, ADC sample sequencer 3
// is used here because it only takes one sample, and only one
// sample is absolutely needed.  Sample sequencer 3 generates a
// raw interrupt when the conversion is complete, but it is not
// promoted to a controller interrupt.  Software triggers the
// ADC conversion and waits for the conversion to finish.  If
// somewhat precise periodic measurements are required, the
// software trigger can occur in a periodic interrupt.  This
// approach has the advantage of being simple.  However, it does
// not guarantee real-time.
//
// A better approach would be to use a hardware timer to trigger
// the ADC conversion independently from software and generate
// an interrupt when the conversion is finished.  Then, the
// software can transfer the conversion result to memory and
// process it after all measurements are complete.

// This initialization function sets up the ADC according to the
// following parameters.  Any parameters not explicitly listed
// below are not modified:
// Max sample rate: <=125,000 samples/second
// Sequencer 0 priority: 1st (highest)
// Sequencer 1 priority: 2nd
// Sequencer 2 priority: 3rd
// Sequencer 3 priority: 4th (lowest)
// SS3 triggering event: software trigger
// SS3 1st sample source: programmable using variable 'channelNum' [0:7]
// SS3 interrupts: enabled but not promoted to controller
void ADC_Init(unsigned char channelNum)
{
		if(channelNum > 7)
		{
			return;
		}
		SYSCTL_RCGC0_R |= 0x00010000;   // 1) activate ADC
		SYSCTL_RCGC0_R &= ~0x00000300;  // 2) configure for 125K
		ADC_SSPRI_R = 0x3210;           // 3) Sequencer 3 is lowest priority
		ADC_ACTSS_R &= ~0x0008;         // 4) disable sample sequencer 3
		ADC_EMUX_R &= ~0xF000;          // 5) seq3 is software trigger
		ADC_SSMUX3_R &= ~0x0007;        // 6) clear SS3 field
		ADC_SSMUX3_R += channelNum;     //    set channel
		ADC_SSCTL3_R = 0x0006;          // 7) no TS0 D0, yes IE0 END0
		ADC_IM_R &= ~0x0008;            // 8) disable SS3 interrupts
		ADC_ACTSS_R |= 0x0008;          // 9) enable sample sequencer 3
}

//------------ADC_In()------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 10-bit result of ADC conversion
unsigned long ADC_In(void)
{  
		unsigned long result;
		ADC_PSSI_R = 0x0008;             // 1) initiate SS3
		while((ADC_RIS_R&0x08)==0){};    // 2) wait for conversion done
		result = ADC_SSFIFO3_R&0x3FF;    // 3) read result
		ADC_ISC_R = 0x0008;              // 4) acknowledge completion
		return result;
}

void ADC_PortGInit(void)
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOG; // activate port G
  delay = SYSCTL_RCGC2_R;      					// allow time for clock to stabilize
	GPIO_PORTG_DIR_R |= 0x04;							// PG2 set to out
	GPIO_PORTG_AFSEL_R &= ~0x04; 					// Turn off alternate functions PG2
	GPIO_PORTG_DEN_R |= 0x04;	 						// Enable PG2 
}
