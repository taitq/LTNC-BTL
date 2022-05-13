//
// Created by taitq on 27/03/2022.
//

#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H


#include "BaseFunction.h"
#include "BaseObject.h"
#include "ThreatObject.h"
#include "MainObject.h"

void InitWindow(SDL_Window* window, SDL_Renderer* &renderer);
void InitGame(SDL_Renderer* renderer, BaseObject &bgGame, MainObject &rocket);
void InitPlaneList(SDL_Renderer* renderer,std::vector<ThreatObject*> &planeList);
void showPlaneList(SDL_Renderer* renderer,std::vector<ThreatObject*> planeList);
void drawScore(SDL_Renderer * renderer, int score);
bool GameOver(SDL_Renderer* renderer);
bool level1(SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE,int &score, bool &gameOver);
#endif //MAINFUNCTION_H
