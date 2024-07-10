#ifndef MAZE_H
#define MAZE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 64
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct {
    SDL_Texture *wall;
    SDL_Texture *floor;
    SDL_Texture *ceiling;
} Textures;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    Textures textures;
    double playerX, playerY; // Player position
    double playerDirX, playerDirY; // Player direction
    double planeX, planeY; // Camera plane
} Game;

bool initSDL(Game *game);
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *path);
void closeSDL(Game *game);
bool parseMap(Game *game, const char *filename);
void handleInput(Game *game, bool *running);
void updateGame(Game *game);
void render(Game *game);

#endif /* MAZE_H */