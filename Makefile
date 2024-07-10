CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs) -lSDL2_image -lm

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
HEADER_DIR = headers

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/maze

$(EXECUTABLE): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/init.o: $(SRC_DIR)/init.c $(HEADER_DIR)/init.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/player.o: $(SRC_DIR)/player.c $(HEADER_DIR)/player.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Add more rules for other source files like parser.o, render.o, etc.

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

