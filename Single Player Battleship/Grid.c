// Grid.c
// Module for creating and manipulating grids
// Phillip Lemons
// 4/20/13

#include "Grid.h"
#include "Utils.h"
#include "lm3s1968.h"
#include "Display.h"
#include <stdio.h>
#include <stdlib.h>

#define UNOCCUPIED 0
#define OCCUPIED 1

Grid* createGrid(void);
void printGrid(Grid *grid);
void randomizeShips1(int ships);
void randomizeShips2(int ships);

Grid *enemyGrid;
Grid *enemyGridHidden;
Grid *friendlyGrid;
int has_attacked = 0;
int attack_point[2];
int error_count = 0;

// Initiates enemy and friendly grids
// Randomly places ships into the Friendly grid
void Grid_Init(int ships)
{
	enemyGrid = createGrid();
	enemyGridHidden = createGrid();
	enemyGridHidden->cursorX = -1;  // cursor is not used for enemy hidden grid
	enemyGridHidden->cursorY = -1;
	friendlyGrid = createGrid();
	friendlyGrid->cursorX = -1;		// cursor is not used of friendly grid
	friendlyGrid->cursorY = -1;
	randomizeShips1(ships);
	randomizeShips2(ships);
	
}

// Frees the memory allocated by the grids
void Grid_Free()
{
	free(enemyGrid);
	free(friendlyGrid);
	free(enemyGridHidden);
}

void Grid_SetHasAttacked(int n)
{
	has_attacked = n;
}

int Grid_HasAttacked()
{
	return has_attacked;
}

void Grid_AIAttack()
{
	int x,y;
	int is_valid = 0;
	while(!is_valid)
	{
		x = Random()%(GRIDXSIZE*10);
		y = Random()%(GRIDYSIZE*10);
		x = x/10;
		y = y/10;
		if(friendlyGrid->grid[x][y] != TILE_MISS && friendlyGrid->grid[x][y] != TILE_HIT)
			is_valid = 1;
	}
	if(Grid_IsOccupied(FRIEND,x,y))
	{
		Display_Hit();
		Grid_PlaceTile(FRIEND, TILE_HIT, x,y);
	} else {
		Display_Miss();
		Grid_PlaceTile(FRIEND, TILE_MISS, x,y);
	}
}

// Sets the attack coordinate when the user presses the select button
void Grid_Attack()
{
	int x,y;
	has_attacked = 1;
	x = enemyGrid->cursorX;
	y = enemyGrid->cursorY;
	if(Grid_IsOccupied(ENEMY_HIDDEN,x,y))
	{
		Display_Hit();
		Grid_PlaceTile(ENEMY, TILE_HIT, x,y);
		Grid_PlaceTile(ENEMY_HIDDEN, TILE_HIT, x,y);
	} else {
		Display_Miss();
		Grid_PlaceTile(ENEMY, TILE_MISS, x,y);
		Grid_PlaceTile(ENEMY_HIDDEN, TILE_MISS, x,y);
	}
}

// Checks to see if all of the players ships have been hit
// Output: 0 if ships still alive, 1 if end of game
int Grid_CheckEndGame(int player)
{
	Grid *grid;
	int i,j;
	if(player == ENEMY) grid = enemyGridHidden;
	else grid = friendlyGrid;
	for(j=0;j<GRIDYSIZE;j++)
	{
		for(i=0;i<GRIDXSIZE;i++)
		{
			if(grid->grid[i][j]>=3)
				return 0;
		}
	}
	return 1;
}

// Returns a copy of either the players grid or the enemies grid
Grid Grid_GetGrid(int player)
{
	Grid my_grid;
	if(player==ENEMY)
		my_grid = *enemyGrid;
	else
		my_grid = *friendlyGrid;
	return my_grid;
}

// Places tyle of given type in either the enemy or friendly grid at coord (x,y)
// Input: int player (FRIEND or ENEMY)
//				int tile (from tile types in header file)
//				(x,y) coords
void Grid_PlaceTile(int player, enum Tile tile, int x, int y)
{
	if(player==ENEMY)
	{
		enemyGrid->grid[x][y] = tile;
	} else if(player==FRIEND) {
		friendlyGrid->grid[x][y] = tile;
	} else if(player==ENEMY_HIDDEN) {
		enemyGridHidden->grid[x][y] = tile;
	} else {
		error_count+=1;
	}
}

// checks if a point on friendly grid is occupied
// Output: 1 if occupied, 0 if unoccupied
int Grid_IsOccupied(int player, int x, int y)
{
	Grid *grid;
	if(player == FRIEND)
	{
		grid = friendlyGrid;
	} else if(player == ENEMY_HIDDEN) {
		grid = enemyGridHidden;
	}
	
	if(grid->grid[x][y]>=3)
	{
		return OCCUPIED;
	} else {
		return UNOCCUPIED;
	}
}

