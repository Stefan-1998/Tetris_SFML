#pragma once

#include "tetrominos.hpp"
#include <vector>

class L_Piece:public virtual Tetrominos
{
    public:
        L_Piece(sf::Color c);
        ~L_Piece();
    private:
        //int canRotate(std::vector<std::shared_ptr<Square>> *blocks);
        //void rotatePiece();
};


class J_Piece:public Tetrominos
{
    public:
        J_Piece(sf::Color c);
        ~J_Piece();
    private:
        //int canRotate(std::vector<std::shared_ptr<Square>> *blocks);
        //void rotatePiece();
};

class O_Piece:public Tetrominos
{
    public:
        O_Piece(sf::Color c);
        ~O_Piece();
    private:
        //int canRotate(std::vector<std::shared_ptr<Square>> *blocks);
        //void rotatePiece();
};

class S_Piece:public Tetrominos
{
    public:
        S_Piece(sf::Color c);
        ~S_Piece();
    private:
        //int canRotate(std::vector<std::shared_ptr<Square>> *blocks);
        //void rotatePiece();
};

class Z_Piece:public Tetrominos
{
    public:
        Z_Piece(sf::Color c);
        ~Z_Piece();
    private:
        //int canRotate(std::vector<std::shared_ptr<Square>> *blocks);
        //void rotatePiece();
};


class I_Piece:public Tetrominos
{
    public:
        I_Piece(sf::Color c);
        ~I_Piece();
    private:
        //int canRotate(std::vector<std::shared_ptr<Square>> *blocks);
        //void rotatePiece();
};


class T_Piece:public Tetrominos
{
    public:
        T_Piece(sf::Color c);
        ~T_Piece();
    private:
        //int canRotate(std::vector<std::shared_ptr<Square>> *blocks);
        //void rotatePiece();
};

