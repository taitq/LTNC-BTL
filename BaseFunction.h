//
// Created by taitq on 26/03/2022.
//

#ifndef BASEFUNCTION_H
#define BASEFUNCTION_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <bits/stdc++.h>
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"
#include "Color.h"
    extern const int WIDTH ;
    extern const int HEIGHT ;
    extern const std::string TITLE ;
    extern const int FPS;
    extern const int DELAYTIME;
    namespace SDL_BaseFunction
    {
        SDL_Texture* loadImage(std::string path, SDL_Renderer* renderer);
        void applySurface(SDL_Renderer* renderer, SDL_Texture* srcTexture, int x, int y,int w, int h);
        void playAudio(const std::string& audioSource,int n);
        SDL_Texture* loadText(SDL_Renderer* renderer,std::string text, SDL_Rect rect,SDL_Color color);
        bool checkIntersect(SDL_Rect rect1, SDL_Rect rect2);
    }




#endif //BASEFUNCTION_H
