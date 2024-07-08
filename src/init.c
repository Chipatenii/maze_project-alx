#include "../headers/maze.h"

/**
 * initSDL - Initializes SDL and sets up the game window and renderer.
 * @game: A pointer to the Game structure.
 *
 * Return: true if successful, false otherwise.
 */
bool initSDL(Game *game)
{
    /*Initialize SDL video subsystem*/
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    /*Create SDL window*/
    game->window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!game->window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    /*Create SDL renderer*/
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (!game->renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    /*Initialize SDL_image for loading textures*/
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    /*Load textures for walls, floor, and ceiling*/
    if (!loadTextures(game)) {
        return false;
    }

    /*Initialize player position and view direction*/
    game->posX = 22;
    game->posY = 12;
    game->dirX = -1;
    game->dirY = 0;
    game->planeX = 0;
    game->planeY = 0.66;

    return true;
}

/**
 * closeSDL - Shuts down SDL and frees resources.
 * @game: A pointer to the Game structure.
 */
void closeSDL(Game *game)
{
    /*Free loaded textures*/
    for (int i = 0; i < 3; i++) {
        if (game->textures[i]) {
            SDL_DestroyTexture(game->textures[i]);
        }
    }

    /*Destroy SDL renderer and window*/
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);

    /*Quit SDL subsystems*/
    IMG_Quit();
    SDL_Quit();
}
