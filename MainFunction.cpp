//
// Created by taitq on 27/03/2022.
//

#include "MainFunction.h"


void InitWindow(SDL_Window* window, SDL_Renderer* &renderer)
{
    window = SDL_CreateWindow(TITLE.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,1,0);
    Mix_OpenAudio(3300,MIX_DEFAULT_FORMAT,2,2048);
    TTF_Init();
}

void InitGame(SDL_Renderer* renderer, BaseObject &bgGame, MainObject &rocket)
{
    bgGame.loadObject("ImageSource/bg.jpg",renderer);
    bgGame.rect.w = WIDTH;
    bgGame.rect.h = HEIGHT;
    rocket.loadObject("ImageSource/SAM2.png",renderer);
    rocket.rect.x = WIDTH/2;
    rocket.rect.y = HEIGHT - rocket.rect.h;
}

void InitPlaneList(SDL_Renderer * renderer, std::vector<ThreatObject*> &planeList)
{
  ThreatObject* newPlane = new ThreatObject();
  newPlane->loadObject("ImageSource/B52.png",renderer);
  planeList.push_back(newPlane);
}

void showPlaneList(SDL_Renderer* renderer,std::vector<ThreatObject*> planeList)
{
    for(int i = 0; i < planeList.size();i++)
    {
        planeList[i]->showObject(renderer);
    }
}
void drawScore(SDL_Renderer * renderer, int score)
{
    SDL_Rect r;
    r.x = 500;
    r.y = 100;
    r.h = 100;
    r.w = 100;
    SDL_Texture*  t = SDL_BaseFunction::loadText(renderer, std::to_string(score),r,RED);
    SDL_RenderCopy(renderer,t,NULL,&r);
}

bool GameOver(SDL_Renderer* renderer)
{
    BaseObject Defeat;
    BaseObject bgGame;
    bgGame.loadObject("ImageSource/bg.jpg",renderer);
    bgGame.rect.w = WIDTH;
    bgGame.rect.h = HEIGHT;
    Defeat.loadObject("ImageSource/Defeat.jpg",renderer);
    Defeat.rect.x = 450;
    Defeat.rect.y = 150;
    Defeat.showObject(renderer);
    std::vector<SDL_Rect> rect(2);
    rect[0].x = 650;
    rect[0].y = 250;
    rect[0].w = 200;
    rect[0].h = 100;
    rect[1].x = 650;
    rect[1].y = 350;
    rect[1].w = 200;
    rect[1].h= 100;
    std::vector<SDL_Texture*> text(2);
    text[0] = SDL_BaseFunction::loadText(renderer,"PLAY AGAIN",rect[0], BLACK);
    text[1] = SDL_BaseFunction::loadText(renderer,"EXIT", rect[1], BLACK);
    for(int i = 0; i < text.size();i++)
        SDL_RenderCopy(renderer,text[i], nullptr,&rect[i]);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    SDL_Point mouse;
    while (event.type != SDL_QUIT)
    {
        SDL_PollEvent(&event);
        switch (event.type ) {
            case SDL_MOUSEMOTION:
                mouse.x = event.motion.x;
                mouse.y = event.motion.y;
                if(SDL_PointInRect(&mouse,&rect[0])) {
                    bgGame.showObject(renderer);
                    Defeat.showObject(renderer);
                    SDL_SetRenderDrawColor(renderer,125,125,125,255);
                    SDL_RenderFillRect(renderer,&rect[0]);
                    SDL_RenderCopy(renderer,text[0], nullptr,&rect[0]);
                    SDL_RenderCopy(renderer,text[1], nullptr,&rect[1]);
                }
                else if(SDL_PointInRect(&mouse,&rect[1])) {
                    bgGame.showObject(renderer);
                    Defeat.showObject(renderer);
                    SDL_SetRenderDrawColor(renderer,125,125,125,255);
                    SDL_RenderFillRect(renderer,&rect[1]);
                    SDL_RenderCopy(renderer,text[1], nullptr,&rect[1]);
                    SDL_RenderCopy(renderer,text[0], nullptr,&rect[0]);
                }
                else
                {
                  bgGame.showObject(renderer);
                  Defeat.showObject(renderer);
                  for(int i = 0; i < text.size();i++)
                        SDL_RenderCopy(renderer,text[i], nullptr,&rect[i]);
                }
                SDL_RenderPresent(renderer);
                SDL_RenderClear(renderer);
                break;
            case  SDL_MOUSEBUTTONDOWN:
                mouse.x = event.motion.x;
                mouse.y = event.motion.y;
                for(int i = 0 ; i < 2;i++)
                {
                    if(SDL_PointInRect(&mouse,&rect[i]))
                        return i;
                }
                break;
        }
    }

}
void IntroLevel(SDL_Renderer* renderer, const std::string& pathToBackgroundIntroLevel)
{
    BaseObject IntroLevel;
    IntroLevel.loadObject(pathToBackgroundIntroLevel,renderer);
    IntroLevel.rect.h = HEIGHT;
    IntroLevel.rect.w = WIDTH;
    IntroLevel.showObject(renderer);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    while (event.type != SDL_QUIT && event.key.keysym.sym != SDLK_SPACE )
    {
        SDL_PollEvent(&event);
        SDL_Delay(10);
    }
    SDL_RenderClear(renderer);
    if(event.type == SDL_QUIT)
        exit(0);
}

