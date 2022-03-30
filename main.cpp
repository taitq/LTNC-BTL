//
// Created by taitq on 14/03/2022.
//

#include "MainFunction.h"
#include "Intro.h"
using namespace std;
int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    InitGame(window,renderer);

    BaseObject backGround;
    MainObject cannon;
    ThreatObject plane;
    backGround.setRect(0,0);
    cannon.setRect(200,300);
    plane.setRect(200,200);
    cannon.setVelocity(2);
    plane.setVelocity(1);
    SDL_BaseFunction::playAudio("AudioSource/backGroundSound.mp3",0);
    loadFrame(renderer,backGround, plane,cannon);

    BaseObject backGroundIntro;
    backGroundIntro.setRect(0,0);
    loadIntroBackGround(renderer,backGroundIntro);
    int a = chooseOption(renderer,backGroundIntro);
    if(a== 0 )
    {
        showFrame(renderer,backGround, plane,cannon);
        test(renderer,backGround,plane,cannon);
    }
    return 0;
}
