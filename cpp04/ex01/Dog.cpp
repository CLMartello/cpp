
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    _brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
    if (this != &copy) {
        this->_type = copy._type;
        delete this->_brain;
        this->_brain = new Brain(*copy._brain);
    }
    std::cout << "Dog operator assignment called" << std::endl;
    return (*this);
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "AuAu" << std::endl;
}

Brain   *Dog::getBrain() const {
    return (this->_brain);
}

