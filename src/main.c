#include <SDL2/SDL.h>
#include "../headers/init.h"
#include "../headers/input.h"
#include "../headers/player.h"
#include "../headers/parser.h"
#include "../headers/render.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    SDLContext context;
    Game game;

    if (!initSDL(&context, SCREEN_WIDTH, SCREEN_HEIGHT)) {
        return 1;
    }

    if (!loadMap(&game, "map/map.txt")) {
        closeSDL(&context);
        return 1;
    }

    game.running = 1;
    game.player.x = 50;
    game.player.y = 50;
    game.player.angle = 0;

    while (game.running) {
        handleInput(&game);
        renderGame(&context, &game);
    }

    closeSDL(&context);
    return 0;
}
