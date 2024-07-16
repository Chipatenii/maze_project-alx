#include "rain.h"

void initialize_rain(Rain *rain, SDL_Renderer *renderer) {
    rain->texture = IMG_LoadTexture(renderer, "images/rain.png");
    rain->is_raining = 0;
}

void toggle_rain(Rain *rain) {
    rain->is_raining = !rain->is_raining;
}

void render_rain(Rain *rain, SDL_Renderer *renderer) {
    if (rain->is_raining) {
        SDL_RenderCopy(renderer, rain->texture, NULL, NULL);
    }
}