//
// Created by taitq on 26/03/2022.
//

#include "BaseFunction.h"

const int WIDTH = 1300;
const int HEIGHT = 800;
const std::string TITLE = "GAME";
const int FPS = 60;
const int DELAYTIME = 1000.0f/FPS;

SDL_Texture* SDL_BaseFunction::loadImage(std::string path, SDL_Renderer *renderer) {
   SDL_Surface* surface = IMG_Load(path.c_str());
   SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
   SDL_FreeSurface(surface);
   return texture;
}

void SDL_BaseFunction::applySurface(SDL_Renderer *renderer, SDL_Texture *srcTexture, int x, int y, int w, int h) {
    SDL_Rect drect;
    drect.x = x;
    drect.y = y;
    drect.w = w;
    drect.h = h;
    SDL_RenderCopy(renderer, srcTexture, NULL, &drect);
}

void SDL_BaseFunction::playAudio(const std::string& audioSource,int n)
{
    Mix_Chunk * chunk = nullptr;
    chunk = Mix_LoadWAV(audioSource.c_str());
    if(chunk == nullptr)
        std::cout<<Mix_GetError()<<"Can't load file "<< audioSource<<std::endl;
    else
        Mix_PlayChannel(-1,chunk,n);
}

SDL_Texture* SDL_BaseFunction::loadText(SDL_Renderer *renderer, std::string text, SDL_Rect rect, SDL_Color color)
{
    TTF_Font* font = nullptr;
    font = TTF_OpenFont("FontSource/VeraMoBd.ttf", 100);
    if(font == nullptr)
        std::cout<<TTF_GetError()<<std::endl;
    SDL_Surface * surface = TTF_RenderText_Solid(font,text.c_str(),color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    return  texture;
}
bool  SDL_BaseFunction::checkIntersect(SDL_Rect rect1, SDL_Rect rect2) {
    return (rect1.x + 65 >= rect2.x  && rect2.x + rect2.w >= rect1.x + 35 && rect1.y + rect1.h >= rect2.y + 60  && rect2.y +  141 >= rect1.y);

}