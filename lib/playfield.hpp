#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>
#include "square.hpp"

class Playfield
{
    public:
        Playfield(int width, int hight);
        ~Playfield();
        void draw(sf::RenderWindow * window);
        void sort();
        void checkTetris();
        std::vector <std::shared_ptr<Square>>  blocks;

        void print();

    private:
       int m_width; 
       int m_hight; 
       sf::RectangleShape * playfield;
       sf::RectangleShape * frame;
       int m_points;


};
