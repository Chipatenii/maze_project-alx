#include "../headers/maze.h"

/**
 * render - Renders the maze game frame by frame.
 * @game: A pointer to the Game structure containing game state.
 */
void render(Game *game) {
    /*Clear the renderer*/
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(game->renderer);

    /*Calculate the frame*/
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; // X-coordinate in camera space
        double rayDirX = game->player.dirX + game->player.planeX * cameraX;
        double rayDirY = game->player.dirY + game->player.planeY * cameraX;

        /*Which box of the map we're in*/
        int mapX = (int)game->player.posX;
        int mapY = (int)game->player.posY;

        /*Length of ray from current position to next x or y-side*/
        double sideDistX;
        double sideDistY;

        /*Length of ray from one x or y-side to next x or y-side*/
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        /*Direction to go in x and y (either +1 or -1)*/
        int stepX;
        int stepY;

        int hit = 0; // Was there a wall hit?
        int side; // Was the wall vertical or horizontal?

        /*Calculate step and initial sideDist*/
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (game->player.posX - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - game->player.posX) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (game->player.posY - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - game->player.posY) * deltaDistY;
        }

        /*Perform DDA*/
        while (hit == 0) {
            /*Jump to next map square, either in x-direction, or in y-direction*/
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            /*Check if ray has hit a wall*/
            if (game->map[mapX][mapY] > 0) hit = 1;
        }

        /*Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)*/
        if (side == 0) perpWallDist = (mapX - game->player.posX + (1 - stepX) / 2) / rayDirX;
        else perpWallDist = (mapY - game->player.posY + (1 - stepY) / 2) / rayDirY;

        /*Calculate height of line to draw on screen*/
        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        /*Calculate lowest and highest pixel to fill in current stripe*/
        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

        /*Choose wall color*/
        SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        if (side == 1) { SDL_SetRenderDrawColor(game->renderer, 127, 0, 0, SDL_ALPHA_OPAQUE); }

        /*Draw the pixels of the stripe as a vertical line*/
        SDL_RenderDrawLine(game->renderer, x, drawStart, x, drawEnd);
    }

    /*Update the screen*/
    SDL_RenderPresent(game->renderer);
}