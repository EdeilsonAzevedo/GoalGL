#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include "draw.h"

const int player1_positions[PLAYER_COUNT][2] = {
    {100, 280}, {200, 150}, {200, 230}, {200, 330}, {200, 410},
    {300, 160}, {300, 220}, {300, 340}, {300, 400},
    {400, 250}, {400, 370}
};

const int player2_positions[PLAYER_COUNT][2] = {
    {800, 280}, {700, 150}, {700, 230}, {700, 330}, {700, 410},
    {600, 160}, {600, 220}, {600, 340}, {600, 400},
    {500, 250}, {500, 370}
};

void draw_line(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    glBegin(GL_POINTS);
    while (1) {
        glVertex2i(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
    glEnd();
}

void draw_circle(int xc, int yc, int radius) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    glBegin(GL_POINTS);
    while (y >= x) {
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);
        x++;
        if (d > 0) {
            y--;
            d += 4 * (x - y) + 10;
        } else {
            d += 4 * x + 6;
        }
    }
    glEnd();
}

void draw_field() {
    glPointSize(2.0);
    int left = 50, right = 850, top = 50, bottom = 550;
    int mid_x = (left + right) / 2;
    int goal_top = 250;
    int goal_bottom = 350;

    // Campo externo
    draw_line(left, top, right, top);
    draw_line(right, top, right, bottom);
    draw_line(right, bottom, left, bottom);
    draw_line(left, bottom, left, top);

    // Linha central
    draw_line(mid_x, top, mid_x, bottom);

    // Círculo central
    draw_circle(mid_x, (top + bottom) / 2, 50);

    // Marca do pênalti
    draw_circle(left + 120, 300, 3);
    draw_circle(right - 120, 300, 3);

    // Grandes áreas
    draw_line(left, 200, left + 120, 200);
    draw_line(left + 120, 200, left + 120, 400);
    draw_line(left + 120, 400, left, 400);

    // Pequenas áreas
    draw_line(right, 200, right - 120, 200);
    draw_line(right - 120, 200, right - 120, 400);
    draw_line(right - 120, 400, right, 400);

    // Gol da esquerda
    draw_line(left - 10, goal_top, left, goal_top);
    draw_line(left - 10, goal_bottom, left, goal_bottom);
    draw_line(left - 10, goal_top, left - 10, goal_bottom);

    // Gol da direita
    draw_line(right, goal_top, right + 10, goal_top);
    draw_line(right, goal_bottom, right + 10, goal_bottom);
    draw_line(right + 10, goal_top, right + 10, goal_bottom);
}

void draw_highlight_circle(float x, float y, float radius) {
    glDisable(GL_TEXTURE_2D); // ← garante que não estamos usando textura aqui
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(0.3, 0.3, 0.3, 0.5); // cinza semitransparente

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // centro
    for (int angle = 0; angle <= 360; angle += 10) {
        float rad = angle * 3.14159f / 180.0f;
        glVertex2f(x + radius * cos(rad), y + radius * sin(rad));
    }
    glEnd();

    glColor3f(1.0, 1.0, 1.0); // restaura branco
}

void draw_score(int score1, int score2) {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "Placar: %d : %d", score1, score2);

    // Coordenadas fixas do retângulo de fundo
    int x = 380, y = 5;
    int width = 100, height = 30;

    // Retângulo preto semi-transparente
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.0, 0.0, 0.0, 0.4); // preto com 60% de opacidade

    glBegin(GL_QUADS);
        glVertex2i(x, y);
        glVertex2i(x + width, y);
        glVertex2i(x + width, y + height);
        glVertex2i(x, y + height);
    glEnd();

    // Texto em branco por cima
    glColor3f(1.0, 1.0, 1.0);

    // Posição do texto (centralizado verticalmente no retângulo)
    glRasterPos2i(x + 15, y + 15);

    // Fonte maior: HELVETICA_18 ou TIMES_ROMAN_24
    void *font = GLUT_BITMAP_TIMES_ROMAN_24;

    for (char *c = buffer; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
