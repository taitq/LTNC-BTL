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
int GameOver(SDL_Renderer* renderer);
void reset(MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList,int &score,bool &gameOver);
void win(SDL_Renderer* renderer);
void IntroLevel(SDL_Renderer* renderer, const std::string& pathToBackgroundIntroLevel);
void LogicGame(SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE,int &score,int target, bool &gameOver);
void LogicGame2(SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket, std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE,int &score,int target, bool &gameOver,std::vector<std::string> PathToImage );
bool level1( SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE,int &score, bool &gameOver);
bool level2( SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE,int &score, bool &gameOver);
bool level3(SDL_Renderer* renderer, BaseObject bgGame, MainObject& rocket, std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE, int &score,  bool &gameOver);
bool level4(SDL_Renderer* renderer, BaseObject bgGame , MainObject& rocket, std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE, int &score,  bool &gameOver);
void vitory(SDL_Renderer* renderer);
#endif //MAINFUNCTION_H
