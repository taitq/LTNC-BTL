//
// Created by taitq on 14/03/2022.
//

#include "MainFunction.h"
#include "Intro.h"

using namespace std;
int main(int argc, char* argv[])
{
    srand(time(0));
    vector<EnemyBullet*> enemyBulletList;
    bool gameOver = false;
    int score = 0;
    SDL_Window* window;
    SDL_Renderer* renderer;
    InitWindow(window,renderer);
    BaseObject backGroundIntro;
    vector<SDL_Texture*> text(NUMBER_OPTION, nullptr);
    loadIntro(renderer,backGroundIntro,text);
    SDL_BaseFunction::playAudio("AudioSource/backGroundSound.mp3",-1);
    int option = chooseOption(renderer,backGroundIntro,text);

    if(option == 0)
    {
        SDL_RenderClear(renderer);
        BaseObject bgGame;
        MainObject rocket;
        bool passLevel1 = level1(renderer,bgGame,rocket,enemyBulletList,3,score,gameOver);
        if(passLevel1)
        {
            bool passLevel2 = level2(renderer,bgGame,rocket,enemyBulletList,7,score,gameOver);
            if(passLevel2)
            {
                SDL_RenderClear(renderer);
                bool passLevel3 = level3(renderer,bgGame,rocket,enemyBulletList,4,score,gameOver);
                if(passLevel3) {
                    bool passLevel4 = level4(renderer, bgGame, rocket, enemyBulletList, 4, score, gameOver);
                    if (passLevel4)
                        vitory(renderer);
                }
            }
        }
    }

    return 0;
}
