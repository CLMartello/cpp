
#include "Fixed.hpp"

Fixed::Fixed(): _raw(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw) {
    std::cout << "Int constructor called" << std::endl;
    _raw = raw << _bits;
    //_raw = raw * 256;
    //<< _bits is the same as << 8, which is the same as << 2^8, which is the same as * 256 bits
}

Fixed::Fixed(float const raw) {
    std::cout << "Float constructor called" << std::endl;
    _raw = roundf(raw * (1 << _bits));
    //float has no bit-shift operator
    //so we have to bit-shift a int 1, and then multiple by the float
    //and round it to have the result more precise
    //otherwise 1356,8 will be 1356 and not 1357
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        _raw = copy.getRawBits();
    return(*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return(_raw);
}

void    Fixed::setRawBits( int const raw ) {
    _raw = raw;
}

float   Fixed::toFloat( void ) const {
    return ((float)_raw / (1 << _bits));
}

int     Fixed::toInt( void ) const {
    return (_raw >> _bits);
}

std::ostream    &operator<<(std::ostream &output, const Fixed &fixed) {
    output << fixed.toFloat();
    return (output);
}

bool    Fixed::operator>(const Fixed &fixed) const {
    return (_raw > fixed._raw);
}

bool    Fixed::operator<(const Fixed &fixed) const {
    return (_raw < fixed._raw);
}

bool    Fixed::operator>=(const Fixed &fixed) const {
    return (_raw >= fixed._raw);
}

bool    Fixed::operator<=(const Fixed &fixed) const {
    return (_raw <= fixed._raw);
}

bool    Fixed::operator==(const Fixed &fixed) const {
    return (_raw == fixed._raw);
}

bool    Fixed::operator!=(const Fixed &fixed) const {
    return (_raw != fixed._raw);
}

Fixed   Fixed::operator+(const Fixed &fixed) const {
    Fixed   result;
    result._raw = this->_raw + fixed._raw;
    return (result);
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    Fixed   result;
    result._raw = this->_raw - fixed._raw;
    return (result);
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    Fixed   result;
    result._raw = this->_raw * fixed._raw;
    return (result);
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    Fixed   result;
    result._raw = this->_raw / fixed._raw;
    return (result);
}

Fixed &Fixed::operator++(void) {
    ++_raw;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed   result(*this);
    ++_raw;
    return (result);
}

Fixed &Fixed::operator--(void) {
    --_raw;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed   result(*this);
    --_raw;
    return (result);
}

static Fixed &Fixed::min(Fixed &a, Fixed &b) {}

static const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {}

static Fixed &Fixed::max(Fixed &a, Fixed &b) {}

static const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {}