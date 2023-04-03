#ifndef TIC_TAC_GAME_H
#define TIC_TAC_GAME_H


#include "Background/Background.h"
#include "GameObjects/O_obj/O_obj.h"
#include "GameObjects/X_obj/X_obj.h"
#include "GameObjects/Grid/Grid.h"
#include "Text/Text.h"


class Game {
public:
    Game();
    ~Game();

    void run();
private:
    sf::RenderWindow mWindow;
    sf::Event mEvent;
    sf::RectangleShape mRect;
    sf::RectangleShape mLine;
    Background mBackground;
    Grid field_grid;
    Text player1text, player2Text, winner1Text, winner2Text, drawText, restartText; // Winnder/Draw <-> restart text

    enum gameStates{PLAYER_1, PLAYER_2, WINNER};
    int gameState = gameStates::PLAYER_1;
    int winner;
    std::vector<gameObject*> drawable_objs;

    void processEvents();
    void update();
    void render();

    void draw_objs();
    void handleInputMouse(sf::Vector2f cursor_pos);
    void checkWin();
};



//2)check draw


#endif //TIC_TAC_GAME_H
