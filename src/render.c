#include "../headers/maze.h"

/**
 * render - Renders the game to the screen.
 * @game: A pointer to the Game structure.
 */
void render(Game *game)
{
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            SDL_Rect tileRect = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
            if (game->map[x][y] == 1)
            {
                SDL_RenderCopy(game->renderer, game->textures.wall, NULL, &tileRect);
            }
            else
            {
                SDL_RenderCopy(game->renderer, game->textures.floor, NULL, &tileRect);
            }
        }
    }

    SDL_Rect playerRect = { game->playerX * TILE_SIZE, game->playerY * TILE_SIZE, TILE_SIZE, TILE_SIZE };
    SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255); // Red color for player
    SDL_RenderFillRect(game->renderer, &playerRect);

    SDL_RenderPresent(game->renderer);
}
