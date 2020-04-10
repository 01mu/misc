/*
 * linked list
 * github.com/01mu
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <string>
#include <vector>

template <class T>
class LinkedList
{
    private:
    struct Item
    {
        T data;
        Item * next = NULL;
        Item * prev = NULL;
    };

    Item * head;
    int ll_size;

    public:

    struct Ass
    {
        T data;
        Item * next = NULL;
        Item * prev = NULL;
    };

    LinkedList(T data);
    ~LinkedList();

    void insert(T data);
    int find(T needle);
    T remove(int index);

    int size();

    std::string to_string();
    void to_vector(std::vector<T> & vector);
};

#endif
