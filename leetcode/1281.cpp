#include <iostream>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int r, p = 1, s = 0;

        while(n != 0) {
           r = n % 10;
           n = n / 10;

           p *= r;
           s += r;
        }

        return p - s;
    }
};

int main()
{
    Solution solution;
    int n = 234;

    cout << solution.subtractProductAndSum(n);
}
