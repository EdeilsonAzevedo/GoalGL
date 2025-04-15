#ifndef SPRITES_H
#define SPRITES_H

typedef struct {
    float x, y;
    float vx, vy;
    unsigned int texture_id;
} Ball;

void init_ball(Ball *ball, const char *image_path);
void draw_ball(const Ball *ball);
void update_ball(Ball *ball);
int is_goal(const Ball *ball);
unsigned int load_texture(const char *filename);
void draw_sprite(unsigned int texture_id, float x, float y, float width, float height);

#endif
