
#include "Array.hpp"
#include <iostream>

int main(void)
{
    try
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

        Array<int> d = c;

        d[3] = 6;

        Array<char> e(4);

        e[0] = 'c';

        Array<std::string> f(2);

        f[0] = "banana";
        f[1] = "apple";

        std::cout << "b[3]: " << b[3] << std::endl;
        std::cout << "c[3]: " << c[3] << std::endl;
        std::cout << "d[3]: " << d[3] << std::endl;
        std::cout << "c[3]: " << c[3] << std::endl;
        std::cout << "e[0]: " << e[0] << std::endl;
        for (int i = 0; i < 2; i++)
            std::cout << f[i] << std::endl;
        std::cout << "c[-3]: " << c[-3] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}