/*
 * quicksort
 * github.com/01mu
 */

#include "quicksort.h"

#ifndef QUICKSORT_CPP_
#define QUICKSORT_CPP_

template <class T>
void QuickSort<T>::swap(T & a, T & b)
{
    T temp = a;

    a = b;
    b = temp;
}

template <class T>
int QuickSort<T>::partition(int l, int h)
{
    int i;

    int pivot = arr[h];
    int j = l - 1;

    for(i = l; i <= h - 1; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[++j]);
        }
    }

    swap(arr[h], arr[++j]);

    return j;
}

template <class T>
void QuickSort<T>::sort(int l, int h)
{
    int pivot;

    if(l < h)
    {
        pivot = partition(l, h);

        sort(l, pivot - 1);
        sort(pivot + 1, h);
    }
}

template <class T>
QuickSort<T>::QuickSort(T * a, int l, int h)
{
    arr = a;

    sort(l, h - 1);
}

#endif
