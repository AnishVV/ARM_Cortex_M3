// Sound.h
// Runs on LM3S1968
// Sound_Init initiates sound driver with systick interrupts creating a sine wave on DAC
// Phillip Lemons & Anish Vaghasia
// March 30, 2013

void Sound_Init(void);
void Sound_Play(char note);
void PortGInit(void);
