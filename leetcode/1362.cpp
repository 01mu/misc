#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> res;
        int i, min = INT_MAX, d1, d2;

        for(i = num; i < num+3; i++) {
            for(int j : divisors(i)) {
                if(abs(i/j-j) < min) {
                    min = abs(i/j-j);
                    d1 = j;
                    d2 = i/j;
                }
            }
        }

        return {d1, d2};
    }

    vector<int> divisors(int n) {
        int i;
        vector<int> res;

        for(i = 1; i <= n; i++) {
            if(n % i == 0) {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    int num = 123;

    vector<int> res = solution.closestDivisors(num);

    cout << res[0] << " " << res[1];
}
