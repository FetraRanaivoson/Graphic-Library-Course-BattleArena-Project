//
// Created by Administrator on 8/20/2021.
//

#ifndef _GAMEFLOW_H
#define _GAMEFLOW_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "SDL2/SDL_mixer.h"

#ifdef _WIN32
#include <windows.h>
#endif
#include <gl/GL.h>
#include <gl/GLU.h>

#include <vector>
#include <stdlib.h>
#include <time.h>

#include "SkyboxElements/Arbre.h"
#include "SkyboxElements/Champignon.h"
#include "Utils.h"
#include "Camera.h"
#include "Projectile.h"
#include "Enemy.h"
#include "CollisionManager.h"

class GameFlow {
protected:
    int widthScreen, heightScreen;
    SDL_Window *win;
    SDL_GLContext context;
    SDL_Event event;
    bool isRunning;
    const Uint8 *state;
    GLdouble zFar;
    float worldSize;
    Player *p1;
    Camera *c1;
    Player *p2;
    Camera *c2;
    Mix_Chunk *sonBG;
    GLuint idDesert;
    GLuint idSolSkybox;
    GLuint idTankTexture;
    GLuint idBulletTexture;
    Uint32 startRotation;
    GLUquadric *params;
    std::vector<Arbre *> arbres;
    std::vector<Champignon *> champignons;
    int nbArbres;
    int nbChampignons;
    std::vector<Enemy *> enemies;
    CollisionManager *collisionManager;

public :
    int getWidthScreen() const;
    int getHeightScreen() const;
    GameFlow(int widthScreen, int heightScreen, GLdouble zfar, float wSize);
    void init();
    void loop();
    void clean();
    void createObject();
    void move();
    void draw();
    void
    drawsplitScreen();
    void drawUi();

};

#endif