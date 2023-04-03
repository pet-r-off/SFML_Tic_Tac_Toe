#ifndef TIC_TAC_BACKGROUND_H
#define TIC_TAC_BACKGROUND_H


#include "../../stdafx.h"


class Background {
public:
    Background();
    ~Background();

    sf::Sprite bkgrndSprite;
private:
    sf::Texture bkgrndTexture;
};


#endif //TIC_TAC_BACKGROUND_H
