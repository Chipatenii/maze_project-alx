#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SDL2/SDL.h>
#include "../headers/camera.h"
#include "../headers/map.h"
#include "../headers/textures.h"

void render_raycasting(SDL_Renderer *renderer, Map *map, Camera *camera, Textures *textures);

#endif