#ifndef MAP_H
#define MAP_H

typedef struct {
    int width;
    int height;
    int **data;
} Map;

Map* load_map(const char *filename);
void free_map(Map *map);

#endif
