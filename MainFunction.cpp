//
// Created by taitq on 27/03/2022.
//

#include "MainFunction.h"


void InitGame(SDL_Window* window, SDL_Renderer* &renderer)
{
    window = SDL_CreateWindow(TITLE.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,1,0);
    Mix_OpenAudio(3300,MIX_DEFAULT_FORMAT,2,2048);
    TTF_Init();
}
void loadFrame(SDL_Renderer* renderer,BaseObject &backGround, ThreatObject &plane, MainObject &cannon)
{
    backGround.loadObject("ImageSource/backGround.jpg",renderer);
    backGround.rect.w = WIDTH;
    backGround.rect.h = HEIGHT;
    cannon.loadObject("ImageSource/cannon1.png",renderer);
    plane.loadObject("ImageSource/B52.png",renderer);
}
void showFrame(SDL_Renderer* renderer,BaseObject backGround, ThreatObject plane, MainObject cannon)
{
        backGround.showObject(renderer);
        cannon.showObject(renderer);
        plane.showObject(renderer);
        SDL_RenderPresent(renderer);
}


void test(SDL_Renderer* renderer,BaseObject backGround, ThreatObject plane, MainObject cannon)
{
    SDL_Event event;
    showFrame(renderer,backGround,plane,cannon);
    while(event.type!= SDL_QUIT)
    {
        SDL_PollEvent(&event);
        SDL_RenderClear(renderer);
        cannon.HandleInput(event);
        plane.move();
        showFrame(renderer,backGround,plane,cannon);
    }
}