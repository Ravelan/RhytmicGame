#pragma once
class ArrowShort : public Arrow
{
	sf::Texture ArrowTexture;
public:
	ArrowShort(std::string kierunek);
	ArrowShort() = delete;
	~ArrowShort() = default;
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};