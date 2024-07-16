#ifndef PLAYER_H
#define PLAYER_H

#include "camera.h"

typedef struct {
    Camera camera;
    float speed;
} Player;

void initialize_player(Player *player, float posX, float posY);
void move_player(Player *player, Map *map, float moveX, float moveY);
void handle_input(Player *player, SDL_Event event);

#endif