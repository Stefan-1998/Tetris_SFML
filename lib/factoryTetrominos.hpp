#pragma once

#include "tetrisPieces.hpp"
#include <SFML/Graphics/Color.hpp>


class FactoryTetrominos
{
    public:
        static Tetrominos* createTetrominos();

    private:
        static sf::Color get_color(int* selectedColor);


};
