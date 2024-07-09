#include "../headers/maze.h"

/**
 * movePlayer - Moves the player forward or backward.
 * @player: Pointer to the player structure.
 * @map: Pointer to the game map.
 * @moveSpeed: Speed at which to move the player.
 *
 * Return: void
 */
void movePlayer(Player *player, int map[24][24], double moveSpeed)
{
    double newX = player->x + player->dirX * moveSpeed;
    double newY = player->y + player->dirY * moveSpeed;

    /* Check for collisions with walls */
    if (map[(int)newX][(int)player->y] == 0)
    {
        player->x = newX;
    }
    if (map[(int)player->x][(int)newY] == 0)
    {
        player->y = newY;
    }
}

/**
 * strafePlayer - Strafes the player left or right.
 * @player: Pointer to the player structure.
 * @map: Pointer to the game map.
 * @moveSpeed: Speed at which to strafe the player.
 *
 * Return: void
 */
void strafePlayer(Player *player, int map[24][24], double moveSpeed)
{
    double newX = player->x + player->planeX * moveSpeed;
    double newY = player->y + player->planeY * moveSpeed;

    /* Check for collisions with walls */
    if (map[(int)newX][(int)player->y] == 0)
    {
        player->x = newX;
    }
    if (map[(int)player->x][(int)newY] == 0)
    {
        player->y = newY;
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