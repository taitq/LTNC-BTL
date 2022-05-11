//
// Created by taitq on 10/05/2022.
//

#include "EnemyBullet.h"

void EnemyBullet::move() {
    if(isMove)
    {
        rect.y += velocity;
    }
    if(rect.y >= HEIGHT)
        isMove = false;
}

EnemyBullet::EnemyBullet() {
    rect.x = 0;
    rect.y = 0;
    fullObject = nullptr;
    isMove = false;
    velocity = 10;
    angle = 0;
}
