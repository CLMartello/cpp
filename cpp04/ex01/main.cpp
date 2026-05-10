
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* k = new Cat();

    // int size = 4;

    // Animal *array[size];

    // for (int i = 0; i < (size / 2); i++)
    //     array[i] = new Cat();

    // for (int i = 50; i < size; i++)
    //     array[i] = new Dog();

    // for (int i = 0; i < size; i++)
    //     array[i]->makeSound();
        
    // for (int i = 0; i < size; i++)
    //     delete array[i];
    
    delete j;
    delete k;

    return 0;
}