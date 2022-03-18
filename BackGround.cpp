//
// Created by taitq on 15/03/2022.
//

#include "BackGround.h"

void BackGround::showObject() {
    SDL_Texture* texture = loadImage(imageSource);
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
}
