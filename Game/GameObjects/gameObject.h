#ifndef TIC_TAC_GAMEOBJECT_H
#define TIC_TAC_GAMEOBJECT_H


#include "../../stdafx.h"


class gameObject {
public:
    gameObject();
    explicit gameObject(sf::Vector2f position);
    ~gameObject();

    sf::RectangleShape objectRect;
private:
    float width = 80;
    float height = 80;

protected:
};


#endif //TIC_TAC_GAMEOBJECT_H
