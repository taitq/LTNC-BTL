//
// Created by taitq on 29/03/2022.
//

#ifndef INTRO_H
#define INTRO_H

#include "BaseObject.h"

using namespace std;
extern const int NUMBER_OPTION ;

vector<SDL_Rect> setRectOption();
void loadIntroBackGround(SDL_Renderer* renderer,BaseObject &backGroundIntro);
void showIntro(SDL_Renderer* renderer,BaseObject backGroundIntro);
int chooseOption(SDL_Renderer* renderer,BaseObject &backGroundIntro);


void renderOption(SDL_Renderer* renderer);



#endif //INTRO_H
