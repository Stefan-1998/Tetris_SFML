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
        void fall();
        int get_x();
        int get_y();

        //0, wenn Fallen möglich ist
        //-1, ansonsten
        int canFall();
        
    private:
        //Position des Würfels
        int m_x;
        int m_y;
        sf::Color m_color;

        sf::RectangleShape *m_DrawBody;

        int checkBottom();
        //Hier übergabeParameter der Vektor mit den Square
        int checkForBlock();
        void calculateOffset(int *x_offset, int *y_offset);

};

