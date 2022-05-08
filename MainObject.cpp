//
// Created by taitq on 27/03/2022.
//

#include "MainObject.h"
#include "Bullet.h"
MainObject::MainObject() {
    rect.x = 0;
    rect.y = 0;
    fullObject = nullptr;
    angle = 0;
    velocity = 10;
    flip = SDL_FLIP_NONE;
}
void MainObject::HandleInput(SDL_Event event) {
    switch (event.type) {
        case SDL_QUIT:
            exit(0);
        case SDL_KEYDOWN:
        {
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    rect.x += velocity;
                    break;
                case SDLK_LEFT:
                    rect.x -= velocity;
                    break;
                case SDLK_UP:
                    angle-= 5;
                    break;
                case SDLK_DOWN:
                    angle += 5;
                    break;
                case SDLK_SPACE:
                {
                   bullet.setRect(rect.x,rect.y);
                   bullet.isMove = true;
                   break;
                }
            }
            break;
        }
    }
}

void MainObject::rotate(SDL_Renderer *renderer) {
    SDL_RenderCopyEx(renderer,fullObject, nullptr,&rect,angle,NULL,flip);
}


