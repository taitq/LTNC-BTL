//
// Created by taitq on 27/03/2022.
//

#include "MainFunction.h"

int score = 0;
bool killed = false;
void InitWindow(SDL_Window* window, SDL_Renderer* &renderer)
{
    window = SDL_CreateWindow(TITLE.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,1,0);
    Mix_OpenAudio(3300,MIX_DEFAULT_FORMAT,2,2048);
    TTF_Init();
}
void InitGame(SDL_Renderer* renderer, BaseObject &bgGame, MainObject &rocket)
{
    bgGame.loadObject("ImageSource/bg.jpg",renderer);
    bgGame.rect.w = WIDTH;
    bgGame.rect.h = HEIGHT;
    rocket.loadObject("ImageSource/SAM2.png",renderer);
    rocket.rect.x = WIDTH/2;
    rocket.rect.y = HEIGHT - rocket.rect.h;
}

void InitPlaneList(SDL_Renderer * renderer, std::vector<ThreatObject*> &planeList)
{
  ThreatObject* newPlane = new ThreatObject();
  newPlane->loadObject("ImageSource/B52.png",renderer);
  planeList.push_back(newPlane);
  /*if(planeList[planeList.size()-1]->fullObject == nullptr)
    std::cout<<"error"<<std::endl;
  std::cout<<planeList[planeList.size()-1]->rect.x<<"  "<<planeList[planeList.size()-1]->rect.y<< std::endl;*/
}
void showPlaneList(SDL_Renderer* renderer,std::vector<ThreatObject*> planeList)
{
    for(int i = 0; i < planeList.size();i++)
    {
        planeList[i]->showObject(renderer);
    }
}
void drawScore(SDL_Renderer * renderer)
{
    SDL_Rect r;
    r.x = 500;
    r.y = 100;
    r.h = 100;
    r.w = 100;
    SDL_Texture*  t = SDL_BaseFunction::loadText(renderer, std::to_string(score),r,RED);
    SDL_RenderCopy(renderer,t,NULL,&r);
}


/*
void loadFrame(SDL_Renderer* renderer,BaseObject &backGround, ThreatObject &plane, MainObject &cannon, ThreatObject &planeKilled)
{
    backGround.loadObject("ImageSource/bg.jpg",renderer);
    backGround.rect.w = WIDTH;
    backGround.rect.h = HEIGHT;
    cannon.bullet.loadObject("ImageSource/bullet1.png",renderer);
    cannon.loadObject("ImageSource/SAM2.png",renderer);
    planeKilled.loadObject("ImageSource/planeKilled.png",renderer);
    plane.loadObject("ImageSource/B52.png",renderer);
}
void showFrame(SDL_Renderer* renderer,BaseObject backGround, ThreatObject plane, MainObject cannon,ThreatObject planeKilled)
{
    backGround.showObject(renderer);
    cannon.turn(renderer);
    cannon.bullet.isMove = true;
    if(cannon.bullet.isMove && cannon.bullet.rect.y > 0 )
        cannon.bullet.showObject(renderer);
    if(!SDL_BaseFunction::checkIntersect(plane.rect,cannon.bullet.rect))
        plane.showObject(renderer);
    else {
        planeKilled.setRect(plane.rect.x,plane.rect.y);
        planeKilled.showObject(renderer);
        SDL_Delay(DELAYTIME);
        plane.rect.x = 100;
        plane.rect.y = 100;
        score++;
        killed = true;
    }
    drawScore(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(DELAYTIME);
}

void test(SDL_Renderer* renderer,BaseObject backGround, ThreatObject plane, MainObject cannon,ThreatObject planeKilled)
{
    SDL_Event event;
    showFrame(renderer,backGround,plane,cannon,planeKilled);
    //std::cout<<plane.rect.w<<" "<<plane.rect.h<<std::endl<<cannon.bullet.rect.w<<" "<<cannon.bullet.rect.h;
    while(event.type!= SDL_QUIT)
    {
        SDL_PollEvent(&event);
        SDL_RenderClear(renderer);
        cannon.HandleInput(event);
        cannon.turn(renderer);
        if(cannon.bullet.isMove)
            cannon.bullet.move();
        plane.move();
        showFrame(renderer,backGround,plane,cannon,planeKilled);
    }
}*/
