//GameSound.c
//
//
//
//
//

#include "DAC.h"
#include "PLL.h"
#include <string.h>
#include "hw_types.h"
#include "sysctl.h"
#include "lm3s1968.h"
#include "math.h"
#include "Sounds.h"
#include <stdio.h>
#include <stdlib.h>
#include "GameSound.h"


#define NVIC_SYS_PRI3_R         (*((volatile unsigned long *)0xE000ED20))  // Sys. Handlers 12 to 15 Priority
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define M_PI 3.14159265358979323846
#define PROC_SPEED 100000



//Global Variables

char SFX;
char Music;
int countSFX = 0;
int countMusic = 0;
volatile unsigned long Counts = 0;
//*****************************************Initializations************************************************


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
// Disables SysTick interrupts
	}

void SysTick_Stop(void) {
	NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;
}

// **************Sound_Init*********************
// Initializes everything needed to produce sound
// Calls DAC_Init, SysTick_Init
// Input: none
// Output: none
void Sound_Init(void) {
	countSFX = countMusic = 0;
	DAC_Init();
	PLL_Init();
}





//**********************************************Sound Code******************************************************

// const unsigned int freq_arr[42] = {16,18,21,22,25,28,31,33,37,41,44,49,55,62,65,73,82,87,98,110,123,131,
// 								   147,165,175,196,220,247,262,294,330,349,392,440,494,523,587,659,698,
// 								   784,880,988};

const unsigned int freq_arr[19] = {440, 220, 494, 247, 523, 262, 587, 294, 659, 330, 698, 349, 783, 392,
																	 196, 175, 165, 147, 130};

long get_freq(char note) {
	long freq;
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
	return freq;
}


void Sound_Stop(void) {
	NVIC_ST_CTRL_R=0;
}


// **************Sound_PlayNote******************
// Plays a specified note
// Input: character of note to play
// Output: none
void PlayNote(char note) {
	long freq;
	long period;
	freq = get_freq(note);
	if(freq!=0) 
	{
		period = 1000000000/(100*freq*20); // period = 1e9/(wave.length*freq*20)
		SysTick_Init(period);
	} 
	else
	{
		Sound_Stop();
	}
}



//*****************************************Systick ISR*****************************************


#define BEAT 100000
#define Shoot_SIZE 0
#define Explosion_SIZE 0
#define Plop_SIZE 1054       //15931 //plopsize

#define IntroM_SIZE 0
#define GameM_SIZE 0
#define EndM_SIZE 0


//**************SysTick ISR*************************
//Determines what to play from looking at Flags SFX and Music
//Then calls respective method with parameters of Array pointer and array size
// 

const unsigned char wave[100] = {7,8,8,9,9,10,10,11,11,12,12,12,13,13,13,14,14,14,14,14,15,15,15,15,15,15,15,15,15,
																 15,15,14,14,14,14,14,13,13,13,12,12,12,11,11,10,10,9,9,8,8,7,7,7,6,6,5,5,4,4,3,3,3,
																 2,2,2,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,2,2,2,3,3,3,4,4,5,5,6,6,7,7};
	

	
const int arraylength = 86;
static char MUS1[arraylength] =  {'f','A','B','f','A','B','f','A','B' ,'E','D','B','C','B','g','e',
															 'd','e','g','e','f','A','B','f','A','B','f','A','B', 'E','D','B','C','E','B','g',
															 'B','g','c','d', 'v','w','x','y','z','a','b','a','w',
															 'c','d','e','f','g','A','B','C','D', 'v','w','x','y','z','a','b','a','w',
															 'c','b','e','d','f','e','g','f','A','g','B','A','C','B', 'e','f','d','e'};
static int MUSC[arraylength] = {2,2,4,2,2,4,2,2,2 ,2,4,2,2,2,2,8,
														 2,2,2,5,2,2,4,2,2,4,2,2,2, 2,4,2,2,2,2,7,
														 2,2,2,5, 2,2,4,2,2,4,2,2,4,
														 2,2,4,2,2,4,2,2,7, 2,2,4,2,2,4,2,2,7,
														 2,2,2,2,2,2,2,2,2,2,2,2,2,2, 1,2,1,8};



	

														 
