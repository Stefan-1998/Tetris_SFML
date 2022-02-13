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

int Tetrominos::fall()
{
    int temp1,temp2,temp3,temp4;
    temp1=block1->canFall();
    temp2=block2->canFall();
    temp3=block3->canFall();
    temp4=block4->canFall();


    int sum=temp1+temp2+temp3+temp4; 

    if(sum!=0)
    {
        return -1;
    }
    else
    {
        block1->fall();
        block2->fall();
        block3->fall();
        block4->fall();
        return 0;
    }

    
}
