#include "../headers/maze.h"

/**
 * handleInput - Handles user input.
 * @game: A pointer to the Game structure.
 * @running: A pointer to the running flag.
 */
void handleInput(Game *game, bool *running)
{
    const double moveSpeed = 0.05;
    const double rotSpeed = 0.05;
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            *running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_w:
                    movePlayer(game, moveSpeed);
                    break;
                case SDLK_s:
                    movePlayer(game, -moveSpeed);
                    break;
                case SDLK_a:
                    rotatePlayer(game, -rotSpeed);
                    break;
                case SDLK_d:
                    rotatePlayer(game, rotSpeed);
                    break;
                default:
                    break;
            }
        }
    }
}

