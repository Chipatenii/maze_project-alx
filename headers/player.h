#ifndef PLAYER_H
#define PLAYER_H

#include "../headers/map.h"

typedef struct {
    double x, y;   // position
    double speed;  // movement speed
} Player;

void move_forward(Player *player, Camera *camera, Map *map);
void move_backward(Player *player, Camera *camera, Map *map);

#endif