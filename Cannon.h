//
// Created by taitq on 17/03/2022.
//

#ifndef MAIN_CPP_CANNON_H
#define MAIN_CPP_CANNON_H

#include "BackGround.h"

class Cannon : public PrimaryObject{
public:
    void move();
    void playAudio() override;
    void showObject() override;
};


#endif //MAIN_CPP_CANNON_H
