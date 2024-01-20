// Name: Taeju Kwon, Geonhwi Sim
// Assignment Name: C ASCII game
// Course Name: CS170
// Term: 2021 Spring
#include "struct.h"
#include "drawHelper.h"
#include "bitwise.h"

void printing(unsigned int x, unsigned int y, char* s, int type)
{
	dpc_move_cursor((int)multiply(2, x), (int)y);
	printf("%s", s);
	pushpush.World[x][y] = type;
}

void MapFor(unsigned int start, unsigned int end, unsigned int yLoca)
{
	unsigned int i;
	for (i = start; i < end; i++)
	{
		printing(i, yLoca, "#", WALL);
	}
}

void drawEdge()
{
	unsigned int i, j, k;
	for (i = 0; i < MAP_X_SIZE; i++)
	{
		printing(i, 1, "¡á", WALL);
	}
	for (j = 1; j < MAP_Y_SIZE - 1; j++)
	{
		printing(0, j, "¡á", WALL);
		printing(subtract(MAP_X_SIZE, 1), j, "¡á", WALL);
	}
	for (k = 0; k < MAP_X_SIZE; k++)
	{
		printing(k, subtract(MAP_Y_SIZE, 1), "¡á", WALL);
	}
}

void drawMap()
{
	switch (pushpush.CurrentLevel)
	{
	case 1:
		dpc_set_font_color(dpc_WHITE);
		MapFor(6, 12, 4);
		MapFor(4, 7, 5);
		printing(11, 5, "#", WALL);
		MapFor(3, 5, 6);
		MapFor(9, 10, 6);
		MapFor(11, 13, 6);
		printing(3, 7, "#", WALL);
		printing(12, 7, "#", WALL);
		printing(3, 8, "#", WALL);
		MapFor(11, 13, 8);
		MapFor(3, 9, 9);
		printing(11, 9, "#", WALL);
		MapFor(8, 12, 10);
		break;
	}
}

void drawBomb()
{
	dpc_set_font_color(dpc_RED);
	printing(bomb1.x, bomb1.y, "O", BOMB);
	printing(bomb2.x, bomb2.y, "O", BOMB);
	printing(bomb3.x, bomb3.y, "O", BOMB);
	printing(bomb4.x, bomb4.y, "O", BOMB);
	printing(bomb5.x, bomb5.y, "O", BOMB);
}
