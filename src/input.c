#include "../headers/maze.h"

/**
 * handleInput - Handles user input for moving and rotating the player.
 * @game: A pointer to the Game structure.
 * @running: A pointer to the running flag.
 */
void handleInput(Game *game, bool *running)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *running = false;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    movePlayer(game, 0.1);
                    break;
                case SDLK_s:
                    movePlayer(game, -0.1);
                    break;
                case SDLK_a:
                    rotatePlayer(game, -0.1);
                    break;
                case SDLK_d:
                    rotatePlayer(game, 0.1);
                    break;
            }
        }
    }
}
