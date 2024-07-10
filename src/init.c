#include "../headers/maze.h"

/**
 * initSDL - Initialize SDL and set up the game.
 * @game: Pointer to the game structure.
 *
 * Return: true if successful, false otherwise.
 */
bool initSDL(Game *game) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    game->window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (game->window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (game->renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Load textures
    game->textures.wall = loadTexture(game->renderer, "images/wall.bmp");
    game->textures.floor = loadTexture(game->renderer, "images/floor.bmp");
    game->textures.ceiling = loadTexture(game->renderer, "images/ceiling.bmp");

    // Initialize player position and direction
    game->playerX = 22.0;
    game->playerY = 12.0;
    game->playerDirX = -1.0;
    game->playerDirY = 0.0;
    game->planeX = 0.0;
    game->planeY = 0.66;

    return true;
}

/**
 * loadTexture - Load a texture from a file.
 * @renderer: Pointer to the SDL renderer.
 * @path: Path to the image file.
 *
 * Return: Pointer to the loaded texture.
 */
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *path) {
    SDL_Surface *loadedSurface = SDL_LoadBMP(path);
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    return texture;
}

/**
 * closeSDL - Clean up SDL resources.
 * @game: Pointer to the game structure.
 */
void closeSDL(Game *game) {
    SDL_DestroyTexture(game->textures.wall);
    SDL_DestroyTexture(game->textures.floor);
    SDL_DestroyTexture(game->textures.ceiling);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}