//
// Created by taitq on 18/03/2022.
//

#include "Lobby.h"

int NUMBEROPTION = 3;

std::vector<SDL_Rect> setRectOption()
{
    std::vector<SDL_Rect> option(NUMBEROPTION);
    option[0].y = 250;
    option[0].x = 500;
    option[0].h = 100;
    option[0].w = 300;
    for(int i = 1 ; i < NUMBEROPTION;i++) {
        option[i].x = 500;
        option[i].y = option[i-1].y + 101;
        option[i].w = 300;
        option[i].h = 100;
    }
    return option;
}

void showOption() {
    std::vector<SDL_Rect > option (NUMBEROPTION);
    option = setRectOption();
    BackGround lobby;
    lobby.setImageSource("ImageSource/lobby.jpg");
    lobby.showObject();
    SDL_SetRenderDrawColor(renderer,0,0,255,0);
    for(int i = 0; i < NUMBEROPTION; i++)
        SDL_RenderDrawRect(renderer,&option[i]);
    loadText("PLAY",option[0],RED);
    loadText("EXIT", option[1],RED);
    SDL_RenderPresent(renderer);
}
void LobbyChooseOption() {
    showOption();
    SDL_Event event;
    SDL_Point mouse;
    bool quit = false;
    std::vector<SDL_Rect > option (NUMBEROPTION);
    option = setRectOption();
    while(!quit)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                quit = true;
                exit(0);
            case SDL_MOUSEMOTION:
                mouse.x = event.motion.x;
                mouse.y = event.motion.y;
                for(int i = 0; i < NUMBEROPTION;i++)
                {
                    if(SDL_PointInRect(&mouse,&option[i])) {
                        showOption();
                        SDL_SetRenderDrawColor(renderer, 125, 125, 125, 255);
                        SDL_RenderFillRect(renderer, &option[i]);
                        if(i == 0)
                            loadText("PLAY",option[i],RED);
                        if(i== 1)
                            loadText("EXIT",option[1],RED);

                        SDL_RenderPresent(renderer);
                    }

                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                mouse.x = event.motion.x;
                mouse.y = event.motion.y;
               if(SDL_PointInRect(&mouse,&option[0]))
                   quit = true;
                if(SDL_PointInRect(&mouse,&option[1] ))
                {
                    quit = true;
                    exit(0);
                }
                break;
        }
    }
}






