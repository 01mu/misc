/*
 * counting sort
 * github.com/01mu
 */

#include "countingsort.h"

#ifndef COUNTINGSORT_CPP_
#define COUNTINGSORT_CPP_

template <class T>
int CountingSort<T>::get_max(T * a, int size)
{
    int i;

    int max = a[0];

    for(i = 1; i < size; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    return ++max;
}

template <class T>
CountingSort<T>::CountingSort(T * a, int size)
{
    int i;

    int max = get_max(a, size);

    int * count = new int[max];
    int * out = new int[size];

    for(i = 0; i < max; i++)
    {
        count[i] = 0;
    }

    for(i = 0; i < size; i++)
    {
        count[a[i]]++;
    }

    for(i = 1; i < max; i++)
    {
        count[i] += count[i - 1];
    }

    for(i = 0; i < size; i++)
    {
        out[--count[a[i]]] = a[i];
    }

    for(i = 0; i < size; i++)
    {
        a[i] = out[i];
    }

    delete[] count;
    delete[] out;
}

#endif
