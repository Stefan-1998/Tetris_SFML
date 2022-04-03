
#include "../lib/playfield.hpp"
#include "../lib/configGlobal.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <memory>
#include <vector>
#include <iterator>

Playfield::Playfield(int width, int hight):m_width(width),m_hight(hight)
{
    //Punktzahl
    m_points=0;


    //Spielfeld
    sf::Vector2f size;
    size.x=m_width;
    size.y=m_hight;

    playfield=new sf::RectangleShape();
    playfield->setSize(size);
    playfield->setPosition(playfieldOffsetLeft,playfieldOffsetUp);
    playfield->setFillColor(sf::Color::White);

    size.x=size.x+10;
    size.y=size.y+10;
    frame = new sf::RectangleShape();
    frame->setSize(size);
    frame->setPosition(playfieldOffsetLeft-5,playfieldOffsetUp-5);
    frame->setFillColor(sf::Color::Blue);

    //Vector für die gespeicherten Blöcke
    blocks.clear();
        
}


Playfield::~Playfield()
{
    delete( playfield);
    delete( frame);
    blocks.clear();
    
    //delete blocks;
    std::cout<<"Spielfeld wurde destroyed"<<std::endl;
    
}

void Playfield::draw(sf::RenderWindow * window)
{
    //Zeichnen des Spielfeldes
    window->draw(*frame);
    window->draw(*playfield);
}


void Playfield::sort()
{
    //bubblesort
    //Es kommen immer bloß 4 Blöcke hinzu-> Bubblesort aufreichend
    //Die ersten Elemete sind die oberen

    int i,j;
    bool swapped;

    //Alle blöcke durchgehen
    for(i=0;i<blocks.size()-1;i++)
    {
        swapped=false;
        for(j=0;j<blocks.size()-i-1;j++)
        {
            //Kontrolle, ob der nächste Block unterhalt liegt
            if(blocks.at(j)->get_y()>blocks.at(j+1)->get_y())
            {
                //Tauschen
                blocks.at(j).swap(blocks.at(j+1));
            
                swapped=true;
            }
            //Bei gleicher Höhe der aktuellen und kommenden Blocks
            //muss auf den x-Wert geachtet werden
            else if(blocks.at(j)->get_y()==blocks.at(j+1)->get_y())
            {
                if(blocks.at(j)->get_x()>blocks.at(j+1)->get_x())
                {
                    //Tauschen
                    blocks.at(j).swap(blocks.at(j+1));
                    swapped=true;
                }
            }
        }
        //kein Tausch-> Sortieren fertig
        if(swapped==false)
            break;
    }
}

void Playfield::checkTetris()
{
    int lines=0;
    int currentLine;
    int lastLine=sizeHightInBlocks-1;
    int counter=0;
    std::vector<int> buffer;
    for(int i=0;i<blocks.size();i++)
    {
        //Vektor ist sotiert
        //Vergleicht die y-Werte
        currentLine=blocks.at(i)->get_y();   
        if(currentLine==lastLine)
        {
            //Bei gleichem y-Wert wird erhöht
            counter++;

            //Fall komplette Reihe ist voll
            if(counter==sizeWidthInBlocks-1)
            {
                //Abspeichern der Linie
               buffer.push_back(currentLine);
            }
        }
        else
        {
            lastLine=currentLine;
            counter=0;
        }

    }


    //Berechnen der Punkte
    //Überprüft außerdem, ob mehrere Reihen ein Tetris oder ähnliches formen
    int Tetris=1;
    if(buffer.size()>0)
    {
        for(int i=0;i<buffer.size()-1;i++)
        {
            if(buffer.at(i)+1==buffer.at(i+1))
            {
                Tetris++;
            }
            else
            {
                switch(Tetris)
                {
                    case 1: m_points=m_points+100;break;
                    case 2: m_points=m_points+200;break;
                    case 3: m_points=m_points+300;break;
                    case 4: m_points=m_points+500;break;
                    default: ;
                }

                Tetris=1;
            }
        }
        switch(Tetris)
        {
            case 1: m_points=m_points+100;break;
            case 2: m_points=m_points+200;break;
            case 3: m_points=m_points+300;break;
            case 4: m_points=m_points+500;break;
            default: ;
        }
    }

    //Das Arbeiten mit Vektoren hier ist sehr ineffizent. 
    //Es kann ggf. verbessert werden mit List
    std::shared_ptr<Square> currentBlock;
    std::vector<std::shared_ptr<Square>>::iterator iter; 
    
    //Löschen der Blöcke
    for(int i=0;i<buffer.size();i++)
    {
        iter=blocks.begin();

        std::cout<<buffer[i]<<std::endl;
        do
        {
            currentBlock=*iter;
            if(currentBlock->get_y()==buffer[i])
            {
                blocks.erase(iter);
                iter=blocks.begin();

            }
            std::advance(iter,1);
        }while(iter!=blocks.end());
    }
    //Verschieben der Blöcke nach unten
    for(int i=0;i<buffer.size();i++)
    {
        iter=blocks.begin();

        while(iter!=blocks.end())
        {
            
            currentBlock=*iter;
            if(currentBlock->get_y()<buffer[i])
            {
                currentBlock->fall();
            }
            advance(iter,1);
        }
    }

}

void Playfield::print()
{
    for(int i=0;i<blocks.size();i++)
    {
        std::cout<<"Block"<<i+1<<"\n";
        std::cout<<"y\t"<<blocks.at(i)->get_y()<<"\n";
        std::cout<<"x\t"<<blocks.at(i)->get_x()<<std::endl;
    }

    std::cout<<"\n\n Points \t"<<m_points<<"\n"<<std::endl;
}

