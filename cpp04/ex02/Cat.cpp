#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    _brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
    if (this != &copy) {
        this->_type = copy._type;
        delete this->_brain;
        this->_brain = new Brain(*copy._brain);
    }
    std::cout << "Cat operator assignment called" << std::endl;
    return (*this);
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "MiauAu" << std::endl;
}

Brain   *Cat::getBrain() const {
    return (this->_brain);
}

