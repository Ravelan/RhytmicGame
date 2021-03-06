#pragma once
#include "HpBar.h"
#include "Target.h"
#include "ArrowShort.h"
#include "Bomb.h"

class Game
{

	sf::Texture bGroundTexture;
	sf::Sprite bGround;
	sf::Texture ArrowTexture;
	sf::RenderWindow window = { sf::VideoMode(1280,800),"gra" };
	sf::Text text;
	sf::Font font;
	std::map<int, std::string> mapa;

	

public:
	std::list<GraphicObject*> ListaStrzalek;
	std::list<GraphicObject*> ListaBomb;
	double gameSpeed=5;
	int counter = 0;
	HealthBar health;
	Target Cel_;
	//HpBar
	Game();
	~Game();
	void start();
	void update();
	void render();
	void setArrow();
	void moveArrows();
	void combo();
	void writetext();
	void setmap();
	std::string searchinMap(int wartosc);
	void arrowPressed( sf::Event event );
	void arrowReleased(sf::Event event);
	double deleteNearestArrow(double x_, double y_);
	double deleteNearestBomb(double x_, double y_);
	void startScreen();
	void updateHp(float value);
	void moveBomb();
	void createArrow(int typeofArrow, std::string direction);
	void createBomb(int typeofArrow, std::string direction);
	void generateall();
};



class GameMenu
{
};



