#pragma once 
#include "square.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>
#include "configGlobal.hpp"


class Tetrominos
{
    public:
        ~Tetrominos();
        Tetrominos();
        void draw(sf::RenderWindow *w);
        virtual void rotate(std::vector<std::shared_ptr<Square>> *blocks);
        

        //0, wenn Fallen möglich
        //-1 ansonsten
        int fall(std::vector<std::shared_ptr<Square>> *blocks);

        void moveSideway(bool left,std::vector<std::shared_ptr<Square>> *blocks);


        std::shared_ptr<Square> block1; 
        std::shared_ptr<Square> block2; 
        std::shared_ptr<Square> block3; 
        std::shared_ptr<Square> block4; 


        //return 0 when possible
        //-1 else
        int checkPosition(int *x,int *y,std::vector<std::shared_ptr<Square>> *blocks);


        //return 0 when possible
        //-1 else
        int checkOwnPosition(std::vector<std::shared_ptr<Square>> *blocks);
    private:




        //returns 0 when possible
        //else -1
        virtual int canRotate(std::vector<std::shared_ptr<Square>> *blocks);
        virtual void rotatePiece();

        //Position des Tetromino
        void leftOffset(int *x);
        void upperOffset(int *y);


        //Cacluclates the position of a block after 90° rotations
        //
        //
        //  |123|           |741|
        //  |456|   ->      |852|
        //  |789|   90°     |963|
        //
        //Jedes Tetromino (I-Tetromino wird exktra rotiert) passt om doe 3x3 Matrix
        //Die Drehung der Poositionen kann mit einer mathematischen Formel 
        //dargestellt werden. Mit Modulo und Geteilt und den Offset 
        //kann die neue Position der Blöcke berechnet werden 
        void calculateRotation(int blockNumber,int *x,int *y);
            

};
