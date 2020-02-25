#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> res;
        int i;

        for(i = num; i < num+3; i++) {
            for(int j : divisors(i)) {
                cout << j << " (" << abs(i/j-j) << ")" << endl;
            }

            cout << endl;
        }

        return res;
    }

    vector<int> divisors(int n)
    {
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

    solution.closestDivisors(num);
}
