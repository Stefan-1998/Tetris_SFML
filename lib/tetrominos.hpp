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
        void move();
        void draw(sf::RenderWindow *w);
        void rotate(std::vector<std::shared_ptr<Square>> *blocks);
        

        //0, wenn Fallen möglich
        //-1 ansonsten
        int fall(std::vector<std::shared_ptr<Square>> *blocks);

        void moveSideway(bool left);


        std::shared_ptr<Square> block1; 
        std::shared_ptr<Square> block2; 
        std::shared_ptr<Square> block3; 
        std::shared_ptr<Square> block4; 


    private:

        const int rotationState[4]={0,90,180,270};
        const int *rotationPtr;
        void advancePtr();

        //return 0 when possible
        //-1 else
        int checkPosition(int *x,int *y,std::vector<std::shared_ptr<Square>> *blocks);


        //returns 0 when possible
        //else -1
        virtual int canRotate(std::vector<std::shared_ptr<Square>> *blocks);
        virtual void rotatePiece();

        //Position des Tetromino
        void leftOffset(int *x);
        void upperOffset(int *y);


        //Cacluclates the position of a block after 90° rotations
        void calculateRotation(int blockNumber,int *x,int *y);
            

};
