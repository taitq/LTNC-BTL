//
// Created by taitq on 27/03/2022.
//

#include "MainObject.h"

void MainObject::HandleInput(SDL_Event event) {
    switch (event.type) {
        case SDL_QUIT:
            exit(0);
        case SDL_KEYDOWN:
        {
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    rect.x += 5;
                    break;
                case SDLK_LEFT:
                    rect.x -= 5;
                    break;
            }
            break;
        }
    }
}
