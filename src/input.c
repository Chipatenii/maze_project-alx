#include "../headers/maze.h"

/**
 * handleInput - Processes player input.
 * @game: A pointer to the Game structure.
 * @quit: A pointer to the quit flag.
 */
void handleInput(Game *game, bool *quit) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            *quit = true;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_w: game->player.moveForward = true; break;
                case SDLK_s: game->player.moveBackward = true; break;
                case SDLK_a: game->player.turnLeft = true; break;
                case SDLK_d: game->player.turnRight = true; break;
            }
        } else if (e.type == SDL_KEYUP) {
            switch (e.key.keysym.sym) {
                case SDLK_w: game->player.moveForward = false; break;
                case SDLK_s: game->player.moveBackward = false; break;
                case SDLK_a: game->player.turnLeft = false; break;
                case SDLK_d: game->player.turnRight = false; break;
            }
        }
    }
}
