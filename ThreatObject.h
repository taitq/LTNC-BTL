//
// Created by taitq on 27/03/2022.
//

#ifndef TEST_CPP_THREATOBJECT_H
#define TEST_CPP_THREATOBJECT_H
#include "BaseObject.h"

class ThreatObject : public BaseObject{
private:
    int velocity;
public:
    void setVelocity(int v);
    void move();
};


#endif //TEST_CPP_THREATOBJECT_H