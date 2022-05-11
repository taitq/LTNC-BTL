//
// Created by taitq on 27/03/2022.
//

#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include "BaseObject.h"
#include "BaseFunction.h"
#include "Bullet.h"
#include "ThreatObject.h"
class MainObject : public BaseObject {
public:
    int velocity;
    double angleRotate;
    int NUMBERBULLET ;
    std::vector<Bullet*> bulletList;
    SDL_RendererFlip flip;
    MainObject();
    void HandleInput(SDL_Event event,SDL_Renderer* renderer);
    void rotate(SDL_Renderer* renderer);
    void killEnemy( std::vector<ThreatObject* >& planeList, SDL_Renderer* renderer, int& score);

};


#endif //MAINOBJECT_H
