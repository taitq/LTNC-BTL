//
// Created by taitq on 27/03/2022.
//

#include "ThreatObject.h"

void ThreatObject::move() {
    if(rect.x < 1000)
        rect.x+= 1;
    if(rect.x >= 1000)
        rect.x = 0;
}
