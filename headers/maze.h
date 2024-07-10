#ifndef MAZE_H
#define MAZE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

#define ROTATE_SPEED 0.05
#define MOVE_SPEED 0.1

typedef struct {
    double x;
    double y;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
} Player;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    Player player;
    int map[MAP_WIDTH][MAP_HEIGHT];
} Game;

int initSDL(Game *game);
void closeSDL(Game *game);
void handleInput(Game *game, bool *running);
void updateGame(Game *game);
void render(Game *game);
void rotatePlayer(Player *player, double angle);
void movePlayer(Player *player, int map[MAP_WIDTH][MAP_HEIGHT], double moveSpeed);
void strafePlayer(Player *player, int map[MAP_WIDTH][MAP_HEIGHT], double moveSpeed);
bool parseMap(Game *game, const char *filename);

#endif /* MAZE_H */