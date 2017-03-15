#include "Game.hpp"
#include "include.h"

Game::Game()
{
    new(&map) Map();
    
    new(&texture) sf::Texture();
    texture.loadFromFile("hero.png");
    
    new(&hero) sf::Sprite();
    hero.setTexture(texture);
    hero.setScale(1, 1);
    hero.setPosition(0, 0);
    
    new(&bullets) std::vector<sf::CircleShape>();
    
    new(&window) sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Shooter");
    new(&event)  sf::Event();
}

void* Game::operator new(size_t size, void* where)
{
    return where;
}

int Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        
        window.clear(sf::Color::White);
        drawMap();
        
        window.display();
        map.update(DIFF_TIME);
    }
    
    return 0;
}

int Game::processEvents()
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
                
            case sf::Event::KeyPressed:
                processKeyPressed();
                break;
                
            case sf::Event::MouseMoved:
                processMouseMoved();
                break;
                
            case sf::Event::MouseButtonPressed:
                processMouseButtonPressed();
                break;
                
            default:
                map.hero.setVelocity(Vector2(0, 0));
                break;
        }
    }
    
    return 0;
}

int Game::processKeyPressed()
{
    switch(event.key.code)
    {
        case sf::Keyboard::Up:
            map.hero.setVelocity(Vector2(0, -MAX_VELOCITY));
            break;
            
        case sf::Keyboard::Down:
            map.hero.setVelocity(Vector2(0, MAX_VELOCITY));
            break;
            
        case sf::Keyboard::Left:
            map.hero.setVelocity(Vector2(-MAX_VELOCITY, 0));
            break;
            
        case sf::Keyboard::Right:
            map.hero.setVelocity(Vector2(MAX_VELOCITY, 0));
            break;
            
        default:
            map.hero.setVelocity(Vector2(0, 0));
            break;
    }
    
    return 0;
}

int Game::processMouseMoved()
{
    sf::Vector2f heroPosition = hero.getPosition();
    
    Vector2 direction;
    direction.x = event.mouseMove.x - heroPosition.x;
    direction.y = event.mouseMove.y - heroPosition.y;
    map.hero.setDirection(direction);
    
    return 0;
}

int Game::processMouseButtonPressed()
{
    sf::Vector2f heroPosition = hero.getPosition();
    
    Vector2 mousePosition(event.mouseButton.x - heroPosition.x, event.mouseButton.y - heroPosition.y);
    
    map.bullets.push_back(Bullet(map.hero.getDirection().norm() * BULLET_VELOCITY, map.hero.getPosition()));
    
    /*for (auto& bullet : bullets)
    {
        if (checkBoardOfCircle(bullet))
        {
            bullets.erase(bullets.begin());
        }
    }*/
    
    return 0;
}

int Game::drawMap()
{
    Vector2 heroPosition = map.hero.getPosition();
    
    hero.setPosition(heroPosition.x, heroPosition.y);
    hero.setRotation(360. - map.hero.getDirection().getAngleBetween(Vector2(0, -1)));
    
    Vector2 bulletPosition;
    sf::CircleShape bulletShape(BULLET_RADIUS);
    
    for (int i = 0; i < map.bullets.size(); i++)
    {
        bulletShape.setFillColor(sf::Color::Red);
        bulletShape.setPosition(bulletPosition.x, bulletPosition.y);
        bullets.push_back(bulletShape);
        
        bulletPosition = map.bullets[i].getPosition();
        bullets[i].setPosition(bulletPosition.x, bulletPosition.y);
        
        window.draw(bullets[i]);
    }
    
    window.draw(hero);
    
    for (auto& bullet : bullets)
    {
        if (!checkBoardOfCircle(bullet))
        {
            bullets.erase(bullets.begin());
            std::cout << bullet.getPosition().x << " " << bullet.getPosition().y << std::endl;
        }
    }
    
    return 0;
}

bool Game::checkBoardOfCircle(const sf::CircleShape &circle) const
{
    sf::Vector2f circlePos = circle.getPosition();
    
    if (circlePos.x < 0 || circlePos.y < 0 || circlePos.x > map.size.x || circlePos.y > map.size.y)
    {
        return false;
    }
    
    return true;
}
