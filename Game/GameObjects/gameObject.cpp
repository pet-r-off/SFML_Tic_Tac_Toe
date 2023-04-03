#include "gameObject.h"


gameObject::gameObject() {
    this->objectRect.setSize(sf::Vector2f(this->width, this->height));
    this->objectRect.setPosition(sf::Vector2f(0.f, 0.f));
}


gameObject::gameObject(sf::Vector2f position) {
    this->objectRect.setSize(sf::Vector2f(this->width, this->height));
    this->objectRect.setPosition(position);
}


gameObject::~gameObject() {}

