
#include "Serializer.hpp"

//not converting data
//keeping memory and only visualizing different
//storying a pointer as a number, and then returning it
uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}
//take memory address
//store it as an integer
//serialize = convert a pointer into an integer representation

//uintptr_t = TYPE of unsigned integer that is big enought to store a pointer

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}
//take integer
//treat as a pointer

//needs reinterpret_cast because those are not normal convertions
//also, integer -> pointer is not a safe conversion

//reinterpret_cast = treat these bit as anothr type
//but no convert it, no computate it, just reinterpretate it