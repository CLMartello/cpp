
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) {
    _type = type;
    std::cout << "WrongAnimal " << _type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    this->_type = copy._type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
    if (this != &copy)
        this->_type = copy._type;
    std::cout << "WrongAnimal operator assignment called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

const std::string WrongAnimal::getType() const {
    return (_type);
}

void WrongAnimal::makeSound() const {
    std::cout << "Grllllquaquabrlll" << std::endl;
}
