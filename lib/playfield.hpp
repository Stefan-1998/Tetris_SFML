#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "square.hpp"

class Playfield
{
    public:
        Playfield(int width, int hight);
        ~Playfield();
        void draw(sf::RenderWindow * window);
        std::vector<Square> * blocks;


    private:
       int m_width; 
       int m_hight; 
       sf::RectangleShape * playfield;
       sf::RectangleShape * frame;


};
