/*
 * stack
 * github.com/01mu
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <string>
#include <vector>

template<class T>
class Stack
{
    private:
    int st_size;
    T * stack;
    void copy(T * to, T * from, int c);
    void new_stack(T * temp, int new_size);

    public:
    Stack();
    Stack(int sz);
    Stack(int sz, T * init);
    ~Stack();

    void push(T value);
    void clear();
    T at(int index);
    T pop();
    T top();

    int size();

    std::string to_string();
    void to_vector(std::vector<T> & vector);
};

#endif
