#ifndef PLAYER_H
#define PLAYER_H
#include "sprites.h"

typedef struct {
    int x, y;
    char dir;      // 'N', 'S', 'L', 'O'
    int team;
    int has_ball;
} Player;

#define PLAYER_COUNT 11

extern Player team1[PLAYER_COUNT];
extern Player team2[PLAYER_COUNT];

void init_players();
void move_player_controlled(int team, int index, char dir);
void try_push_ball(Player *p, Ball *ball);

#endif
