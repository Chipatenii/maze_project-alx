# Makefile for maze project

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_image -lm
SRC_DIR = src
BIN_DIR = bin
HEADERS_DIR = headers
IMAGES_DIR = images

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))

all: $(BIN_DIR) maze

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

maze: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_DIR)/maze.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR) maze

.PHONY: all clean
