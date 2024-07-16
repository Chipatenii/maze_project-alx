#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SDL2/SDL.h>
#include "map.h"
#include "camera.h"
#include "textures.h"

void render_scene(SDL_Renderer *renderer, Camera *camera, Map *map, Textures *textures);

#endif