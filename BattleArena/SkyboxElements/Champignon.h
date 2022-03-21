//
// Created by Administrator on 18/08/2021.
//

#ifndef CHAMPIGNON_H
#define CHAMPIGNON_H

#ifdef _WIN32
#include <windows.h>
#endif
#include <gl/GL.h>
#include <gl/GLU.h>


#include <SDL2/SDL_stdinc.h>

class Champignon {
private:
    float x, y, z, angleRotate = 0, deltaTime, velocity = .01;
    GLuint idTexture;
    float radius;
    Uint32 endPosition;
public:
    float getX() const;
    float getY() const;
    float getZ() const;
    float getRadius() const;
public:
    Champignon(float x, float y, float z, GLUquadric *params, float radius, float deltaTime);
    void draw();
    void move(Uint32 startRotation);
    virtual ~Champignon();
};
#endif 
