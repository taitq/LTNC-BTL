//
// Created by taitq on 17/03/2022.
//

#include "Cannon.h"
#include "BaseFunction.h"
void Cannon::move()
{
    SDL_Event event;
    bool check= true;
    while(check)
    {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                check = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_RIGHT: {
                        SDL_RenderClear(renderer);
                        hoanhDo += 20;
                        BackGround bg;
                        bg.setImageSource("ImageSource/backGround.jpg");
                        bg.showObject();
                        Cannon::showObject();
                        break;
                    }

                    case SDLK_LEFT: {
                        SDL_RenderClear(renderer);
                        hoanhDo -= 20;
                        BackGround bg;
                        bg.setImageSource("ImageSource/backGround.jpg");
                        bg.showObject();
                        Cannon::showObject();
                        break;
                    }
                }
                break;
        }
    }

}

void Cannon::playAudio() {
    Mix_Chunk* chunk = nullptr;
    chunk = Mix_LoadWAV(audioSource.c_str());
    if(chunk == nullptr)
       std:: cout<<"Error load Audio "<<audioSource<< std::endl;
    else
        Mix_PlayChannel(-1,chunk,0);
}

void Cannon::showObject() {
        SDL_Rect drect;
        drect.x = hoanhDo;
        drect.y = tungDo;

        SDL_Texture* texture = loadImage(imageSource.c_str());
        SDL_QueryTexture(texture,NULL,NULL,&drect.w,&drect.h);
        drect.w /= 2;
        drect.h /= 2;
        SDL_RenderCopy(renderer, texture, NULL, &drect);
        SDL_RenderPresent(renderer);
}
