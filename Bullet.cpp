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
    angle = 0;
}

void Bullet::move() {
    if (isMove) {
        double heSoGoc = tan((90 - angle) * 3.14159 / 180);
        if (angle > 0) {
            rect.y -= velocity;
            rect.x += velocity / heSoGoc;
        } else {
            rect.y -= velocity;
            rect.x += (int) (velocity / heSoGoc );
        }
        if (rect.y <= 0 || rect.x <= 0 || rect.x >= WIDTH || rect.y >= HEIGHT)
            isMove = false;
    }
}



