#include "Vector2.hpp"

Vector2::Vector2 (double _x, double _y):
    x(_x),
    y(_y)
{}

double Vector2::getX() const
{
    return x;
}

double Vector2::getY() const
{
    return y;
}

Vector2 Vector2::operator +(const Vector2& other) const
{
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator -(const Vector2& other) const
{
    return Vector2(x - other.x, y - other.y);
}

Vector2& Vector2::operator +=(const Vector2& other)
{
    x += other.x;
    y += other.y;
    
    return *this;
}

Vector2& Vector2::operator -=(const Vector2& other)
{
    x -= other.x;
    y -= other.y;
    
    return *this;
}

Vector2 Vector2::operator -() const
{
    return Vector2(-x, -y);
}

double Vector2::operator *(const Vector2& other) const
{
    return x * other.x + y * other.y;
}

double Vector2::operator ^(const Vector2& other) const
{
    return x * other.y - y * other.x;
}

Vector2 Vector2::operator *(const double value) const
{
    return Vector2(x * value, y * value);
}

Vector2 Vector2::operator /(const double value) const
{
    return Vector2(x / value, y / value);
}

Vector2 operator *(const double value, const Vector2& vec)
{
    return vec * value;
}

double Vector2::len() const
{
    return sqrt(x * x + y * y);
}

Vector2 Vector2::norm() const
{
    double size = len();
    
    return Vector2(x / size, y / size);
}

Vector2 Vector2::perpendicular() const
{
    return Vector2(y, -x);
}

Vector2 Vector2::rotate(double angle)
{
    double oldX = x;
    double oldY = y;
    
    x = oldX * cos(angle) - oldY * sin(angle);
    y = oldX * sin(angle) + oldY * cos(angle);
    
    return Vector2(x, y);
}

Vector2 Vector2::getRotated(double angle) const
{
    return Vector2(x, y).rotate(angle);
}

std::istream& operator >>(std::istream& stream, Vector2& vec)
{
    stream >> vec.x;
    stream >> vec.y;
    
    return stream;
}

std::ostream& operator <<(std::ostream& stream, const Vector2& vec)
{
    stream << "(" << vec.x << ", " << vec.y << ")";
    
    return stream;
}


//================================DEBUG===================================

int Vector2::vector2Dump()
{
    std::ofstream dump("dump.vecdmp", std::ofstream::app);
    
    dump << x << " " << y << std::endl;
    
    dump.close();
    
    return 0;
}

bool Vector2::vector2OK()
{
    return true;
}

//================================DEBUG===================================
