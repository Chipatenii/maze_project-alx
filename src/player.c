#include "../headers/maze.h"

/**
 * movePlayer - Moves the player within the game.
 * @game: A pointer to the Game structure.
 * @moveSpeed: The speed at which the player moves.
 */
void movePlayer(Game *game, double moveSpeed)
{
    double newPosX = game->posX + game->dirX * moveSpeed;
    double newPosY = game->posY + game->dirY * moveSpeed;
    
    if (game->map[(int)newPosX][(int)game->posY] == '0') {
        game->posX = newPosX;
    }
    if (game->map[(int)game->posX][(int)newPosY] == '0') {
        game->posY = newPosY;
    }
}

/**
 * rotatePlayer - Rotates the player's direction within the game.
 * @game: A pointer to the Game structure.
 * @rotSpeed: The speed at which the player rotates.
 */
void rotatePlayer(Game *game, double rotSpeed)
{
    double oldDirX = game->dirX;
    game->dirX = game->dirX * cos(rotSpeed) - game->dirY * sin(rotSpeed);
    game->dirY = oldDirX * sin(rotSpeed) + game->dirY * cos(rotSpeed);

    double oldPlaneX = game->planeX;
    game->planeX = game->planeX * cos(rotSpeed) - game->planeY * sin(rotSpeed);
    game->planeY = oldPlaneX * sin(rotSpeed) + game->planeY * cos(rotSpeed);
}
