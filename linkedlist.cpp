/*
 * linked list
 * github.com/01mu
 */

#include "linkedlist.h"

#ifndef LINKEDLIST_CPP_
#define LINKEDLIST_CPP_

template <class T>
LinkedList<T>::LinkedList(T data)
{
    head = new Item;
    head->data = data;
    ll_size = 1;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Item * recent = head;
    Item * temp_del = head;

    while(recent->next != NULL)
    {
        delete temp_del;

        recent = recent->next;
        temp_del = recent;
    }

    delete recent;
}

template <class T>
void LinkedList<T>::insert(T data)
{
    Item * recent = head;
    Item * new_item = new Item;

    while(recent->next != NULL)
    {
        recent = recent->next;
    }

    new_item->data = data;
    new_item->prev = recent;

    recent->next = new_item;
    ll_size++;
}

template <class T>
int LinkedList<T>::find(T needle)
{
    int index = -1;
    int i = 0;

    Item * recent = head;

    if(recent->data == needle)
    {
        return 0;
    }

    while(recent->next != NULL)
    {
        if(recent->next->data == needle)
        {
            index = i + 1;
            break;
        }

        recent = recent->next;
        i++;
    }

    return index;
}

template <class T>
T LinkedList<T>::remove(int index)
{
    int i = 1;

    Item * recent = head;
    Item * temp;

    T data;

    if(index == 0)
    {
        temp = head->next;
        data = head->data;
        temp->prev = NULL;
        delete head;
        head = temp;
        ll_size--;
    }

    while(recent->next != NULL)
    {
        if(index == i)
        {
            temp = recent->next;
            data = temp->data;

            if(temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }

            if(temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }

            delete temp;
            ll_size--;
            break;
        }

        recent = recent->next;
        i++;
    }

    return data;
}

template <class T>
std::string LinkedList<T>::to_string()
{
    Item * recent = head;
    std::string ll_str = std::to_string(recent->data) + " ";

    while(recent->next != NULL)
    {
        recent = recent->next;

        ll_str += std::to_string(recent->data);

        if(recent->next)
        {
            ll_str += " ";
        }
    }

    return ll_str;
}

template <class T>
int LinkedList<T>::size()
{
   return ll_size;
}

template <class T>
void LinkedList<T>::to_vector(std::vector<T> & vector)
{
    int i = 0;

    Item * recent = head;

    vector.resize(size);
    vector.at(i++) = recent->data;

    while(recent->next != NULL)
    {
        recent = recent->next;
        vector.at(i++) = recent->data;
    }
}

#endif
