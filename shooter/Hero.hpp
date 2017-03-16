#ifndef Hero_hpp
#define Hero_hpp

#include "Vector2.hpp"

class Bullet // Bullet is a circle
{
public:
    Bullet ();
    Bullet (const Vector2& vel, const Vector2& pos_);
    ~Bullet();
    
    Vector2 getPosition() const;
    double  getRadius  () const;
    
    void update(double dt);
    
    void setVelocity(const Vector2& _velocity);
    void setPosition(const Vector2& position);
    
    bool checkBoards(const Vector2& size) const;
    
private:
    Vector2 pos;
    Vector2 velocity;
    double  radius;
    
    /*
    думаю const можно опустить, т.к. уже constexpr написали
    */
    constexpr static const double INIT_RADIUS = 1.;
    constexpr static const double RAD_POSION  = 1.;
    constexpr static const double POS_POSION  = 1.;
    constexpr static const double VEL_POSION  = 1.;
};



class Hero
{
public:
    Hero (double _radius = INIT_RADIUS);
    ~Hero();
    
    Vector2 getVelocity () const;
    Vector2 getDirection() const;
    Vector2 getPosition () const;
    double  getRadius   () const;
    
    void update(double dt);
    
    void setPosition (const Vector2& _pos);
    void setVelocity (const Vector2& vel);
    void setDirection(const Vector2& dir);
    void setRadius   (const double   rad);
    
private:
    Vector2 pos; // center of Hero
    Vector2 velocity;
    Vector2 direction;
    double  radius;
    
    constexpr static const double INIT_RADIUS = 100.; // in pixeles
    
    constexpr static const double POS_POISON = -666;
    constexpr static const double VEL_POISON = -666;
    constexpr static const double DIR_POISON = -666;
    constexpr static const double RAD_POISON = -666;
    
#ifndef NDEBUG
public:
#else
private:
#endif // NDEBUG
    bool ok  () const;
    void dump() const;
};

#endif /* Hero_hpp */
