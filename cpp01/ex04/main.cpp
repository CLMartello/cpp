
#include "Replace.hpp"

int main(int argc, char **argv) {

    if (argc != 4)
        return (std::cerr << "Arguments must be: ./program filename s1 s2\n", 1);
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    return (replace(filename, s1, s2));
}
