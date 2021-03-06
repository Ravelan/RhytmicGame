#include "pch.h"
Bomb::Bomb(std::string kierunek)
{
    {
        this->BombTexture.loadFromFile("Mine.png");
        if (kierunek == "left")
        {
            bomba.setTexture(&this->BombTexture);
            //bomba.setFillColor(sf::Color::Red);
            bomba.setSize({ 50,50 });
            bomba.setOrigin({ 25,25 });
            bomba.setPosition({ 540,0 });
            bomba.rotate(90.0);
        }
        if (kierunek == "right")
        {
            bomba.setTexture(&this->BombTexture);
            //bomba.setFillColor(sf::Color::Red);
            bomba.setSize({ 50,50 });
            bomba.setOrigin({ 25,25 });
            bomba.setPosition({ 690,0 });
            bomba.rotate(270.0);
        }

        if (kierunek == "up")
        {
            bomba.setTexture(&this->BombTexture);
            //bomba.setFillColor(sf::Color::Red);
            bomba.setSize({ 50,50 });
            bomba.setOrigin({ 25,25 });
            bomba.setPosition({ 640,0 });
            bomba.rotate(180.0);
        }

        if (kierunek == "down")
        {
            bomba.setTexture(&this->BombTexture);
            //bomba.setFillColor(sf::Color::Red);
            bomba.setSize({ 50,50 });
            bomba.setOrigin({ 25,25 });
            bomba.setPosition({ 590,0 });
        }
    }
}

void Bomb::update()
{
}

void Bomb::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->Strzalka, state);
}


