#include <GL/glut.h>
#include "players.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    draw_player(450, 300); // posição central
    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0.5, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 900, 600, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Visualizador de Modelo");
    init();
    load_player_model("assets/Untitled.obj");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
