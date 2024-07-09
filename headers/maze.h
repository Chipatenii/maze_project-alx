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

typedef struct Textures {
    SDL_Texture *wall;
    SDL_Texture *floor;
    SDL_Texture *ceiling;
} Textures;

typedef struct Player {
    double posX, posY; // player position
    double dirX, dirY; // direction vector
    double planeX, planeY; // camera plane
} Player;

typedef struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    Textures textures;
    Player player;
    int map[MAP_WIDTH][MAP_HEIGHT];
} Game;

bool initSDL(Game *game);
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *path);
void closeSDL(Game *game);
bool parseMap(Game *game, const char *filename);
void handleInput(Game *game, bool *running);
void updateGame(Game *game);
void render(Game *game);
void castRays(Game *game);

#endif /* MAZE_H */