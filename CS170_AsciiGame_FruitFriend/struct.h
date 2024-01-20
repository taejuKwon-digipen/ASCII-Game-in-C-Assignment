// Name: Taeju Kwon, Geonhwi Sim
// Assignment Name: C ASCII game
// Course Name: CS170
// Term: 2021 Spring
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "dp_console.h"

#define MAP_X_SIZE 15
#define MAP_Y_SIZE 15
#define MAX_VIEW_RANGE 10
#define FALSE 0
#define TRUE 1
#define RESETKEY 114
#define BOMBC 5

typedef enum
{
	WALL,
	PLAYER,
	BOMB,
	HOUSE,
	SPACE
} TILES;

typedef struct
{
	int type;
	unsigned int Playerx, Playery;
	unsigned int MovesCount;
	unsigned int BombC;
	unsigned int CurrentLevel;
	TILES World[MAP_X_SIZE][MAP_Y_SIZE];
}PushPush;

typedef struct
{
	bool move;
	unsigned int x, y;
}Bomb;

typedef struct
{
	bool exist;
	unsigned int x, y;
}House;

typedef struct
{
	int type;
	unsigned int x, y;
}Wall;

PushPush pushpush;
TILES tiles;
House house;
Bomb bomb1, bomb2, bomb3, bomb4, bomb5;
