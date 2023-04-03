#include "Game.h"


Game::Game() : mWindow(sf::VideoMode(480, 800),"Tic Tac Toe"),
                player1text("PlayerX", sf::Color::Blue, 20, sf::Vector2f(140, 600)),
                player2Text("PlayerO", sf::Color::Red, 20, sf::Vector2f(240, 600)),
                winner1Text("PlayerX WIN", sf::Color::Blue, 50, sf::Vector2f(85, 420)),
                winner2Text("PlayerO WIN", sf::Color::Red, 50, sf::Vector2f(85, 420)),
                drawText("DRAW", sf::Color::Green, 50, sf::Vector2f(85, 420)),
                restartText("RESTART", sf::Color::Magenta, 30, sf::Vector2f(160, 490)),
                mRect(sf::Vector2f(90.f, 40.f)),
                mLine(sf::Vector2f(300.f, 10.f)) {
    this->mRect.setFillColor(sf::Color::Transparent);
    this->mRect.setOutlineThickness(5.f);
    this->mRect.setOutlineColor(sf::Color::Blue);
    this->mRect.setPosition(sf::Vector2f(130.f, 595.f));

    this->mLine.setFillColor(sf::Color::Green);
    this->mLine.setPosition(sf::Vector2f(80.f, 55.f));
}


Game::~Game() {}


void Game::run() {
    while(this->mWindow.isOpen()){
         this->processEvents();
         this->update();
         this->render();
    }
}


void Game::processEvents() {
    while (this->mWindow.pollEvent(this->mEvent)) {
        switch (mEvent.type) {
            case sf::Event::EventType::Closed:
                this->mWindow.close();
                break;

            case sf::Event::EventType::MouseButtonPressed:
                handleInputMouse(sf::Vector2f(sf::Mouse::getPosition(this->mWindow)));
                break;
        }
    }
}


void Game::update() {
    if (this->gameState == gameStates::PLAYER_1){
        this->mRect.setOutlineColor(sf::Color::Blue);
        this->mRect.setPosition(sf::Vector2f(130.f, 595.f));
    }
    else {
        this->mRect.setOutlineColor(sf::Color::Red);
        this->mRect.setPosition(sf::Vector2f(230.f, 595.f));
    }
}


void Game::render() {
    this->mWindow.clear();

    this->mWindow.draw(this->mBackground.bkgrndSprite);
    this->draw_objs();
    this->mWindow.draw(this->player2Text.getText());
    this->mWindow.draw(this->player1text.getText());
    this->mWindow.draw(this->mRect);

    if (this->gameState == gameStates::WINNER){
        this->mWindow.draw(this->mLine);

        if (this->winner == gameStates::PLAYER_1){
            this->mWindow.draw(this->winner1Text.getText());
        }
        else if(this->winner == gameStates::PLAYER_2){
            this->mWindow.draw(this->winner2Text.getText());
        }
        else{
            this->mWindow.draw(this->drawText.getText());
        }
        this->mWindow.draw(this->restartText.getText());
    }

    this->mWindow.display();
}











