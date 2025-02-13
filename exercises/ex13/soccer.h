#ifndef SOCCER_H
#define SOCCER_H

#include <stdbool.h>

//TODO 1: DEFINE DATE, STAT AND PLAYER STRUCTS HERE

void create_player (Player *p, bool goalie);
void create_team(Player team[], int size);
void print_team (Player team[], int size);

#endif
