#include "../headers/maze.h"

#define ROTATE_SPEED 0.05
#define MOVE_SPEED 0.1

/**
 * initSDL - Initializes SDL and game resources.
 * @game: Pointer to the Game struct.
 *
 * Return: 1 on success, 0 on failure.
 */
int initSDL(Game *game)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    game->window = SDL_CreateWindow("Maze Game",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);

    if (game->window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

    if (game->renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    /* Initialize player position and direction */
    game->player.x = 22.0;
    game->player.y = 12.0;
    game->player.dirX = -1.0;
    game->player.dirY = 0.0;
    game->player.planeX = 0.0;
    game->player.planeY = 0.66;

    return 1;
}