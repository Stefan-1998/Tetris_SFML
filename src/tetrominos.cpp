#include "../lib/tetrominos.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <vector>


Tetrominos::Tetrominos()
{
}


Tetrominos::~Tetrominos()
{
}


void Tetrominos::draw(sf::RenderWindow *w)
{
    block1->draw(w);
    block2->draw(w);
    block3->draw(w);
    block4->draw(w);
}

void Tetrominos::rotate(std::vector<std::shared_ptr<Square>> *blocks)
{
     
    
    int ret=0;
    ret=canRotate(blocks);


    std::cout<<"Rotiere"<<std::endl;
    if(ret==0)
    {
        rotatePiece();
    }
    
}

int Tetrominos::fall(std::vector<std::shared_ptr<Square>> *blocks)
{
    int temp1,temp2,temp3,temp4;
    temp1=block1->canFall(blocks);
    temp2=block2->canFall(blocks);
    temp3=block3->canFall(blocks);
    temp4=block4->canFall(blocks);


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

void Tetrominos::moveSideway(bool left,std::vector<std::shared_ptr<Square>> *blocks)
{
    int temp1, temp2, temp3, temp4;
    int sum;
    if(left)
    {
        temp1=block1->canMoveSideway(true,blocks);
        temp2=block2->canMoveSideway(true,blocks);
        temp3=block3->canMoveSideway(true,blocks);
        temp4=block4->canMoveSideway(true,blocks);
        
        sum= temp1+ temp2 + temp3 + temp4;

        //Sobald 1 Block sich nicht bewegen kann, darf sich der Block nicht 
        //bewegen
        if(sum==0)
        {
            block1->moveLeft();
            block2->moveLeft();
            block3->moveLeft();
            block4->moveLeft();
        }

    } 
    else
    {
        temp1=block1->canMoveSideway(false,blocks);
        temp2=block2->canMoveSideway(false,blocks);
        temp3=block3->canMoveSideway(false,blocks);
        temp4=block4->canMoveSideway(false,blocks);
        
        sum= temp1+ temp2 + temp3 + temp4;

        //Sobald 1 Block sich nicht bewegen kann, darf sich der Block nicht 
        //bewegen
        if(sum==0)
        {
            block1->moveRight();
            block2->moveRight();
            block3->moveRight();
            block4->moveRight();
        }

   
    }
}




int Tetrominos::checkPosition(int *x, int*y, std::vector<std::shared_ptr<Square>> *blocks)
{
    if((*x<0)||(*x>=sizeWidthInBlocks))
    {
        return -1;
    }
    else if(*y>sizeHightInBlocks)
    {
        return -1;
    }


    if(blocks->empty())
    {
        //std::cout<<"Is Empty"<<std::endl;
        return 0;
    }
    int test=blocks->size(); 
    for(int i=0;i<blocks->size();i++)
    {
       if((*y==blocks->at(i)->get_y())&&(*x==blocks->at(i)->get_x()))
       {
            return -1;
       }
        
    }
    return 0;
}

int Tetrominos::canRotate(std::vector<std::shared_ptr<Square>>*blocks)
{
    int x,y;
    int offset_x,offset_y;
    int ret1, ret2, ret3, ret4;
    int ret;


    ret1=0;
    ret2=0;
    ret3=0;
    ret4=0;
    ret=0;

    x=0;
    y=0;

    upperOffset(&offset_y);
    leftOffset(&offset_x);

    calculateRotation(1,&x,&y);
    x=x+offset_x;
    y=y+offset_y;

    
    ret1= checkPosition(&x,&y,blocks);

    x=0;
    y=0;
    calculateRotation(2,&x,&y);
    x=x+offset_x;
    y=y+offset_y;
    ret2= checkPosition(&x,&y,blocks);

    x=0;
    y=0;
    calculateRotation(3,&x,&y);
    x=x+offset_x;
    y=y+offset_y;
    ret3= checkPosition(&x,&y,blocks);

    x=0;
    y=0;
    calculateRotation(4,&x,&y);
    x=x+offset_x;
    y=y+offset_y;
    ret4= checkPosition(&x,&y,blocks);

    ret=ret1 + ret2+ ret3 +ret3;
    return  ret;
}

void Tetrominos::rotatePiece()
{

    int x1,y1;
    int x2,y2;
    int x3,y3;
    int x4,y4;
    int offset_x,offset_y;

    offset_x=0;
    offset_y=0;
    
    x1=0;
    x2=0;
    x3=0;
    x4=0;

    y1=0;
    y2=0;
    y3=0;
    y4=0;

    leftOffset(&offset_x);
    upperOffset(&offset_y);


    calculateRotation(1,&x1,&y1);
    calculateRotation(2,&x2,&y2);
    calculateRotation(3,&x3,&y3);
    calculateRotation(4,&x4,&y4);

    x1=offset_x+x1;
    x2=offset_x+x2;
    x3=offset_x+x3;
    x4=offset_x+x4;

    y1=offset_y+y1;
    y2=offset_y+y2;
    y3=offset_y+y3;
    y4=offset_y+y4;

    block1->set_x(x1);
    block1->set_y(y1);

    block2->set_x(x2);
    block2->set_y(y2);

    block3->set_x(x3);
    block3->set_y(y3);

    block4->set_x(x4);
    block4->set_y(y4);

}

void Tetrominos::leftOffset(int *x)
{
    *x=block1->get_x();
    if(block2->get_x()<*x)
    {
        *x=block2->get_x();
    }

    if(block3->get_x()<*x)
    {
        *x=block3->get_x();
    }
    if(block4->get_x()<*x)
    {
        *x=block4->get_x();
    }
} 

void Tetrominos::upperOffset(int *y)
{
    *y=block1->get_y();
    if(block2->get_y()<*y)
    {
        *y=block2->get_y();
    }

    if(block3->get_y()<*y)
    {
        *y=block3->get_y();
    }
    if(block4->get_y()<*y)
    {
        *y=block4->get_y();
    }
} 
void Tetrominos::calculateRotation(int blockNumber,int *x, int *y)
{
    
    int offset_x,offset_y;
    int number=0;

    leftOffset(&offset_x);
    upperOffset(&offset_y);

    int tempX,tempY;

    switch(blockNumber)
    {
        case 1:
            tempX=block1->get_x();
            tempY=block1->get_y();
            break;
        case 2:
            tempX=block2->get_x();
            tempY=block2->get_y();
            break;
        case 3:
            tempX=block3->get_x();
            tempY=block3->get_y();
            break;
        case 4:
            tempX=block4->get_x();
            tempY=block4->get_y();
            break;
        default:
            break;
    }
        
    tempX=tempX-offset_x;
    tempY=tempY-offset_y;

    number=tempY*3+tempX+1;

    //Berechnen der nächsten Position
    number=number+number*2-tempY*10;


    //Abzug, damit modulo und geteilt x und y berechnen kann 
    number=number-1;


    //Berechnen der x und y Position
    *y=number/3;
    
    *x=number%3;
    *x=*x;

}
