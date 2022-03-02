#include "../lib/tetrisPieces.hpp"
#include <SFML/Graphics/Color.hpp>
#include <ios>
#include <memory>
#include <vector>
#include "../lib/square.hpp"
#include <iostream>

L_Piece::L_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(6,0,c);
     block2 = std::make_shared<Square>(6,1,c);
     block3 = std::make_shared<Square>(6,2,c);
     block4 = std::make_shared<Square>(7,2,c);
}




J_Piece::J_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(6,0,c);
     block2 = std::make_shared<Square>(6,1,c);
     block3 = std::make_shared<Square>(6,2,c);
     block4 = std::make_shared<Square>(5,2,c);
}



O_Piece::O_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(6,0,c);
     block2 = std::make_shared<Square>(6,1,c);
     block3 = std::make_shared<Square>(5,0,c);
     block4 = std::make_shared<Square>(5,1,c);
}

S_Piece::S_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(7,1,c);
     block2 = std::make_shared<Square>(6,1,c);
     block3 = std::make_shared<Square>(6,0,c);
     block4 = std::make_shared<Square>(5,1,c);
}

Z_Piece::Z_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(7,0,c);
     block2 = std::make_shared<Square>(6,0,c);
     block3 = std::make_shared<Square>(6,1,c);
     block4 = std::make_shared<Square>(5,1,c);
}

I_Piece::I_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(5,0,c);
     block2 = std::make_shared<Square>(5,1,c);
     block3 = std::make_shared<Square>(5,2,c);
     block4 = std::make_shared<Square>(5,3,c);
     rotationPtr=&rotationState[0];
}

void I_Piece::rotate(std::vector<std::shared_ptr<Square>> *blocks)
{
    
    int ret=0;
    ret=canRotate(blocks);


    if(ret==0)
    {
        rotatePiece();
    }
    
}
void I_Piece::advancePtr()
{
    if(rotationPtr== & rotationState[3])
    {
        rotationPtr=&rotationState[0];
    }
    else 
    {
        rotationPtr++;
    }
}
int I_Piece::canRotate(std::vector<std::shared_ptr<Square>> *blocks)
{
    int ret1,ret2,ret3,ret4;
    int x,y;
    x=0;
    y=0;

    if(*rotationPtr==rotationState[0])
    {
        x=block1->get_x();
        y=block1->get_y();
        x=x+2;
        y=y+1;
        ret1=checkPosition(&x,&y,blocks);

        x=block2->get_x();
        y=block2->get_y();
        x=x+1;
        ret2=checkPosition(&x,&y,blocks);

        x=block3->get_x();
        y=block3->get_y();
        y=y-1;
        ret3=checkPosition(&x,&y,blocks);

        x=block4->get_x();
        y=block4->get_y();
        x=x-1;
        y=y-2;
        ret4=checkPosition(&x,&y,blocks);
        
        return ret1+ret2+ret3+ret4;
    }
    if(*rotationPtr==rotationState[1])
    {
        x=block1->get_x();
        y=block1->get_y();
        x=x-1;
        y=y+2;
        ret1=checkPosition(&x,&y,blocks);

        x=block2->get_x();
        y=block2->get_y();
        y=y+1;
        ret2=checkPosition(&x,&y,blocks);

        x=block3->get_x();
        y=block3->get_y();
        x=x+1;
        ret3=checkPosition(&x,&y,blocks);

        x=block4->get_x();
        y=block4->get_y();
        x=x+2;
        y=y-1;
        ret4=checkPosition(&x,&y,blocks);
        
        return ret1+ret2+ret3+ret4;
    }
    if(*rotationPtr==rotationState[2])
    {
        x=block1->get_x();
        y=block1->get_y();
        x=x-2;
        y=y-1;
        ret1=checkPosition(&x,&y,blocks);

        x=block2->get_x();
        y=block2->get_y();
        x=x-1;
        ret2=checkPosition(&x,&y,blocks);

        x=block3->get_x();
        y=block3->get_y();
        y=y+1;
        ret3=checkPosition(&x,&y,blocks);

        x=block4->get_x();
        y=block4->get_y();
        x=x+1;
        y=y+2;
        ret4=checkPosition(&x,&y,blocks);
        
        return ret1+ret2+ret3+ret4;
    }
    if(*rotationPtr==rotationState[3])
    {
        x=block1->get_x();
        y=block1->get_y();
        x=x+1;
        y=y-2;
        ret1=checkPosition(&x,&y,blocks);

        x=block2->get_x();
        y=block2->get_y();
        y=y-1;
        ret2=checkPosition(&x,&y,blocks);

        x=block3->get_x();
        y=block3->get_y();
        x=x-1;
        ret3=checkPosition(&x,&y,blocks);

        x=block4->get_x();
        y=block4->get_y();
        x=x-2;
        y=y+1;
        ret4=checkPosition(&x,&y,blocks);
        
        return ret1+ret2+ret3+ret4;
    }
    return -1;
}

