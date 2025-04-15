#include <GL/glut.h>
#include <stdio.h>
#include "draw.h"
#include "sprites.h"
#include "players.h"
#include "input.h"
#include "audio.h"

unsigned int player1_texture;
unsigned int player2_texture;

Ball ball;
int score1 = 0, score2 = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPointSize(2.0);
    draw_field();

    int i1 = get_selected_player(1);
    int i2 = get_selected_player(2);

    // desenha antes dos jogadores
    draw_highlight_circle(team1[i1].x + 16, team1[i1].y + 21, 20);
    draw_highlight_circle(team2[i2].x + 16, team2[i2].y + 21, 20);

    // depois desenha os jogadores (sprites)
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        draw_sprite(player1_texture, team1[i].x, team1[i].y, 32, 32);
        draw_sprite(player2_texture, team2[i].x, team2[i].y, 32, 32);
    }

    draw_ball(&ball);
    update_ball(&ball);

    int p1 = get_selected_player(1);
    int p2 = get_selected_player(2);
    try_push_ball(&team1[p1], &ball);
    try_push_ball(&team2[p2], &ball);

    // Detecta gol
    if (is_goal(&ball)) {
        if (ball.x < 100) score2++;
        else score1++;

        init_players(); // reseta jogadores
        init_ball(&ball, "assets/ball.png"); // reseta bola
    }
    draw_score(score1, score2);

    glutSwapBuffers();
}


void init() {
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.0, 0.5, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 900, 600, 0);


    player1_texture = load_texture("assets/red.png");
    player2_texture = load_texture("assets/chuck.png");

    init_ball(&ball, "assets/ball.png");
    init_players();
}

int main(int argc, char** argv) {
    if (!init_audio("./assets/audio/soundtrack.mp3")) {
        fprintf(stderr, "Erro ao iniciar música\n");
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(900, 600);
    glutCreateWindow("GoalGL - Main Jogo");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(handle_keypress);
    glutSpecialFunc(handle_special_keypress);

    glutMainLoop();
    return 0;
}
