#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include "../lib/configGlobal.hpp"
#include "../lib/square.hpp"
#include "../lib/playfield.hpp"

#include "../lib/tetrisPieces.hpp"
#include "../lib/factoryTetrominos.hpp"
#include "../lib/statemachine.hpp"

int main ()
{

    std::cout<<"Start"<<std::endl;
    Playfield *field= new Playfield(playfieldWidth,playfieldHight);
    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHight), "My Window");
    sf::Keyboard keyboard; 

    

    //Interrupt für das Fallen des Tetrominos
    sf::Clock clock;
    sf::Time interruptTime=sf::milliseconds(1500);
      

    Tetrominos *currentPiece;

    //Statemaschine initialisieren
    enum StateMachine currentState=createPiece;

    bool loop=true;
    while(loop)
    {
        //Ausschalten des Programmes
        if(keyboard.isKeyPressed(sf::Keyboard::Q) )
        {
            loop=false;
        }

        //Kreiieren neuer Tetrominos und Abändern der Statemaschine
        if(currentState==createPiece) 
        {
            currentPiece=FactoryTetrominos::createTetrominos();
            currentState=falling;
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

