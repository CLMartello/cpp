
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {}

Dog::Dog(const Dog &copy) : Animal(copy) {
    this->_type = copy._type;
}

Dog &Dog::operator=(const Dog &copy) {
    if (this != &copy) {
        this->_type = copy._type;
    }
    return (*this);
}

Dog::~Dog() {}