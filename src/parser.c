#include "../headers/maze.h"
/**
 * loadMap - Loads the game map from a file.
 * @game: A pointer to the Game structure.
 * @filename: The name of the file containing the map.
 *
 * Return: true if successful, false otherwise.
 */
bool loadMap(Game *game, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open map file!\n");
        return false;
    }

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            fscanf(file, "%d", &game->map[i][j]);
        }
    }

    fclose(file);
    return true;
}