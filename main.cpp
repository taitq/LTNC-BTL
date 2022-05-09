//
// Created by taitq on 14/03/2022.
//

#include "MainFunction.h"
#include "Intro.h"

const int NUMBERPLANE = 5;
using namespace std;
int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    BaseObject bgGame;
    InitWindow(window,renderer); // khoi tao cua so game
    BaseObject backGroundIntro;  // khoi tao background intro
    backGroundIntro.setRect(0,0);
    MainObject rocket;
    // cac lua chon trong game
    vector<SDL_Texture*> text(NUMBER_OPTION, nullptr);
    loadIntro(renderer,backGroundIntro,text);
    SDL_BaseFunction::playAudio("AudioSource/backGroundSound.mp3",-1); // nhac nen
    int option = chooseOption(renderer,backGroundIntro,text);

    if(option == 0)
    {
        vector<ThreatObject*> planeList;
        for(int i = 0; i < NUMBERPLANE; i++)
            InitPlaneList(renderer,planeList);
        InitGame(renderer,bgGame,rocket); // khoi tao man hinh game va ten lua sam2
        SDL_Event event;

        while( event.type != SDL_QUIT  )
        {
            SDL_PollEvent(&event);
            bgGame.showObject(renderer);
            showPlaneList(renderer,planeList);
            for(int i = 0; i < rocket.bulletList.size();i++)
            {
                if(rocket.bulletList[i]->isMove)
                {
                    rocket.bulletList[i]->move();
                    SDL_RenderCopyEx(renderer,rocket.bulletList[i]->fullObject, nullptr,&rocket.bulletList[i]->rect,rocket.bulletList[i]->angle,NULL,SDL_FLIP_NONE);
                }
            }

            for(int  i = 0; i < planeList.size();i++)
                planeList[i]->move();

            rocket.HandleInput(event, renderer);
            rocket.rotate(renderer);
            SDL_RenderPresent(renderer);
            SDL_Delay(DELAYTIME);
            SDL_RenderClear(renderer);
        }

    }
    /*MainObject sam;

    ThreatObject plane,planeKilled;
    backGround.setRect(0,0);
    sam.setRect(300,500);
    plane.setRect(200,200);
    sam.setVelocity(10);


    loadFrame(renderer,backGround, plane,sam,planeKilled);


    if(a == 0 )
    {
        showFrame(renderer,backGround, plane,sam,planeKilled);
        test(renderer,backGround,plane,sam,planeKilled);
    }*/

    return 0;
}
