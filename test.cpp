//
// Created by taitq on 14/03/2022.
//

#include "BackGround.h"
#include "BaseFunction.h"
#include "Cannon.h"


int main(int argc, char* argv[])
{
    initWindow();
    BackGround war;
    war.setImageSource("ImageSource/backGround.jpg");
    war.setAudioSource("AudioSource/backGroundSound.mp3");
    war.showObject();
    war.playAudio();

    Cannon cannon;
    cannon.setDrect(300,400);
    cannon.setImageSource("ImageSource/cannon1.png");
    cannon.showObject();
    cannon.move();
}
