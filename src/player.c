#include "../headers/player.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

int checkCollision(char **map, float x, float y) {
    int mapX = (int)x / 10;
    int mapY = (int)y / 10;

    return (map[mapY][mapX] == '1');
}

void rotatePlayer(Player *player, float angle) {
    player->angle += angle;
}

void movePlayer(Player *player, char **map, float speed) {
    float newX = player->x + speed * cos(player->angle);
    float newY = player->y + speed * sin(player->angle);
    
    if (!checkCollision(map, newX, newY)) {
        player->x = newX;
        player->y = newY;
    }
}

void strafePlayer(Player *player, char **map, float speed) {
    float newX = player->x + speed * cos(player->angle + M_PI_2);
    float newY = player->y + speed * sin(player->angle + M_PI_2);

    if (!checkCollision(map, newX, newY)) {
        player->x = newX;
        player->y = newY;
    }
}
