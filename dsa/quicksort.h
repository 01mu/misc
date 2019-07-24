/*
 * quicksort
 * github.com/01mu
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

template <class T>
class QuickSort
{
    private:
    T * arr;

    void swap(T & a, T & b);
    int partition(int l, int h);
    void sort(int l, int h);

    public:
    QuickSort(T * a, int l, int h);
};

#endif
