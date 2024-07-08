CC = gcc
CFLAGS = -Wall -Wextra -pedantic `sdl2-config --cflags`
LIBS = `sdl2-config --libs` -lSDL2_image -lm

SRCDIR = src
BINDIR = bin

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(BINDIR)/%.o)

TARGET = $(BINDIR)/maze

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ) | $(BINDIR)
    $(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.c | $(BINDIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(BINDIR):
    mkdir -p $(BINDIR)

clean:
    rm -rf $(BINDIR)