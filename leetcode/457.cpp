/*
 * https://leetcode.com/problems/circular-array-loop/
 */

#include <iostream>

using namespace std;

int checkCycle(const int * vals, const int n) {
    int found = 0;

    for(int i = 0; i < n; i++) {
        const int orig = i;
        int idx = orig;

        int count = 0;
        int first = 0;
        int length = 0;

        int pass = 0;

        if(vals[idx] > 0) {
            first = 1;
        } else {
            first = 0;
        }

        while(1) {
            if((vals[idx] < 0 && first == 1) || (vals[idx] > 0 && first == 0)) {
                break;
            }

            count += vals[idx];
            idx = count + idx;
            count = 0;

            length++;

            if(idx >= n) {
                idx = idx - n;
                pass = 1;
            }

            if(idx < 0) {
                idx = idx + n;
                pass = 1;
            }

            if(idx == orig && pass) {
                if(length > 1) {
                    cout << idx << " ";
                    found = 1;
                    break;
                } else if(length == 1) {
                    found = 0;
                    break;
                }
            }
        }
    }

    cout << endl;

    return found;
}

int main()
{
    const int n = 5;

    //const int vals[2] = {-1, 2};
    const int vals[5] = {2, -1, 1, 2, 2};
    //const int vals[5] = {-2, 1, -1, -2, -2};

    cout << checkCycle(vals, n);
}
