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
#include <memory>
#include <vector>

Square::Square(int x, int y,sf::Color color):m_x(x),m_y(y),m_color(color)
{
 
    //Position Start

    //Berechnen der Position des Drawingkörpers
    int x_offset,y_offset;
    calculateOffset(&x_offset,&y_offset);

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
    delete(m_DrawBody);
}

void Square::draw(sf::RenderWindow * window)
{
   //Zeichnen des Würfels 
    window->draw(*m_DrawBody);
}

void Square::fall()
{
    m_y++;
    int x_offset,y_offset;
    calculateOffset(&x_offset,&y_offset);
    m_DrawBody->setPosition(x_offset,y_offset);
}

void Square::moveLeft()
{
    m_x--;
    int x_offset,y_offset;
    calculateOffset(&x_offset,&y_offset);
    m_DrawBody->setPosition(x_offset,y_offset);
}

void Square::moveRight()
{
    m_x++;
    int x_offset,y_offset;
    calculateOffset(&x_offset,&y_offset);
    m_DrawBody->setPosition(x_offset,y_offset);
}
//Simple getter-Methode
int Square::get_x()
{
    return m_x;
}

int Square::get_y()
{
    return m_y;
}

void Square::set_x(int x)
{
    m_x=x;
    int x_offset,y_offset;
    calculateOffset(&x_offset,&y_offset);
    m_DrawBody->setPosition(x_offset,y_offset);
}

void Square::set_y(int y)
{
    m_y=y;
    int x_offset,y_offset;
    calculateOffset(&x_offset,&y_offset);
    m_DrawBody->setPosition(x_offset,y_offset);
}


int Square::canFall(std::vector<std::shared_ptr<Square>> *blocks)
{
    int ret1=checkBottom();
    int ret2=checkForBlock(blocks);
    if(ret1+ret2<0)
    {
        return -1;
    }
    return 0;
}

int Square::canMoveSideway(bool left,std::vector<std::shared_ptr<Square>> *blocks)
{
    if(left)
    {
        return canMoveLeft(blocks);
    }
    else
    {
        return canMoveRight(blocks);
    }
}


//0, wenn Block nicht am Boden ist
//-1, ansonsten
int Square::checkBottom()
{
    if(m_y>=sizeHightInBlocks-1)
    {
        return -1; 
    }
    return 0;
           
}

//0, wenn Block nicht am Boden ist
//-1, ansonsten
int Square::checkForBlock(std::vector<std::shared_ptr<Square>> *blocks)
{
    for(int i=0;i<blocks->size();i++)
    {
        if(m_y+1==blocks->at(i)->get_y())
        {
            if(m_x==blocks->at(i)->get_x())
            {
                return -1;
            }
        }
        
    }
    return 0;
}

void Square::calculateOffset(int *x_offset, int *y_offset)
{
    
    //Position startet mit 0
    *x_offset = position_leftWall+m_x*blockWidth;
    *y_offset = position_upperWall+m_y*blockHight;

    //Abstand zwischen den Blöcken
    *x_offset = *x_offset + m_x*offsetLeft;
    *y_offset = *y_offset + m_y*offsetUp;

}

int Square::canMoveLeft(std::vector<std::shared_ptr<Square>> *blocks)
{
    for(int i=0;i<blocks->size();i++)
    {
        if(m_x-1==blocks->at(i)->get_x()&& m_y==blocks->at(i)->get_y())
            return -1;
    }
    if(m_x>0)
        return 0;
    else
    {
        return -1;
    }
}

int Square::canMoveRight(std::vector<std::shared_ptr<Square>> *blocks)
{
    for(int i=0;i<blocks->size();i++)
    {
        if(m_x+1==blocks->at(i)->get_x()&& m_y==blocks->at(i)->get_y())
            return -1;
    }
    if(m_x<sizeWidthInBlocks-1)
        return 0;
    else
    {
        return -1;
    }
}

