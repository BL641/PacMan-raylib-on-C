
#ifndef __MAP__H
#define __MAP__H

#define MAP_LENGHT 28
#define MAP_HEIGHT 28

#include "PacMan.h"

extern int map[MAP_LENGHT][MAP_HEIGHT];
extern int itemsMap[MAP_LENGHT][MAP_HEIGHT];

int saveMap[MAP_LENGHT][MAP_HEIGHT];
int saveItemsMap[MAP_LENGHT][MAP_HEIGHT];

void MapDraw(PacMan* self);
int MapNull();
int MapRestore();
void MapCopy();

#endif