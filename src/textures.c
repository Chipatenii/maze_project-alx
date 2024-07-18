#include "../headers/textures.h"
#include <SDL2/SDL_image.h>

/**
 * load_textures - Load textures from files
 * @renderer: Pointer to the SDL renderer
 * Return: Pointer to the textures structure
 */
Textures *load_textures(SDL_Renderer *renderer) {
    Textures *textures = malloc(sizeof(Textures));
    if (!textures) return NULL;

    textures->wall = IMG_LoadTexture(renderer, "../images/wall.png");
    textures->floor = IMG_LoadTexture(renderer, "../images/floor.png");
    textures->ceiling = IMG_LoadTexture(renderer, "../images/ceiling.png");
    textures->weapon = IMG_LoadTexture(renderer, "../images/weapon.png");
    textures->enemy = IMG_LoadTexture(renderer, "../images/enemy.png");
    textures->rain = IMG_LoadTexture(renderer, "../images/rain.png");

    if (!textures->wall || !textures->floor || !textures->ceiling || !textures->weapon || !textures->enemy || !textures->rain) {
        free_textures(textures);
        return NULL;
    }

    return textures;
}

/**
 * free_textures - Free the loaded textures
 * @textures: Pointer to the textures structure
 */
void free_textures(Textures *textures) {
    if (textures->wall) SDL_DestroyTexture(textures->wall);
    if (textures->floor) SDL_DestroyTexture(textures->floor);
    if (textures->ceiling) SDL_DestroyTexture(textures->ceiling);
    if (textures->weapon) SDL_DestroyTexture(textures->weapon);
    if (textures->enemy) SDL_DestroyTexture(textures->enemy);
    if (textures->rain) SDL_DestroyTexture(textures->rain);
    free(textures);
}