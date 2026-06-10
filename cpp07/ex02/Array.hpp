
#ifndef ARRAY_HPP

#define ARRAY_HPP

#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array
{
private:
    T               *_data;
    unsigned int   _size;
public:

    Array() : _data(NULL), _size(0) {}

    Array(unsigned int n)
    {
        if (n > 0)
        {
            _data = new T[n];
            _size = n;
        }
        else
        {
            _data = NULL;
            _size = 0;
        }
    }

    Array(const Array &copy)
    {
        this->_size = copy._size;
        this->_data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
        {
            this->_data[i] = copy._data[i];
        }
    }

    Array &operator=(const Array &copy)
    {
        if (this != &copy)
        {
            delete[] this->_data;
            this->_size = copy._size;
            this->_data = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
            {
                this->_data[i] = copy._data[i];
            }
        }
        return (*this);
    }

    ~Array()
    {
        if (_data)
            delete[] _data;
    }

    int size() const
    {
        return(_size);
    }

    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Invalid index");
        return(_data[index]);
    }

    const T &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Invalid index");
        return(_data[index]);
    }

};

#endif