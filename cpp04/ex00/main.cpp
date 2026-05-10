
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=============Constructors===========" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "=============Get Type===========" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "=============Make Sound===========" << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    std::cout << "=============Wrong Animal===========" << std::endl;
    const WrongAnimal* wrongmeta = new WrongAnimal();
    const WrongAnimal* ia = new WrongCat();
    
    std::cout << ia->getType() << " " << std::endl;
    ia->makeSound();
    wrongmeta->makeSound();

    std::cout << "=============Animal array===========" << std::endl;
    Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    std::cout << "=============Animal array sounds===========" << std::endl;
    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    std::cout << "=============Animal copy===========" << std::endl; 
    Dog a;
    Dog b(a);        // copy constructor
    Dog c;
    c = a;           // assignment
    
    a.makeSound();
    b.makeSound();
    c.makeSound();

    std::cout << "=============Destructors===========" << std::endl;
    delete meta;
    delete j;
    delete i;
    //delete wrongmeta;
    //delete ia;

    for (int i = 0; i < 4; i++)
    delete animals[i];

    return 0;
}