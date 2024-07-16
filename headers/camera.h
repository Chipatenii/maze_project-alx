#ifndef CAMERA_H
#define CAMERA_H

typedef struct {
    float x, y;    /*Position of the camera*/
    float dirX, dirY; /*Direction vector*/
    float planeX, planeY; /*2D raycaster version of camera plane*/
} Camera;

void initialize_camera(Camera *camera, float posX, float posY, float dirX, float dirY, float planeX, float planeY);
void rotate_camera(Camera *camera, float angle);

#endif
