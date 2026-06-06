
#ifndef SERIALIZER_HPP

#define SERIALIZER_HPP

#include <string>
#include <cstdint>

struct Data {
    int value;
};

class Serializer {
private:
    Serializer();
    Serializer(Serializer &copy);
    Serializer &operator=(Serializer &copy);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    //unsigned integer type guaranteed to be large enough to hold a pointer

};

#endif