
#include "Serializer.hpp"
#include <iostream>

int main()

{
    Data data;
    data.value = 42;

    std::cout << data.value << std::endl;

    uintptr_t raw = Serializer::serialize(&data);

    std::cout << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);

    std::cout << ptr->value << std::endl;
}
