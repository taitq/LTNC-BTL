//
// Created by taitq on 27/03/2022.
//

#include "MainObject.h"
#include "Bullet.h"
MainObject::MainObject() {
    rect.x = 0;
    rect.y = 0;
    NUMBERBULLET = 5;
    fullObject = nullptr;
    angleRotate = 0;
    velocity = 20;
    flip = SDL_FLIP_NONE;
}
void MainObject::HandleInput(SDL_Event event, SDL_Renderer* renderer) {
    //SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
            case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym) {
                    case SDLK_RIGHT: {
                        if(rect.x < WIDTH - rect.w)
                            rect.x += velocity;
                    }
                        break;
                    case SDLK_LEFT:
                       if(rect.x > velocity)
                           rect.x -= velocity;
                        break;
                    case SDLK_UP:
                        if(angleRotate >= -60)
                            angleRotate -= 5;
                        break;
                    case SDLK_DOWN:
                        if(angleRotate <= 60)
                            angleRotate += 5;
                        break;
                    case SDLK_SPACE:
                    {
                        Bullet* newBullet = new Bullet();
                        newBullet->loadObject("ImageSource/bullet1.png",renderer);
                        newBullet->isMove = true;
                        newBullet->rect.x = rect.x + rect.w/2;
                        newBullet->rect.y = rect.y + rect.h/2;
                        newBullet->angle =  (int ) angleRotate ;
                        if(bulletList.size() <= NUMBERBULLET)
                            bulletList.push_back(newBullet);

                        for(int i = 0; i< bulletList.size();i++)
                            if(!bulletList[i]->isMove) {
                                bulletList.erase(bulletList.begin() + i);
                            }
                        break;
                    }
                }
                break;
            }
        }
    }


void MainObject::rotate(SDL_Renderer *renderer) {
    SDL_RenderCopyEx(renderer,fullObject, nullptr,&rect,angleRotate, nullptr,flip);
}

void MainObject::killEnemy( std::vector<ThreatObject *>& planeList, SDL_Renderer* renderer, int& score) {
    for(int i = 0; i < bulletList.size();i++)
    {
       for(int j = 0; j < planeList.size();j++)
       {
           if(SDL_BaseFunction::checkIntersect(planeList[j]->rect,bulletList[i]->rect))
           {
               score++;
               ThreatObject* newThreat = new ThreatObject();
               newThreat->loadObject("ImageSource/planeKilled.png", renderer);
               newThreat->rect.x = planeList[j]->rect.x;
               newThreat->rect.y = planeList[j]->rect.y;
               newThreat->showObject(renderer);
               planeList.erase(planeList.begin()+j);
               bulletList.erase(bulletList.begin() +i);
               delete newThreat;
               break;
           }
       }
    }
}


