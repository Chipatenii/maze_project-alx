#include "../headers/map.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * load_map - Load the map from a file
 * @filename: Path to the map file
 * Return: Pointer to the loaded map structure
 */
Map *load_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    int rows = 0, cols = 0;
    fscanf(file, "%d %d", &rows, &cols);

    Map *map = malloc(sizeof(Map));
    if (!map) return NULL;
    map->rows = rows;
    map->cols = cols;
    map->arr = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        map->arr[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%d", &map->arr[i][j]);
        }
    }

    fclose(file);
    return map;
}

/**
 * free_map - Free the allocated memory for the map
 * @map: Pointer to the map structure
 */
void free_map(Map *map) {
    for (int i = 0; i < map->rows; i++) {
        free(map->arr[i]);
    }
    free(map->arr);
    free(map);
}