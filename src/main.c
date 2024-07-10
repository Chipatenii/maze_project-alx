#include "../headers/maze.h"

/**
 * main - Entry point for the maze game.
 *
 * This function initializes SDL, parses the game map, and starts the game loop.
 *
 * Return: 0 on success, non-zero on failure.
 */
int main(void)
{
    Game game;
    bool running = true;

    /* Initialize SDL and check for initialization success */
    if (!initSDL(&game)) {
        return 1;
    }

    /* Parse the game map from file */
    if (!parseMap(&game, "map/map1.txt")) {
        closeSDL(&game);
        return 1;
    }

    /* Game loop */
    while (running) {
        handleInput(&game, &running);
        updateGame(&game);
        render(&game);
    }

    /* Clean up and exit */
    closeSDL(&game);
    return 0;
}