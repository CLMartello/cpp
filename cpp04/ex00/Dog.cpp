
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Sog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
    this->_type = copy._type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
    if (this != &copy) {
        this->_type = copy._type;
    }
    std::cout << "Dog operator assignment called" << std::endl;
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "AuAu" << std::endl;
}