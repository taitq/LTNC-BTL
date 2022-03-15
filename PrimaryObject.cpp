//
// Created by taitq on 09/03/2022.
//

#include "PrimaryObject.h"

SDL_Texture *PrimaryObject::loadImage() {
    SDL_Texture* texture = nullptr;
    SDL_Surface* surface = IMG_Load(ImageSource.c_str());
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    return texture;
}
void PrimaryObject::showObject() {

    SDL_RenderCopy(renderer,loadImage(),NULL,NULL);
    SDL_RenderPresent(renderer);
}
