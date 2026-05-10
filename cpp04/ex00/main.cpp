
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    //const WrongAnimal* wrongmeta = new WrongAnimal();
    //const WrongAnimal* ia = new WrongCat();
    
    //std::cout << ia->getType() << " " << std::endl;
    //ia->makeSound();
    //wrongmeta->makeSound();

    delete meta;
    delete j;
    delete i;
    //delete wrongmeta;
    //delete ia;

    Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    for (int i = 0; i < 4; i++)
        delete animals[i];

    Dog a;
    Dog b(a);        // copy constructor
    Dog c;
    c = a;           // assignment
    
    a.makeSound();
    b.makeSound();
    c.makeSound();

    return 0;
}