#include "../headers/maze.h"

/**
 * loadTextures - Loads textures for the game (walls, floor, ceiling).
 * @game: A pointer to the Game structure.
 *
 * Return: true if successful, false otherwise.
 */
bool loadTextures(Game *game)
{
    /*Load wall texture*/
    game->textures[0] = IMG_LoadTexture(game->renderer, "images/wall.bmp");
    if (!game->textures[0]) {
        printf("Failed to load wall texture: %s\n", IMG_GetError());
        return false;
    }

    /*Load floor texture*/
    game->textures[1] = IMG_LoadTexture(game->renderer, "images/floor.bmp");
    if (!game->textures[1]) {
        printf("Failed to load floor texture: %s\n", IMG_GetError());
        return false;
    }

    /*Load ceiling */
    game->textures[2] = IMG_LoadTexture(game->renderer, "images/ceiling.bmp");
    if (!game->textures[2]) {
        printf("Failed to load ceiling texture: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

/**
 * render - Renders the game scene.
 * @game: A pointer to the Game structure.
 */
void render(Game *game)
{
    /*Clear the renderer*/
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    /*Example code for rendering walls*/
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        /*Example: rendering walls*/
        SDL_Rect wallRect = { x, drawStart, 1, drawEnd - drawStart };
        SDL_RenderCopy(game->renderer, game->textures[0], NULL, &wallRect);
    }


    /*Present the renderer*/
    SDL_RenderPresent(game->renderer);
}
