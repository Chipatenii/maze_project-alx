#include "../headers/sdl_utils.h"

/**
 * init_window - Initialize an SDL window
 * @title: Window title
 * @width: Window width
 * @height: Window height
 * Return: Pointer to the initialized SDL window
 */
SDL_Window *init_window(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    return window;
}

/**
 * init_renderer - Initialize an SDL renderer
 * @window: Pointer to the SDL window
 * Return: Pointer to the initialized SDL renderer
 */
SDL_Renderer *init_renderer(SDL_Window *window) {
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return NULL;
    }

    return renderer;
}

/**
 * cleanup - Cleanup SDL resources
 * @window: Pointer to the SDL window
 * @renderer: Pointer to the SDL renderer
 */
void cleanup(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}