#include "raycasting.h"
#include <math.h>

void render_scene(SDL_Renderer *renderer, Camera *camera, Map *map, Textures *textures) {
    int w, h;
    SDL_GetRendererOutputSize(renderer, &w, &h);

    for (int x = 0; x < w; x++) {
        float cameraX = 2 * x / (float)w - 1;
        float rayDirX = camera->dirX + camera->planeX * cameraX;
        float rayDirY = camera->dirY + camera->planeY * cameraX;

        int mapX = (int)camera->x;
        int mapY = (int)camera->y;

        float sideDistX;
        float sideDistY;

        float deltaDistX = fabs(1 / rayDirX);
        float deltaDistY = fabs(1 / rayDirY);
        float perpWallDist;

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

        while (!hit) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            if (map->data[mapX][mapY] > 0) hit = 1;
        }

        if (side == 0)
            perpWallDist = (mapX - camera->x + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - camera->y + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(h / perpWallDist);

        int drawStart = -lineHeight / 2 + h / 2;
        if (drawStart < 0) drawStart = 0;

        int drawEnd = lineHeight / 2 + h / 2;
        if (drawEnd >= h) drawEnd = h - 1;

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        if (side == 1) SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255);

        SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
    }
}
