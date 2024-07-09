#include "../headers/maze.h"

/**
 * initSDL - Initializes SDL and sets up the game window and renderer.
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

    game->window = SDL_CreateWindow("Maze Game",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
    if (game->window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (game->renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    game->textures.wall = loadTexture(game->renderer, "images/wall.bmp");
    game->textures.floor = loadTexture(game->renderer, "images/floor.bmp");
    game->textures.ceiling = loadTexture(game->renderer, "images/ceiling.bmp");

    if (!game->textures.wall || !game->textures.floor || !game->textures.ceiling)
    {
        printf("Failed to load textures!\n");
        return false;
    }

    game->player.posX = 22.0;
    game->player.posY = 12.0;
    game->player.dirX = -1.0;
    game->player.dirY = 0.0;
    game->player.planeX = 0.0;
    game->player.planeY = 0.66;

    return true;
}

/**
 * loadTexture - Loads a texture from a specified path.
 * @renderer: The SDL renderer.
 * @path: The path to the image file.
 *
 * Return: A pointer to the loaded texture, or NULL on failure.
 */
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *path)
{
    SDL_Texture *newTexture = NULL;
    SDL_Surface *loadedSurface = SDL_LoadBMP(path);
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_Error: %s\n", path, SDL_GetError());
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL_Error: %s\n", path, SDL_GetError());
        }
    }
    return newTexture;
}

/**
 * closeSDL - Cleans up SDL resources.
 * @game: A pointer to the Game structure.
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
