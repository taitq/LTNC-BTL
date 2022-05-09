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
    double angleRotate;
    std::vector<Bullet*> bulletList;
    SDL_RendererFlip flip;
    MainObject();
    void HandleInput(SDL_Event event,SDL_Renderer* renderer);
    void rotate(SDL_Renderer* renderer);

};


#endif //MAINOBJECT_H
