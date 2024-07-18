#ifndef CAMERA_H
#define CAMERA_H

typedef struct {
    double x, y;       // position
    double dirX, dirY; // direction vector
    double planeX, planeY; // camera plane
} Camera;

void rotate_left(Camera *camera, double rotSpeed);
void rotate_right(Camera *camera, double rotSpeed);

#endif