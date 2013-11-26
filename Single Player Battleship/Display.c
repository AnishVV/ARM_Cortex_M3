// Display.c
// Contains the functions to display everything on the screen
// Phillip Lemons
// 4/21/13

#include "Display.h"
#include "Art/Art.h"
#include "rit128x96x4.h"
#include "Output.h"
#include "logo.h"
#include "Utils.h"
#include <stdio.h>
#include "GameSound.h"

int convertToPxY(int y);
int convertToPxX(int x);
unsigned const char* chooseTile(int tile);
char New = 0;
extern char Turn = 0;

// Initiates everything needed to display things on the screen
void Display_Init()
{
	Output_Init();
	Output_Color(15);
	RIT128x96x4Init(1000000);
}

// Clears the display
void Display_Clear()
{
	RIT128x96x4Clear();
}

// Displays the main cover art
void Display_Cover()
{
	RIT128x96x4_BMP(0, 95, battleshipCover);
}

void Display_Menu(int ships)
{
	if(ships==1)
	{
		RIT128x96x4_BMP(43,43, menuBorder);
	} else if(ships==2) {
		RIT128x96x4_BMP(43,55, menuBorder);
	} else {
		RIT128x96x4_BMP(43,67, menuBorder);
	}
	RIT128x96x4_BMP(44,42, menuOption1);
	RIT128x96x4_BMP(44,54, menuOption2);
	RIT128x96x4_BMP(44,66, menuOption3);
}

// Displays screen with winning or losing graphics/text
void Display_Winner(int winner)
{
	if(winner == FRIEND)
	{
		printf("You have won!");
		RIT128x96x4_BMP(0, 95, YouWin);
	} else {
		printf("You have lost.");
		RIT128x96x4_BMP(0, 95, YouLost);
	}
}

// Displays hit messge
void Display_Hit()
{
	printf("              Hit!\n");
	SFX = 1;
	SysTick_Init(100);
	//RIT128x96x4_BMP(0, 95, DisplayHit);
	//Delay1(45000000/2);
	//Display_Clear();
}

// Displays miss message
void Display_Miss()
{
	printf("              Miss!\n");
	SFX = 2;
	SysTick_Init(100);
	//RIT128x96x4_BMP(0, 95, DisplayMiss);
	//Delay1(45000000/2);
	//Display_Clear();
}

// Displays the desired grid
// Displays empty grid, cursor, then tiles
void Display_Grid(int player)
{
	int i,j;
	int x,y;
	Grid grid;
	for(j=0;j<GRIDYSIZE;j++)			// displays empty grid
	{
		for(i=0;i<GRIDXSIZE;i++)
		{
			x=convertToPxX(i);				// converts x coordinate to its corresponding pixel
			y=convertToPxY(j);				// converts y coordinate to its corresponding pixel
			RIT128x96x4_BMP(x,y,GridTileNoCursor);		// displays an empty grid tile
		}
	}
	
	if(player == ENEMY)	{						// Checks which grid to display
		grid = Grid_GetGrid(ENEMY);		// chooses enemy grid
		if(New != 0)
				printf("Player Turn:\n");
		else
				printf("Player Turn:       \n");
		New ^= 1;
	}
	else{
		grid = Grid_GetGrid(FRIEND);	// chooses friendly grid
		if(New != 0)
				printf("Enemy Turn:\n");
		else
				printf("Enemy Turn:        \n");
		New ^= 1;
	}
	
 	if(player!=FRIEND)						// displays cursor on enemy grid
	{
		x = convertToPxX(grid.cursorX);		// converts x coord to corresponding pixel
		y = convertToPxY(grid.cursorY);		// converts y coord to corresponding pixel
 		RIT128x96x4_BMP(x,y,GridTileCursor);	// displays cursor tile
	}
 	
	for(j=0;j<GRIDYSIZE;j++)			// Displays all non-empty tiles in the chosen grid
	{
		for(i=0;i<GRIDXSIZE;i++)
		{
			if(grid.grid[i][j] != 0)	// if the grid location is not empty it displays the tile
			{
				x=convertToPxX(i)+BORDER_WIDTH;		// convert x coord to corresponding pixel
				y=convertToPxY(j)-BORDER_WIDTH;		// convert y coord to corresponding pixel
				RIT128x96x4_BMP(x,y,chooseTile(grid.grid[i][j]));		// chooses and displays tile
			}
		}
	}
}

// Moves the cursor and displays it in the new direction
// Does not require the OLED to display the whole grid again
// If the desired move is invalid the grid remains unchanged
void Display_MoveCursor(int direction)
{
	int is_valid=0;
	char prev_tile, new_tile;
	char prev_x,prev_y,new_x,new_y;
	int x,y;
	Grid grid;
	grid = Grid_GetGrid(ENEMY);
	prev_x = grid.cursorX;
	prev_y = grid.cursorY;
	prev_tile =  grid.grid[prev_x][prev_y];
	
	switch(direction)
	{
		case LEFT: if(prev_x-1>=0) is_valid=1;break;
		case RIGHT: if(prev_x+1<GRIDXSIZE) is_valid=1;break;
		case UP: if(prev_y-1>=0) is_valid=1;break;
		case DOWN: if(prev_y+1<GRIDYSIZE) is_valid=1;break;
	}
	
	if(is_valid)
	{
		Grid_MoveCursor(direction);
		grid = Grid_GetGrid(ENEMY);
		new_x = grid.cursorX;
		new_y = grid.cursorY;
		new_tile = grid.grid[new_x][new_y];
	
		x = convertToPxX(prev_x);
		y = convertToPxY(prev_y);
		RIT128x96x4_BMP(x,y,GridTileNoCursor);
		RIT128x96x4_BMP(x+2,y-2,chooseTile(prev_tile));
	
		x = convertToPxX(new_x);
		y = convertToPxY(new_y);
		RIT128x96x4_BMP(x,y,GridTileCursor);
		RIT128x96x4_BMP(x+2,y-2,chooseTile(new_tile));
	}
}

// Chooses tile from Art.h
unsigned const char* chooseTile(int tile)
{
	unsigned const char* output;
	switch(tile)
	{
		case TILE_HIT: output=HitTile; break;
		case TILE_MISS: output=MissTile; break;
		case TILE_H_SMALL_SHIP_FRONT: output=HSmallShipFront; break;
		case TILE_H_SMALL_SHIP_BACK: output=HSmallShipBack; break;
		case TILE_V_SMALL_SHIP_FRONT: output=VSmallShipFront; break;
		case TILE_V_SMALL_SHIP_BACK: output=VSmallShipBack; break;
		case TILE_H_MED_SHIP_FRONT: output=HSmallShipFront; break;
		case TILE_H_MED_SHIP_MIDDLE: output=HMedShipMiddle; break;
		case TILE_H_MED_SHIP_BACK: output=HSmallShipBack; break;
		case TILE_V_MED_SHIP_FRONT: output=VSmallShipFront; break;
		case TILE_V_MED_SHIP_MIDDLE: output=VMedShipMiddle; break;
		case TILE_V_MED_SHIP_BACK: output=VSmallShipBack; break;
	}
	return output;
}

// converts grid x coordinate to corresponding pixel
int convertToPxX(int x)
{
	x=16*x;
	return x;
}

// converts grid y coordinate to corresponding pixel
int convertToPxY(int y)
{
	y = 31+(16*y);
	return y;
}
