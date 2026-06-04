
#include "Serializer.hpp"

//not converting data
//keeping memory and only visualizing different
uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}
//take memory address
//store it as an integer

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}
//take integer
//treat as a pointer

//needs reinterpret_cast because those are not normal convertions
//also, integer -> pointer is not a safe conversion