#include "../lib/tetrominos.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>




Tetrominos::~Tetrominos()
{
    std::cout<<"delete Tetrominos"<<std::endl;
    delete block1;
    delete block2;
    delete block3;
    delete block4;
}


void Tetrominos::draw(sf::RenderWindow *w)
{
    block1->draw(w);
    block2->draw(w);
    block3->draw(w);
    block4->draw(w);
}
