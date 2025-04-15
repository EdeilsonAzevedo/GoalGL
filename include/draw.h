#ifndef DRAW_H
#define DRAW_H

void draw_field();
void render_field_scene();
void draw_highlight_circle(float x, float y, float radius);
void draw_score(int score1, int score2);


#define PLAYER_COUNT 11

extern const int player1_positions[PLAYER_COUNT][2];
extern const int player2_positions[PLAYER_COUNT][2];

#endif