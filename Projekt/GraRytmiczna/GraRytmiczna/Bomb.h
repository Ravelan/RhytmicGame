#pragma once
class Bomb : public Movable
{
	sf::Texture BombTexture;
public:
	sf::RectangleShape bomba;
	Bomb(std::string kierunek);
	Bomb() = delete;
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};
