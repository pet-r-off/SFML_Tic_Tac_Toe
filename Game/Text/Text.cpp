#include "Text.h"


Text::Text() {
    try {
        this->textFont.loadFromFile("/home/petroff/C++_Lessons/Common/sfml/tic_tac_game/tic_tac/common_files/Arial_Bold.ttf");
    } catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    this->stringText.setFont(this->textFont);
    this->stringText.setFillColor(sf::Color::Red);
    this->stringText.setCharacterSize(25);
    this->stringText.setString("Text: ");
    this->stringText.setPosition(sf::Vector2f(0.f, 0.f));
}


Text::Text(std::string text_string, sf::Color color, const int font_size, sf::Vector2f position) {
    try {
        this->textFont.loadFromFile("/home/petroff/C++_Lessons/Common/sfml/tic_tac_game/tic_tac/common_files/Arial_Bold.ttf");
    } catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    this->stringText.setFont(this->textFont);
    this->stringText.setFillColor(color);
    this->stringText.setCharacterSize(font_size);
    this->stringText.setString(text_string);
    this->stringText.setPosition(position);
}


Text::~Text() {std::cout << "Text Destructor" << std::endl;}


sf::Text Text::getText() {
    return this->stringText;
}


void Text::updateText(std::string text_string) {
    this->stringText.setString(text_string);
}

