#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

/**
 * struct Game - Represents the game state.
 * @window: The SDL window.
 * @renderer: The SDL renderer.
 * @mapWidth: The width of the map.
 * @mapHeight: The height of the map.
 * @map: The map represented as a 2D array.
 * @posX: The player's X position.
 * @posY: The player's Y position.
 * @dirX: The X direction vector.
 * @dirY: The Y direction vector.
 * @planeX: The X plane vector.
 * @planeY: The Y plane vector.
 */

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int mapWidth;
    int mapHeight;
    char **map;
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    SDL_Texture *wallTexture;
    SDL_Texture *floorTexture;
    SDL_Texture *ceilingTexture;
} Game;

bool initSDL(Game *game);
void closeSDL(Game *game);
void render(Game *game);
void handleInput(Game *game, bool *running);
bool parseMap(Game *game, const char *filename);
void movePlayer(Game *game, double moveSpeed);
void rotatePlayer(Game *game, double rotSpeed);
bool loadTextures(Game *game);

#endif // MAZE_H
