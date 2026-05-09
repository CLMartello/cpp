
#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(const std::string type) : Animal(type) {}

Animal::Animal(const Animal &copy) {
    this->_type = copy._type;
}

Animal &Animal::operator=(const Animal &copy) {
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

Animal::~Animal() {}

const std::string Animal::getType() const {
    return (_type);
}

void Animal::makeSound() {}
