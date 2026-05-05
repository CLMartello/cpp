
#ifndef FIXED_HPP

#define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed {
private:
    int                 _raw;
    static const int    _bits = 8;

public:
    Fixed();
    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &copy);
    ~Fixed();

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    
    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream    &operator<<(std::ostream &output, const Fixed &fixed);

#endif
