#include "../headers/maze.h"

/**
 * parseMap - Parses the map from a file.
 * @game: Pointer to the game structure.
 * @filePath: Path to the map file.
 *
 * Return: true if parsing is successful, false otherwise.
 */
bool parseMap(Game *game, const char *filePath)
{
    FILE *file = fopen(filePath, "r");
    if (!file)
    {
        SDL_Log("Unable to open file: %s", filePath);
        return false;
    }

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            int value;
            if (fscanf(file, "%d", &value) != 1)
            {
                SDL_Log("Invalid map format in file: %s", filePath);
                fclose(file);
                return false;
            }
            game->map[y][x] = value;
        }
    }

    fclose(file);
    return true;
}