#pragma once

#include "tetrominos.hpp"
#include <vector>

class L_Piece:public Tetrominos
{
    public:
        L_Piece(sf::Color c);
        ~L_Piece();
};


class J_Piece:public Tetrominos
{
    public:
        J_Piece(sf::Color c);
        ~J_Piece();
};

class O_Piece:public Tetrominos
{
    public:
        O_Piece(sf::Color c);
        ~O_Piece();
};

class S_Piece:public Tetrominos
{
    public:
        S_Piece(sf::Color c);
        ~S_Piece();
};

class Z_Piece:public Tetrominos
{
    public:
        Z_Piece(sf::Color c);
        ~Z_Piece();
};


class I_Piece:public Tetrominos
{
    public:
        I_Piece(sf::Color c);
        ~I_Piece();
        void rotate(std::vector<std::shared_ptr<Square>> *blocks);
    private:
        int canRotate(std::vector<std::shared_ptr<Square>> *blocks);
        void rotatePiece();
        int rotationState[4]={0,90,180,270};
        int *rotationPtr;
        void advancePtr();
};


class T_Piece:public Tetrominos
{
    public:
        T_Piece(sf::Color c);
        ~T_Piece();
};

