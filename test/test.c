#include <stdio.h>
#include "map.h"

int main() {
    Map *map = load_map("../maps/map.txt");
    if (map) {
        printf("Map loaded successfully\n");
        for (int i = 0; i < map->height; i++) {
            for (int j = 0; j < map->width; j++) {
                printf("%d ", map->data[i][j]);
            }
            printf("\n");
        }
        free_map(map);
    } else {
        printf("Failed to load map\n");
    }
    return 0;
}