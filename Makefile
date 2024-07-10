CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_image -lm
SRC = src/init.c src/player.c src/parser.c src/main.c src/input.c src/render.c
OBJ = $(SRC:.c=.o)
BIN = bin

all: $(BIN) $(BIN)/maze

$(BIN):
	mkdir -p $(BIN)

$(BIN)/maze: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BIN)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN)/*.o $(BIN)/maze