int size;
int counter = 0;
int Mcounter = 0;
char note;
char savenote;
void SysTick_Handler(void){
		static long i=0;
		GPIO_PORTG_DATA_R ^= 0x04;
		DAC_Out(wave[i]);
		i = (i+1)%100;
		Counts = Counts+1;
		if(SFX != 0){
			if(SFX == 1){
				if(counter >= 5000){
					PlayNote(0);
					SFX = 0;
					counter = 0;
				}
				else if(counter >= 4000){
					PlayNote('D');
					counter++;
				}
				else if(counter >= 3000){
					PlayNote('C');
					counter++;
				}
				else if(counter >= 2000){
					PlayNote('B');
					counter++;
				}
				else if(counter >= 0) {
					PlayNote('A');
					counter++;
				}
			}
			if(SFX == 2){
				if(counter >= 5000){
					PlayNote(0);
					SFX = 0;
					counter = 0;
				}
				else if(counter >= 4000){
					PlayNote('A');
					counter++;
				}
				else if(counter >= 3000){
					PlayNote('B');
					counter++;
				}
				else if(counter >= 2000){
					PlayNote('C');
					counter++;
				}
				else if(counter >= 0) {
					PlayNote('D');
					counter++;
				}
			}
		PlayNote(note);
		}
		else if(Music !=0){
			if(Mcounter == 0){
				note = MUS1[countMusic];
				PlayNote(note);
				Mcounter = MUSC[countMusic] * 4500;
				if((note > 'D')&&(note <= 'G')){
					Mcounter+= 500;
				}
				if(note >= 'a'){
					Mcounter-= 500;
				}
				if(note >= 'v'){
					Mcounter-= 500;
				}
				countMusic = (countMusic + 1)% (arraylength-1);
			}
			Mcounter--;
		}
		
}
// 		else if(Music != 0){
// 			if(Music == 0) {
// 				size = IntroM_SIZE;
// 				PlayMusic(MUS1, size);
// 			}
// 		}




// void SysTick_Handler(void){
// 			GPIO_PORTG_DATA_R ^= 0x04;
// 			if(SFX != 0){
// // 			if(SFX == 1) {
// // 				size = Shoot_SIZE;
// // 				PlaySFX(Shoot, size);
// // 			}
// // 			else if(SFX == 2) {
// // 				size = Explosion_SIZE;
// // 				PlaySFX(Explosion, size);
// // 			}
// 			if(SFX == 3) {
// 				size = Plop_SIZE;
// 				PlaySFX(Invader, size);
// 			}
// 		}
// 		else if(Music != 0){
// 			if(Music == 0) {
// 				size = IntroM_SIZE;
// 				PlayMusic(/* pointer which to Music array*/, size);
// 			}
// 			else if(Music == 0) {
// 				size = GameM_SIZE;
// 				PlayMusic(/* pointer which to Music2 array*/, size);
// 			}
// 			else if(Music == 0) {
// 				size = EndM_SIZE;
// 				PlayMusic(/* pointer which to Music3 array*/, size);
// 			}
// 		}

//}

// char output;
// void PlaySFX(const unsigned char array[], int Max){
// 	if(countSFX <= Max - 1)
// 	{
// 		unsigned char output = array[countSFX];
// 		DAC_Out(output);
// 		countSFX++;                                //check
// 	}
// 	else
// 	{
// 		countSFX = countSFX%Max;
// 		SFX = 0;
// 	}
// }
	
// char *note;
// short PrevMax;
// short counter;
// void PlayMusic(/*pointer which to SFX array*/, short Max){
// 		if(PrevMax != Max){
// 			PrevMax = Max;
// 			countMusic = 0;
// 		}
// 		if(counter == 0){
// 			note = Array[countMusic];
// 			PlayNote(note);
//			countMusic++;
// 		}
// 		counter = (counter+1)%BEAT;
// 		countMusic = countMusic%Max;
// 		
// }
		

	
	//*****************************************Sounds**************************************************
