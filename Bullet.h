//
// Created by taitq on 03/04/2022.
//

#ifndef BULLET_H
#define BULLET_H
#include "BaseObject.h"


class Bullet :public BaseObject{
public:
    int velocity;
    int angle;
    Bullet();
    bool isMove;
    void move();
};


#endif //BULLET_H
