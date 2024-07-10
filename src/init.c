#include "../headers/init.h"
#include <stdio.h>

int initSDL(SDLContext *context, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    context->window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!context->window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    context->renderer = SDL_CreateRenderer(context->window, -1, SDL_RENDERER_ACCELERATED);
    if (!context->renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

void closeSDL(SDLContext *context) {
    SDL_DestroyRenderer(context->renderer);
    SDL_DestroyWindow(context->window);
    SDL_Quit();
}
