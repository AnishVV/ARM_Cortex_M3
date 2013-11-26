//Test.c
//Anish Vaghasia & Phillip Lemons

//

#include "Sound.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "Test.h"
#include "lm3s1968.h"
#include "Piano.h"

 void Test_Scale(void)
 {
	 char note = 'A';
	 char stopnote;;
	 while(note <= 'g')
	 {
		int counter =5000000;
		 while(counter > 0)
			{
				char PrevNote;
				if(note != PrevNote)
				{
					Sound_Play(note);
					PrevNote = note;
				}
				counter--;
			}
		note++;
		stopnote = Piano_Read();
		if(stopnote == 'S')
			{
				counter = 8000000;
				Sound_Play(stopnote);
				while(counter > 0)
				{					
					counter--;
				}
				break;
			}
		while((note > 'G') && (note < 'a'))
		{
			note++;
		}
	 }
 }

 
 void Test_Music(void)
 {
		const int arraylength = 86;
		static char Sample[arraylength] =  {'f','A','B','f','A','B','f','A','B' ,'E','D','B','C','B','g','e',
															 'd','e','g','e','f','A','B','f','A','B','f','A','B', 'E','D','B','C','E','B','g',
															 'B','g','c','d', 'v','w','x','y','z','a','b','a','w',
															 'c','d','e','f','g','A','B','C','D', 'v','w','x','y','z','a','b','a','w',
															 'c','b','e','d','f','e','g','f','A','g','B','A','C','B', 'e','f','d','e'};
		static int Length[arraylength] = {2,2,4,2,2,4,2,2,2 ,2,4,2,2,2,2,8,
														 2,2,2,7,2,2,4,2,2,4,2,2,2, 2,4,2,2,2,2,7,
														 2,2,2,9, 2,2,4,2,2,4,2,2,7,
														 2,2,4,2,2,4,2,2,7, 2,2,4,2,2,4,2,2,7,
														 2,2,2,2,2,2,2,2,2,2,2,2,2,2, 1,2,1,11};
		int i = 0;																										
		char note = Sample[i];
		char stopnote;
		int counter;
		while(i != arraylength + 1)
		 {
			  Sound_Play(note);
				counter = Length[i]*7000000/8;  //1.2s = 5813953
				while(counter > 0)
				{					
					counter--;
					counter++;
					counter--;
				}
			i++;
			note = Sample[i];
			stopnote = Piano_Read();
			if(stopnote == 'S')
			{
				counter = 8000000;
				Sound_Play(stopnote);
				while(counter > 0)
				{					
					counter--;
				}
				break;
			}
		 }
		 
 }
 
void Test_Chord(void)
{
	char note = 'A';
	char note2 = 'B';
	int counter =0;
	counter =2000;
		 while(counter > 0)
			{
				char PrevNote;
				if(note != PrevNote)
				{
					Sound_Play(note);
					PrevNote = note;
				}
				counter--;
			}
		counter =2000;
		 while(counter > 0)
			{
				char PrevNote;
				if(note2 != PrevNote)
				{
					Sound_Play(note2);
					PrevNote = note2;
				}
				counter--;
			}
}


