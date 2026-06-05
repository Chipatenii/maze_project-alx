CC = gcc
CFLAGS = -Wall -Wextra -Iheaders
LDFLAGS = -lSDL2 -lSDL2_image -lm

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test
VPATH = $(SRC_DIR) $(TEST_DIR)

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.c=$(OBJ_DIR)/%.o)
EXEC = maze_game
TEST_EXEC = test_runner

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(TEST_EXEC): $(TEST_OBJS) $(OBJS)
	$(CC) $(TEST_OBJS) $(OBJS) -o $@ $(LDFLAGS)

all: $(EXEC)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -rf $(OBJ_DIR) $(EXEC) $(TEST_EXEC)

.PHONY: all test clean