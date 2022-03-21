//
// Created by Administrator on 8/18/2021.
//

#ifndef ABILITY_H
#define ABILITY_H

#include "Projectile.h"

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "SDL2/SDL_mixer.h"

#ifdef _WIN32
#include <windows.h>
#endif
#include <gl/GL.h>
#include <gl/GLU.h>


class Ability {
protected:
    std::vector<Projectile*> bullets;
    float maxAmmo;
    float ammoLeft;
    float cooldown;
    Uint32 currentTime;
    Mix_Chunk *sonShoot;
    float damage;
public:
    Ability(float maxAmmo, float cd);
    void use(GLUquadric *params, GLuint idTexture, float radius, Coord coord, float velocity, float angle);
    void draw();
    float getAmmoLeft() const;
    void move();
    const std::vector<Projectile *> &getBullets() const;
    float getDamage() const;
};
#endif 