/////////////////////////////////////////////////////////////////////////////////////
//      STATE METHODS
/////////////////////////////////////////////////////////////////////////////////////
void Game::handleInputMouse(sf::Vector2f cursor_pos) {

    if (this->gameState == gameStates::WINNER){
        if (sf::IntRect(160, 490, 100, 30).contains(int(cursor_pos.x), int(cursor_pos.y))){ //restart check
            this->drawable_objs.clear();
            this->gameState = gameStates::PLAYER_1;

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    this->field_grid.arr_obj[i][j] = 3;
                }
            }

            this->mLine.rotate(360.f - this->mLine.getRotation());
            this->mLine.setPosition(sf::Vector2f(80.f, 55.f));
        }
    }
    else{
        if (this->gameState == gameStates::PLAYER_1){
            if (sf::IntRect(120, 20, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new X_obj(sf::Vector2f(80.f, 20.f)));
                this->field_grid.addX(0,0, 0);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_2;
                this->checkWin();
            }
            if (sf::IntRect(220, 20, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new X_obj(sf::Vector2f(190.f, 20.f)));
                this->field_grid.addX(0,1, 1);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_2;
                this->checkWin();
            }
            if (sf::IntRect(320, 20, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new X_obj(sf::Vector2f(300.f, 20.f)));
                this->field_grid.addX(0,2, 2);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_2;
                this->checkWin();
            }


            if (sf::IntRect(120, 170, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new X_obj(sf::Vector2f(80.f, 170.f)));
                this->field_grid.addX(1,0, 3);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_2;
                this->checkWin();
            }
            if (sf::IntRect(220, 170, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new X_obj(sf::Vector2f(190.f, 170.f)));
                this->field_grid.addX(1,1, 4);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_2;
                this->checkWin();
            }
            if (sf::IntRect(320, 170, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new X_obj(sf::Vector2f(300.f, 170.f)));
                this->field_grid.addX(1,2, 5);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_2;
                this->checkWin();
            }


            if (sf::IntRect(120, 320, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new X_obj(sf::Vector2f(80.f, 320.f)));
                this->field_grid.addX(2,0, 6);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_2;
                this->checkWin();
            }
            if (sf::IntRect(220, 320, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new X_obj(sf::Vector2f(190.f, 320.f)));
                this->field_grid.addX(2,1, 7);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_2;
                this->checkWin();
            }
            if (sf::IntRect(320, 320, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new X_obj(sf::Vector2f(300.f, 320.f)));
                this->field_grid.addX(2,2, 8);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_2;
                this->checkWin();
            }
        }









        else {
            if (sf::IntRect(120, 20, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new O_obj(sf::Vector2f(80.f, 20.f)));
                this->field_grid.addO(0,0, 0);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_1;
                this->checkWin();
            }
            if (sf::IntRect(220, 20, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new O_obj(sf::Vector2f(190.f, 20.f)));
                this->field_grid.addO(0,1, 1);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_1;
                this->checkWin();
            }
            if (sf::IntRect(320, 20, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new O_obj(sf::Vector2f(300.f, 20.f)));
                this->field_grid.addO(0,2, 2);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_1;
                this->checkWin();
            }


            if (sf::IntRect(120, 170, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new O_obj(sf::Vector2f(80.f, 170.f)));
                this->field_grid.addO(1,0, 3);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_1;
                this->checkWin();
            }
            if (sf::IntRect(220, 170, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new O_obj(sf::Vector2f(190.f, 170.f)));
                this->field_grid.addO(1,1, 4);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_1;
                this->checkWin();
            }
            if (sf::IntRect(320, 170, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new O_obj(sf::Vector2f(300.f, 170.f)));
                this->field_grid.addO(1,2, 5);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_1;
                this->checkWin();
            }


            if (sf::IntRect(120, 320, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new O_obj(sf::Vector2f(80.f, 320.f)));
                this->field_grid.addO(2,0, 6);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_1;
                this->checkWin();
            }
            if (sf::IntRect(220, 320, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new O_obj(sf::Vector2f(190.f, 320.f)));
                this->field_grid.addO(2,1, 7);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_1;
                this->checkWin();
            }
            if (sf::IntRect(320, 320, 80, 80).contains(int(cursor_pos.x), int(cursor_pos.y))){
                this->drawable_objs.push_back(new O_obj(sf::Vector2f(300.f, 320.f)));
                this->field_grid.addO(2,2, 8);
                this->field_grid.printGrid();
                this->gameState = gameStates::PLAYER_1;
                this->checkWin();
            }
        }
    }


}


void Game::draw_objs() {
    for (auto &drawObjs : this->drawable_objs) {
        this->mWindow.draw(drawObjs->objectRect);
    }
}


