#include "../headers/raycasting.h"
#include <math.h>

/**
 * render_raycasting - Render the scene using raycasting
 * @renderer: Pointer to the SDL renderer
 * @map: Pointer to the map structure
 * @camera: Pointer to the camera structure
 * @textures: Pointer to the textures structure
 */
void render_raycasting(SDL_Renderer *renderer, Map *map, Camera *camera, Textures *textures) {
    int w, h;
    SDL_GetRendererOutputSize(renderer, &w, &h);

    for (int x = 0; x < w; x++) {
        double cameraX = 2 * x / (double)w - 1;
        double rayDirX = camera->dirX + camera->planeX * cameraX;
        double rayDirY = camera->dirY + camera->planeY * cameraX;

        int mapX = (int)camera->x;
        int mapY = (int)camera->y;

        double sideDistX;
        double sideDistY;

        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (camera->x - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - camera->x) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (camera->y - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - camera->y) * deltaDistY;
        }

        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (map->arr[mapX][mapY] > 0) hit = 1;
        }

        if (side == 0) perpWallDist = (mapX - camera->x + (1 - stepX) / 2) / rayDirX;
        else perpWallDist = (mapY - camera->y + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(h / perpWallDist);

        int drawStart = -lineHeight / 2 + h / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + h / 2;
        if (drawEnd >= h) drawEnd = h - 1;

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
    }
}