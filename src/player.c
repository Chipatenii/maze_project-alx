#include "../headers/maze.h"

/**
 * movePlayer - Moves the player forward or backward.
 * @game: A pointer to the Game structure.
 * @moveSpeed: The speed at which to move the player.
 */
void movePlayer(Game *game, double moveSpeed)
{
    // Check collision with walls before moving
    if (game->map[(int)(game->posX + game->dirX * moveSpeed)][(int)(game->posY)] == '0') {
        game->posX += game->dirX * moveSpeed;
    }
    if (game->map[(int)(game->posX)][(int)(game->posY + game->dirY * moveSpeed)] == '0') {
        game->posY += game->dirY * moveSpeed;
    }
}

/**
 * rotatePlayer - Rotates the player left or right.
 * @game: A pointer to the Game structure.
 * @rotSpeed: The speed at which to rotate the player.
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
