#include "Vector2.hpp"

int main()
{
    Vector2 a;
    Vector2 b;
    
    std::cin >> a;
    
    double angle = 0;
    std::cin >> angle;
    
    a.rotate(angle * M_PI / 180);
    std::cout << a << std::endl;
    
    return 0;
}
