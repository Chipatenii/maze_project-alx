#ifndef MAZE_H
#define MAZE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MOVE_SPEED 0.05
#define ROTATE_SPEED 0.05

typedef struct {
    double x, y;
    double dirX, dirY;
    double planeX, planeY;
} Player;

typedef struct {
    SDL_Texture *wall;
    SDL_Texture *floor;
    SDL_Texture *ceiling;
} Textures;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int map[24][24];
    Player player;
    Textures textures;
} Game;

bool initSDL(Game *game);
void closeSDL(Game *game);
void handleInput(Game *game, bool *running);
void movePlayer(Player *player, int map[24][24], double moveSpeed);
void strafePlayer(Player *player, int map[24][24], double moveSpeed);
void rotatePlayer(Player *player, double angle);
SDL_Texture* loadTexture(SDL_Renderer *renderer, const char *path);

#endif /* MAZE_H */