
#ifndef ARRAY_HPP

#define ARRAY_HPP

#include <cstdlib>
#include <exception>

template <typename T>
class Array
{
private:
    T               *_data;
    unsigned int   _size;
public:
    Array();
    Array(unsigned int n);
    Array(Array &copy);
    Array<T> &operator=(const Array<T> &copy);
    ~Array();

    int size() const;
    T &operator[](const unsigned int n);

    class InvalidIndex: public std::exception
    {
    public:
        virtual const char * what() const throw()
        {
            return ("Invalid index");
        }
    };

};

template <typename T>
Array<T>::Array()
    : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _data = new T[n];
    _size = n;
}

template <typename T>
Array<T>::Array(Array &copy)
{
    this->_data = new T[copy.size()];
    for (int i = 0; i < copy.size(); i++)
    {
        this[i] = copy[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &copy)
{
    if (this != &copy)
    {
        delete[] this->_data;
        this->_data = new T[copy.size()];
        for (int i = 0; i < copy.size(); i++)
        {
            this[i] = copy[i];
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array ()
{
    delete[] _data;
}

template <typename T>
int Array<T>::size () const
{
    return(_size);
}

template <typename T>
T &Array<T>::operator[](const unsigned int n)
{
    if (n >= _size)
        throw InvalidIndex();
    return(_data[n]);
}

#endif