#include "../headers/maze.h"

/**
 * movePlayer - Moves the player based on input.
 * @player: A pointer to the Player structure.
 * @map: The game map.
 * @moveX: The amount to move in the X direction.
 * @moveY: The amount to move in the Y direction.
 */
void movePlayer(Player *player, int map[MAP_WIDTH][MAP_HEIGHT], double moveX, double moveY)
{
    if (map[(int)(player->posX + moveX)][(int)(player->posY)] == 0)
        player->posX += moveX;
    if (map[(int)(player->posX)][(int)(player->posY + moveY)] == 0)
        player->posY += moveY;
}
