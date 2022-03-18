//
// Created by taitq on 09/03/2022.
//

#include "PrimaryObject.h"

void PrimaryObject::playAudio() {
    Mix_Chunk * chunk = nullptr;
    chunk = Mix_LoadWAV(audioSource.c_str());
    if(chunk == nullptr)
        std::cout<<Mix_GetError()<<"Can't load file "<< audioSource<<std::endl;
    else
        Mix_PlayChannel(-1,chunk,0);
}

void PrimaryObject::setDrect(int _hoanhDo, int _tungDo) {
    tungDo = _tungDo;
    hoanhDo = _hoanhDo;
}
