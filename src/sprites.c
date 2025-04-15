#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "sprites.h"
#include <GL/glut.h>
#include <stdio.h>

unsigned int load_texture(const char *filename) {
    int width, height, channels;
    unsigned char *image = stbi_load(filename, &width, &height, &channels, STBI_rgb_alpha);
    if (!image) {
        fprintf(stderr, "Erro ao carregar imagem: %s\n", filename);
        return 0;
    }

    unsigned int texture_id;
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(image);
    return texture_id;
}

void draw_sprite(unsigned int texture_id, float x, float y, float width, float height) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(x, y);
        glTexCoord2f(1, 0); glVertex2f(x + width, y);
        glTexCoord2f(1, 1); glVertex2f(x + width, y + height);
        glTexCoord2f(0, 1); glVertex2f(x, y + height);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void init_ball(Ball *ball, const char *image_path) {
    ball->x = (50 + 850) / 2.0f - 8;
    ball->y = (50 + 550) / 2.0f - 8;
    ball->vx = 0;
    ball->vy = 0;
    ball->texture_id = load_texture(image_path);
}


void draw_ball(const Ball *ball) {
    draw_sprite(ball->texture_id, ball->x, ball->y, 20, 20); // bola 16x16 px
}

void update_ball(Ball *ball) {
    ball->x += ball->vx;
    ball->y += ball->vy;

    ball->vx *= 0.9f;
    ball->vy *= 0.9f;

    if (fabs(ball->vx) < 0.1f) ball->vx = 0;
    if (fabs(ball->vy) < 0.1f) ball->vy = 0;
}

int is_goal(const Ball *ball) {
    return (
        (ball->x <= 50 && ball->y >= 250 && ball->y <= 350) ||    // Gol da esquerda
        (ball->x + 16 >= 850 && ball->y >= 250 && ball->y <= 350) // Gol da direita
    );
}
