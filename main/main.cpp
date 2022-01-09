#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include<SFML/Window.hpp>
#include<SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>



int main ()
{
    std::cout<<"Hello World!"<<std::endl;

    sf::RenderWindow window(sf::VideoMode(800,600), "My Window");
    sf::Keyboard keyboard; 

    sf::CircleShape circ(100.f);
    circ.setFillColor(sf::Color::Green);

    sf::Vector2f vect1;
    vect1.x=200;
    vect1.y=200;

    sf::RectangleShape rect(vect1);
    rect.setFillColor(sf::Color::Blue);
    rect.setPosition(100,100);
    
    bool loop=true;
    while(loop)
    {
        if(keyboard.isKeyPressed(sf::Keyboard::Q) )
        {
            loop=false;
        }
        window.clear();
        window.draw(circ);
        window.draw(rect);
        window.display();
            
    
    }


    return 0;

}

