#include "../headers/maze.h"

/**
 * parseMap - Parses the game map from a file.
 * @game: A pointer to the Game structure.
 * @filename: The name of the map file.
 *
 * Return: true if successful, false otherwise.
 */
bool parseMap(Game *game, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Failed to open map file: %s\n", filename);
        return false;
    }

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            int tile;
            if (fscanf(file, "%1d", &tile) != 1)
            {
                printf("Failed to read map data at (%d, %d)\n", x, y);
                fclose(file);
                return false;
            }
            game->map[x][y] = tile;
        }
    }

    fclose(file);
    return true;
}