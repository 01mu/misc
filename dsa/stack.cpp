/*
 * stack
 * github.com/01mu
 */

#include "stack.h"

#ifndef STACK_CPP_
#define STACK_CPP_

template <class T>
Stack<T>::Stack()
{
    st_size = 0;
    stack = new T[0];
}

template <class T>
Stack<T>::Stack(int sz)
{
    st_size = sz;
    stack = new T[sz];
}

template <class T>
Stack<T>::Stack(int sz, T * init)
{
    int i;

    st_size = sz;
    stack = new T[sz];

    for(i = 0; i < st_size; i++)
    {
        stack[i] = init[i];
    }
}

template <class T>
Stack<T>::~Stack()
{
    delete[] stack;
}

template <class T>
void Stack<T>::push(T value)
{
    int i;
    int new_size = st_size + 1;

    T temp[new_size];

    copy(temp, stack, st_size);
    temp[st_size] = value;
    new_stack(temp, new_size);
    st_size++;
}

template <class T>
void Stack<T>::clear()
{
    delete[] stack;
    stack = new T[0];
    st_size = 0;
}

template <class T>
T Stack<T>::at(int index)
{
    return stack[index];
}

template <class T>
T Stack<T>::pop()
{
    int i;
    int new_size = st_size - 1;
    T out = stack[st_size - 1];

    T temp[new_size];

    copy(temp, stack, new_size);
    new_stack(temp, new_size);
    st_size--;

    return out;
}

template <class T>
T Stack<T>::top()
{
   return stack[st_size - 1];
}

template <class T>
int Stack<T>::size()
{
   return st_size;
}

template <class T>
std::string Stack<T>::to_string()
{
    std::string st_str = "";
    int i;

    for(i = 0; i < st_size; i++)
    {
        st_str += std::to_string(stack[i]);

        if(i != st_size - 1)
        {
            st_str += " ";
        }
    }

    return st_str;
}

template <class T>
void Stack<T>::to_vector(std::vector<T> & vector)
{
    int i;

    vector.resize(st_size);

    for(i = 0; i < st_size; i++)
    {
        vector.at(i) = stack[i];
    }
}

template <class T>
void Stack<T>::copy(T * to, T * from, int c)
{
    int i;

    for(i = 0; i < c; i++)
    {
        to[i] = from[i];
    }
}

template <class T>
void Stack<T>::new_stack(T * temp, int new_size)
{
    delete[] stack;
    stack = new T[new_size];

    copy(stack, temp, new_size);
}

#endif
