#include "Background.h"


Background::Background() {
    try {
        this->bkgrndTexture.loadFromFile("/home/petroff/C++_Lessons/Common/sfml/tic_tac_game/tic_tac/common_files/field.png.bmp");
    } catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    this->bkgrndSprite.setTexture(this->bkgrndTexture);
    this->bkgrndSprite.setPosition(sf::Vector2f(80.f, 10.f));
}


Background::~Background() {}
