// Name: Taeju Kwon, Geonhwi Sim
// Assignment Name: C ASCII game
// Course Name: CS170
// Term: 2021 Spring
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "struct.h"
#include "drawHelper.h"
#include "dp_console.h"
#include "bitwise.h"
#include <time.h>

void charaMove();
void setting();
void deleteHouse(House* h1, House* h2, House* h3, House* h4, House* h5);
void HowToPlay();
void UseArrowKey();

void HowToPlay()
{
	printf("How To Play\n");
}

void UseArrowKey()
{
	printf("Use Arrow Keys to move\n ");
}

void UsespaceKey()
{
	printf("Press space key for restart");
}
int main(int argc, char* argv[])
{
	House* house1 = malloc(sizeof(House));
	House* house2 = malloc(sizeof(House));
	House* house3 = malloc(sizeof(House));
	House* house4 = malloc(sizeof(House));
	House* house5 = malloc(sizeof(House));
	FILE* fp;
	char buffer[100];
	
	unsigned int i;
	for (i = 0; i < (unsigned)argc + 1; i++)
	{
		printf("%s", argv[i]);
	}
	
	pushpush.MovesCount = 0;
	pushpush.BombC = BOMBC;
	setting();
	dpc_startup(true);
	drawEdge();
	drawBomb();


	if (house1 && house2 && house3 && house4 && house5 != NULL) {
		house1->x = 4, house1->y = 7;
		house2->x = 5, house2->y = 7;
		house3->x = 4, house3->y = 8;
		house4->x = 5, house4->y = 8;
		house5->x = 5, house5->y = 6;

		dpc_set_font_color(dpc_YELLOW);
		printing(house1->x, house1->y, "1", HOUSE);
		printing(house2->x, house2->y, "2", HOUSE);
		printing(house3->x, house3->y, "3", HOUSE);
		printing(house4->x, house4->y, "4", HOUSE);
		printing(house5->x, house5->y, "5", HOUSE);
	}

	fp = fopen("before_moveCount.txt", "w");
	if (fp == NULL)
	{
		printf("Fail to read");
		exit(1);
	}
	else
	{
		while (house.exist == false)
		{
			void(*htp)();
			dpc_move_cursor(30, 2);
			dpc_set_font_color(dpc_WHITE);
			htp = HowToPlay;
			htp();

			dpc_move_cursor(30, 3);
			dpc_set_font_color(dpc_WHITE);
			htp = UseArrowKey;
			htp();

			dpc_move_cursor(30, 4);
			dpc_set_font_color(dpc_WHITE);
			htp = UsespaceKey;
			htp();

			dpc_set_font_color(dpc_YELLOW);
			dpc_move_cursor(32, 10);
			printf("MOVE COUNT: %d ", pushpush.MovesCount);
			
			pushpush.CurrentLevel = 1;
			drawMap();
			drawEdge();
			dpc_set_font_color(dpc_LIGHTCYAN);
			printing(pushpush.Playerx, pushpush.Playery, "A", PLAYER);
			deleteHouse(house1, house2, house3, house4, house5);
			charaMove();
			if(pushpush.BombC == 0)
			{
				house.exist = true;
			}
		}
		sprintf(buffer, "%d", pushpush.MovesCount);
		fputs(buffer, fp);
	}
	fclose(fp);

	exit(0);
}


void setting()
{
	int i, j;
	for (i = 0; i < MAP_X_SIZE; i++)
	{
		for (j = 0; j < MAP_Y_SIZE; j++)
		{
			pushpush.World[i][j] = SPACE;
		}
	}

	pushpush.Playerx = 11, pushpush.Playery = 7;
	pushpush.World[pushpush.Playerx][pushpush.Playery] = PLAYER;

	bomb1.x = 7, bomb1.y = 6;
	bomb2.x = 6, bomb2.y = 7;
	bomb3.x = 8, bomb3.y = 7;
	bomb4.x = 7, bomb4.y = 8;
	bomb5.x = 9, bomb5.y = 8;

	house.exist = false;
}

