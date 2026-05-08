
#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &copy) {
    *this = copy;
}

Point &Point::operator=(const Point &copy) {
    if (this != &copy)
    return(*this);
}