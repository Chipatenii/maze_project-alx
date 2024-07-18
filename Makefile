CC = gcc
CFLAGS = -Wall -Wextra -Iheaders
LDFLAGS = -lSDL2 -lSDL2_image

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.c=$(OBJ_DIR)/%.o)
EXEC = maze_game
TEST_EXEC = test

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(TEST_EXEC): $(TEST_OBJS) $(OBJS)
	$(CC) $(TEST_OBJS) $(OBJS) -o $@ $(LDFLAGS)

all: $(EXEC)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC) $(TEST_EXEC)

.PHONY: all test clean