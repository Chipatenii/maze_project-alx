#include "../headers/maze.h"

/**
 * updatePlayer - Updates the player's position and direction based on input.
 * @game: A pointer to the Game structure.
 */
void updatePlayer(Game *game) {
    double moveSpeed = 0.1;
    double rotSpeed = 0.05;

    if (game->player.moveForward) {
        game->player.posX += game->player.dirX * moveSpeed;
        game->player.posY += game->player.dirY * moveSpeed;
    }
    if (game->player.moveBackward) {
        game->player.posX -= game->player.dirX * moveSpeed;
        game->player.posY -= game->player.dirY * moveSpeed;
    }
    if (game->player.turnLeft) {
        double oldDirX = game->player.dirX;
        game->player.dirX = game->player.dirX * cos(-rotSpeed) - game->player.dirY * sin(-rotSpeed);
        game->player.dirY = oldDirX * sin(-rotSpeed) + game->player.dirY * cos(-rotSpeed);
    }
    if (game->player.turnRight) {
        double oldDirX = game->player.dirX;
        game->player.dirX = game->player.dirX * cos(rotSpeed) - game->player.dirY * sin(rotSpeed);
        game->player.dirY = oldDirX * sin(rotSpeed) + game->player.dirY * cos(rotSpeed);
    }
}
