//
// Created by taitq on 27/03/2022.
//

#include "MainFunction.h"


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
}
void showPlaneList(SDL_Renderer* renderer,std::vector<ThreatObject*> planeList)
{
    for(int i = 0; i < planeList.size();i++)
    {
        planeList[i]->showObject(renderer);
    }
}
void drawScore(SDL_Renderer * renderer, int score)
{
    SDL_Rect r;
    r.x = 500;
    r.y = 100;
    r.h = 100;
    r.w = 100;
    SDL_Texture*  t = SDL_BaseFunction::loadText(renderer, std::to_string(score),r,RED);
    SDL_RenderCopy(renderer,t,NULL,&r);
}

