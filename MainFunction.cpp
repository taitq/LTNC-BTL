//
// Created by taitq on 27/03/2022.
//

#include "MainFunction.h"


void InitWindow(SDL_Window* window, SDL_Renderer* &renderer)
{
    window = SDL_CreateWindow(TITLE.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,1,0);
    Mix_OpenAudio(44300,MIX_DEFAULT_FORMAT,1,2048);
    TTF_Init();
}

void InitGame(SDL_Renderer* renderer, BaseObject &bgGame, MainObject &rocket)
{
    bgGame.loadObject("ImageSource/bg.jpg",renderer);
    bgGame.rect.w = WIDTH;
    bgGame.rect.h = HEIGHT;
    rocket.loadObject("ImageSource/MIG15.png",renderer);
    rocket.rect.x = WIDTH/2;
    rocket.rect.y = HEIGHT - rocket.rect.h;
}

void InitPlaneList(SDL_Renderer * renderer, std::vector<ThreatObject*> &planeList)
{
  ThreatObject* newPlane = new ThreatObject();
  int type = rand()%3;
  if(type == 1)
    newPlane->loadObject("ImageSource/B52_1.png",renderer);
  if(type == 2)
      newPlane->loadObject("ImageSource/B52_2.png",renderer);
  if(type == 0)
      newPlane->loadObject("ImageSource/B52_0.png",renderer);
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
    SDL_Rect rect1,rect2;
    rect2.x = 1170;
    rect2.y = 100;
    rect2.h = 70;
    rect2.w = 70;
    rect1.x = 1100;
    rect1.y = 0;
    rect1.h = 100;
    rect1.w = 180;
    SDL_Texture* scoreText = SDL_BaseFunction::loadText(renderer,"SCORE",rect1,WHITE);
    SDL_Texture*  t = SDL_BaseFunction::loadText(renderer, std::to_string(score),rect2,YELLOW);
    SDL_RenderCopy(renderer,t, nullptr,&rect2);
    SDL_RenderCopy(renderer,scoreText, nullptr,&rect1);
}

int GameOver(SDL_Renderer* renderer)
{
    BaseObject Defeat;
    BaseObject bgGame;
    bgGame.loadObject("ImageSource/bg.jpg",renderer);
    bgGame.rect.w = WIDTH;
    bgGame.rect.h = HEIGHT;
    Defeat.loadObject("ImageSource/Defeat.png",renderer);
    Defeat.rect.x = 450;
    Defeat.rect.y = 150;
    Defeat.showObject(renderer);
    std::vector<SDL_Rect> rect(2);
    rect[0].x = 550;
    rect[0].y = 250;
    rect[0].w = 200;
    rect[0].h = 100;
    rect[1].x = 550;
    rect[1].y = 350;
    rect[1].w = 200;
    rect[1].h= 100;
    std::vector<SDL_Texture*> text(2);
    text[0] = SDL_BaseFunction::loadText(renderer,"PLAY AGAIN",rect[0], PURPLE);
    text[1] = SDL_BaseFunction::loadText(renderer,"EXIT", rect[1], PURPLE);
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

        }
    }

}
void reset(MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList,int &score,bool &gameOver)
{
    gameOver = false;
    score = 0;
    rocket.bulletList.clear();
    rocket.angleRotate = 0;
    enemyBulletList.clear();
}
void win(SDL_Renderer* renderer){


    SDL_Texture* text;
    SDL_Rect rect;
    rect.x = 200;
    rect.y = 300;
    rect.h = 300;
    rect.w = 1000;
    text = SDL_BaseFunction::loadText(renderer," COMPLETE MISSON", rect,PURPLE);
    SDL_RenderCopy(renderer,text, nullptr,&rect);
    SDL_RenderPresent(renderer);
    SDL_BaseFunction::playAudio("AudioSource/VictorySound.wav",0);
    SDL_Delay(1500);
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
    while (event.type != SDL_QUIT && event.key.keysym.sym != SDLK_q )
    {
        SDL_WaitEvent(&event);
        SDL_Delay(10);
    }
    SDL_BaseFunction::playAudio("AudioSource/IntroSound.mp3",0);
    SDL_RenderClear(renderer);
    if(event.type == SDL_QUIT)
        exit(0);
}

