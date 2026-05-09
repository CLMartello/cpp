
#ifndef CAT_HPP

#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
private:

public:
    Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &copy);
    ~Animal();

};

#endif