#ifndef MAZE_H
#define MAZE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define MOVE_SPEED 0.1
#define ROTATE_SPEED 0.05

typedef struct {
    double x, y;
    double dirX, dirY;
    double planeX, planeY;
} Player;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int map[24][24];
    Player player;
} Game;

void initSDL(Game *game);
void closeSDL(Game *game);
void handleInput(Game *game, bool *running);
void movePlayer(Player *player, int map[24][24], double moveSpeed);
void strafePlayer(Player *player, int map[24][24], double moveSpeed);
void rotatePlayer(Player *player, double angle);

#endif /* MAZE_H */