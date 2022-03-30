//
// Created by taitq on 29/03/2022.
//

#ifndef INTRO_H
#define INTRO_H

#include "BaseObject.h"

using namespace std;
extern const int NUMBER_OPTION ;

vector<SDL_Rect> setRectOption();
void loadIntro(SDL_Renderer* renderer,BaseObject &backGroundIntro,  vector<SDL_Texture*> &text);
void showIntro(SDL_Renderer* renderer,BaseObject backGroundIntro, const vector<SDL_Texture*> &text);
void showChoice(SDL_Renderer* renderer,BaseObject backGroundIntro, const vector<SDL_Texture*> &text,int k);
int chooseOption(SDL_Renderer* renderer,BaseObject &backGroundIntro, const vector<SDL_Texture*> &text);




#endif //INTRO_H
