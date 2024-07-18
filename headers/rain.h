#ifndef RAIN_H
#define RAIN_H

#include <SDL2/SDL.h>

typedef struct {
    int x, y;
    int velocity;
} Raindrop;

typedef struct {
    Raindrop *drops;
    int count;
} Rain;

void init_rain(Rain *rain, int count);
void update_rain(Rain *rain);
void render_rain(SDL_Renderer *renderer, Rain *rain);

#endif