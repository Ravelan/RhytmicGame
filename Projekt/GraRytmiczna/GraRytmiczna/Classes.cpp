#include "pch.h"
#include "Classes.h"
#include <functional>
Game::Game() 
{
    this->bGroundTexture.loadFromFile("test.jpg");
    this->bGround.setTexture(this->bGroundTexture);
}
Game::~Game()
{
}
void Game::start()
{
    window.setFramerateLimit(60);
    sf::err().rdbuf(NULL);
    sf::Event event;
    window.pollEvent(event);
    writetext();
    //ekran startowy
    
    
    while (event.type != sf::Event::KeyPressed)
    {
        window.clear(sf::Color::Blue);
        window.pollEvent(event);
        startScreen();
        window.display();
    }
    text.setString("");
    setmap();
    while (window.isOpen())
    {
        window.clear();
        window.draw(this->bGround);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            
            
        }
        updateHp(-1);
        counter++;
        render();
        arrowReleased(event);
        arrowPressed(event);
        moveArrows();
        generateall();
        
        window.display();
    }
}

void Game::update()
{
}

void Game::render()
{
    for (auto i : ListaStrzalek)
    {
        window.draw(dynamic_cast<ArrowShort*>(i)->Strzalka);
    }
    for (auto i : ListaBomb)
    {
        window.draw(dynamic_cast<Bomb*>(i)->bomba);
    }
   
    window.draw(text);
    window.draw(health.healthBarOutline);
    window.draw(health.healthBar);
    window.draw(Cel_.DownTarget);
    window.draw(Cel_.UpTarget);
    window.draw(Cel_.LeftTarget);
    window.draw(Cel_.RightTarget);
}

void Game::moveArrows()
{
    for (auto i : ListaStrzalek)
    {
       dynamic_cast<ArrowShort*>(i)->Strzalka.move(0, gameSpeed);
    }
    for (auto i : ListaBomb)
    {
        dynamic_cast<Bomb*>(i)->bomba.move(0, gameSpeed);
    }
}


void Game::writetext()
{
    if (!font.loadFromFile("ArialUnicodeMS.ttf"))
    {
        // Error...
    }
    text.setFont(font);
    text.setString("");
    text.setCharacterSize(50);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition({ 540,300 });
}

void Game::setmap()
{
    mapa.insert(std::pair<int, std::string>(10, "najlepszy wynik"));
    mapa.insert(std::pair<int, std::string>(20, "dobry wynik"));
    mapa.insert(std::pair<int, std::string>(40, "sredni wynik"));
    mapa.insert(std::pair<int, std::string>(60, "zly wynik"));
}

std::string Game::searchinMap(int wartosc)
{
    for (auto i : mapa) {
        if (wartosc < i.first)
        {
            updateHp(150.0-i.first);
            return i.second;

        }
            
    }
    return "error";
}

void Game::arrowPressed(sf::Event event)
{
    if (sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Cel_.LeftTarget.setFillColor(sf::Color::Blue);
            double zmienna = deleteNearestArrow(Cel_.LeftTarget.getPosition().x, Cel_.LeftTarget.getPosition().y);
            double zmiennab = deleteNearestBomb(Cel_.LeftTarget.getPosition().x, Cel_.LeftTarget.getPosition().y);
            if(zmienna!=0)
            {
                text.setString(searchinMap(zmienna));
            }
            if (zmiennab)
                updateHp(-20);
                
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Cel_.RightTarget.setFillColor(sf::Color::Blue);
            double zmienna = deleteNearestArrow(Cel_.RightTarget.getPosition().x, Cel_.RightTarget.getPosition().y);
            double zmiennab = deleteNearestBomb(Cel_.RightTarget.getPosition().x, Cel_.RightTarget.getPosition().y);
            if (zmienna != 0)
            {
                text.setString(searchinMap(zmienna));
            }
            if (zmiennab)
                updateHp(-20);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Cel_.DownTarget.setFillColor(sf::Color::Blue);
            double zmienna = deleteNearestArrow(Cel_.DownTarget.getPosition().x, Cel_.DownTarget.getPosition().y);
            double zmiennab = deleteNearestBomb(Cel_.DownTarget.getPosition().x, Cel_.DownTarget.getPosition().y);
            if (zmienna != 0)
            {
                text.setString(searchinMap(zmienna));
            }
            if (zmiennab)
                updateHp(-20);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Cel_.UpTarget.setFillColor(sf::Color::Blue);
            double zmienna = deleteNearestArrow(Cel_.UpTarget.getPosition().x, Cel_.UpTarget.getPosition().y);
            double zmiennab = deleteNearestBomb(Cel_.UpTarget.getPosition().x, Cel_.UpTarget.getPosition().y);
            if (zmienna != 0)
            {
                text.setString(searchinMap(zmienna));
            }
            if (zmiennab)
                updateHp(-20);
        }
    }
   
}
void Game::arrowReleased(sf::Event event)
{
     if (sf::Event::KeyReleased)
    {
            Cel_.LeftTarget.setFillColor(sf::Color::White);
            Cel_.RightTarget.setFillColor(sf::Color::White);
            Cel_.DownTarget.setFillColor(sf::Color::White);
            Cel_.UpTarget.setFillColor(sf::Color::White);
    }
}

