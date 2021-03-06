#pragma once
class GraphicObject: public sf::Drawable
{
public:
	virtual void update() = 0;
};

class Movable : public  GraphicObject
{
public:
	sf::RectangleShape Strzalka;
};



class Arrow : public Movable
{
public:
	Arrow();
};



class ArrowLongT : public Arrow
{

};

class ArrowLongH : public Arrow
{

};

class Immovable : public GraphicObject
{

};

class HealthBar : public Immovable
{
public:
	sf::RectangleShape healthBar;
	sf::RectangleShape healthBarOutline;
	HealthBar();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

class SongDuration : public  Immovable
{
};



class ComboCounter :public  Immovable
{

};

