#include "../lib/tetrisPieces.hpp"
#include <SFML/Graphics/Color.hpp>
#include "../lib/square.hpp"

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
     block1 = std::make_shared<Square>(5,0,c);
     block2 = std::make_shared<Square>(5,1,c);
     block3 = std::make_shared<Square>(6,0,c);
     block4 = std::make_shared<Square>(6,1,c);
}

S_Piece::S_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(5,1,c);
     block2 = std::make_shared<Square>(6,1,c);
     block3 = std::make_shared<Square>(6,0,c);
     block4 = std::make_shared<Square>(7,1,c);
}

Z_Piece::Z_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(5,0,c);
     block2 = std::make_shared<Square>(6,0,c);
     block3 = std::make_shared<Square>(6,1,c);
     block4 = std::make_shared<Square>(7,1,c);
}

I_Piece::I_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(5,0,c);
     block2 = std::make_shared<Square>(5,1,c);
     block3 = std::make_shared<Square>(5,2,c);
     block4 = std::make_shared<Square>(5,3,c);
}

T_Piece::T_Piece(sf::Color c)
{
     block1 = std::make_shared<Square>(5,1,c);
     block2 = std::make_shared<Square>(6,1,c);
     block3 = std::make_shared<Square>(7,1,c);
     block4 = std::make_shared<Square>(6,0,c);
}