double Game::deleteNearestArrow(double x_, double y_)
{
    double y;
    double tempY=10000;
    std::list<GraphicObject*>::iterator it1 = ListaStrzalek.begin(), it2 = ListaStrzalek.begin();
    std::list<GraphicObject*>::iterator it3;
    for (auto i : ListaStrzalek)
    {
        if (x_ == dynamic_cast<ArrowShort*>(i)->Strzalka.getPosition().x)
        {
            y = dynamic_cast<ArrowShort*>(i)->Strzalka.getPosition().y;
            if (abs(y_ - y) < tempY)
            {
                tempY = abs(y_ - y);
                it2 = it1;
            }
        }
        it1++;
    }
        
    if (tempY < 50)
    {
        ListaStrzalek.erase(it2);
        return tempY;
    }
    
    return 0;
}
double Game::deleteNearestBomb(double x_, double y_)
{
    double y;
    double tempY = 10000;
    std::list<GraphicObject*>::iterator it1 = ListaBomb.begin(), it2 = ListaBomb.begin();
    std::list<GraphicObject*>::iterator it3;
    for (auto i : ListaBomb)
    {
        if (x_ == dynamic_cast<Bomb*>(i)->bomba.getPosition().x)
        {
            y = dynamic_cast<Bomb*>(i)->bomba.getPosition().y;
            if (abs(y_ - y) < tempY)
            {
                tempY = abs(y_ - y);
                it2 = it1;
            }
        }
        it1++;
    }
    if (tempY < 50)
    {
        ListaBomb.erase(it2);
        return tempY;
    }

    return 0;
}

void Game::startScreen()
{
    text.setString("Press Any Key to Start");
    text.setFillColor(sf::Color::Black);
    window.draw(text);   
}


void Game::updateHp(float value)
{
    health.healthBar.setSize({ health.healthBar.getSize().x + value,health.healthBar.getSize().y });
}

void Game::createArrow(int typeofArrow, std::string direction)
{
    if (typeofArrow == 1)
    {
        

        if (direction == "left")
        {
            ListaStrzalek.push_back(new ArrowShort("left"));
        }
        
        if (direction == "right")
        {

            ListaStrzalek.push_back(new ArrowShort("right"));
        }

        if (direction == "up")
        {

            ListaStrzalek.push_back(new ArrowShort("up"));
            ListaBomb.push_back(new Bomb("left"));
        }
        
        if (direction == "down")
        {
            ListaStrzalek.push_back(new ArrowShort("down"));
        }     

    }
}
void Game::createBomb(int typeofArrow, std::string direction)
{
        if (direction == "left")
        {
            ListaBomb.push_back(new Bomb("left"));
        }

        if (direction == "right")
        {

            ListaBomb.push_back(new Bomb("right"));
        }

        if (direction == "up")
        {

            ListaBomb.push_back(new Bomb("up"));
        }

        if (direction == "down")
        {
            ListaBomb.push_back(new Bomb("down"));
        }

}
void Game::generateall()
{
    if (counter < 10000)
    {
        if (counter % 20 == 0)
        {
            //losowanie zmiany tempa gry
            int zmiennarand = rand()%100;
            if (zmiennarand < 5)
                gameSpeed += 1;
            if (zmiennarand > 98)
                gameSpeed -= 0.5;
            zmiennarand=zmiennarand % 20;
            if (zmiennarand >= 3)
            {
                if (zmiennarand % 4 == 0)
                {
                    createArrow(1, "left");
                }
                if (zmiennarand % 4 == 1)
                {
                    createArrow(1, "right");
                }
                if (zmiennarand % 4 == 2)
                {
                    createArrow(1, "up");
                }
                if (zmiennarand % 4 == 3)
                {
                    createArrow(1, "down");
                }
            }
            else
            {
                if (zmiennarand % 4 == 0)
                {
                    createBomb(1, "left");
                }
                if (zmiennarand % 4 == 1)
                {
                    createBomb(1, "right");
                }
                if (zmiennarand % 4 == 2)
                {
                    createBomb(1, "up");
                }
                if (zmiennarand % 4 == 3)
                {
                    createBomb(1, "down");
                }
            }
        }
            
    }
    

}