void reset()
{
	House* house1 = malloc(sizeof(House));
	House* house2 = malloc(sizeof(House));
	House* house3 = malloc(sizeof(House));
	House* house4 = malloc(sizeof(House));
	House* house5 = malloc(sizeof(House));
	unsigned int i, j;
	for (i = 0; i <= MAP_X_SIZE; i++)
	{
		for (j = 0; j <= MAP_Y_SIZE; j++)
		{
			printing(i,j, " ", SPACE);
		}
	}


	drawMap();
	setting();
	drawBomb();
	
	if (house1 && house2 && house3 && house4 && house5 != NULL) {
		house1->x = 4, house1->y = 7;
		house2->x = 5, house2->y = 7;
		house3->x = 4, house3->y = 8;
		house4->x = 5, house4->y = 8;
		house5->x = 5, house5->y = 6;

		dpc_set_font_color(dpc_YELLOW);
		printing(house1->x, house1->y, "1", HOUSE);
		printing(house2->x, house2->y, "2", HOUSE);
		printing(house3->x, house3->y, "3", HOUSE);
		printing(house4->x, house4->y, "4", HOUSE);
		printing(house5->x, house5->y, "5", HOUSE);
	}
}

void charaMove()
{
	TILES currTile, frontTile;
	switch (dpc_get_key())
	{
	case 16:
		currTile = pushpush.World[subtract(pushpush.Playerx, 1)][pushpush.Playery];
		frontTile = pushpush.World[subtract(pushpush.Playerx, 2)][pushpush.Playery];
		if (currTile != WALL && currTile != HOUSE) {
			if (currTile == BOMB && frontTile != BOMB && frontTile != WALL) {
				dpc_set_font_color(dpc_RED);
				if (pushpush.World[subtract(pushpush.Playerx, 2)][pushpush.Playery] != HOUSE) {
					printing(subtract(pushpush.Playerx, 2), pushpush.Playery, "O", BOMB);
				}
				else
				{
					printing(subtract(pushpush.Playerx, 2), pushpush.Playery, " ", SPACE);
				}
				pushpush.Playerx = subtract(pushpush.Playerx, 1);
				printing(add(pushpush.Playerx, 1), pushpush.Playery, " ", SPACE);
			}
			else if (currTile != BOMB) {
				pushpush.Playerx = subtract(pushpush.Playerx, 1);
				printing(add(pushpush.Playerx, 1), pushpush.Playery, " ", SPACE);
			}
		}
		pushpush.MovesCount = add(pushpush.MovesCount, 1);
		break;
		
	case 17:
		currTile = pushpush.World[add(pushpush.Playerx, 1)][pushpush.Playery];
		frontTile = pushpush.World[add(pushpush.Playerx, 2)][pushpush.Playery];
		if (currTile != WALL && currTile != HOUSE) {
			if (currTile == BOMB && frontTile != BOMB && frontTile != WALL) {
				dpc_set_font_color(dpc_RED);
				if (frontTile != HOUSE) {
					printing(add(pushpush.Playerx, 2), pushpush.Playery, "O", BOMB);
				}
				else
				{
					printing(add(pushpush.Playerx, 2), pushpush.Playery, " ", SPACE);
				}
				pushpush.Playerx = add(pushpush.Playerx, 1);
				printing(subtract(pushpush.Playerx, 1), pushpush.Playery, " ", SPACE);
			}
			else if (currTile != BOMB) {
				pushpush.Playerx = add(pushpush.Playerx, 1);
				printing(subtract(pushpush.Playerx, 1), pushpush.Playery, " ", SPACE);
			}
		}
		pushpush.MovesCount = add(pushpush.MovesCount, 1);
		break;

	case 14:
		currTile = pushpush.World[pushpush.Playerx][subtract(pushpush.Playery, 1)];
		frontTile = pushpush.World[pushpush.Playerx][subtract(pushpush.Playery, 2)];
		if (currTile != WALL && currTile != HOUSE) {
			if (currTile == BOMB && frontTile != BOMB && frontTile != WALL) {
				dpc_set_font_color(dpc_RED);
				if (frontTile != HOUSE) {
					printing(pushpush.Playerx, subtract(pushpush.Playery, 2), "O", BOMB);
				}
				else
				{
					printing(pushpush.Playerx, subtract(pushpush.Playery, 2), " ", SPACE);
				}
				pushpush.Playery = subtract(pushpush.Playery, 1);
				printing(pushpush.Playerx, add(pushpush.Playery, 1), " ", SPACE);
			}
			else if (currTile != BOMB) {
				pushpush.Playery = subtract(pushpush.Playery, 1);
				printing(pushpush.Playerx, add(pushpush.Playery, 1), " ", SPACE);
			}
		}
		pushpush.MovesCount = add(pushpush.MovesCount, 1);
		break;

	case 15:
		currTile = pushpush.World[pushpush.Playerx][add(pushpush.Playery, 1)];
		frontTile = pushpush.World[pushpush.Playerx][add(pushpush.Playery, 2)];
		if (currTile != WALL && currTile != HOUSE) {
			if (currTile == BOMB && frontTile != BOMB && frontTile != WALL) {
				dpc_set_font_color(dpc_RED);
				if (pushpush.World[pushpush.Playerx][add(pushpush.Playery, 2)] != HOUSE) {
					printing(pushpush.Playerx, add(pushpush.Playery, 2), "O", BOMB);
				}
				else
				{
					printing(pushpush.Playerx, add(pushpush.Playery, 2), " ", SPACE);
				}
				pushpush.Playery = add(pushpush.Playery, 1);
				printing(pushpush.Playerx, subtract(pushpush.Playery, 1), " ", SPACE);
			}
			else if (currTile != BOMB) {
				pushpush.Playery = add(pushpush.Playery, 1);
				printing(pushpush.Playerx, subtract(pushpush.Playery, 1), " ", SPACE);
			}
		}
		pushpush.MovesCount = add(pushpush.MovesCount, 1);
		break;

	case 32:
		reset();
		pushpush.MovesCount = 0;
		break;
	}
}