void LogicGame(SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE,int &score, int target, bool &gameOver)
{
    SDL_RenderClear(renderer);
    std::vector<ThreatObject*> planeList;
    for(int i = 0; i < NUMBERPLANE; i++) {
        InitPlaneList(renderer, planeList);
        planeList[i]->velocity = rand()%5+5;
    }
    InitGame(renderer,bgGame,rocket);
    SDL_Event event;
    bgGame.showObject(renderer);
    rocket.showObject(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    SDL_RenderClear(renderer);
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
                Mix_Pause(1);
                gameOver = true;
                return;
            }
            enemyBulletList[i]->showObject(renderer);
        }
        SDL_Rect prohibitZone;
        prohibitZone.w = 0;
        rocket.HandleInput(event, renderer,prohibitZone);
        if(!rocket.bulletList.empty())
            rocket.killEnemy(planeList, renderer,score);
        rocket.rotate(renderer);
        drawScore(renderer,score);
        if(score >= target)
        {
            win(renderer);
            SDL_Delay(2000);
            return;
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(DELAYTIME);
        SDL_RenderClear(renderer);

    }
}
void LogicGame2(SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket, std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE,int &score,int target, bool &gameOver,std::vector<std::string> PathToImage)
{
    SDL_RenderClear(renderer);
    std::vector<ThreatObject*> planeList;
    for(int i = 0; i < NUMBERPLANE; i++) {
        InitPlaneList(renderer, planeList);
        planeList[i]->velocity = rand()%5+5;
    }
    InitGame(renderer,bgGame,rocket);
    BaseObject structure;
    int number_bullet_attack_structure = 0;
    structure.loadObject(PathToImage[0],renderer);
    structure.rect.x = WIDTH - structure.rect.w;
    structure.rect.y = HEIGHT - structure.rect.h;
    bgGame.showObject(renderer);
    structure.showObject(renderer);
    rocket.showObject(renderer);
    std::vector<BaseObject> heart(PathToImage.size());

    for(int i = 0; i < heart.size() ;i++)
    {
       heart[i].loadObject("ImageSource/heart.png",renderer);
       if(i == 0)
       {
           heart[0].rect.x = 0;
           heart[0].rect.y = 0;
       }
       else
       {
           heart[i].rect.x  = heart[i-1].rect.x + 50;
           heart[i].rect.y = 0;
       }
       heart[i].showObject(renderer);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    SDL_RenderClear(renderer);
    SDL_Event event;
    while( event.type != SDL_QUIT  )
    {
        SDL_PollEvent(&event);
        bgGame.showObject(renderer);
        showPlaneList(renderer,planeList);
        structure.showObject(renderer);
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
                return;
            }
            if(SDL_BaseFunction::checkIntersect(enemyBulletList[i]->rect,structure.rect) )
                {
                    number_bullet_attack_structure++;
                    if(number_bullet_attack_structure < 6)
                        structure.loadObject(PathToImage[number_bullet_attack_structure],renderer);
                    structure.rect.x = WIDTH - structure.rect.w;
                    structure.rect.y = HEIGHT - structure.rect.h;
                    structure.showObject(renderer);
                    enemyBulletList[i]->loadObject("ImageSource/explosive.png",renderer);
                    enemyBulletList[i]->showObject(renderer);
                    enemyBulletList.erase(enemyBulletList.begin()+i);
                    heart.pop_back();
                }
            enemyBulletList[i]->showObject(renderer);
        }
        for(int j = 0; j < heart.size();j++)
            heart[j].showObject(renderer);
        rocket.HandleInput(event, renderer,structure.rect);
        if(!rocket.bulletList.empty())
            rocket.killEnemy(planeList, renderer,score);
        drawScore(renderer,score);
        rocket.rotate(renderer);
        SDL_RenderPresent(renderer);
        if(number_bullet_attack_structure >= PathToImage.size())
        {
            SDL_Delay(1500);
            gameOver = true;
            return;
        }
        if(score>= target)
        {
            win(renderer);
            SDL_Delay(2000);
            return;
        }
        SDL_Delay(DELAYTIME);
        SDL_RenderClear(renderer);

    }
}
bool level1 (SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList, const int NUMBERPLANE, int &score, bool &gameOver)
{
    IntroLevel(renderer,"ImageSource/IntroLevel1.jpg");
    int target = 2;
    LogicGame(renderer,bgGame,rocket,enemyBulletList,NUMBERPLANE,score,target,gameOver);
    if(score >= target)
    {
        reset(rocket,enemyBulletList,score,gameOver);
        return true;
    }
    else
    {
        int chooseOption = GameOver(renderer);
        if(chooseOption == 0) {
            reset(rocket,enemyBulletList,score,gameOver);
            bool pass = level1(renderer, bgGame, rocket, enemyBulletList, NUMBERPLANE, score, gameOver);
            return pass;
        }
        else
            exit(0);
    }
}
bool level2( SDL_Renderer* renderer, BaseObject bgGame, MainObject &rocket,  std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE,int &score, bool &gameOver)
{
    IntroLevel(renderer,"ImageSource/IntroLevel2.jpg");
    SDL_Delay(500);
    int target = 50;
    LogicGame(renderer,bgGame,rocket,enemyBulletList,NUMBERPLANE,score,target,gameOver);
    if(score >= target)
    {
        reset(rocket,enemyBulletList,score,gameOver);
        return true;
    }
    else
    {
        int chooseOption = GameOver(renderer);
        if(chooseOption == 0) {
            reset(rocket,enemyBulletList,score,gameOver);
            bool pass = level2(renderer, bgGame, rocket, enemyBulletList, NUMBERPLANE, score, gameOver);
            return pass;
        }
        else
            exit(0);
    }
}
bool level3(SDL_Renderer* renderer, BaseObject bgGame, MainObject& rocket, std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE, int& score, bool &gameOver)
{
    IntroLevel(renderer,"ImageSource/IntroLevel3.jpg");
    int target = 30;
    std::vector<std::string> PathToImage(6);
    PathToImage[0] = "ImageSource/longBien0.png";
    PathToImage[1] = "ImageSource/longBien1.png";
    PathToImage[2] = "ImageSource/longBien2.png";
    PathToImage[3] = "ImageSource/longBien3.png";
    PathToImage[4] = "ImageSource/longBien4.png";
    PathToImage[5] = "ImageSource/longBien5.png";
    LogicGame2(renderer,bgGame,rocket,enemyBulletList,NUMBERPLANE,score,target,gameOver,PathToImage);
    if(!gameOver)
    {
        SDL_Delay(1000);
        reset(rocket,enemyBulletList,score,gameOver);
        return true;
    }
    int chooseOption = GameOver(renderer);
    if(gameOver) {
        if(chooseOption == 0)  // lua chon PLAY AGAIN
        {
            reset(rocket,enemyBulletList,score,gameOver);
            level3(renderer,bgGame,rocket,enemyBulletList,NUMBERPLANE,score,gameOver);
        }
        else if(chooseOption == 1) // lua chon EXIT
        {
            exit(0);
        }
    }

}
bool level4(SDL_Renderer* renderer, BaseObject bgGame , MainObject& rocket, std::vector<EnemyBullet*> &enemyBulletList, int NUMBERPLANE, int &score,  bool &gameOver)
{
    IntroLevel(renderer,"ImageSource/IntroLevel4.jpg");
    int target = 10;
    std::vector<std::string> PathToImage(6);
    PathToImage[0] = "ImageSource/cotCo0.png";
    PathToImage[1] = "ImageSource/cotCo1.png";
    PathToImage[2] = "ImageSource/cotCo2.png";
    PathToImage[3] = "ImageSource/cotCo3.png";
    PathToImage[4] = "ImageSource/cotCo4.png";
    PathToImage[5] = "ImageSource/cotCo5.png";
    LogicGame2(renderer,bgGame,rocket,enemyBulletList,NUMBERPLANE,score,target,gameOver,PathToImage);
    if(!gameOver)
    {
        SDL_Delay(1000);
        rocket.bulletList.clear();
        enemyBulletList.clear();
        score = 0;
        return true;
    }
    int chooseOption = GameOver(renderer);
    if(gameOver) {
        if(chooseOption == 0)
        {
            reset(rocket,enemyBulletList,score,gameOver);
            level4(renderer,bgGame,rocket,enemyBulletList,NUMBERPLANE,score,gameOver);
        }
        else if(chooseOption == 1)
        {
            exit(0);
        }
    }
    return false;
}

void vitory(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
    BaseObject flag;
    flag.loadObject("ImageSource/flag.png",renderer);
    flag.showObject(renderer);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    while(event.type != SDL_QUIT)
    {
        SDL_PollEvent(&event);
        SDL_Delay(10);
    }

}