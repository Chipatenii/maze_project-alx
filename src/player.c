#include "../headers/maze.h"

/**
 * updateGame - Updates the game state.
 * @game: A pointer to the Game structure.
 */
void updateGame(Game *game)
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP] && game->map[game->playerX][game->playerY - 1] == 0)
    {
        game->playerY--;
    }
    if (state[SDL_SCANCODE_DOWN] && game->map[game->playerX][game->playerY + 1] == 0)
    {
        game->playerY++;
    }
    if (state[SDL_SCANCODE_LEFT] && game->map[game->playerX - 1][game->playerY] == 0)
    {
        game->playerX--;
    }
    if (state[SDL_SCANCODE_RIGHT] && game->map[game->playerX + 1][game->playerY] == 0)
    {
        game->playerX++;
    }
}
