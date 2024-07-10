#include "../headers/maze.h"

/**
 * initSDL - Initializes SDL and creates a window and renderer.
 * @game: Pointer to the game structure.
 *
 * Return: true if initialization is successful, false otherwise.
 */
bool initSDL(Game *game)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    game->window = SDL_CreateWindow("Maze Game",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
    if (!game->window)
    {
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (!game->renderer)
    {
        SDL_DestroyWindow(game->window);
        SDL_Log("Could not create renderer: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    game->textures.wall = loadTexture(game->renderer, "images/wall.bmp");
    game->textures.floor = loadTexture(game->renderer, "images/floor.bmp");
    game->textures.ceiling = loadTexture(game->renderer, "images/ceiling.bmp");

    if (!game->textures.wall || !game->textures.floor || !game->textures.ceiling)
    {
        SDL_Log("Failed to load textures");
        closeSDL(game);
        return false;
    }

    game->player.x = 22.0;
    game->player.y = 12.0;
    game->player.dirX = -1.0;
    game->player.dirY = 0.0;
    game->player.planeX = 0.0;
    game->player.planeY = 0.66;

    return true;
}

/**
 * loadTexture - Loads a texture from a file.
 * @renderer: The renderer to use.
 * @path: The file path to the image.
 *
 * Return: The loaded texture or NULL on failure.
 */
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *path)
{
    SDL_Surface *surface = SDL_LoadBMP(path);
    if (!surface)
    {
        SDL_Log("Failed to load image %s: %s", path, SDL_GetError());
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        SDL_Log("Failed to create texture from %s: %s", path, SDL_GetError());
    }

    return texture;
}

/**
 * closeSDL - Cleans up and closes SDL.
 * @game: Pointer to the game structure.
 *
 * Return: void
 */
void closeSDL(Game *game)
{
    SDL_DestroyTexture(game->textures.wall);
    SDL_DestroyTexture(game->textures.floor);
    SDL_DestroyTexture(game->textures.ceiling);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}