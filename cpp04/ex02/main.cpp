
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=============Constructors===========" << std::endl;
    Cat cat;
    //Animal animal; //does not allow compilation
    //Animal secondCat = new Cat();
    Dog dog;
    std::cout << std::endl;

    std::cout << "=============CatDog===========" << std::endl;
    cat.makeSound();
    dog.getBrain()->setIdea(0, "I am so happy cpp04 is over");
    std::cout << dog.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << "=============Destructors===========" << std::endl;

    return 0;
}