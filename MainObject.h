//
// Created by taitq on 27/03/2022.
//

#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include "BaseObject.h"
#include "BaseFunction.h"
#include "Bullet.h"

class MainObject : public BaseObject {
private:
    int velocity;
    double angle;
    SDL_RendererFlip flip;
public:
    MainObject();
    Bullet bullet;
    void setVelocity(int v);
    void HandleInput(SDL_Event event,SDL_Renderer* renderer);
    void turn(SDL_Renderer* renderer);
};


#endif //MAINOBJECT_H
