#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int init_SDL(SDL_Window **window, SDL_Renderer **renderer, int width, int height);
void cleanup_SDL(SDL_Window *window, SDL_Renderer *renderer);

#endif