#ifndef Vector2_hpp
#define Vector2_hpp

#include <iostream>
#include <string>
#include <cmath>
#ifndef VECTOR2NDEBUG
#include <fstream>
#endif // VECTOR2NDEBUG

class Vector2
{
public:
    Vector2 (double _x = 0, double _y = 0);
    
    // здесь можно не писать деструктор, т.к. он всё равно будет создал автоматически
    ~Vector2();
    
    Vector2  operator + (const Vector2& other) const;
    Vector2  operator - (const Vector2& other) const;
    Vector2& operator +=(const Vector2& other)      ;
    Vector2& operator -=(const Vector2& other)      ;
    Vector2  operator - (                    ) const;
    
    double operator *(const Vector2& other) const;
    double operator ^(const Vector2& other) const;
    
    Vector2 operator *(const double value) const;
    Vector2 operator /(const double value) const;
    
    friend Vector2 operator *(const double value, const Vector2& vec);
    
    double  len          () const;
    Vector2 norm         () const;
    Vector2 perpendicular() const;
    
    friend std::istream& operator >>(std::istream& stream,       Vector2& vec);
    friend std::ostream& operator <<(std::ostream& stream, const Vector2& vec);
    
    //================================DEBUG===================================
    
#ifndef VECTOR2NDEBUG
public:
#else
private:
#endif // VECTOR2NDEBUG
    
    int  vector2Dump();
    bool vector2OK  ();
    
    //================================DEBUG===================================
    
private:
// FIXIT: лучше оставить x и y в public ... иначе надо писать методы доступа к полям ...
    double x;
    double y;
};



#endif /* Vector2_hpp */
