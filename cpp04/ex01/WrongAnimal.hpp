
#ifndef WRONGANIMAL_HPP

#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(const std::string type);
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal &operator=(const WrongAnimal &copy);
    ~WrongAnimal();

    const std::string getType() const;
    void makeSound() const;

};

#endif