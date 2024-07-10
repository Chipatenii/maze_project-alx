#include "../headers/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAP_SIZE 100

int loadMap(Game *game, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open map file");
        return 0;
    }

    game->map = malloc(MAX_MAP_SIZE * sizeof(char *));
    if (!game->map) {
        perror("Failed to allocate memory for map");
        fclose(file);
        return 0;
    }

    char line[MAX_MAP_SIZE];
    int row = 0;
    while (fgets(line, sizeof(line), file) && row < MAX_MAP_SIZE) {
        game->map[row] = strdup(line);
        if (!game->map[row]) {
            perror("Failed to duplicate line");
            fclose(file);
            return 0;
        }
        row++;
    }

    fclose(file);
    return 1;
}