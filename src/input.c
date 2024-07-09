#include "../headers/maze.h"

/**
 * rotatePlayer - Rotates the player by a given angle.
 * @player: Pointer to the player structure.
 * @angle: Angle by which to rotate the player.
 *
 * Return: void
 */
void rotatePlayer(Player *player, double angle);

/**
 * movePlayer - Moves the player forward or backward.
 * @player: Pointer to the player structure.
 * @map: Pointer to the game map.
 * @moveSpeed: Speed at which to move the player.
 *
 * Return: void
 */
void movePlayer(Player *player, int **map, double moveSpeed);

/**
 * strafePlayer - Strafes the player left or right.
 * @player: Pointer to the player structure.
 * @map: Pointer to the game map.
 * @moveSpeed: Speed at which to strafe the player.
 *
 * Return: void
 */
void strafePlayer(Player *player, int **map, double moveSpeed);

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

/**
 * rotatePlayer - Rotates the player by a given angle.
 * @player: Pointer to the player structure.
 * @angle: Angle by which to rotate the player.
 *
 * Return: void
 */
void rotatePlayer(Player *player, double angle)
{
    double oldDirX = player->dirX;
    player->dirX = player->dirX * cos(angle) - player->dirY * sin(angle);
    player->dirY = oldDirX * sin(angle) + player->dirY * cos(angle);

    double oldPlaneX = player->planeX;
    player->planeX = player->planeX * cos(angle) - player->planeY * sin(angle);
    player->planeY = oldPlaneX * sin(angle) + player->planeY * cos(angle);
}
