#include "../lib/square.hpp"
#include "../lib/configGlobal.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>

Square::Square(int x, int y,sf::Color color):m_x(x),m_y(y),m_color(color)
{
 
    //Position Start

    //Position startet mit 0
    int x_offset = position_leftWall+m_x*blockWidth;
    int y_offset = position_upperWall+m_y*blockHight;

    //Abstand zwischen den Blöcken
    x_offset = x_offset + m_x*offsetLeft;
    y_offset = y_offset + m_y*offsetUp;


    //Blockgröße
    sf::Vector2f size;
    size.x=blockWidth;
    size.y=blockHight;

    m_DrawBody=new sf::RectangleShape();

    //Setzen der Parameter    
    m_DrawBody->setPosition(x_offset,y_offset); 
    m_DrawBody->setSize(size); 
    m_DrawBody->setFillColor(m_color);

   
}

Square::~Square()
{
    std::cout<<"Wuerfel wurde zerstoert"<<'\n';

    delete(m_DrawBody);


}

void Square::draw(sf::RenderWindow * window)
{
   //Zeichnen des Würfels 
    window->draw(*m_DrawBody);
}

