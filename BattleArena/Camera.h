//
// Created by Administrator on 8/17/2021.
//

#ifndef CAMERA_H
#define CAMERA_H

#include "Player.h"

#define _USE_MATH_DEFINES
#include "math.h"


class Camera {
protected:
    Player * p;
public:
    Camera(Player *p);
    void move();
};
#endif 