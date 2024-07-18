#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <SDL2/SDL.h>

SDL_Window *init_window(const char *title, int width, int height);
SDL_Renderer *init_renderer(SDL_Window *window);
void cleanup(SDL_Window *window, SDL_Renderer *renderer);

#endif