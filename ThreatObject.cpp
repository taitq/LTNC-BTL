//
// Created by taitq on 27/03/2022.
//

#include "ThreatObject.h"

ThreatObject::ThreatObject() {
    isMove = true;
    rect.x = 0;
    rect.y = rand() % (HEIGHT/3);
    velocity = rand()%5 + 8;
    numberBullet = 3;
}

void ThreatObject::move(SDL_Renderer* renderer) {
    if(rect.x < WIDTH - rect.w && isMove)
        rect.x+= velocity;
    if(rect.x >= WIDTH - rect.h )
    {
        rect.x = 0;
        rect.y = rand() % (HEIGHT/3);
        velocity = rand() % 5 + 8;
    }

}

 void ThreatObject::attack(SDL_Renderer *renderer, std::vector<EnemyBullet*> &enemyBulletList) {
    int temp = WIDTH/velocity;
    int viTriNemBom = (rand()% temp) *velocity;
    if(rect.x == viTriNemBom)
    {
        auto * newEnemyBullet = new EnemyBullet();
        newEnemyBullet->loadObject("ImageSource/enemyBullet1.png",renderer);
        newEnemyBullet->rect.x = rect.x + rect.w/2;
        newEnemyBullet->rect.y = rect.y + rect.h/2;
        newEnemyBullet->isMove = true;
        enemyBulletList.push_back(newEnemyBullet);
    }
}






