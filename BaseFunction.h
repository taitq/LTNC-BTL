//
// Created by taitq on 17/03/2022.
//

#ifndef MAIN_CPP_BASEFUNCTION_H
#define MAIN_CPP_BASEFUNCTION_H

#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "Color.h"

extern SDL_Window* window;
extern SDL_Renderer* renderer;
const  int WIDTH_WINDOW = 1300;
const  int HEIGHT_WINDOW = 800;
const  std::string TTILE_WINDOW = "GAME";


void loadText(std::string text, SDL_Rect rect,SDL_Color color);
void initWindow();
bool quitGame();
SDL_Texture* loadImage(std:: string imageSource);

#endif //MAIN_CPP_BASEFUNCTION_H
