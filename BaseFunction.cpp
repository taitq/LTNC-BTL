//
// Created by taitq on 26/03/2022.
//

#include "BaseFunction.h"

const int WIDTH = 1200;
const int HEIGHT = 700;
const std::string TITLE = "GAME";

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
    SDL_RenderCopy(renderer,srcTexture,NULL,&drect);
}



