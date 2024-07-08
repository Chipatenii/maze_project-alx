#ifndef MAZE_H
#define MAZE_H

#include <SDL.h>
#include <stdbool.h>
#include <SDL_image.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *textures[3];  /*Array to hold textures for walls, floor, and ceiling*/
    char **map;                /*2D array representing the game map*/
    int mapWidth;              /*Width of the game map*/
    int mapHeight;             /*Height of the game map*/
    double posX;               /*Player's X position*/
    double posY;               /*Player's Y position*/
    double dirX;               /*Player's direction X component*/
    double dirY;               /*Player's direction Y component*/
    double planeX;             /*2D camera plane X component*/
    double planeY;             /*2D camera plane Y component*/
} Game;

bool initSDL(Game *game);                                  /*Initializes SDL and game resources*/
void closeSDL(Game *game);                                 /*Shuts down SDL and frees resources*/
bool parseMap(Game *game, const char *filename);           /*Parses the game map from a file*/
void handleInput(Game *game, bool *running);               /*Handles user input*/
void render(Game *game);                                   /*Renders the game scene*/
void movePlayer(Game *game, double moveSpeed);             /*Moves the player in the game world*/
void rotatePlayer(Game *game, double rotSpeed);            /*Rotates the player's view*/
bool loadTextures(Game *game);                             /*Loads textures for walls, floor, and ceiling*/

#endif
