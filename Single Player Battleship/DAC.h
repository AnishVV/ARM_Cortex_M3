// DAC.h
// Runs on LM3S1968
// DAC_Init initiates the DAC driver.
// DAC_Out outputs a four-bit binary number to ports PD0, PD1, PD2, PD3 where PD0 is the
// least significant bit and PD3 is the most significant bit
// Example: DAC_Out(0x03) will make PD0 1, PD1 1, PD2 0, PD3 0
// Phillip Lemons
// March 30, 2013

void DAC_Init(void);
void DAC_Out(long output);
void DAC_Init6(void);
void DAC_Out6(long output);
