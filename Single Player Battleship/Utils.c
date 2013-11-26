// Utils.c
// Provides extra functions like Random
// Phillip Lemons and Anish Vaghasia
// 4/22/13

unsigned long M=1;
void Seed(unsigned long n){
	M = n;
}
// Random number generator
// from Numerical Recipes by Press et al.
unsigned long Random(void){
	M = 1664525*M+1013904223;
	return(M);
}

// which delays 3*ulCount cycles
//Keil uVision Code
__asm void Delay1(unsigned long ulCount)
{
  subs    r0, #1
  bne     Delay1
  bx      lr
}