void Game::checkWin() {

    //X states
    if ( (this->field_grid.arr_obj[0][0] == 1) && (this->field_grid.arr_obj[0][1] == 1) && (this->field_grid.arr_obj[0][2] == 1) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_1;
        this->mLine.setPosition(sf::Vector2f(80.f, 55.f));
    }
    if ( (this->field_grid.arr_obj[1][0] == 1) && (this->field_grid.arr_obj[1][1] == 1) && (this->field_grid.arr_obj[1][2] == 1) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_1;
        this->mLine.setPosition(sf::Vector2f(80.f, 205.f));
    }
    if ( (this->field_grid.arr_obj[2][0] == 1) && (this->field_grid.arr_obj[2][1] == 1) && (this->field_grid.arr_obj[2][2] == 1) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_1;
        this->mLine.setPosition(sf::Vector2f(80.f, 355.f));
    }

    if ( (this->field_grid.arr_obj[0][0] == 1) && (this->field_grid.arr_obj[1][0] == 1) && (this->field_grid.arr_obj[2][0] == 1) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_1;
        this->mLine.setSize(sf::Vector2f(10.f, 400.f));
        this->mLine.setPosition(sf::Vector2f(115.f, 10.f));
    }
    if ( (this->field_grid.arr_obj[0][1] == 1) && (this->field_grid.arr_obj[1][1] == 1) && (this->field_grid.arr_obj[2][1] == 1) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_1;
        this->mLine.setSize(sf::Vector2f(10.f, 400.f));
        this->mLine.setPosition(sf::Vector2f(225.f, 10.f));
    }
    if ( (this->field_grid.arr_obj[0][2] == 1) && (this->field_grid.arr_obj[1][2] == 1) && (this->field_grid.arr_obj[2][2] == 1) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_1;
        this->mLine.setSize(sf::Vector2f(10.f, 400.f));
        this->mLine.setPosition(sf::Vector2f(335.f, 10.f));
    }

    if ( (this->field_grid.arr_obj[0][0] == 1) && (this->field_grid.arr_obj[1][1] == 1) && (this->field_grid.arr_obj[2][2] == 1) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_1;
        this->mLine.setSize(sf::Vector2f(490.f, 10.f));
        this->mLine.rotate(53.f);
        this->mLine.setPosition(sf::Vector2f(85.f, 10.f));
    }
    if ( (this->field_grid.arr_obj[0][2] == 1) && (this->field_grid.arr_obj[1][1] == 1) && (this->field_grid.arr_obj[2][0] == 1) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_1;
        this->mLine.setSize(sf::Vector2f(490.f, 10.f));
        this->mLine.rotate(127.f);
        this->mLine.setPosition(sf::Vector2f(385.f, 15.f));
    }



    //O states
    if ( (this->field_grid.arr_obj[0][0] == 0) && (this->field_grid.arr_obj[0][1] == 0) && (this->field_grid.arr_obj[0][2] == 0) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_2;
        this->mLine.setPosition(sf::Vector2f(80.f, 55.f));
    }
    if ( (this->field_grid.arr_obj[1][0] == 0) && (this->field_grid.arr_obj[1][1] == 0) && (this->field_grid.arr_obj[1][2] == 0) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_2;
        this->mLine.setPosition(sf::Vector2f(80.f, 205.f));
    }
    if ( (this->field_grid.arr_obj[2][0] == 0) && (this->field_grid.arr_obj[2][1] == 0) && (this->field_grid.arr_obj[2][2] == 0) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_2;
        this->mLine.setPosition(sf::Vector2f(80.f, 355.f));
    }

    if ( (this->field_grid.arr_obj[0][0] == 0) && (this->field_grid.arr_obj[1][0] == 0) && (this->field_grid.arr_obj[2][0] == 0) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_2;
        this->mLine.setSize(sf::Vector2f(10.f, 400.f));
        this->mLine.setPosition(sf::Vector2f(115.f, 10.f));
    }
    if ( (this->field_grid.arr_obj[0][1] == 0) && (this->field_grid.arr_obj[1][1] == 0) && (this->field_grid.arr_obj[2][1] == 0) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_2;
        this->mLine.setSize(sf::Vector2f(10.f, 400.f));
        this->mLine.setPosition(sf::Vector2f(225.f, 10.f));
    }
    if ( (this->field_grid.arr_obj[0][2] == 0) && (this->field_grid.arr_obj[1][2] == 0) && (this->field_grid.arr_obj[2][2] == 0) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_2;
        this->mLine.setSize(sf::Vector2f(10.f, 400.f));
        this->mLine.setPosition(sf::Vector2f(335.f, 10.f));
    }

    if ( (this->field_grid.arr_obj[0][0] == 0) && (this->field_grid.arr_obj[1][1] == 0) && (this->field_grid.arr_obj[2][2] == 0) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_2;
        this->mLine.setSize(sf::Vector2f(490.f, 10.f));
        this->mLine.rotate(53.f);
        this->mLine.setPosition(sf::Vector2f(85.f, 10.f));
    }
    if ( (this->field_grid.arr_obj[0][2] == 0) && (this->field_grid.arr_obj[1][1] == 0) && (this->field_grid.arr_obj[2][0] == 0) ){
        this->gameState = gameStates::WINNER;
        this->winner = gameStates::PLAYER_2;
        this->mLine.setSize(sf::Vector2f(490.f, 10.f));
        this->mLine.rotate(127.f);
        this->mLine.setPosition(sf::Vector2f(385.f, 15.f));
    }
}

