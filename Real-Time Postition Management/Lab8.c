// These are the testing files for Lab 8
/*
#include "pll.h"
#include "ADC.h"
unsigned long Data;
int main(void){
  PLL_Init();         // Bus clock is 50 MHz 
  ADC_Init(2);        // turn on ADC, set channel to 2, sequencer 3
  while(1){                
    Data = ADC_In();  // sample 10-bit channel 2
  }
}
*/
/*
unsigned long Convert(unsigned long Data);
unsigned long Data;
unsigned long Position;  // 16-bit fixed-point 0.001 cm
#include "pll.h"
#include "ADC.h"
#include "LCD.h"
#include "SysTickInts.h"
#include "lm3s1968.h"
#define N 256
int main(void){  
	long input;
  PLL_Init();              // Bus clock is 50 MHz 
	//ADC_PortGInit();
  LCD_Open();   
  LCD_Clear();
  ADC_Init(2);             // turn on ADC, set channel to 2, sequencer 3
	
	SysTick_Init(2000000);
	while(1){
		if(mailbox_flag==1)
		{
			input = mailbox;
			mailbox_flag = 0;
			input = Convert(input);
			//input = (8.874+1.668*input);
			//LCD_OutFix(input_cm);
		
		//input = 1552;
		LCD_GoTo(0);
    LCD_OutFix(input); 
		LCD_OutString("cm  ");
		}			
	}
}


unsigned long Convert(unsigned long Data)
{
		unsigned long converted;
		converted = Data*427;
		converted += 2271;
		converted = converted/256;
		return converted;
}
*/

unsigned long Data;
unsigned long Position;  // 16-bit fixed-point 0.001 cm
#include "pll.h"
#include "ADC.h"
#include "LCD.h"
#include "SysTickInts.h"
#include "lm3s1968.h"
#define N 256
int main(void){ int i; unsigned long sum;
  PLL_Init();              // Bus clock is 50 MHz 
  LCD_Open();   
  LCD_Clear();
  ADC_Init(2);             // turn on ADC, set channel to 2, sequencer 3
  while(1){  
    sum = 0;      
    for(i=0; i<N; i++){    // take N samples and perform the average
      sum = sum+ADC_In();  // sample 10-bit channel 2
    }
    Data = sum/N;          // noise reducing filter
    LCD_GoTo(0);
    LCD_OutDec(Data); LCD_OutString("    "); 
  }
}

