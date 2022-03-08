#include <iostream>
#include <SDL2/SDL.h>


using namespace std;

const string TITLE = "Game ban may bay";
const int HEIGHT = 600;
const int WIDTH = 1000;

void InitWindow(SDL_Window* &window);
int main()
{
    SDL_Window* window;
    InitWindow(window);
    SDL_Delay(2000);
}
void InitWindow(SDL_Window* & window)
{
    window = SDL_CreateWindow(TITLE.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
}