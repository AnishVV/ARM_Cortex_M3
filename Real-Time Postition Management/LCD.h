//LCD.h
//
//



//LCD_Open
void LCD_Open(void);

//LCD_OutChar
void LCD_OutChar(unsigned char ASCII);

//LCD_Clear
void LCD_Clear(void);

//LCD_GoTo
void LCD_GoTo(unsigned long DDaddr);

// ---------------------LCD_OutString-------------
// Output character string to LCD display, terminated by a NULL(0)
// Inputs:  R0 (call by reference) points to a string of ASCII characters 
// Outputs: none
// This is a public function
// Invariables: This function must not permanently modify registers R4 to R11
void LCD_OutString(unsigned char * StringPT);

//-----------------------LCD_OutDec-----------------------
// Output a 32-bit number in unsigned decimal format
// Input: R0 (call by value) 32-bit unsigned number 
// Output: none
// This is a public function
// Invariables: This function must not permanently modify registers R4 to R11
void LCD_OutDec(unsigned long CallValue);

//LCD_OutFix
void LCD_OutFix(unsigned short number);

