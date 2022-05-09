//
// Created by taitq on 27/03/2022.
//

#include "ThreatObject.h"

ThreatObject::ThreatObject() {
    isMove = true;
    rect.x = 0;
    rect.y = rand() % (HEIGHT/2);
    velocity = rand()%5 + 8;
}

void ThreatObject::move() {
    if(rect.x < WIDTH - rect.w)
        rect.x+= velocity;
    if(rect.x >= WIDTH - rect.h)
    {
        rect.x = 0;
        rect.y = rand() % (HEIGHT/2);
        velocity = rand() % 5 + 8;
    }
}

void ThreatObject::showMove(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer,fullObject, nullptr,&rect);
   // SDL_RenderPresent(renderer);
}



