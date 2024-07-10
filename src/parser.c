#include "../headers/maze.h"

/**
 * parseMap - Parse the game map from a file.
 * @game: Pointer to the game structure.
 * @filename: Path to the map file.
 *
 * Return: true if successful, false otherwise.
 */
bool parseMap(Game *game, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open map file!\n");
        return false;
    }

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (fscanf(file, "%d", &game->map[i][j]) != 1) {
                printf("Failed to read map data!\n");
                fclose(file);
                return false;
            }
        }
    }

    fclose(file);
    return true;
}
