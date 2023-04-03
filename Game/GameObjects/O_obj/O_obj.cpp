#include "O_obj.h"


O_obj::O_obj() : gameObject() {
    try {
        this->objTexture.loadFromFile("/home/petroff/C++_Lessons/Common/sfml/tic_tac_game/tic_tac/common_files/o.png.bmp");
    } catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    sf::Texture *pTexture = &(this->objTexture);

    this->objectRect.setFillColor(sf::Color::White);
    this->objectRect.setOutlineThickness(3.f);
    this->objectRect.setOutlineColor(sf::Color::Transparent);
    this->objectRect.setTexture(pTexture);
}


O_obj::O_obj(sf::Vector2f position) : gameObject(position) {
    try {
        this->objTexture.loadFromFile("/home/petroff/C++_Lessons/Common/sfml/tic_tac_game/tic_tac/common_files/o.png.bmp");
    } catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    sf::Texture *pTexture = &(this->objTexture);

    this->objectRect.setFillColor(sf::Color::White);
    this->objectRect.setOutlineThickness(3.f);
    this->objectRect.setOutlineColor(sf::Color::Transparent);
    this->objectRect.setTexture(pTexture);
}

O_obj::~O_obj() {}
