#include "../lib/square.hpp"
#include "../lib/configGlobal.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <square.hpp>
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <configGlobal.hpp>

Square::Square(int x, int y,sf::Color color):m_x(x),m_y(x),m_color(color)
{
 
    //Position Start

    std::cout<<"Kreiiert2"<<std::endl;
    //Position startet mit 0
    int x_offset = offsetLeft+m_x*blockWidth;
    int y_offset = offsetLeft+m_y*blockHight;

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

