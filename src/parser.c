#include "../headers/maze.h"

/**
 * parseMap - Parses the map from a file.
 * @game: A pointer to the Game structure.
 * @filename: The name of the map file.
 *
 * Return: true if successful, false otherwise.
 */
bool parseMap(Game *game, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open map file\n");
        return false;
    }

    char buffer[256];
    int width = 0, height = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        width = strlen(buffer) - 1; // excluding newline
        height++;
    }

    fseek(file, 0, SEEK_SET);

    game->mapWidth = width;
    game->mapHeight = height;
    game->map = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        game->map[i] = malloc(width + 1);
        fgets(game->map[i], width + 1, file);
        fgetc(file); // discard newline
    }

    fclose(file);
    return true;
}
