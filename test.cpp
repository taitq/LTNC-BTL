//
// Created by taitq on 14/03/2022.
//

#include "PrimaryObject.cpp"
void InitWindow();
int main(int argc, char* argv[])
{
    InitWindow();
    PrimaryObject game;
    game.setImageSource("backGround.jpg");
    game.showObject();
    PrimaryObject tank;
    tank.setImageSource("B52.png");
    tank.showObject();
    SDL_Delay(4000);
}
void InitWindow()
{
    window = SDL_CreateWindow(TTILE_WINDOW.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIDTH_WINDOW,HEIGHT_WINDOW,SDL_WINDOW_SHOWN);
    renderer= SDL_CreateRenderer(window,1,0);
}
