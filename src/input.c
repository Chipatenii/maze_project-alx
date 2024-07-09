#include "../headers/maze.h"

/**
 * handleInput - Handles user input and updates the game state accordingly.
 * @game: A pointer to the Game structure.
 * @running: A pointer to the running flag.
 */
void handleInput(Game *game, bool *running)
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            *running = false;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                *running = false;
                break;
            case SDLK_w:
                if (game->map[(int)(game->player.posX + game->player.dirX * MOVE_SPEED)][(int)(game->player.posY)] == 0)
                    game->player.posX += game->player.dirX * MOVE_SPEED;
                if (game->map[(int)(game->player.posX)][(int)(game->player.posY + game->player.dirY * MOVE_SPEED)] == 0)
                    game->player.posY += game->player.dirY * MOVE_SPEED;
                break;
            case SDLK_s:
                if (game->map[(int)(game->player.posX - game->player.dirX * MOVE_SPEED)][(int)(game->player.posY)] == 0)
                    game->player.posX -= game->player.dirX * MOVE_SPEED;
                if (game->map[(int)(game->player.posX)][(int)(game->player.posY - game->player.dirY * MOVE_SPEED)] == 0)
                    game->player.posY -= game->player.dirY * MOVE_SPEED;
                break;
            case SDLK_a:
                if (game->map[(int)(game->player.posX - game->player.planeX * MOVE_SPEED)][(int)(game->player.posY)] == 0)
                    game->player.posX -= game->player.planeX * MOVE_SPEED;
                if (game->map[(int)(game->player.posX)][(int)(game->player.posY - game->player.planeY * MOVE_SPEED)] == 0)
                    game->player.posY -= game->player.planeY * MOVE_SPEED;
                break;
            case SDLK_d:
                if (game->map[(int)(game->player.posX + game->player.planeX * MOVE_SPEED)][(int)(game->player.posY)] == 0)
                    game->player.posX += game->player.planeX * MOVE_SPEED;
                if (game->map[(int)(game->player.posX)][(int)(game->player.posY + game->player.planeY * MOVE_SPEED)] == 0)
                    game->player.posY += game->player.planeY * MOVE_SPEED;
                break;
            case SDLK_LEFT:
                rotatePlayer(&game->player, -ROTATE_SPEED);
                break;
            case SDLK_RIGHT:
                rotatePlayer(&game->player, ROTATE_SPEED);
                break;
            }
        }
    }
}

/**
 * rotatePlayer - Rotates the player.
 * @player: A pointer to the Player structure.
 * @angle: The angle by which to rotate the player.
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