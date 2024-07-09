#include "../headers/maze.h"

/**
 * parseMap - Parses the map from a file.
 * @game: A pointer to the Game structure.
 * @filename: The name of the file to parse.
 *
 * Return: true if successful, false otherwise.
 */
bool parseMap(Game *game, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Unable to open map file %s!\n", filename);
        return false;
    }

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            int c = fgetc(file);
            if (c == '1')
                game->map[x][y] = 1;
            else if (c == '0')
                game->map[x][y] = 0;
            else if (c == '\n')
                x--;
            else
            {
                printf("Invalid map format!\n");
                fclose(file);
                return false;
            }
        }
    }

    fclose(file);
    return true;
}