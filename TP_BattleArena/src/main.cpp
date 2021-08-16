#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Utils.h"
int main(int argc, char **args) {
    SDL_Window *win;
    int width = 800, height = 600;
    bool isRunning = true;
    SDL_Init(SDL_INIT_EVERYTHING);
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
    glMatrixMode(GL_PROJECTION);
    //initialise la matrice de projection à 0
    glLoadIdentity();
    //modifie la matrice de projection pour avoir la perspective voulue
    gluPerspective(70, (double) 800 / 600, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    SDL_Event event;
    float angleX = 0;
    float angleZ = 0;
    float  x = 100,y = 100,z = 100;
    const Uint8 *state = nullptr;
    while (isRunning) {
        glLoadIdentity();
        gluLookAt(x, y, z, 0, 0, 0, 0, 1, 0);
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
        if(state[SDL_SCANCODE_ESCAPE]){
            isRunning = false;
        }
        if(state[SDL_SCANCODE_LEFT]){
            x-=.1;
        }
        if(state[SDL_SCANCODE_RIGHT]){
            x+=.1;
        }
        if(state[SDL_SCANCODE_UP]){
            z-=.1;
        }
        if(state[SDL_SCANCODE_DOWN]){
            z+=.1;
        }
        //dessin des différents objet dans la fenêtre


        //plateforme
        Utils::drawCube(2000,.1,2000);
        glTranslatef(0,1,0);
        Utils::drawAxis(50);



        //mise a jour de l'écran
        glFlush();
        SDL_GL_SwapWindow(win);
        angleX += 0.1;
        angleZ += 0.05;
        //pause dans l'image
        SDL_Delay(1);
    }
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
                        