#include "Map.hpp"
#include "include.h"

Map::Map()
{
    size.x = WINDOW_SIZE_X;
    size.y = WINDOW_SIZE_Y;
    
    new(&hero) Hero();
}

void* Map::operator new(size_t size, void* where)
{
    return where;
}

Map::~Map()
{
    size = 0;
}

void Map::update(double dt)
{
    if (checkBoards())
    {
        hero.update(dt);
    }
    
    for (auto& bullet : bullets)
    {
        if (bullet.checkBoards(size))
        {
            bullet.update(dt);
        }
        else
        {
            bullets.erase(bullets.begin());
        }
    }
}

bool Map::checkBoards()
{
    Vector2 heroPosition = hero.getPosition();
    double heroX    = heroPosition.x;
    double heroY    = heroPosition.y;
    
    double heroDiametr = hero.getRadius() * 2;
    double sizeX = size.x - heroDiametr;
    double sizeY = size.y - heroDiametr;
    
    bool boardOk = true;
    
    if (heroX < 0)
    {
        hero.setPosition(Vector2(0, heroY));
        
        boardOk = false;
    }
    
    if (heroY < 0)
    {
        hero.setPosition(Vector2(heroX, 0));
        
        boardOk = false;
    }
    
    if (heroX > sizeX)
    {
        hero.setPosition(Vector2(sizeX, heroY));
        
        boardOk = false;
    }
    
    if (heroY > sizeY)
    {
        hero.setPosition(Vector2(heroX, sizeY));
        
        boardOk = false;
    }
    
    return boardOk;
}
