//
// Created by taitq on 27/03/2022.
//

#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H

#include "BaseFunction.h"
#include "BaseObject.h"
#include "ThreatObject.h"
#include "MainObject.h"

void InitGame(SDL_Window* window, SDL_Renderer* &renderer);
void loadFrame(SDL_Renderer* renderer,BaseObject &backGround, ThreatObject &plane, MainObject &cannon,ThreatObject &planeKilled);
void showFrame(SDL_Renderer* renderer, BaseObject backGround,ThreatObject plane, MainObject cannon, ThreatObject planeKilled);
void test(SDL_Renderer* renderer, BaseObject backGround, ThreatObject plane, MainObject cannon, ThreatObject planeKilled);
#endif //MAINFUNCTION_H
