
#include "Array.hpp"
#include <iostream>

int main(void)
{
    Array<int> a;
    std::cout << "size of default int array a: " << a.size() << std::endl;

    Array<int> b(7);
    std::cout << "size of int array b: " << b.size() << std::endl;

    for (int i = 0; i < b.size(); i++) {
        b[i] = 2;
    }

    Array<int> c(b);

    for (int i = 0; i < c.size(); i++) {
        c[i] = 4;
    }

    std::cout << "c[3]: " << c[3] << std::endl;

}