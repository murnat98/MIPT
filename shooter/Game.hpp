#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include "Map.hpp"

#ifndef NDEBUG
#include <iostream>
#endif // NDEBUG

class Game
{
public:
    Game();
    
    void* operator new (size_t size, void* where);
    
    int run();
    
public:
    Map map;
    
private:
    std::vector<sf::CircleShape> bullets;
    sf::Sprite hero;
    sf::RenderWindow window;
    sf::Event event;
    sf::Texture texture;
    
    int processEvents            ();
    int processKeyPressed        ();
    int processMouseMoved        ();
    int processMouseButtonPressed();
    
    int drawMap();
    
    bool checkBoardOfCircle(const sf::CircleShape& circle) const;
};

#endif /* Game_hpp */
