//
// Created by taitq on 26/03/2022.
//

#ifndef TEST_CPP_BASEOBJECT_H
#define TEST_CPP_BASEOBJECT_H

#include "BaseFunction.h"

class BaseObject {
public:
    SDL_Rect rect;
    SDL_Texture* pObject;
    SDL_Texture* fullObject;
    BaseObject();
    void setRect(int x, int y);
    bool loadObject(std::string path,SDL_Renderer* renderer);
    void showObject(SDL_Renderer * renderer) ;
};


#endif //TEST_CPP_BASEOBJECT_H
