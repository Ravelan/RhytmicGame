#include "pch.h"
#include <functional>
Target::Target()
{
    this->ArrowTexture.loadFromFile("Png.png");
    DownTarget.setTexture(&this->ArrowTexture);
    DownTarget.setSize({ 50,50 });
    DownTarget.setOrigin({ 25,25 });
    DownTarget.setPosition({ 590,750 });
    UpTarget.setTexture(&this->ArrowTexture);
    UpTarget.setSize({ 50,50 });
    UpTarget.setOrigin({ 25,25 });
    UpTarget.setPosition({ 640,750 });
    UpTarget.rotate(180.0);
    LeftTarget.setTexture(&this->ArrowTexture);
    LeftTarget.setSize({ 50,50 });
    LeftTarget.setOrigin({ 25,25 });
    LeftTarget.setPosition({ 540,750 });
    LeftTarget.rotate(90.0);
    RightTarget.setTexture(&this->ArrowTexture);
    RightTarget.setSize({ 50,50 });
    RightTarget.setOrigin({ 25,25 });
    RightTarget.setPosition({ 690,750 });
    RightTarget.rotate(270.0);
}

void Target::update()
{
}

void Target::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->DownTarget, state);
    target.draw(this->UpTarget, state);
    target.draw(this->LeftTarget, state);
    target.draw(this->RightTarget, state);
}