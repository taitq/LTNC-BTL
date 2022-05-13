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
    BaseObject picture;
    picture.loadObject("ImageSource/picture.jpg",renderer);
    picture.rect.x = 400;
    picture.rect.y = 150;
    picture.showObject(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(1000);

}

bool level1 (SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList, const int NUMBERPLANE, int &score, bool &gameOver)
{
    BaseObject IntroBackGroundLevel1;

    IntroBackGroundLevel1.loadObject("ImageSource/IntroLevel1.png",renderer);

    IntroBackGroundLevel1.rect.h = HEIGHT;
    IntroBackGroundLevel1.rect.w = WIDTH;

    IntroBackGroundLevel1.showObject(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
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
                break;
            }
            enemyBulletList[i]->showObject(renderer);
        }
        if(gameOver) {
            GameOver(renderer);
            SDL_RenderPresent(renderer);
            SDL_Delay(500);
            exit(0);
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