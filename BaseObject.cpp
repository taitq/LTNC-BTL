//
// Created by taitq on 26/03/2022.
//

#include "BaseObject.h"

BaseObject::BaseObject() {
    rect.x = 0;
    rect.y = 0;
    pObject = nullptr;
    fullObject= nullptr;
}

void BaseObject::setRect(int x, int y) {
    rect.x = x;
    rect.y = y;
}

bool BaseObject::loadObject(std::string path, SDL_Renderer *renderer) {
    fullObject =  SDL_BaseFunction::loadImage(path.c_str(),renderer);
    SDL_QueryTexture(fullObject,NULL,NULL,&rect.w,&rect.h);
    if(fullObject== nullptr)
        return false;
   return true;
}

void BaseObject::showObject(SDL_Renderer* renderer) {
    SDL_BaseFunction::applySurface(renderer,fullObject,rect.x,rect.y,rect.w,rect.h);
}



