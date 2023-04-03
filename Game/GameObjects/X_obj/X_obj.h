#ifndef TIC_TAC_X_OBJ_H
#define TIC_TAC_X_OBJ_H


#include "../gameObject.h"


class X_obj : public  gameObject{
public:
    X_obj();
    explicit X_obj(sf::Vector2f position);
    ~X_obj();

private:
    sf::Texture objTexture;
};


#endif //TIC_TAC_X_OBJ_H
