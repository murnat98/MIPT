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
    
    /*
        Вы выбрали не лучший вариант из двух предложенных ранее. 
        Вы сделали только getter'ы
        А как поменять значение полей x,y?)
        
        Нужны ещё setter'ы.
        
        Лучше просто поместите x,y в public. Ей удобно будет пользоваться.
    */
    double getX() const;
    double getY() const;
    
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
    
    double  len          (            ) const;
    Vector2 norm         (            ) const;
    Vector2 perpendicular(            ) const;
    Vector2 rotate       (double angle);
    Vector2 getRotated   (double angle) const;
    
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
    double x;
    double y;
};



#endif /* Vector2_hpp */
