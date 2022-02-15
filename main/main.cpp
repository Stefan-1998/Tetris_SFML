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

int main ()
{

    Playfield *field= new Playfield(playfieldWidth,playfieldHight);
    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHight), "My Window");
    window.setPosition(sf::Vector2i(windowPositionsX,windowPositionsY));

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

            if((event.type==sf::Event::KeyPressed) &&(event.key.code==sf::Keyboard::Left))
            {
                //moveLeft 
                currentPiece->moveSideway(true);
            }                

            if((event.type==sf::Event::KeyPressed) &&(event.key.code==sf::Keyboard::Right))
            {
                //moveRigth 
                currentPiece->moveSideway(false);
            }                
        }

        //Interrupt für das Fallen
        if(clock.getElapsedTime()>interruptTime)
        {   
            //Fallesn
            int canFall;
            canFall=currentPiece->fall();

            clock.restart();
        }

        //Darstellen der Komponenten
        window.clear();
        //Zeichnen des Spielfeldes
        field->draw(&window);
        currentPiece->draw(&window);
    
        //Darstellen des Bildes
        window.display();

    }
    

    return 0;

}

