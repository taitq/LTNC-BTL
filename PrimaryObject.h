//
// Created by taitq on 09/03/2022.
//

#ifndef MAIN_CPP_PRIMARYOBJECT_H
#define MAIN_CPP_PRIMARYOBJECT_H

#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

const int WIDTH_WINDOW = 1000;
const int HEIGHT_WINDOW = 600;
const std::string TTILE_WINDOW = "GAME";
static SDL_Window* window;
static SDL_Renderer* renderer;

class PrimaryObject {
    private:
        std::string ImageSource;
        std::string AudioSource;
        SDL_Rect drect;
    public:
        void setImageSource(std::string nameSource)
        {
            ImageSource =nameSource;
        }
        void setAudioSource(std:: string nameSource)
        {
            AudioSource = nameSource;
        }
        void setDrect(SDL_Rect rect)
        {
            drect = rect;
        }
        SDL_Texture* loadImage();
        void showObject();
};


#endif //MAIN_CPP_PRIMARYOBJECT_H
