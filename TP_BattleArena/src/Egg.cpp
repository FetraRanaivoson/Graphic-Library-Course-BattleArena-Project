//
// Created by Administrator on 8/18/2021.
//

#include "Egg.h"

Egg::Egg(GLUquadric *params, float eggPosX, float eggPosY, float eggPosZ, float eggVelocity, float playerPosX, float playerPosY, float playerPosZ)
    : direction(playerPosX,playerPosY,playerPosZ){

    this->eggPosX = eggPosX;
    this->eggPosY = eggPosY;
    this->eggPosZ = eggPosZ;
    this->eggVelocity = eggVelocity;

    direction.normalize();

    eggID = glGenLists(1);
    glNewList(eggID, GL_COMPILE);
    glColor3ub(0, 255, 0);
    gluQuadricDrawStyle(params, GLU_FILL);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluSphere(params, 10, 20, 20);
    glPopMatrix();
    glEndList();
}

void Egg::draw() {
    glPushMatrix();
    glTranslatef(eggPosX, eggPosY, eggPosZ);
    glCallList(eggID);
    glPopMatrix();
}

void Egg::draw(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glCallList(eggID);
    glPopMatrix();
}

void Egg::move() {
    eggPosX += eggVelocity * direction.x;
    //eggPosY += eggVelocity * direction.y;
    eggPosZ += eggVelocity * direction.z;
    //eggPosX += eggVelocity;

}




Egg::~Egg() {
    glDeleteLists(eggID, 1);
}

float Egg::getEggPosX() const {
    return eggPosX;
}

float Egg::getEggPosY() const {
    return eggPosY;
}

float Egg::getEggPosZ() const {
    return eggPosZ;
}

void Egg::setDirection(Vector direction) {
    Egg::direction = direction;
}

void Egg::setEggPosX(float eggPosX) {
    Egg::eggPosX = eggPosX;
}

void Egg::setEggPosY(float eggPosY) {
    Egg::eggPosY = eggPosY;
}

void Egg::setEggPosZ(float eggPosZ) {
    Egg::eggPosZ = eggPosZ;
}




