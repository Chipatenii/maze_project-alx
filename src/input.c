#include "../headers/maze.h"

/**
 * handleInput - Handles player input.
 * @game: Pointer to the Game struct.
 * @running: Pointer to the running flag.
 */
void handleInput(Game *game, bool *running)
{
    SDL_Event e;
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            *running = false;
        }
    }

    if (state[SDL_SCANCODE_UP]) {
        movePlayer(&game->player, game->map, MOVE_SPEED);
    }
    if (state[SDL_SCANCODE_DOWN]) {
        movePlayer(&game->player, game->map, -MOVE_SPEED);
    }
    if (state[SDL_SCANCODE_LEFT]) {
        rotatePlayer(&game->player, ROTATE_SPEED);
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        rotatePlayer(&game->player, -ROTATE_SPEED);
    }
    if (state[SDL_SCANCODE_Q]) {
        strafePlayer(&game->player, game->map, -MOVE_SPEED);
    }
    if (state[SDL_SCANCODE_E]) {
        strafePlayer(&game->player, game->map, MOVE_SPEED);
    }
}