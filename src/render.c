#include "../headers/render.h"
#include <SDL2/SDL.h>

void renderGame(SDLContext *context, Game *game) {
    SDL_SetRenderDrawColor(context->renderer, 0, 0, 0, 255);
    SDL_RenderClear(context->renderer);

    // Render the map
    SDL_SetRenderDrawColor(context->renderer, 255, 255, 255, 255);
    for (int y = 0; game->map[y] != NULL; y++) {
        for (int x = 0; game->map[y][x] != '\0'; x++) {
            if (game->map[y][x] == '1') {
                SDL_Rect rect = { x * 10, y * 10, 10, 10 };
                SDL_RenderFillRect(context->renderer, &rect);
            }
        }
    }

    // Render the player
    SDL_SetRenderDrawColor(context->renderer, 255, 0, 0, 255);
    SDL_Rect rect = { (int)game->player.x, (int)game->player.y, 10, 10 };
    SDL_RenderFillRect(context->renderer, &rect);

    SDL_RenderPresent(context->renderer);
}