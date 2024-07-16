#include "map.h"
#include <stdio.h>
#include <stdlib.h>

Map* load_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    Map *map = malloc(sizeof(Map));
    fscanf(file, "%d %d", &map->width, &map->height);

    map->data = malloc(map->height * sizeof(int*));
    for (int i = 0; i < map->height; i++) {
        map->data[i] = malloc(map->width * sizeof(int));
        for (int j = 0; j < map->width; j++) {
            fscanf(file, "%d", &map->data[i][j]);
        }
    }

    fclose(file);
    return map;
}

void free_map(Map *map) {
    for (int i = 0; i < map->height; i++) {
        free(map->data[i]);
    }
    free(map->data);
    free(map);
}