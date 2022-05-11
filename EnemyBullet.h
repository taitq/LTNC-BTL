//
// Created by taitq on 10/05/2022.
//

#ifndef TEST_CPP_ENEMYBULLET_H
#define TEST_CPP_ENEMYBULLET_H

#include "Bullet.h"

class EnemyBullet : public Bullet{
public:
    EnemyBullet();
    void move() override;

};


#endif //TEST_CPP_ENEMYBULLET_H
