
#ifndef FIXED_HPP

#define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed {
private:
    int                 _raw;
    static const int    _bits = 8;

public:
    //Orthodox Canonical Form
    Fixed();
    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &copy);
    ~Fixed();

    //Getter and Setter
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    
    //Conversion
    float   toFloat( void ) const;
    int     toInt( void ) const;

    //Comparison operators
    bool    operator>(const Fixed &fixed) const;
    bool    operator<(const Fixed &fixed) const;
    bool    operator>=(const Fixed &fixed) const;
    bool    operator<=(const Fixed &fixed) const;
    bool    operator==(const Fixed &fixed) const;
    bool    operator!=(const Fixed &fixed) const;

    //Arithmetic operators
    Fixed operator+(const Fixed &fixed) const;
    Fixed operator-(const Fixed &fixed) const;
    Fixed operator*(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;

    //Increment and decrement
    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);

    //Static functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream    &operator<<(std::ostream &output, const Fixed &fixed);

#endif
