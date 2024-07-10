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
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

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
    int map[MAP_HEIGHT][MAP_WIDTH];
    Player player;
    Textures textures;
} Game;

bool initSDL(Game *game);
void closeSDL(Game *game);
void handleInput(Game *game, bool *running);
void movePlayer(Player *player, int map[MAP_HEIGHT][MAP_WIDTH], double moveSpeed);
void strafePlayer(Player *player, int map[MAP_HEIGHT][MAP_WIDTH], double moveSpeed);
void rotatePlayer(Player *player, double angle);
SDL_Texture* loadTexture(SDL_Renderer *renderer, const char *path);
bool parseMap(Game *game, const char *filePath);

#endif /* MAZE_H */