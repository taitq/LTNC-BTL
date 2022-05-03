//
// Created by taitq on 03/04/2022.
//

#include "Bullet.h"

Bullet::Bullet() {
    rect.x = 0;
    rect.y = 0;
    fullObject = nullptr;
    isMove = false;
    velocity = 20;
}

void Bullet::move() {
    if (isMove && rect.y >= 0) {
        rect.y -= velocity;
    }
}


