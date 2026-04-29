
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *horde = new Zombie[N];
	//new Zombie[] will create a array of objects
	//but will be necessary use the default constructor with no parameters
	//and a new function to set the parameters one by one afterwards
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return (horde);
}
