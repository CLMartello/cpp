
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=============Constructors===========" << std::endl;
    const Animal* j = new Dog();
    const Animal* k = new Cat();
    std::cout << std::endl;

    std::cout << "=============Array===========" << std::endl;
    int size = 6;

    Animal *array[size];

    std::cout << "=============Half Cat Creation===========" << std::endl;
    for (int i = 0; i < (size / 2); i++)
        array[i] = new Cat();
    std::cout << std::endl;

    std::cout << "=============Half Dog Creation===========" << std::endl;
    for (int i = size / 2; i < size; i++)
        array[i] = new Dog();
    std::cout << std::endl;

    std::cout << "=============Array Make Sound===========" << std::endl;
    for (int i = 0; i < size; i++)
        array[i]->makeSound();
    std::cout << std::endl;

    std::cout << "=============Array Destructors===========" << std::endl;  
    for (int i = 0; i < size; i++)
        delete array[i];
    std::cout << std::endl;

    std::cout << "=============Deep copies===========" << std::endl;
    Cat original;
    Cat copy = original;

    std::cout << std::endl;
    original.getBrain()->setIdea(0, "I am the original Cat");

    std::cout << "original brain: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "copy brain: " << copy.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << "=============Destructors===========" << std::endl;
    delete j;
    delete k;

    return 0;
}