void deleteHouse(House* h1, House* h2, House* h3, House* h4, House* h5)
{
	switch (pushpush.Playery) {
	case 6:
		if (pushpush.World[subtract(pushpush.Playerx, 1)][pushpush.Playery] == BOMB && subtract(pushpush.Playerx, 2) == 5 &&
			pushpush.World[subtract(pushpush.Playerx, 2)][pushpush.Playery] == HOUSE)
		{
			if (dpc_get_key() == 16) {
				free(h5);
				pushpush.BombC--;
			}
		}
		break;

	case 7:
		if (pushpush.World[subtract(pushpush.Playerx, 1)][pushpush.Playery] == BOMB)
		{
			if (subtract(pushpush.Playerx, 2) == 5 && pushpush.World[subtract(pushpush.Playerx, 2)][pushpush.Playery] == HOUSE) {
				if (dpc_get_key() == 16) {
					free(h2);
					pushpush.BombC--;
				}
			}
			if (subtract(pushpush.Playerx, 2) == 4 && pushpush.World[subtract(pushpush.Playerx, 2)][pushpush.Playery] == HOUSE)
			{
				if (dpc_get_key() == 16) {
					free(h1);
					pushpush.BombC--;
				}
			}
		}
		break;

	case 8:
		if (pushpush.World[subtract(pushpush.Playerx, 1)][pushpush.Playery] == BOMB)
		{
			if (subtract(pushpush.Playerx, 2) == 5 && pushpush.World[subtract(pushpush.Playerx, 2)][pushpush.Playery] == HOUSE) {
				if (dpc_get_key() == 16) {
					free(h4);
					pushpush.BombC--;
				}
			}
			if (subtract(pushpush.Playerx, 2) == 4 && pushpush.World[subtract(pushpush.Playerx, 2)][pushpush.Playery] == HOUSE)
			{
				if (dpc_get_key() == 16) {
					free(h3);
					pushpush.BombC--;
				}
			}
		}
		break;
	}
}
