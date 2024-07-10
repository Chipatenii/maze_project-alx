CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_image -lm
SRC = src/init.c src/input.c src/main.c src/parser.c src/player.c src/render.c
OBJ = $(SRC:.c=.o)
TARGET = bin/maze

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
