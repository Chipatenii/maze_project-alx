#include <stdio.h>
#include <assert.h>
#include "../headers/map.h"
#include "../headers/player.h"
#include "../headers/camera.h"

void test_map_loading() {
    Map *map = load_map("../maps/map.txt");
    assert(map != NULL);
    assert(map->rows > 0);
    assert(map->cols > 0);
    free_map(map);
    printf("Map loading test passed.\n");
}

void test_player_movement() {
    Map *map = load_map("../maps/map.txt");
    Camera camera = { .x = 1.5, .y = 1.5, .dirX = -1, .dirY = 0, .planeX = 0, .planeY = 0.66 };
    Player player = { .x = 1.5, .y = 1.5, .speed = 0.05 };

    double initialX = player.x;
    double initialY = player.y;

    move_forward(&player, &camera, map);
    assert(player.x != initialX || player.y != initialY);

    initialX = player.x;
    initialY = player.y;

    move_backward(&player, &camera, map);
    assert(player.x != initialX || player.y != initialY);

    free_map(map);
    printf("Player movement test passed.\n");
}

int main() {
    test_map_loading();
    test_player_movement();
    return 0;
}
