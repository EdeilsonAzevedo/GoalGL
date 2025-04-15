cc = gcc
CFLAGS = -Wall -Iinclude -lGL -lGLU -lglut -lm
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
EXEC = goalgl

all: $(EXEC)

$(EXEC): $(SRC)
	$(cc) $(CFLAGS) -o build/$(EXEC) $(SRC)

test_draw:
	$(CC) $(CFLAGS) -o build/test_draw test/test_draw.c src/draw.c

test_sprites:
	$(CC) $(CFLAGS) -o build/test_sprites test/test_sprites.c src/sprites.c src/draw.c

run:
	$(CC) $(CFLAGS) -o build/game_main \
	src/main.c \
	src/draw.c src/sprites.c src/players.c src/input.c src/audio.c 
clean:
	rm -f build/$(EXEC) src/*.o