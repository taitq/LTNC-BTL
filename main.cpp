//
// Created by taitq on 14/03/2022.
//

#include "MainFunction.h"

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
    loadFrame(renderer,backGround, plane,cannon);
    showFrame(renderer,backGround, plane,cannon);
    test(renderer,backGround,plane,cannon);
}
