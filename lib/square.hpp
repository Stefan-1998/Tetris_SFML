#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>




class Square
{
    public:

        //x- und y-Kooridinate startet mit 0
        Square(int x,int y,sf::Color color);
        ~Square();

        void draw(sf::RenderWindow* window);
        void fall();
        void moveLeft();
        void moveRight();
        int get_x();
        int get_y();
        void set_x(int x);
        void set_y(int y);

        //0, wenn Fallen möglich ist
        //-1, ansonsten
        int canFall(std::vector<std::shared_ptr<Square>>*blocks);

        //0, wenn Fallen möglich ist
        //-1, ansonsten
        int canMoveSideway(bool left);
        
    private:
        //Position des Würfels
        int m_x;
        int m_y;
        sf::Color m_color;

        sf::RectangleShape *m_DrawBody;

        int checkBottom();
        int checkForBlock(std::vector<std::shared_ptr<Square>> *blocks);
        void calculateOffset(int *x_offset, int *y_offset);
        int canMoveLeft();
        int canMoveRight();

};

