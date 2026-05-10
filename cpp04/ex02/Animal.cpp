
#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string type) {
    _type = type;
    std::cout << "Animal " << _type << " constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
    this->_type = copy._type;
    std::cout << "Animal copy assignment called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy) {
    if (this != &copy)
        this->_type = copy._type;
    std::cout << "Animal assignment operator called" << std::endl;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

const std::string Animal::getType() const {
    return (_type);
}
