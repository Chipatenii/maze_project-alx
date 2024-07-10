#include "../headers/maze.h"

/**
 * render - Render the game state.
 * @game: Pointer to the game structure.
 */
void render(Game *game) {
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    // Render map
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            SDL_Rect rect = {x * 20, y * 20, 20, 20};
            if (game->map[x][y] == 1) {
                SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
            } else {
                SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
            }
            SDL_RenderFillRect(game->renderer, &rect);
        }
    }

    SDL_RenderPresent(game->renderer);
}
