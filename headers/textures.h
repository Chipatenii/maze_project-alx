#ifndef TEXTURES_H
#define TEXTURES_H

#include <SDL2/SDL.h>

typedef struct {
    SDL_Texture *wall;
    SDL_Texture *floor;
    SDL_Texture *ceiling;
    SDL_Texture *weapon;
    SDL_Texture *enemy;
    SDL_Texture *rain;
} Textures;

int load_textures(SDL_Renderer *renderer, Textures *textures);
void free_textures(Textures *textures);

#endif