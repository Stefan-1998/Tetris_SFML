#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include "../lib/configGlobal.hpp"
#include "../lib/square.hpp"
#include "../lib/playfield.hpp"

#include "../lib/tetrisPieces.hpp"
#include "../lib/factoryTetrominos.hpp"
#include "../lib/statemachine.hpp"

#include <SFML/Window/Window.hpp>
#include <iostream>


/*
 *TO-Do
    Kolliesionsabfrage bei seitwärts Bewegungen
    Drehen ist noch sehr "unintuitiv"
    Abbruch
 *
 *
 * */

int main ()
{

    Playfield *field= new Playfield(playfieldWidth,playfieldHight);
    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHight), "My Window");
    window.setPosition(sf::Vector2i(windowPositionsX,windowPositionsY));

    bool enableInterrupt=true; //Probleme mit Free

    //Tastaturinput
    sf::Keyboard keyboard;
    sf::Event event;
    

    //Interrupt für das Fallen des Tetrominos
    sf::Clock clock;
    sf::Time interruptTime=sf::milliseconds(1500);
      

    Tetrominos *currentPiece;

    //Statemaschine initialisieren
    enum StateMachine currentState=createPiece;

    bool loop=true;
    while(loop)
    {

        //Kreiieren neuer Tetrominos und Abändern der Statemaschine
        if(currentState==createPiece) 
        {
            std::cout<<"Kreiere Block"<<std::endl;
            currentPiece=FactoryTetrominos::createTetrominos();
            currentState=falling;
        }
        

        //Ausschalten des Programmes
        if(keyboard.isKeyPressed(sf::Keyboard::Q))
        {
            loop=false;
        }

        //Holen der Event, wie Tastaturdruck
        while(window.pollEvent(event))
        {
            if(currentState==falling)
            {
                if((event.type==sf::Event::KeyPressed) &&(event.key.code==sf::Keyboard::Left))
                {
                    if(enableInterrupt)
                    {
                        //moveLeft 
                        currentPiece->moveSideway(true,&field->blocks);
                    }
                }                

                if((event.type==sf::Event::KeyPressed) &&(event.key.code==sf::Keyboard::Right))
                {
                    if(enableInterrupt)
                    {
                        //moveRigth 
                        currentPiece->moveSideway(false,&field->blocks);
                    }
                }                

                if((event.type==sf::Event::KeyPressed) &&(event.key.code==sf::Keyboard::Up))
                {
                    if(enableInterrupt)
                    {
                        //moveRigth 
                        currentPiece->rotate(&field->blocks);
                    }
                }                
                if((event.type==sf::Event::KeyPressed) &&(event.key.code==sf::Keyboard::Down))
                {
                    if(enableInterrupt)
                    {
                        if(currentPiece!=NULL)
                        {
                            //moveRigth 
                            int canFall;
                            canFall=currentPiece->fall(&field->blocks);
                            if(canFall!=0)
                            {
                                field->blocks.push_back(currentPiece->block1);
                                field->blocks.push_back(currentPiece->block2);
                                field->blocks.push_back(currentPiece->block3);
                                field->blocks.push_back(currentPiece->block4);

                                delete currentPiece;

                                field->sort();
                                field->checkTetris();
                    

                                currentState=createPiece;
                                clock.restart();
                                
                            }
                        }
                    }
                }                
            }
        }

        //Interrupt für das Fallen
        if(clock.getElapsedTime()>interruptTime)
        {   
            enableInterrupt=false;
            if(currentState==falling)
            {
                if(currentPiece!=NULL)
                {
                    //Fallesn
                    int canFall;
                    canFall=currentPiece->fall(&field->blocks);

                    if(canFall!=0)
                    {
                        field->blocks.push_back(currentPiece->block1);
                        field->blocks.push_back(currentPiece->block2);
                        field->blocks.push_back(currentPiece->block3);
                        field->blocks.push_back(currentPiece->block4);

                        delete currentPiece;

                        field->sort();
                        field->checkTetris();


                        currentState=createPiece;
                        clock.restart();

                    }
                }
            }
            enableInterrupt=true;
            clock.restart();
        }

        //Darstellen der Komponenten
        window.clear();
        //Zeichnen des Spielfeldes
        field->draw(&window);


        //Zeichnen der Abgespeicherten Blöcke
        int safedBlocksSize=field->blocks.size();
        for(int i=0;i<safedBlocksSize;i++)
        {
            field->blocks.at(i)->draw(&window);
        }
        

        if(currentState==falling)
        {
            currentPiece->draw(&window);
        }
    
        //Darstellen des Bildes
        window.display();

    }
    

    return 0;

}

