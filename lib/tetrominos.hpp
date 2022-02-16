#include "square.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>


class Tetrominos
{
    public:
        void move();
        ~Tetrominos();
        void draw(sf::RenderWindow *w);
        

        //0, wenn Fallen möglich
        //-1 ansonsten
        int fall(std::vector<std::shared_ptr<Square>>*blocks);

        void moveSideway(bool left);

    public:
        std::shared_ptr<Square> block1; 
        std::shared_ptr<Square> block2; 
        std::shared_ptr<Square> block3; 
        std::shared_ptr<Square> block4; 

};
