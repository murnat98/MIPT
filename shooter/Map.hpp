#ifndef Map_hpp
#define Map_hpp

#include "Hero.hpp"
#include <vector>

class Map
{
public:
    Map ();
    ~Map();
    
    void update(double dt);
    
    void* operator new(size_t size, void* where);
public:
    Vector2 size;
    Hero hero;
    std::vector<Bullet> bullets;
    
private:
    bool checkBoards();
};

#endif /* Map_hpp */
