//
// Created by PAPOTEUR on 2021-08-17.
//

#ifndef ARBRE_H
#define ARBRE_H

#ifdef _WIN32
#include <windows.h>
#endif
#include <gl/GL.h>
#include <gl/GLU.h>


class Arbre {
private:
    float x, y, z, angleRotate = 0;
    GLuint idTexture;
    float radius;
public:
    Arbre(float x, float y, float z, GLUquadric *params, float radius);
    void draw();
    void move();
    virtual ~Arbre();
    float getX() const;
    float getZ() const;
    float getRadius() const;
};
#endif 
