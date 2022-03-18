//
// Created by taitq on 09/03/2022.
//

#ifndef MAIN_CPP_PRIMARYOBJECT_H
#define MAIN_CPP_PRIMARYOBJECT_H

#include "BaseFunction.h"

class PrimaryObject {
    protected:
    std::string imageSource;
    std::string audioSource;
    int hoanhDo;
    int tungDo;
    public:
        void setImageSource(std::string nameSource)
        {
            imageSource =nameSource;
        }
        void setAudioSource(std:: string nameSource)
        {
            audioSource = nameSource;
        }
        void setDrect(int _hoanhDo, int _tungDo);
        virtual void showObject() = 0;
        virtual void playAudio();
};


#endif //MAIN_CPP_PRIMARYOBJECT_H
