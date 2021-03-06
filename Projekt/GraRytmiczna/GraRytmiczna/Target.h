#pragma once
class Target : public  Immovable
{
public:
	sf::RectangleShape LeftTarget;
	sf::RectangleShape RightTarget;
	sf::RectangleShape UpTarget;
	sf::RectangleShape DownTarget;
	sf::Texture ArrowTexture;
	Target();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};