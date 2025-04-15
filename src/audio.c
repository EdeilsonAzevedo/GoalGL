#include <stdlib.h>
#include <stdio.h>

int init_audio(const char *music_path) {
    char command[512];
    snprintf(command, sizeof(command),
            "mpg123 -q --loop -1 \"%s\" &", music_path);
    return system(command) == 0;
}

void cleanup_audio() {
    system("pkill -f mpg123");
}

// void main(){
//     init_audio("./assets/audio/soundtrack.mp3");
// }