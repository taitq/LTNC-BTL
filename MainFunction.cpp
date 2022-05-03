//
// Created by taitq on 27/03/2022.
//

#include "MainFunction.h"

int score = 0;
void InitGame(SDL_Window* window, SDL_Renderer* &renderer)
{
    window = SDL_CreateWindow(TITLE.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,1,0);
    Mix_OpenAudio(3300,MIX_DEFAULT_FORMAT,2,2048);
    TTF_Init();
}
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
        score++;
    }
    SDL_Rect r;
    r.x = 500;
    r.y = 100;
    r.h = 100;
    r.w = 100;
    SDL_Texture*  t = SDL_BaseFunction::loadText(renderer, std::to_string(score),r,RED);
    SDL_RenderCopy(renderer,t,NULL,&r);
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
        cannon.HandleInput(event,renderer);
        cannon.turn(renderer);
        if(cannon.bullet.isMove)
            cannon.bullet.move();
        plane.move();
        showFrame(renderer,backGround,plane,cannon,planeKilled);
    }
}