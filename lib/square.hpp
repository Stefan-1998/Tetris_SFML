#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>




class Square
{
    public:

        //x- und y-Kooridinate startet mit 0
        Square(int x,int y,sf::Color color);
        ~Square();

        void draw(sf::RenderWindow* window);
    private:
        //Position des Würfels
        int m_x;
        int m_y;
        sf::Color m_color;

        sf::RectangleShape *m_DrawBody;

};

