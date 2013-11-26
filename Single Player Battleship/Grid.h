

#ifndef GRID_H
#define GRID_H
#define ENEMY 0
#define FRIEND 1
#define ENEMY_HIDDEN 2

enum Tile {
	TILE_EMPTY,
	TILE_HIT,
	TILE_MISS,

	TILE_H_SMALL_SHIP_FRONT,
	TILE_H_SMALL_SHIP_BACK,
	TILE_V_SMALL_SHIP_FRONT,
	TILE_V_SMALL_SHIP_BACK,
	
	TILE_H_MED_SHIP_FRONT,
	TILE_H_MED_SHIP_MIDDLE,
	TILE_H_MED_SHIP_BACK,
	TILE_V_MED_SHIP_FRONT,
	TILE_V_MED_SHIP_MIDDLE,
	TILE_V_MED_SHIP_BACK,

	TILE_H_LARGE_SHIP_FRONT,
	TILE_H_LARGE_SHIP_MIDDLE1,
	TILE_H_LARGE_SHIP_MIDDLE2,
	TILE_H_LARGE_SHIP_BACK,
	TILE_V_LARGE_SHIP_FRONT,
	TILE_V_LARGE_SHIP_MIDDLE1,
	TILE_V_LARGE_SHIP_MIDDLE2,
	TILE_V_LARGE_SHIP_BACK
};

#define GRIDXSIZE 8
#define GRIDYSIZE 5

#define LEFT 0				// Use enum direction
#define RIGHT 1
#define UP 2
#define DOWN 3

struct Grid {
	char cursorX;
	char cursorY;
	//char grid[8][5];   // Instead of an array of chars use an enumerated data type
	enum Tile grid[8][5];
};
typedef struct Grid Grid;

// ********************Grid_Init*************************************
// Initiates enemy and friendly grids
// Randomly places ships into the Friendly grid
void Grid_Init(int ships);

// ********************Grid_PlaceTile********************************
// Places tyle of given type in either the enemy or friendly grid at coord (x,y)
// Input: int player (FRIEND or ENEMY)
//				int tile (from tile types in header file)
//				(x,y) coords
// Output: None
void Grid_PlaceTile(int player, enum Tile tile, int x, int y);

// ********************Grid_MoveCursor*******************************
// Changes cursor location to adjacent square in given direction
// Input: direction
// Output: None
// Invariables: Should only be used by Display_MoveCursor
void Grid_MoveCursor(int direction);

// ********************Grid_IsOccupied*******************************
// Checks if a location (x,y) is occupied on the friendlyGrid or hidden enemy grid
// Input: (x,y) coords
//				FRIEND or ENEMY_HIDDEN
// Output: 1 if occupied, 0 if unoccupied
int Grid_IsOccupied(int player, int x, int y);

// ********************Grid_CheckEndGame*****************************
// Checks if all of the ships in the friendly grid have been destroyed
int Grid_CheckEndGame(int player);

// ********************Grid_Free*************************************
void Grid_Free(void);

// ********************Grid_GetGrid**********************************
Grid Grid_GetGrid(int player);

// ********************Grid_Attack***********************************
void Grid_Attack(void);

int Grid_HasAttacked(void);
void Grid_SetHasAttacked(int n);
void Grid_AIAttack(void);

#endif
