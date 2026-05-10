
#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; 1 < 100; i++)
        _ideas[i] = "";
}

Brain::Brain(const Brain &copy) {
    for (int i = 0; i < 100; i++)
        _ideas[i] = copy._ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy) {
    if (this != &copy) {
        for (int i = 0; i < 100; i++)
            _ideas[i] = copy._ideas[i];
    }
    std::cout << "Brain operator assignment called" << std::endl;
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}