//
// Created by taitq on 14/03/2022.
//

#include "BaseFunction.h"
#include "BaseObject.h"

using namespace std;
int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    window = SDL_CreateWindow(TITLE.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,1,0);

}
