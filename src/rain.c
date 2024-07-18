#include "../headers/rain.h"
#include <stdlib.h>

/**
 * init_rain - Initialize rain drops
 * @rain: Pointer to the rain structure
 * @count: Number of rain drops
 */
void init_rain(Rain *rain, int count) {
    rain->count = count;
    rain->drops = malloc(count * sizeof(Raindrop));
    for (int i = 0; i < count; i++) {
        rain->drops[i].x = rand() % 800;
        rain->drops[i].y = rand() % 600;
        rain->drops[i].velocity = 2 + rand() % 5;
    }
}

/**
 * update_rain - Update the positions of rain drops
 * @rain: Pointer to the rain structure
 */
void update_rain(Rain *rain) {
    for (int i = 0; i < rain->count; i++) {
        rain->drops[i].y += rain->drops[i].velocity;
        if (rain->drops[i].y > 600) {
            rain->drops[i].x = rand() % 800;
            rain->drops[i].y = 0;
        }
    }
}

/**
 * render_rain - Render the rain drops
 * @renderer: Pointer to the SDL renderer
 * @rain: Pointer to the rain structure
 */
void render_rain(SDL_Renderer *renderer, Rain *rain) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    for (int i = 0; i < rain->count; i++) {
        SDL_RenderDrawPoint(renderer, rain->drops[i].x, rain->drops[i].y);
    }
}