// Changes cursor location to adjacent square in given direction
// Does not yet check for move validity
void Grid_MoveCursor(int direction)
{
	switch(direction)
	{
		case LEFT: enemyGrid->cursorX -= 1; break;
		case RIGHT: enemyGrid->cursorX += 1; break;
		case UP: enemyGrid->cursorY -= 1; break;
		case DOWN: enemyGrid->cursorY += 1; break;
		default: break;
	}
}

// Frees memory of grid
// Input: ptr to grid
void freeGrid(Grid *grid)
{
	free(grid);
}

// Allocate memory for grid and initialize values
Grid* createGrid()
{
	int i,j;
	Grid *grid;
	grid = (Grid *)malloc(sizeof(Grid));
	grid->cursorX = 0;
	grid->cursorY = 0;
	for(i=0;i<GRIDXSIZE;i++)
	{
		for(j=0;j<GRIDYSIZE;j++)
		{
			grid->grid[i][j] = TILE_EMPTY;
		}
	}
	return grid;
}

// randomly places ships
// possibly a good place to optimize for minimal code
void randomizeShips1(int ships)
{
	int is_h;
	int is_valid;
	int xpos, ypos;
	is_h = Random()%2;
	if(is_h)
	{
		xpos = Random()%(GRIDXSIZE-1);
		ypos = Random()%GRIDYSIZE;
		Grid_PlaceTile(FRIEND, TILE_H_SMALL_SHIP_FRONT, xpos,ypos);
		Grid_PlaceTile(FRIEND, TILE_H_SMALL_SHIP_BACK, xpos+1,ypos);
	} else {
		xpos = Random()%GRIDXSIZE;
		ypos = Random()%(GRIDYSIZE-1);
		Grid_PlaceTile(FRIEND, TILE_V_SMALL_SHIP_FRONT, xpos,ypos);
		Grid_PlaceTile(FRIEND, TILE_V_SMALL_SHIP_BACK, xpos,ypos+1);
	}
	
	if(ships>1)
	{
		is_valid=0;
		is_h = NVIC_ST_CURRENT_R%2;
		if(is_h)
		{
			while(!is_valid)
			{
				xpos = Random()%(GRIDXSIZE-2);
				ypos = Random()%GRIDYSIZE;
				if(!Grid_IsOccupied(FRIEND,xpos,ypos) && !Grid_IsOccupied(FRIEND,xpos+1,ypos) && !Grid_IsOccupied(FRIEND,xpos+2,ypos))
					is_valid = 1;
				if(is_valid)
				{
					Grid_PlaceTile(FRIEND, TILE_H_MED_SHIP_FRONT, xpos,ypos);
					Grid_PlaceTile(FRIEND, TILE_H_MED_SHIP_MIDDLE, xpos+1,ypos);
					Grid_PlaceTile(FRIEND, TILE_H_MED_SHIP_BACK, xpos+2,ypos);
				}
			}
		} else {
			while(!is_valid)
			{
				xpos = Random()%GRIDXSIZE;
				ypos = Random()%(GRIDYSIZE-2);
				if(!Grid_IsOccupied(FRIEND,xpos,ypos) && !Grid_IsOccupied(FRIEND,xpos,ypos+1) && !Grid_IsOccupied(FRIEND,xpos,ypos+2))
					is_valid = 1;
				if(is_valid)
				{
					Grid_PlaceTile(FRIEND, TILE_V_MED_SHIP_FRONT, xpos,ypos);
					Grid_PlaceTile(FRIEND, TILE_V_MED_SHIP_MIDDLE, xpos,ypos+1);
					Grid_PlaceTile(FRIEND, TILE_V_MED_SHIP_BACK, xpos,ypos+2);
				}
			}
		}
	}
	
	if(ships>2)
	{
		is_valid=0;
		is_h = NVIC_ST_CURRENT_R%2;
		if(is_h)
		{
			while(!is_valid)
			{
				xpos = Random()%(GRIDXSIZE-2);
				ypos = Random()%GRIDYSIZE;
				if(!Grid_IsOccupied(FRIEND,xpos,ypos) && !Grid_IsOccupied(FRIEND,xpos+1,ypos) && !Grid_IsOccupied(FRIEND,xpos+2,ypos))
					is_valid = 1;
				if(is_valid)
				{
					Grid_PlaceTile(FRIEND, TILE_H_MED_SHIP_FRONT, xpos,ypos);
					Grid_PlaceTile(FRIEND, TILE_H_MED_SHIP_MIDDLE, xpos+1,ypos);
					Grid_PlaceTile(FRIEND, TILE_H_MED_SHIP_BACK, xpos+2,ypos);
				}
			}
		} else {
			while(!is_valid)
			{
				xpos = Random()%GRIDXSIZE;
				ypos = Random()%(GRIDYSIZE-2);
				if(!Grid_IsOccupied(FRIEND,xpos,ypos) && !Grid_IsOccupied(FRIEND,xpos,ypos+1) && !Grid_IsOccupied(FRIEND,xpos,ypos+2))
					is_valid = 1;
				if(is_valid)
				{
					Grid_PlaceTile(FRIEND, TILE_V_MED_SHIP_FRONT, xpos,ypos);
					Grid_PlaceTile(FRIEND, TILE_V_MED_SHIP_MIDDLE, xpos,ypos+1);
					Grid_PlaceTile(FRIEND, TILE_V_MED_SHIP_BACK, xpos,ypos+2);
				}
			}
		}
	}
}

