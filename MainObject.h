//
// Created by taitq on 27/03/2022.
//

#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include "BaseObject.h"
#include "BaseFunction.h"

class MainObject : public BaseObject {
public:
    void HandleInput(SDL_Event event);
};


#endif //MAINOBJECT_H
