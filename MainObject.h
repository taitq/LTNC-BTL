//
// Created by taitq on 27/03/2022.
//

#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include "BaseObject.h"
#include "BaseFunction.h"
#include "Bullet.h"

class MainObject : public BaseObject {
public:
    int velocity;
    double angle;
    SDL_RendererFlip flip;
    MainObject();
    Bullet bullet;
    void HandleInput(SDL_Event event);
    void rotate(SDL_Renderer* renderer);
};


#endif //MAINOBJECT_H
