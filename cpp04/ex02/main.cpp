
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* k = new Cat();
    
    delete j;
    delete k;

    return 0;
}