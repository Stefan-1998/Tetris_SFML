#include "../lib/factoryTetrominos.hpp"
#include <SFML/Graphics/Color.hpp>
#include <stdlib.h>
#include <time.h>

Tetrominos* FactoryTetrominos::createTetrominos()
{
    srand(time(NULL));
    //Durch eine Zufallszahl wird das erzeugte Tetromino entschieden
    int selectedForm=rand()%7;

    //Durch eine Zufallszahl wird die Farbe entschieden
    int selectedColor=rand()%6;

    sf::Color blockColor=get_color(&selectedColor);


    switch(selectedForm)
    {
        case 0: return new O_Piece(blockColor) ;
        case 1: return new S_Piece(blockColor) ;
        case 2: return new Z_Piece(blockColor) ;
        case 3: return new T_Piece(blockColor) ;
        case 4: return new L_Piece(blockColor) ;
        case 5: return new J_Piece(blockColor) ;
        case 6: return new I_Piece(blockColor) ;
        default: return new I_Piece(blockColor) ;
    }
}


 sf::Color FactoryTetrominos::get_color(int* selectedColor)
{
    switch(*selectedColor)
    {
        case 0: return sf::Color::Red;
        case 1: return sf::Color::Green;
        case 2: return sf::Color::Blue;
        case 3: return sf::Color::Yellow;
        case 4: return sf::Color::Magenta;
        case 5: return sf::Color::Cyan;
        default: return sf::Color::Red;
    }
}
