# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic

# SDL flags
SDL_FLAGS = `sdl2-config --cflags --libs`

# Source files directory
SRC_DIR = ./src

# Header files directory
INC_DIR = ./headers

# Object files directory
OBJ_DIR = ./obj

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Executable name
EXEC = maze

# Libraries
LIBS = -lm

# Make all
all: $(EXEC)

# Linking executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC) $(SDL_FLAGS) $(LIBS)

# Compiling source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@ $(SDL_FLAGS)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean
clean:
	rm -rf $(OBJ_DIR) $(EXEC)
