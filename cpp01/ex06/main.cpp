
#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
        return(std::cout << "Run ./harl LEVEL only" << std::endl, 1);
    
    Harl    harlinho;
    harlinho.complain(argv[1]);
    return (0);
}