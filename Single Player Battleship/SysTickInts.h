// SysTickInts.h
// Runs on LM3S1968
// Use the SysTick timer to request interrupts at a particular period.
// Daniel Valvano
// June 27, 2011

// **************SysTick_Init*********************
// Initialize Systick periodic interrupts
// Input: interrupt period
//        Units of period are 20ns
//        Maximum is 2^24-1
//        Minimum is determined by length of ISR
// Output: none
void SysTick_Init(unsigned long period);

// *************SysTick_Stop()********************
// Disables SysTick interrupts without changing anything else
void SysTick_Stop(void);

// *************SysTick_Start()********************
// Enables SysTick interrupts
void SysTick_Start(void);

// **************SysTick_ISR***********************
// 1) Toggles PG2
