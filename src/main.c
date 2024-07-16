#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sdl_utils.h"
#include "raycasting.h"
#include "player.h"
#include "map.h"
#include "textures.h"
#include "rain.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <map file>\n", argv[0]);
        return -1;
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (init_SDL(&window, &renderer, WINDOW_WIDTH, WINDOW_HEIGHT) != 0) {
        printf("Failed to initialize SDL\n");
        return -1;
    }

    Map *map = load_map(argv[1]);
    if (!map) {
        printf("Failed to load map\n");
        cleanup_SDL(window, renderer);
        return -1;
    }

    Textures textures;
    if (load_textures(renderer, &textures) != 0) {
        printf("Failed to load textures\n");
        free_map(map);
        cleanup_SDL(window, renderer);
        return -1;
    }

    Player player;
    initialize_player(&player, 22.0, 12.0);

    Rain rain;
    initialize_rain(&rain, renderer);

    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r) {
                toggle_rain(&rain);
            } else {
                handle_input(&player, event);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render_scene(renderer, &player.camera, map, &textures);
        render_rain(&rain, renderer);

        SDL_RenderPresent(renderer);
    }

    free_textures(&textures);
    free_map(map);
    cleanup_SDL(window, renderer);
    return 0;
}