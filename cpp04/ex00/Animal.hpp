
#ifndef ANIMAL_HPP

#define ANIMAL_HPP

#include <string>

class Animal {
protected:
    std::string _type;

public:
    Animal();
    Animal(const std::string type);
    Animal(const Animal &copy);
    Animal &operator=(const Animal &copy);
    ~Animal();

    const std::string getType() const;
    void makeSound();

};

#endif