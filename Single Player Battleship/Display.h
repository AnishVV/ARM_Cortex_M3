// Display.h
// This file contains all the function prototypes and constants for using the Display in battleship
// Phillip Lemons and Anish Vaghasia
// 4/23/13

#include "Grid.h"

#define BORDER_WIDTH 2

extern char Turn;

// ********************Display_Init****************************
// Initates everything needed to display pictures or text on the screen
void Display_Init(void);

// ********************Display_Cover***************************
// Displays the main cover art on the screen
// Allows for text to be displayed at the very top
void Display_Cover(void);

// ********************Display_Clear***************************
// Clears the display
void Display_Clear(void);

// ********************Display_Grid****************************
// Displays the desired grid
// Displays empty grid, cursor, then tiles
void Display_Grid(int player);

// ********************Display_MoveCursor**********************
// Moves the cursor and displays it in the new direction
// Does not require the OLED to display the whole grid again
// If the desired move is invalid the grid remains unchanged
// Input: direction
// Output: None
void Display_MoveCursor(int direction);

// ********************Display_Miss****************************
// Displays miss graphic/text
void Display_Miss(void);

// ********************Display_Hit*****************************
// Displays hit graphic/text
void Display_Hit(void);

// ********************Display_Winner**************************
// Displays winner/loser graphic/text
// Input: winner (ENEMY if loser, FRIEND if winner)
// Output: None
void Display_Winner(int winner);


void Display_Menu(int ships);
