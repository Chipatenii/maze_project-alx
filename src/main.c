#include "../headers/maze.h"

/**
 * main - Entry point of the program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
    (void)argc;  // Mark argc as used to avoid compiler warning
    (void)argv;  // Mark argv as used to avoid compiler warning

    Game game;
    bool running = true;

    if (!initSDL(&game))
        return 1;

    game.player.posX = 22.0;
    game.player.posY = 12.0;
    game.player.dirX = -1.0;
    game.player.dirY = 0.0;
    game.player.planeX = 0.0;
    game.player.planeY = 0.66;

    int map[MAP_WIDTH][MAP_HEIGHT] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    for (int x = 0; x < MAP_WIDTH; x++)
        for (int y = 0; y < MAP_HEIGHT; y++)
            game.map[x][y] = map[x][y];

    /* Game loop */
    while (running)
    {
        handleInput(&game, &running);
        updateGame(&game);
        render(&game);
    }

    closeSDL(&game);
    return 0;
}