void I_Piece::rotatePiece()
{

    int ret1,ret2,ret3,ret4;
    int x,y;

    if(*rotationPtr==rotationState[0])
    {
        x=block1->get_x();
        y=block1->get_y();
        x=x+2;
        y=y+1;

        block1->set_x(x);
        block1->set_y(y);

        x=block2->get_x();
        y=block2->get_y();
        x=x+1;
        block2->set_x(x);
        block2->set_y(y);

        x=block3->get_x();
        y=block3->get_y();
        y=y-1;
        block3->set_x(x);
        block3->set_y(y);

        x=block4->get_x();
        y=block4->get_y();
        x=x-1;
        y=y-2;
        block4->set_x(x);
        block4->set_y(y);

        advancePtr();
        return;
        
    }
    if(*rotationPtr==rotationState[1])
    {
        x=block1->get_x();
        y=block1->get_y();
        x=x-1;
        y=y+2;
        block1->set_x(x);
        block1->set_y(y);

        x=block2->get_x();
        y=block2->get_y();
        y=y+1;
        block2->set_x(x);
        block2->set_y(y);

        x=block3->get_x();
        y=block3->get_y();
        x=x+1;
        block3->set_x(x);
        block3->set_y(y);

        x=block4->get_x();
        y=block4->get_y();
        x=x+2;
        y=y-1;
        block4->set_x(x);
        block4->set_y(y);
        
        advancePtr();
        return;
    }
    if(*rotationPtr==rotationState[2])
    {
        x=block1->get_x();
        y=block1->get_y();
        x=x-2;
        y=y-1;
        block1->set_x(x);
        block1->set_y(y);

        x=block2->get_x();
        y=block2->get_y();
        x=x-1;
        block2->set_x(x);
        block2->set_y(y);

        x=block3->get_x();
        y=block3->get_y();
        y=y+1;
        block3->set_x(x);
        block3->set_y(y);

        x=block4->get_x();
        y=block4->get_y();
        x=x+1;
        y=y+2;
        block4->set_x(x);
        block4->set_y(y);
        
        advancePtr();
        return;
    }
    if(*rotationPtr==rotationState[3])
    {
        x=block1->get_x();
        y=block1->get_y();
        x=x+1;
        y=y-2;
        block1->set_x(x);
        block1->set_y(y);

        x=block2->get_x();
        y=block2->get_y();
        y=y-1;
        block2->set_x(x);
        block2->set_y(y);

        x=block3->get_x();
        y=block3->get_y();
        x=x-1;
        block3->set_x(x);
        block3->set_y(y);

        x=block4->get_x();
        y=block4->get_y();
        x=x-2;
        y=y+1;
        block4->set_x(x);
        block4->set_y(y);
        
        advancePtr();
        return;
    }
}

T_Piece::T_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(7,1,c);
     block2 = std::make_shared<Square>(6,1,c);
     block3 = std::make_shared<Square>(6,0,c);
     block4 = std::make_shared<Square>(5,1,c);
}
