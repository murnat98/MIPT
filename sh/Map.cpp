#include "Map.hpp"
#include "include.h"

Map::Map()
{
    size.x = WINDOW_SIZE_X;
    size.y = WINDOW_SIZE_Y;
}

Map::~Map()
{
    size = 0;
}

void Map::update(double dt)
{
    hero.update(dt);
    
    for (auto& b : bullets)
    {
        b.update(dt);
    }
}
