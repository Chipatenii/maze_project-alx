#ifndef RAIN_H
#define RAIN_H

#include <SDL2/SDL.h>

typedef struct {
    SDL_Texture *texture;
    int is_raining;
} Rain;

void initialize_rain(Rain *rain, SDL_Renderer *renderer);
void toggle_rain(Rain *rain);
void render_rain(Rain *rain, SDL_Renderer *renderer);

#endif