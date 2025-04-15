#include <GL/glut.h>
#include "players.h"
#include "sprites.h"

static int selected_player1 = 0;
static int selected_player2 = 0;

int get_selected_player(int team) {
    return (team == 1) ? selected_player1 : selected_player2;
}


void handle_keypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': move_player_controlled(1, selected_player1, 'N'); break;
        case 's': move_player_controlled(1, selected_player1, 'S'); break;
        case 'a': move_player_controlled(1, selected_player1, 'O'); break;
        case 'd': move_player_controlled(1, selected_player1, 'L'); break;
        case 'q': selected_player1 = (selected_player1 + 1) % PLAYER_COUNT; break;
        case 'p': selected_player2 = (selected_player2 + 1) % PLAYER_COUNT; break;
    }
    glutPostRedisplay();
}

void handle_special_keypress(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:    move_player_controlled(2, selected_player2, 'N'); break;
        case GLUT_KEY_DOWN:  move_player_controlled(2, selected_player2, 'S'); break;
        case GLUT_KEY_LEFT:  move_player_controlled(2, selected_player2, 'O'); break;
        case GLUT_KEY_RIGHT: move_player_controlled(2, selected_player2, 'L'); break;
    }
    glutPostRedisplay();
}
