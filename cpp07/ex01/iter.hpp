
#ifndef ITER_HPP

#define ITER_HPP

template <typename T>
void    iter(T *array, const int size, void (f)(T&))
{
    for (int i = 0; i < size; i++)
    {
        f(array[i]);
    }
}

template <typename T>
void    iter(T *array, const int size, void (f)(const T&))
{
    for (int i = 0; i < size; i++)
    {
        f(array[i]);
    }
}

#endif