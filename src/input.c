#include "../headers/input.h"
#include <SDL2/SDL.h>

void handleInput(Game *game) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            game->running = 0;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    rotatePlayer(&game->player, -ROTATE_SPEED);
                    break;
                case SDLK_RIGHT:
                    rotatePlayer(&game->player, ROTATE_SPEED);
                    break;
                case SDLK_UP:
                    movePlayer(&game->player, game->map, MOVE_SPEED);
                    break;
                case SDLK_DOWN:
                    movePlayer(&game->player, game->map, -MOVE_SPEED);
                    break;
                case SDLK_a:
                    strafePlayer(&game->player, game->map, -MOVE_SPEED);
                    break;
                case SDLK_d:
                    strafePlayer(&game->player, game->map, MOVE_SPEED);
                    break;
            }
        }
    }
}
