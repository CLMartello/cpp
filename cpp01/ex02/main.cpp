
#include <string>
#include <iostream>

int	main(void) {
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    //variable that holds the addres, needs * to access value
    std::string &stringREF = string;
    //another name, same variable
    //std::string stringREF = string; -> that is consider a copy, not a reference
    
    std::cout << &string << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << string << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
    
    return (0);
}
