//
// Created by taitq on 27/03/2022.
//

#ifndef TEST_CPP_THREATOBJECT_H
#define TEST_CPP_THREATOBJECT_H
#include "BaseObject.h"

class ThreatObject : public BaseObject{
public:
        ThreatObject();
        void move();
        void showMove(SDL_Renderer* renderer);
        int velocity;
        bool isMove ;

};


#endif //TEST_CPP_THREATOBJECT_H
