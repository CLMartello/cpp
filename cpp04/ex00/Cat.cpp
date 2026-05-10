#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    this->_type = copy._type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
    if (this != &copy) {
        this->_type = copy._type;
    }
    std::cout << "Cat operator assignment called" << std::endl;
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "MiauAu" << std::endl;
}