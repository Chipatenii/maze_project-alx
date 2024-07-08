#include "../headers/maze.h"

/**
 * initSDL - Initializes SDL and sets up the game window and renderer.
 * @game: A pointer to the Game structure.
 *
 * Return: true if successful, false otherwise.
 */
bool initSDL(Game *game)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    game->window = SDL_CreateWindow("Maze Game",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
    if (!game->window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (!game->renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(game->window);
        return false;
    }

    game->posX = 22;
    game->posY = 12;
    game->dirX = -1;
    game->dirY = 0;
    game->planeX = 0;
    game->planeY = 0.66;

    return loadTextures(game);
}

/**
 * loadTextures - Loads textures for the game.
 * @game: A pointer to the Game structure.
 *
 * Return: true if successful, false otherwise.
 */
bool loadTextures(Game *game)
{
    SDL_Surface *loadedSurface = SDL_LoadBMP("images/wall.bmp");
    if (!loadedSurface) {
        printf("Unable to load image %s! SDL Error: %s\n", "images/wall.bmp", SDL_GetError());
        return false;
    }
    game->wallTexture = SDL_CreateTextureFromSurface(game->renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    if (!game->wallTexture) {
        printf("Unable to create texture from %s! SDL Error: %s\n", "images/wall.bmp", SDL_GetError());
        return false;
    }

    loadedSurface = SDL_LoadBMP("images/floor.bmp");
    if (!loadedSurface) {
        printf("Unable to load image %s! SDL Error: %s\n", "images/floor.bmp", SDL_GetError());
        return false;
    }
    game->floorTexture = SDL_CreateTextureFromSurface(game->renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    if (!game->floorTexture) {
        printf("Unable to create texture from %s! SDL Error: %s\n", "images/floor.bmp", SDL_GetError());
        return false;
    }

    loadedSurface = SDL_LoadBMP("images/ceiling.bmp");
    if (!loadedSurface) {
        printf("Unable to load image %s! SDL Error: %s\n", "images/ceiling.bmp", SDL_GetError());
        return false;
    }
    game->ceilingTexture = SDL_CreateTextureFromSurface(game->renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    if (!game->ceilingTexture) {
        printf("Unable to create texture from %s! SDL Error: %s\n", "images/ceiling.bmp", SDL_GetError());
        return false;
    }

    return true;
}

/**
 * closeSDL - Shuts down SDL and cleans up resources.
 * @game: A pointer to the Game structure.
 */
void closeSDL(Game *game)
{
    SDL_DestroyTexture(game->wallTexture);
    SDL_DestroyTexture(game->floorTexture);
    SDL_DestroyTexture(game->ceilingTexture);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}
