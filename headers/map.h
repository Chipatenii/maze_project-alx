#ifndef MAP_H
#define MAP_H

typedef struct {
    int **arr;
    int rows;
    int cols;
} Map;

Map *load_map(const char *filename);
void free_map(Map *map);

#endif