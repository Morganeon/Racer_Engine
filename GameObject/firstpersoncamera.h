#ifndef FIRSTPERSONCAMERA_H
#define FIRSTPERSONCAMERA_H
#include <GameObject/camera.h>

class FirstPersonCamera : public Camera
{
public:
    FirstPersonCamera();
    void move(float dx, float dy, int z, int s, int q, int d,int dh);
    QMatrix4x4 getViewMatrix();

private:

};

#endif // FIRSTPERSONCAMERA_H
