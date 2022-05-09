//
// Created by taitq on 27/03/2022.
//

#include "MainObject.h"
#include "Bullet.h"
MainObject::MainObject() {
    rect.x = 0;
    rect.y = 0;
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
                        for(int i = 0; i < velocity;i++ )
                        {
                            rect.x++;
                            SDL_RenderCopyEx(renderer,fullObject, nullptr,&rect,angleRotate, nullptr,flip);
                        }
                    }
                        break;
                    case SDLK_LEFT:
                        for(int i = 0; i < velocity;i++ )
                        {
                            rect.x--;
                            SDL_RenderCopyEx(renderer,fullObject, nullptr,&rect,angleRotate, nullptr,flip);
                        }
                        break;
                    case SDLK_UP:
                        if(angleRotate >= -60)
                            angleRotate -= 15;
                        break;
                    case SDLK_DOWN:
                        if(angleRotate <= 60)
                            angleRotate += 15;
                        break;
                    case SDLK_SPACE:
                    {
                        Bullet* newBullet = new Bullet();
                        newBullet->loadObject("ImageSource/bullet1.png",renderer);
                        newBullet->isMove = true;
                        newBullet->rect.x = rect.x + rect.w/2;
                        newBullet->rect.y = rect.y + rect.h/2;
                        newBullet->angle =  (int ) angleRotate ;
                        if(bulletList.size() <= 5)
                            bulletList.push_back(newBullet);

                        for(int i = 0; i< bulletList.size();i++)
                            if(!bulletList[i]->isMove) {
                                delete bulletList[i];
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


