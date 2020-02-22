#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int low_d = digits(low), high_d = digits(high), i, v;
        vector<int> res;

        for(i = low_d; i <= high_d; i++) {
            v = 123456789/(int) pow(10, 9-i);

            while(v <= pow(10, 9)/pow(10, 9-i)) {
                cout << v << endl;
                v += 1111;
            }
        }

        return res;
    }

    int digits(long long n)
    {
        int count = 0;

        while (n != 0) {
            n = n / 10;
            ++count;
        }

        return count;
    }

};

int main()
{
    Solution solution;

    int low = 1121, high = 1221;

    solution.sequentialDigits(low, high);
}
