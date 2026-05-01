
#include "Harl.hpp"

int main(void) {
    Harl    harlinho;
    std::cout << "Make Harl DEBUG" << std::endl;
    harlinho.complain("DEBUG");
    std::cout << std::endl;
    std::cout << "Now make Harl INFO" << std::endl;
    harlinho.complain("INFO");
    std::cout << std::endl;
    std::cout << "It is getting dangerous, make Harl WARNING" << std::endl;
    harlinho.complain("WARNING");
    std::cout << std::endl;
    std::cout << "It is unavoidable! Make Harl ERROR" << std::endl;
    harlinho.complain("ERROR");
    return (0);
}

// int main(int argc, char **argv) {
//     if (argc != 2)
//         return(std::cout << "Run ./harl LEVEL only" << std::endl, 1);
    
//     Harl    harlinho;
//     harlinho.complain(argv[1]);
//     return (0);
// }