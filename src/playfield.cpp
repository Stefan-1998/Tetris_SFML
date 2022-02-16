
#include "../lib/playfield.hpp"
#include "../lib/configGlobal.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <vector>

Playfield::Playfield(int width, int hight):m_width(width),m_hight(hight)
{
    sf::Vector2f size;
    size.x=m_width;
    size.y=m_hight;

    playfield=new sf::RectangleShape();
    playfield->setSize(size);
    playfield->setPosition(playfieldOffsetLeft,playfieldOffsetUp);
    playfield->setFillColor(sf::Color::White);

    size.x=size.x+10;
    size.y=size.y+10;
    frame = new sf::RectangleShape();
    frame->setSize(size);
    frame->setPosition(playfieldOffsetLeft-5,playfieldOffsetUp-5);
    frame->setFillColor(sf::Color::Blue);
        
    //std::vector<std::shared_ptr<Square>> temp;
    //blocks=&temp;
}


Playfield::~Playfield()
{
    delete( playfield);
    delete( frame);
    blocks.clear();
    
    //delete blocks;
    std::cout<<"Spielfeld wurde destroyed"<<std::endl;
    
}

void Playfield::draw(sf::RenderWindow * window)
{
    window->draw(*frame);
    window->draw(*playfield);
}
