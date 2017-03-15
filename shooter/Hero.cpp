#include "Hero.hpp"

Bullet::Bullet()
{
    radius = INIT_RADIUS;
    
    velocity = 0;
    pos      = 0;
}

Bullet::Bullet(const Vector2& vel, const Vector2& pos_)
{
    radius = INIT_RADIUS;
    
    velocity = vel;
    pos      = pos_;
}

Bullet::~Bullet()
{
    radius   = RAD_POSION;
    velocity = VEL_POSION;
    pos      = POS_POSION;
}

Vector2 Bullet::getPosition() const
{
    return pos;
}

double Bullet::getRadius() const
{
    return radius;
}

void Bullet::update(double dt)
{
    pos += velocity * dt;
}

void Bullet::setVelocity(const Vector2& _velocity)
{
    velocity = _velocity;
}

void Bullet::setPosition(const Vector2& position)
{
    pos = position;
}

bool Bullet::checkBoards(const Vector2& size) const
{
    Vector2 bulletPosition = getPosition();
    double bulletX    = bulletPosition.x;
    double bulletY    = bulletPosition.y;
    
    double bulletDiametr = getRadius() * 2;
    double sizeX = size.x - bulletDiametr;
    double sizeY = size.y - bulletDiametr;
    
    bool boardOk = true;
    
    if (bulletX < 0)
    {
        return false;
    }
    
    if (bulletY < 0)
    {
        return false;
    }
    
    if (bulletX > sizeX)
    {
        return false;
    }
    
    if (bulletY > sizeY)
    {
        return false;
    }
    
    return true;
}


Hero::Hero(double _radius)
{
    radius = _radius;
    
    pos.x = 0;
    pos.y = 0;
    
    velocity = 0;
    
    direction.x = 1;
    direction.y = 0;
}

Hero::~Hero()
{
    pos       = POS_POISON;
    direction = DIR_POISON;
    velocity  = VEL_POISON;
    radius    = RAD_POISON;
}

Vector2 Hero::getVelocity() const
{
    return velocity;
}

Vector2 Hero::getDirection() const
{
    return direction;
}

Vector2 Hero::getPosition() const
{
    return pos;
}

double Hero::getRadius() const
{
    return radius;
}

void Hero::update(double dt)
{
    pos += velocity * dt;
}

void Hero::setPosition(const Vector2 &_pos)
{
    pos = _pos;
}

void Hero::setVelocity(const Vector2& vel)
{
    velocity = vel;
}

void Hero::setDirection(const Vector2& dir)
{
    direction = dir;
}

void Hero::setRadius(const double rad)
{
    radius = rad;
}
