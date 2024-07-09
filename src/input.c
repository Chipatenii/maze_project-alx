#include "../headers/maze.h"

/**
 * handleInput - Handles input events and updates the game state accordingly.
 * @game: Pointer to the game structure.
 * @running: Pointer to the running flag.
 *
 * Return: void
 */
void handleInput(Game *game, bool *running)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            *running = false;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_LEFT:
                    rotatePlayer(&game->player, -ROTATE_SPEED);
                    break;
                case SDLK_RIGHT:
                    rotatePlayer(&game->player, ROTATE_SPEED);
                    break;
                case SDLK_w:
                    movePlayer(&game->player, game->map, MOVE_SPEED);
                    break;
                case SDLK_s:
                    movePlayer(&game->player, game->map, -MOVE_SPEED);
                    break;
                case SDLK_a:
                    strafePlayer(&game->player, game->map, -MOVE_SPEED);
                    break;
                case SDLK_d:
                    strafePlayer(&game->player, game->map, MOVE_SPEED);
                    break;
                case SDLK_ESCAPE:
                    *running = false;
                    break;
                default:
                    break;
            }
        }
    }
}