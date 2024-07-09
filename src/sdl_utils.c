#include "../headers/maze.h"

/**
 * initSDL - Initializes SDL.
 * @game: A pointer to the Game structure.
 *
 * Return: true if successful, false otherwise.
 */
bool initSDL(Game *game)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    game->window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!game->window)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (!game->renderer)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(game->window);
        return false;
    }

    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);

    return true;
}

/**
 * closeSDL - Cleans up SDL.
 * @game: A pointer to the Game structure.
 */
void closeSDL(Game *game)
{
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}