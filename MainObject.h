//
// Created by taitq on 27/03/2022.
//

#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include "BaseObject.h"
#include "BaseFunction.h"

class MainObject : public BaseObject {
private:
    int velocity;
public:
    void setVelocity(int v);
    void HandleInput(SDL_Event event);
};


#endif //MAINOBJECT_H
