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
    InitWindow(window,renderer); // khoi tao cua so game

    BaseObject backGroundIntro;
    vector<SDL_Texture*> text(NUMBER_OPTION, nullptr);
    loadIntro(renderer,backGroundIntro,text);

    SDL_BaseFunction::playAudio("AudioSource/backGroundSound.mp3",-1); // nhac nen

    int option = chooseOption(renderer,backGroundIntro,text);

    // cac lua chon trong game


    if(option == 0)
    {
        SDL_RenderClear(renderer);
        BaseObject bgGame;
        MainObject rocket;
        level1(renderer,bgGame,rocket,enemyBulletList,3,score, gameOver);
    }
    return 0;
}
