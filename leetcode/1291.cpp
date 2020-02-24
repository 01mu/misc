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
                v += st(i);

                if(v >= low && v <= high) {
                    cout << v << endl;
                }
            }
        }

        return res;
    }

    int st(int c)
    {
        int i;
        string r = "";

        for(i = 0; i < c; i++) {
            r+= "1";
        }

        return stoi(r);
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

    int low = 121, high = 9999;

    solution.sequentialDigits(low, high);
}
