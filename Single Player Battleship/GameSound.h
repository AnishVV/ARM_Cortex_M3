//GameSound.h
//
//
//
//

typedef struct
{
	long length, bpm;
	char **notes;
	int *lengths;
} Song;

//Global Varaiables
extern char SFX;
extern char Music;


//Methods

void SysTick_Init(unsigned long period);
void Sound_Init(void);
void PlaySFX(const unsigned char array[], int Max);
void PlayNote(char note);




