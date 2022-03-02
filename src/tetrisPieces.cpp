#include "../lib/tetrisPieces.hpp"
#include <SFML/Graphics/Color.hpp>
#include <ios>
#include <vector>
#include "../lib/square.hpp"

L_Piece::L_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(6,0,c);
     block2 = std::make_shared<Square>(6,1,c);
     block3 = std::make_shared<Square>(6,2,c);
     block4 = std::make_shared<Square>(7,2,c);
}

/*int L_Piece::canRotate(std::vector<std::shared_ptr<Square>> *blocks)
{
    int *x,*y;
    int ret1, ret2, ret3, ret4;
    switch(*rotationPtr)
    {
        case 0:
            //Position holen
            *x=block1->get_x();
            *y=block1->get_y();

            //zukünftige Blockposition
            *x=*x+2; 

            //Überprüfen
            ret1=checkPosition(x,y,blocks);

            //Position holen
            *x=block2->get_x();
            *y=block2->get_y();

            //zukünftige Blockposition
            *x=*x+1; 
            *y=*y-1; 

            //Überprüfen
            ret2=checkPosition(x,y,blocks);

            //Position holen
            *x=block3->get_x();
            *y=block3->get_y();

            //zukünftige Blockposition
            *x=*x+2; 
            *y=*y-2; 

            //Überprüfen
            ret3=checkPosition(x,y,blocks);

            //Position holen
            *x=block4->get_x();
            *y=block4->get_y();

            //zukünftige Blockposition
            *x=*x-1; 
            *y=*y-1; 

            //Überprüfen
            ret4=checkPosition(x,y,blocks);

            break;
        case 90:
            break;
        case 180:
            break;
        case 270:
            break;
        default:
            return -1;
    }
    return ret1+ret2+ret3+ret4;
}*/



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
     block1 = std::make_shared<Square>(5,3,c);
     block2 = std::make_shared<Square>(5,2,c);
     block3 = std::make_shared<Square>(5,1,c);
     block4 = std::make_shared<Square>(5,0,c);
}

T_Piece::T_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(7,1,c);
     block2 = std::make_shared<Square>(6,1,c);
     block3 = std::make_shared<Square>(6,0,c);
     block4 = std::make_shared<Square>(5,1,c);
}
