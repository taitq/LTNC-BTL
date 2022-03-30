//
// Created by taitq on 29/03/2022.
//

#include "Intro.h"

const int NUMBER_OPTION = 3;

vector<SDL_Rect> setRectOption()
{
    std::vector<SDL_Rect> option(NUMBER_OPTION);
    option[0].y = 250;
    option[0].x = 500;
    option[0].h = 100;
    option[0].w = 300;
    for(int i = 1 ; i < NUMBER_OPTION;i++) {
        option[i].x = 500;
        option[i].y = option[i-1].y + 101;
        option[i].w = 300;
        option[i].h = 100;
    }
    return option;
}
void loadIntro(SDL_Renderer* renderer,BaseObject &backGroundIntro,  vector<SDL_Texture*> &text)
{
    std::vector<SDL_Rect > option (NUMBER_OPTION);
    option = setRectOption();
    backGroundIntro.loadObject("ImageSource/lobby.jpg",renderer);
    backGroundIntro.rect.w = WIDTH;
    backGroundIntro.rect.h = HEIGHT;
    text[0] = SDL_BaseFunction::loadText(renderer,"PLAY ",option[0],RED);
    text[1] = SDL_BaseFunction::loadText(renderer,"HISTORY " ,option[1], RED );
    text[2] = SDL_BaseFunction::loadText(renderer, "EXIT ", option[2],RED);

}
void showIntro(SDL_Renderer* renderer,BaseObject backGroundIntro, const vector<SDL_Texture*> &text)
{
    std::vector<SDL_Rect > option (NUMBER_OPTION);
    option = setRectOption();
    backGroundIntro.showObject(renderer);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    for(int i = 0; i < NUMBER_OPTION;i++ )
        SDL_RenderCopy(renderer,text[i],NULL,&option[i]);
}
void showChoice(SDL_Renderer* renderer,BaseObject backGroundIntro, const vector<SDL_Texture*> &text,int k)
{
    std::vector<SDL_Rect > option (NUMBER_OPTION);
    option = setRectOption();
    backGroundIntro.showObject(renderer);
    SDL_SetRenderDrawColor(renderer, 125, 125, 125, 255);
    SDL_RenderFillRect(renderer, &option[k]);
    for(int i = 0; i < NUMBER_OPTION;i++ )
        SDL_RenderCopy(renderer,text[i],NULL,&option[i]);
}
int chooseOption(SDL_Renderer* renderer, BaseObject &backGroundIntro, const vector<SDL_Texture*> &text)
{
    showIntro(renderer,backGroundIntro,text);
    SDL_RenderPresent(renderer);
    SDL_BaseFunction::playAudio("AudioSource/backGroundSound.mp3",0);
    SDL_Point mouse;
    SDL_Event event;
    std::vector<SDL_Rect > option (NUMBER_OPTION);
    option = setRectOption();
    while(event.type!= SDL_QUIT)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEMOTION:
                mouse.x = event.motion.x;
                mouse.y = event.motion.y;
                if(SDL_PointInRect(&mouse,&option[0])) {
                    showChoice(renderer, backGroundIntro, text, 0);
                    SDL_RenderPresent(renderer);
                }
                else if (SDL_PointInRect(&mouse,&option[1])) {
                    showChoice(renderer, backGroundIntro, text, 1);
                    SDL_RenderPresent(renderer);
                }
                else if (SDL_PointInRect(&mouse,&option[2])) {
                    showChoice(renderer, backGroundIntro, text, 2);
                    SDL_RenderPresent(renderer);
                }
                else {
                    showIntro(renderer, backGroundIntro, text);
                    SDL_RenderPresent(renderer);
                }

                break;

            case SDL_MOUSEBUTTONDOWN:
                mouse.x = event.motion.x;
                mouse.y = event.motion.y;
                for(int i = 0 ; i < NUMBER_OPTION;i++)
                {
                    if(SDL_PointInRect(&mouse,&option[i]))
                        return i;
                }
                break;
        }

    }
}