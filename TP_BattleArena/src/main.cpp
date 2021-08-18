#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "Utils.h"
#include "Camera.h"
#include "Enemy.h"
#include "time.h"

int main(int argc, char **args) {

    srand(time(NULL));


    SDL_Window *win;
    int width = 800, height = 600;
    bool isRunning = true;
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG);
    win = SDL_CreateWindow("opengl Template", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                           SDL_WINDOW_OPENGL);



    //precise la version d opengl
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);



    //creation du context
    SDL_GLContext context = SDL_GL_CreateContext(win);
    SDL_GL_SetSwapInterval(0);


    //appelle la matrice de projection
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);


    //initialise la matrice de projection à 0
    glLoadIdentity();


    //modifie la matrice de projection pour avoir la perspective voulue
    gluPerspective(70, (double) 800 / 600, 1, 10000);
    glMatrixMode(GL_MODELVIEW);


    SDL_Event event;
    float angleX = 0;
    float angleZ = 0;
    float x = 100, y = 100, z = 100;
    const Uint8 *state = nullptr;


    GLUquadric *params = gluNewQuadric();
    GLuint idTankTexture = Utils::loadTexture("./assets/tanktexture.jpg");


    Player *p1 = new Player(params, idTankTexture, 18, 16, {0, 1, 0}, 0, 0.5, 0.5, 20);
    Camera *c1 = new Camera(p1);


    float enemyPosX = 0;
    float enemyPosY = 20;
    float enemyPosZ = -800;
    float enemyVelocity = .2;
    Enemy *enemy = new Enemy(params, enemyPosX, enemyPosY, enemyPosZ, enemyVelocity);
//    std::vector<Enemy *> enemies;
//    for (int i = 0; i < 5; i++) {
//        int sign = 1;
//        if (rand()%2 == 0)
//            sign = -1;
//        else
//            sign = 1;
//        enemies.push_back(new Enemy(params, sign * rand() % 700, 2, sign * rand() % 700, .2));
//    }


    while (isRunning) {
        glLoadIdentity();
//        glPushMatrix();
//        gluLookAt(x, y, z, 0, 0, 0, 0, 1, 0);
        c1->move();
//        glPopMatrix();



        //Nettoyer la fenêtre
        glClearColor(0.0f, 0.f, 0.f,
                     1.f); //permet d'expliquer avec quelle couleur on va remplir la memoire des couleurs
        glClear(GL_COLOR_BUFFER_BIT |
                GL_DEPTH_BUFFER_BIT); //permet de dire que la memoire des couleurs est prête à être modifié



        //gestion évènement
        SDL_PollEvent(&event);
        state = SDL_GetKeyboardState(NULL);
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        if (state[SDL_SCANCODE_ESCAPE]) {
            isRunning = false;
        }
        if (state[SDL_SCANCODE_LEFT]) {
            x -= .1;
        }
        if (state[SDL_SCANCODE_RIGHT]) {
            x += .1;
        }
        if (state[SDL_SCANCODE_UP]) {
            z -= .1;
        }
        if (state[SDL_SCANCODE_DOWN]) {
            z += .1;
        }
        p1->move(state);


        //plateforme
        Utils::drawCube(2000, .1, 2000);
        glTranslatef(0, 1, 0);

        //Player
        p1->draw();

        enemy->draw();
        enemy->trackPlayer(p1->getX(), p1->getY(), p1->getZ());
//        for (Enemy *e : enemies) {
//            e->draw();
//        }
//
//        for (Enemy *e : enemies) {
//            e->trackPlayer(p1->getX(), p1->getY(), p1->getZ());
//        }



        //mise a jour de l'écran
        glFlush();
        SDL_GL_SwapWindow(win);
        angleX += 0.1;
        angleZ += 0.05;



        //pause dans l'image
        SDL_Delay(1);
    }
    delete p1;
    gluDeleteQuadric(params);
    glDeleteTextures(1, &idTankTexture);
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
                        
