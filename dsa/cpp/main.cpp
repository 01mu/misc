#include <iostream>
#include <string>
#include <fstream>

#include "stack.cpp"
#include "linkedlist.cpp"
#include "quicksort.cpp"
#include "countingsort.cpp"
#include "bst.cpp"

using namespace std;

void read_vals(int * a);
void display_vals(int * a, int c);

const unsigned int c = 100;
const string file_name = "numbers_100";

int nums[c];
int arr[10] = {2, 1, 0, 9, 8, 12, 13, 3, 5, 14};

int main()
{
    BST<int> bst(arr, 10);

    bst.remove(5);
    bst.inorder();

    return 0;
}

void read_vals(int * a)
{
    int i = 0;

    ifstream input;
    string line;

    input.open(file_name);

    if(input.is_open())
    {
        while(getline(input, line))
        {
            a[i] = stoi(line);
            i++;
        }

        input.close();
    }
}

void display_vals(int * a, int c)
{
    int i;

    for(i = 0; i < c; i++)
    {
        cout << i << " " << a[i] << endl;
    }
}
