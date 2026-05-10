
#ifndef ANIMAL_HPP

#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
    std::string _type;

public:
    Animal();
    Animal(const std::string type);
    Animal(const Animal &copy);
    Animal &operator=(const Animal &copy);
    virtual ~Animal();
    //allows call child class destructor before parent class destructor

    const std::string getType() const;
    virtual void makeSound() const;
    //virtual allow to run correct function at time
    //will run dog makesound, not animal makesound

};

#endif