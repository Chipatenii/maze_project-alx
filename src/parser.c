#include "../headers/maze.h"

/**
 * parseMap - Parses the game map from a file.
 * @game: A pointer to the Game structure.
 * @filename: The name of the file containing the map.
 *
 * Return: true if successful, false otherwise.
 */
bool parseMap(Game *game, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open map file: %s\n", filename);
        return false;
    }

    fscanf(file, "%d %d", &game->mapWidth, &game->mapHeight);

    game->map = malloc(game->mapHeight * sizeof(char *));
    for (int i = 0; i < game->mapHeight; i++) {
        game->map[i] = malloc(game->mapWidth * sizeof(char));
        fscanf(file, "%s", game->map[i]);
    }

    fclose(file);
    return true;
}