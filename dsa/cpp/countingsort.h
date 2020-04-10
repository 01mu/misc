/*
 * counting sort
 * github.com/01mu
 */

#ifndef COUNTINGSORT_H_
#define COUNTINGSORT_H_

template <class T>
class CountingSort
{
    private:
    int get_max(T * a, int size);

    public:
    CountingSort(T * a, int size);
};

#endif
