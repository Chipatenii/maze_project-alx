#include "player.h"

void initialize_player(Player *player, float posX, float posY) {
    initialize_camera(&player->camera, posX, posY, -1.0, 0.0, 0.0, 0.66);
    player->speed = 0.05;
}

void move_player(Player *player, Map *map, float moveX, float moveY) {
    if (map->data[(int)(player->camera.x + moveX * player->speed)][(int)player->camera.y] == 0)
        player->camera.x += moveX * player->speed;
    if (map->data[(int)player->camera.x][(int)(player->camera.y + moveY * player->speed)] == 0)
        player->camera.y += moveY * player->speed;
}

void handle_input(Player *player, SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                rotate_camera(&player->camera, -0.05);
                break;
            case SDLK_RIGHT:
                rotate_camera(&player->camera, 0.05);
                break;
            case SDLK_UP:
                move_player(player, map, player->camera.dirX, player->camera.dirY);
                break;
            case SDLK_DOWN:
                move_player(player, map, -player->camera.dirX, -player->camera.dirY);
                break;
            case SDLK_a:
                move_player(player, map, -player->camera.dirY, player->camera.dirX);
                break;
            case SDLK_d:
                move_player(player, map, player->camera.dirY, -player->camera.dirX);
                break;
            default:
                break;
        }
    }
}
