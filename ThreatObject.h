//
// Created by taitq on 27/03/2022.
//

#ifndef TEST_CPP_THREATOBJECT_H
#define TEST_CPP_THREATOBJECT_H
#include "BaseObject.h"
#include "EnemyBullet.h"
class ThreatObject : public BaseObject{
public:
        ThreatObject();
        void move(SDL_Renderer* renderer);
        void attack(SDL_Renderer* renderer, std::vector<EnemyBullet*> &enemyBulletList);
        int velocity;
        int numberBullet;
        bool isMove ;
};


#endif //TEST_CPP_THREATOBJECT_H
