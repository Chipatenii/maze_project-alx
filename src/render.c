#include "../headers/maze.h"

/**
 * render - Renders the game state to the screen.
 * @game: A pointer to the Game structure.
 */
void render(Game *game)
{
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    for (int x = 0; x < SCREEN_WIDTH; x++) {
        double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
        double rayDirX = game->dirX + game->planeX * cameraX;
        double rayDirY = game->dirY + game->planeY * cameraX;

        int mapX = (int)game->posX;
        int mapY = (int)game->posY;

        double sideDistX;
        double sideDistY;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (game->posX - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - game->posX) * deltaDistX;
        }

        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (game->posY - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - game->posY) * deltaDistY;
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
            if (game->map[mapX][mapY] > '0') hit = 1;
        }

        if (side == 0) perpWallDist = (mapX - game->posX + (1 - stepX) / 2) / rayDirX;
        else perpWallDist = (mapY - game->posY + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

        SDL_Color color;
        switch (game->map[mapX][mapY]) {
            case '1':  color = (side == 1) ? (SDL_Color){255, 0, 0, 255} : (SDL_Color){200, 0, 0, 255}; break;
            case '2':  color = (side == 1) ? (SDL_Color){0, 255, 0, 255} : (SDL_Color){0, 200, 0, 255}; break;
            case '3':  color = (side == 1) ? (SDL_Color){0, 0, 255, 255} : (SDL_Color){0, 0, 200, 255}; break;
            case '4':  color = (side == 1) ? (SDL_Color){255, 255, 255, 255} : (SDL_Color){200, 200, 200, 255}; break;
            default:   color = (side == 1) ? (SDL_Color){255, 255, 0, 255} : (SDL_Color){200, 200, 0, 255}; break;
        }

        SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(game->renderer, x, drawStart, x, drawEnd);
    }

    SDL_RenderPresent(game->renderer);
}

