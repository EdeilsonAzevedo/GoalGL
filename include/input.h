#ifndef INPUT_H
#define INPUT_H

void handle_keypress(unsigned char key, int x, int y);
void handle_special_keypress(int key, int x, int y);
int get_selected_player(int team);

#endif
