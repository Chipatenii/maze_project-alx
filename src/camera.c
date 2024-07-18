#include "../headers/camera.h"

/**
 * rotate_left - Rotate the camera to the left
 * @camera: Pointer to the camera structure
 * @rotSpeed: Rotation speed
 */
void rotate_left(Camera *camera, double rotSpeed) {
    double oldDirX = camera->dirX;
    camera->dirX = camera->dirX * cos(rotSpeed) - camera->dirY * sin(rotSpeed);
    camera->dirY = oldDirX * cos(rotSpeed) + camera->dirY * sin(rotSpeed);

    double oldPlaneX = camera->planeX;
    camera->planeX = camera->planeX * cos(rotSpeed) - camera->planeY * sin(rotSpeed);
    camera->planeY = oldPlaneX * cos(rotSpeed) + camera->planeY * sin(rotSpeed);
}

/**
 * rotate_right - Rotate the camera to the right
 * @camera: Pointer to the camera structure
 * @rotSpeed: Rotation speed
 */
void rotate_right(Camera *camera, double rotSpeed) {
    double oldDirX = camera->dirX;
    camera->dirX = camera->dirX * cos(-rotSpeed) - camera->dirY * sin(-rotSpeed);
    camera->dirY = oldDirX * cos(-rotSpeed) + camera->dirY * sin(-rotSpeed);

    double oldPlaneX = camera->planeX;
    camera->planeX = camera->planeX * cos(-rotSpeed) - camera->planeY * sin(-rotSpeed);
    camera->planeY = oldPlaneX * cos(-rotSpeed) + camera->planeY * sin(-rotSpeed);
}