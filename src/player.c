#include "../headers/maze.h"

/**
 * rotatePlayer - Rotates the player's direction vector.
 * @player: Pointer to the Player struct.
 * @angle: The angle to rotate by.
 */
void rotatePlayer(Player *player, double angle)
{
    double oldDirX = player->dirX;
    player->dirX = player->dirX * cos(angle) - player->dirY * sin(angle);
    player->dirY = oldDirX * cos(angle) + player->dirY * sin(angle);

    double oldPlaneX = player->planeX;
    player->planeX = player->planeX * cos(angle) - player->planeY * sin(angle);
    player->planeY = oldPlaneX * cos(angle) + player->planeY * sin(angle);
}

/**
 * movePlayer - Moves the player forward or backward.
 * @player: Pointer to the Player struct.
 * @map: The game map.
 * @moveSpeed: The speed to move by.
 */
void movePlayer(Player *player, int map[MAP_WIDTH][MAP_HEIGHT], double moveSpeed)
{
    if (map[(int)(player->x + player->dirX * moveSpeed)][(int)player->y] == 0)
        player->x += player->dirX * moveSpeed;
    if (map[(int)player->x][(int)(player->y + player->dirY * moveSpeed)] == 0)
        player->y += player->dirY * moveSpeed;
}

/**
 * strafePlayer - Strafes the player left or right.
 * @player: Pointer to the Player struct.
 * @map: The game map.
 * @moveSpeed: The speed to move by.
 */
void strafePlayer(Player *player, int map[MAP_WIDTH][MAP_HEIGHT], double moveSpeed)
{
    if (map[(int)(player->x + player->planeX * moveSpeed)][(int)player->y] == 0)
        player->x += player->planeX * moveSpeed;
    if (map[(int)player->x][(int)(player->y + player->planeY * moveSpeed)] == 0)
        player->y += player->planeY * moveSpeed;
}