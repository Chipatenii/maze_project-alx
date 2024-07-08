#include "../headers/maze.h"

/**
 * main - Entry point for the maze game.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(void)
{
    Game game;
    bool running = true;

    if (!initSDL(&game)) {
        printf("Failed to initialize SDL\n");
        return 1;
    }

    if (!parseMap(&game, "maps/map1.txt")) {
        printf("Failed to load map\n");
        closeSDL(&game);
        return 1;
    }

    while (running) {
        handleInput(&game, &running);
        render(&game);
    }

    closeSDL(&game);
    return 0;
}
