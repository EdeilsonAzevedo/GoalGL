#include <GL/glut.h>
#include "sprites.h"
#include "draw.h" 
unsigned int player1_texture;
unsigned int player2_texture;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1); // cor das linhas do campo
    glPointSize(2.0);  
    draw_field();

    // Time 1 (esquerda)
    draw_sprite(player1_texture, 100, 280, 32, 32); // goleiro

    // Defesa
    draw_sprite(player1_texture, 200, 150, 32, 32);
    draw_sprite(player1_texture, 200, 230, 32, 32);
    draw_sprite(player1_texture, 200, 330, 32, 32);
    draw_sprite(player1_texture, 200, 410, 32, 32);

    // Meio-campo
    draw_sprite(player1_texture, 300, 160, 32, 32);
    draw_sprite(player1_texture, 300, 220, 32, 32);
    draw_sprite(player1_texture, 300, 340, 32, 32);
    draw_sprite(player1_texture, 300, 400, 32, 32);

    // Ataque
    draw_sprite(player1_texture, 400, 250, 32, 32);
    draw_sprite(player1_texture, 400, 370, 32, 32);

    // Time 2 (direita)
    draw_sprite(player2_texture, 800, 280, 32, 32); // goleiro

    // Defesa
    draw_sprite(player2_texture, 700, 150, 32, 32);
    draw_sprite(player2_texture, 700, 230, 32, 32);
    draw_sprite(player2_texture, 700, 330, 32, 32);
    draw_sprite(player2_texture, 700, 410, 32, 32);

    // Meio-campo
    draw_sprite(player2_texture, 600, 160, 32, 32);
    draw_sprite(player2_texture, 600, 220, 32, 32);
    draw_sprite(player2_texture, 600, 340, 32, 32);
    draw_sprite(player2_texture, 600, 400, 32, 32);

    // Ataque
    draw_sprite(player2_texture, 500, 250, 32, 32);
    draw_sprite(player2_texture, 500, 370, 32, 32);

    glutSwapBuffers();
}

void init() {
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.0, 0.5, 0.0, 1.0); // fundo verde
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 900, 600, 0); // origem no topo-esquerdo

    player1_texture = load_texture("assets/red.png");
    player2_texture = load_texture("assets/chuck.png");
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(900, 600);
    glutCreateWindow("GoalGL - Campo com 22 jogadores");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
