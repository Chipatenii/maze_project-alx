#include "camera.h"
#include <math.h>

void initialize_camera(Camera *camera, float posX, float posY, float dirX, float dirY, float planeX, float planeY) {
    camera->x = posX;
    camera->y = posY;
    camera->dirX = dirX;
    camera->dirY = dirY;
    camera->planeX = planeX;
    camera->planeY = planeY;
}

void rotate_camera(Camera *camera, float angle) {
    float oldDirX = camera->dirX;
    camera->dirX = camera->dirX * cos(angle) - camera->dirY * sin(angle);
    camera->dirY = oldDirX * sin(angle) + camera->dirY * cos(angle);

    float oldPlaneX = camera->planeX;
    camera->planeX = camera->planeX * cos(angle) - camera->planeY * sin(angle);
    camera->planeY = oldPlaneX * sin(angle) + camera->planeY * cos(angle);
}