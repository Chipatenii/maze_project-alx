#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/camera.h"
#include "../headers/map.h"
#include "../headers/player.h"
#include "../headers/raycasting.h"
#include "../headers/sdl_utils.h"
#include "../headers/textures.h"
#include "../headers/rain.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char *argv[]) {
    SDL_Window *window = init_window("Maze Game", WINDOW_WIDTH, WINDOW_HEIGHT);
    SDL_Renderer *renderer = init_renderer(window);

    Map *map = load_map("../maps/map.txt");
    if (map == NULL) {
        fprintf(stderr, "Failed to load map.\n");
        cleanup(window, renderer);
        return EXIT_FAILURE;
    }

    Camera camera = { .x = 1.5, .y = 1.5, .dirX = -1, .dirY = 0, .planeX = 0, .planeY = 0.66 };
    Player player = { .x = 1.5, .y = 1.5, .speed = 0.05 };

    Textures *textures = load_textures(renderer);
    if (textures == NULL) {
        fprintf(stderr, "Failed to load textures.\n");
        free_map(map);
        cleanup(window, renderer);
        return EXIT_FAILURE;
    }

    Rain rain;
    init_rain(&rain, 100);

    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_W]) move_forward(&player, &camera, map);
        if (state[SDL_SCANCODE_S]) move_backward(&player, &camera, map);
        if (state[SDL_SCANCODE_A]) rotate_left(&camera, player.speed);
        if (state[SDL_SCANCODE_D]) rotate_right(&camera, player.speed);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render_rain(renderer, &rain);
        update_rain(&rain);
        render_raycasting(renderer, map, &camera, textures);

        SDL_RenderPresent(renderer);
    }

    free_textures(textures);
    free_map(map);
    cleanup(window, renderer);
    return 0;
}