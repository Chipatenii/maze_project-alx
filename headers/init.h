#ifndef INIT_H
#define INIT_H

#include <SDL.h>
#include <SDL_image.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} SDLContext;

int initSDL(SDLContext *context, int width, int height);
void closeSDL(SDLContext *context);

#endif // INIT_H