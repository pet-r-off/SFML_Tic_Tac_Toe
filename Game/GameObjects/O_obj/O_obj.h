#ifndef TIC_TAC_O_OBJ_H
#define TIC_TAC_O_OBJ_H


#include "../gameObject.h"


class O_obj : public gameObject{
public:
    O_obj();
    explicit O_obj(sf::Vector2f position);
    ~O_obj();

private:
    sf::Texture objTexture;
};


#endif //TIC_TAC_O_OBJ_H
