
#include "PrimaryObject.h"

void InitWindow(SDL_Window* &window);
int main()
{

}
void InitWindow(SDL_Window* & window)
{
    window = SDL_CreateWindow(TTILE_WINDOW.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIDTH_WINDOW,HEIGHT_WINDOW,SDL_WINDOW_SHOWN);
}