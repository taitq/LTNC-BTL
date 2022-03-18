//
// Created by taitq on 17/03/2022.
//

#include "BaseFunction.h"

 SDL_Window* window = nullptr;
 SDL_Renderer* renderer = nullptr;

void initWindow()
{
        window = SDL_CreateWindow(TTILE_WINDOW.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIDTH_WINDOW,HEIGHT_WINDOW,SDL_WINDOW_SHOWN);
        renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        Mix_OpenAudio(33000,MIX_DEFAULT_FORMAT,2,2048);
}

bool quitGame()
{
    SDL_Event event;
    while (SDL_WaitEvent(&event) != 0 && event.type != SDL_QUIT) {
        SDL_Delay(10);
    }
    return true;
}

SDL_Texture *loadImage(std::string imageSource) {
    SDL_Texture* texture = nullptr;
    SDL_Surface* surface = IMG_Load(imageSource.c_str());
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if(texture == nullptr )
        std::cout<< IMG_GetError()<< "Error load Image "<<imageSource<<std::endl;
    SDL_FreeSurface(surface);
    return texture;
}
