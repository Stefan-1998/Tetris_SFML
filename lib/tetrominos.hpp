#include "square.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


class Tetrominos
{
    public:
        void move();
        ~Tetrominos();
        void draw(sf::RenderWindow *w);
        

        //0, wenn Fallen möglich
        //-1 ansonsten
        int fall();

        void moveSideway(bool left);

    public:
        Square *block1; 
        Square *block2; 
        Square *block3; 
        Square *block4; 

};
