#include "../headers/maze.h"

/**
 * updateGame - Update game state based on input.
 * @game: Pointer to the game structure.
 */
void updateGame(Game *game) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    // Move forward
    if (state[SDL_SCANCODE_UP] && game->map[(int)(game->playerX + game->playerDirX * 0.1)][(int)(game->playerY)] == 0) {
        game->playerX += game->playerDirX * 0.1;
        game->playerY += game->playerDirY * 0.1;
    }

    // Move backward
    if (state[SDL_SCANCODE_DOWN] && game->map[(int)(game->playerX - game->playerDirX * 0.1)][(int)(game->playerY)] == 0) {
        game->playerX -= game->playerDirX * 0.1;
        game->playerY -= game->playerDirY * 0.1;
    }

    // Move left
    if (state[SDL_SCANCODE_LEFT] && game->map[(int)(game->playerX)][(int)(game->playerY + game->playerDirX * 0.1)] == 0) {
        game->playerX -= game->playerDirY * 0.1;
        game->playerY += game->playerDirX * 0.1;
    }

    // Move right
    if (state[SDL_SCANCODE_RIGHT] && game->map[(int)(game->playerX)][(int)(game->playerY - game->playerDirX * 0.1)] == 0) {
        game->playerX += game->playerDirY * 0.1;
        game->playerY -= game->playerDirX * 0.1;
    }
}