void LogicGame(SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE,int &score, bool &gameOver)
{
    std::vector<ThreatObject*> planeList;
    for(int i = 0; i < NUMBERPLANE; i++)
        InitPlaneList(renderer,planeList);
    InitGame(renderer,bgGame,rocket); // khoi tao man hinh game va ten lua sam2
    SDL_Event event;

    while( event.type != SDL_QUIT  )
    {
        SDL_PollEvent(&event);
        bgGame.showObject(renderer);
        showPlaneList(renderer,planeList);
        if(planeList.size() < NUMBERPLANE)
            InitPlaneList(renderer,planeList);
        for(int i = 0; i < rocket.bulletList.size();i++)
        {
            if(rocket.bulletList[i]->isMove)
            {
                rocket.bulletList[i]->move();
                SDL_RenderCopyEx(renderer,rocket.bulletList[i]->fullObject, nullptr,&rocket.bulletList[i]->rect,rocket.bulletList[i]->angle,NULL,SDL_FLIP_NONE);
            }
        }
        for(int  i = 0; i < planeList.size();i++) {
            planeList[i]->move(renderer);
            planeList[i]->attack(renderer,enemyBulletList);
        }
        for(int i = 0; i < enemyBulletList.size();i++)
        {
            if(enemyBulletList[i]->isMove)
                enemyBulletList[i]->move();
            else
                enemyBulletList.erase(enemyBulletList.begin()+i);
            if(SDL_BaseFunction::checkIntersect(enemyBulletList[i]->rect,rocket.rect))
            {
                enemyBulletList.erase(enemyBulletList.begin()+i);
                rocket.loadObject("ImageSource/planeKilled.png",renderer);
                rocket.showObject(renderer);
                SDL_RenderPresent(renderer);
                SDL_Delay(1000);
                gameOver = true;
                GameOver(renderer);
                return;
            }
            enemyBulletList[i]->showObject(renderer);
        }
        rocket.HandleInput(event, renderer);
        if(!rocket.bulletList.empty())
            rocket.killEnemy(planeList, renderer,score);
        drawScore(renderer,score);
        rocket.rotate(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(DELAYTIME);
        SDL_RenderClear(renderer);
    }
}
bool level1 (SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList, const int NUMBERPLANE, int &score, bool &gameOver)
{
    IntroLevel(renderer,"ImageSource/IntroLevel1.png");
    LogicGame(renderer,bgGame,rocket,enemyBulletList,NUMBERPLANE,score,gameOver);
    return gameOver;

}
