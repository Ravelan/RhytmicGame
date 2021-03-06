
#include "pch.h"
#include <functional>
HealthBar::HealthBar()
{
    healthBar.setSize({ 200,25 });
    healthBarOutline.setSize({ 200,25 });
    healthBar.setOrigin({ 0,0 });
    healthBarOutline.setOrigin({ 0,0 });
    healthBar.setPosition({ 800,50 });
    healthBarOutline.setPosition({ 800,50 });
    healthBar.setFillColor(sf::Color::Red);
    healthBarOutline.setFillColor(sf::Color::Transparent);
    healthBarOutline.setOutlineThickness(5.0);
    healthBarOutline.setOutlineColor(sf::Color::Black);
}
void HealthBar::update()
{
}
void HealthBar::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->healthBar, state);
    target.draw(this->healthBarOutline, state);
}







Arrow::Arrow()
{
}

