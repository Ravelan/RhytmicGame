#include "pch.h"
ArrowShort::ArrowShort(std::string kierunek)
{
    this->ArrowTexture.loadFromFile("Png.png");
    if (kierunek == "left")
    {
        Strzalka.setTexture(&this->ArrowTexture);
        Strzalka.setSize({ 50,50 });
        Strzalka.setOrigin({ 25,25 });
        Strzalka.setPosition({ 540,0 });
        Strzalka.rotate(90.0);
    }
    if (kierunek == "right")
    {
        Strzalka.setTexture(&this->ArrowTexture);
        Strzalka.setSize({ 50,50 });
        Strzalka.setOrigin({ 25,25 });
        Strzalka.setPosition({ 690,0 });
        Strzalka.rotate(270.0);
    }

    if (kierunek == "up")
    {
        Strzalka.setTexture(&this->ArrowTexture);
        Strzalka.setSize({ 50,50 });
        Strzalka.setOrigin({ 25,25 });
        Strzalka.setPosition({ 640,0 });
        Strzalka.rotate(180.0);
    }

    if (kierunek == "down")
    {
        Strzalka.setTexture(&this->ArrowTexture);
        Strzalka.setSize({ 50,50 });
        Strzalka.setOrigin({ 25,25 });
        Strzalka.setPosition({ 590,0 });
    }
}

void ArrowShort::update()
{
}

void ArrowShort::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->Strzalka, state);
}