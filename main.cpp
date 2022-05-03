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
    ThreatObject plane,planeKilled;
    backGround.setRect(0,0);
    cannon.setRect(300,500);
    plane.setRect(200,200);
    cannon.setVelocity(10);
    plane.setVelocity(10);
    planeKilled.setVelocity(10);
    SDL_BaseFunction::playAudio("AudioSource/backGroundSound.mp3",-1);
    loadFrame(renderer,backGround, plane,cannon,planeKilled);
    BaseObject backGroundIntro;
    backGroundIntro.setRect(0,0);
    vector<SDL_Texture*> text(NUMBER_OPTION, nullptr);
    loadIntro(renderer,backGroundIntro,text);
    int a = chooseOption(renderer,backGroundIntro,text);
    if(a == 0 )
    {
        showFrame(renderer,backGround, plane,cannon,planeKilled);
        test(renderer,backGround,plane,cannon,planeKilled);
    }

    return 0;
}
