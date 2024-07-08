CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
LIBS = `sdl2-config --cflags --libs` -lSDL2_image -lm

SRCDIR = src
INCDIR = headers
BINDIR = bin

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(BINDIR)/%.o)

TARGET = $(BINDIR)/maze

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ) | $(BINDIR)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR)