void randomizeShips2(int ships)
{
	int is_h;
	int is_valid;
	int xpos, ypos;
	is_h = Random()%2;
	if(is_h)
	{
		xpos = Random()%(GRIDXSIZE-1);
		ypos = Random()%GRIDYSIZE;
		Grid_PlaceTile(ENEMY_HIDDEN, TILE_H_SMALL_SHIP_FRONT, xpos,ypos);
		Grid_PlaceTile(ENEMY_HIDDEN, TILE_H_SMALL_SHIP_BACK, xpos+1,ypos);
	} else {
		xpos = Random()%GRIDXSIZE;
		ypos = Random()%(GRIDYSIZE-1);
		Grid_PlaceTile(ENEMY_HIDDEN, TILE_V_SMALL_SHIP_FRONT, xpos,ypos);
		Grid_PlaceTile(ENEMY_HIDDEN, TILE_V_SMALL_SHIP_BACK, xpos,ypos+1);
	}
	
	if(ships>1)
	{
		is_valid=0;
		is_h = NVIC_ST_CURRENT_R%2;
		if(is_h)
		{
			while(!is_valid)
			{
				xpos = Random()%(GRIDXSIZE-2);
				ypos = Random()%GRIDYSIZE;
				if(!Grid_IsOccupied(ENEMY_HIDDEN,xpos,ypos) && !Grid_IsOccupied(ENEMY_HIDDEN,xpos+1,ypos) && !Grid_IsOccupied(ENEMY_HIDDEN,xpos+2,ypos))
					is_valid = 1;
				if(is_valid)
				{
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_H_MED_SHIP_FRONT, xpos,ypos);
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_H_MED_SHIP_MIDDLE, xpos+1,ypos);
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_H_MED_SHIP_BACK, xpos+2,ypos);
				}
			}
		} else {
			while(!is_valid)
			{
				xpos = Random()%GRIDXSIZE;
				ypos = Random()%(GRIDYSIZE-2);
				if(!Grid_IsOccupied(ENEMY_HIDDEN,xpos,ypos) && !Grid_IsOccupied(ENEMY_HIDDEN,xpos,ypos+1) && !Grid_IsOccupied(ENEMY_HIDDEN,xpos,ypos+2))
					is_valid = 1;
				if(is_valid)
				{
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_V_MED_SHIP_FRONT, xpos,ypos);
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_V_MED_SHIP_MIDDLE, xpos,ypos+1);
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_V_MED_SHIP_BACK, xpos,ypos+2);
				}
			}
		}
	}
	
	if(ships>2)
	{
		is_valid=0;
		is_h = NVIC_ST_CURRENT_R%2;
		if(is_h)
		{
			while(!is_valid)
			{
				xpos = Random()%(GRIDXSIZE-2);
				ypos = Random()%GRIDYSIZE;
				if(!Grid_IsOccupied(ENEMY_HIDDEN,xpos,ypos) && !Grid_IsOccupied(ENEMY_HIDDEN,xpos+1,ypos) && !Grid_IsOccupied(ENEMY_HIDDEN,xpos+2,ypos))
					is_valid = 1;
				if(is_valid)
				{
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_H_MED_SHIP_FRONT, xpos,ypos);
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_H_MED_SHIP_MIDDLE, xpos+1,ypos);
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_H_MED_SHIP_BACK, xpos+2,ypos);
				}
			}
		} else {
			while(!is_valid)
			{
				xpos = Random()%GRIDXSIZE;
				ypos = Random()%(GRIDYSIZE-2);
				if(!Grid_IsOccupied(ENEMY_HIDDEN,xpos,ypos) && !Grid_IsOccupied(ENEMY_HIDDEN,xpos,ypos+1) && !Grid_IsOccupied(ENEMY_HIDDEN,xpos,ypos+2))
					is_valid = 1;
				if(is_valid)
				{
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_V_MED_SHIP_FRONT, xpos,ypos);
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_V_MED_SHIP_MIDDLE, xpos,ypos+1);
					Grid_PlaceTile(ENEMY_HIDDEN, TILE_V_MED_SHIP_BACK, xpos,ypos+2);
				}
			}
		}
	}
}
