#include "../headers/player.h"
#include "../headers/map.h"

/**
 * move_forward - Move the player forward
 * @player: Pointer to the player structure
 * @camera: Pointer to the camera structure
 * @map: Pointer to the map structure
 */
void move_forward(Player *player, Camera *camera, Map *map) {
    if (map->arr[(int)(player->x + camera->dirX * player->speed)][(int)player->y] == 0)
        player->x += camera->dirX * player->speed;
    if (map->arr[(int)player->x][(int)(player->y + camera->dirY * player->speed)] == 0)
        player->y += camera->dirY * player->speed;
}

/**
 * move_backward - Move the player backward
 * @player: Pointer to the player structure
 * @camera: Pointer to the camera structure
 * @map: Pointer to the map structure
 */
void move_backward(Player *player, Camera *camera, Map *map) {
    if (map->arr[(int)(player->x - camera->dirX * player->speed)][(int)player->y] == 0)
        player->x -= camera->dirX * player->speed;
    if (map->arr[(int)player->x][(int)(player->y - camera->dirY * player->speed)] == 0)
        player->y -= camera->dirY * player->speed;
}