#include "players.h"
#include "draw.h"
#include "sprites.h"

Player team1[PLAYER_COUNT];
Player team2[PLAYER_COUNT];

void init_players() {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        team1[i].x = player1_positions[i][0];
        team1[i].y = player1_positions[i][1];
        team1[i].dir = 'L'; // olhando pra direita
        team1[i].team = 1;
        team1[i].has_ball = 0;

        team2[i].x = player2_positions[i][0];
        team2[i].y = player2_positions[i][1];
        team2[i].dir = 'O'; // olhando pra esquerda
        team2[i].team = 2;
        team2[i].has_ball = 0;
    }
}

void move_player_controlled(int team, int index, char dir) {
    Player *p = (team == 1) ? &team1[index] : &team2[index];

    int dx = 0, dy = 0;
    switch (dir) {
        case 'N': dy = -5; break;
        case 'S': dy =  5; break;
        case 'O': dx = -5; break;
        case 'L': dx =  5; break;
    }

    int new_x = p->x + dx;
    int new_y = p->y + dy;

    if (new_x >= 50 && new_x <= 850 - 32 &&
        new_y >= 50 && new_y <= 550 - 32) {
        p->x = new_x;
        p->y = new_y;
        p->dir = dir;
    }
}

void try_push_ball(Player *p, Ball *ball) {
    float dx = (p->x + 16) - (ball->x + 8);
    float dy = (p->y + 16) - (ball->y + 8);
    float dist2 = dx*dx + dy*dy;

    if (dist2 < 900) { // distância < 30px
        switch (p->dir) {
            case 'N': ball->vy = -3; break;
            case 'S': ball->vy =  3; break;
            case 'L': ball->vx =  3; break;
            case 'O': ball->vx = -3; break;
        }
    }
}
