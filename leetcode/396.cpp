#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int z = 0;
        int max = 0;
        int total = 0;
        int i = 0;
        int ft = 0;

        const int sz = A.size();

        int newIdx;

        if(sz == 0) return 0;

        while(z < sz) {
            for(i = 0; i < sz; i++) {
                newIdx = i + z;

                if(newIdx >= sz) {
                    newIdx -= sz;
                }

                total += i * A.at(newIdx);
            }

            if(ft == 0) {
                max = total;
                ft = 1;
            } else if(total > max) {
                max = total;
            }

            total = 0;
            z++;
        }

        return max;
    }
};

int main()
{
    Solution solution = Solution();

    //vector<int> A{};
    vector<int> A{4, 3, 2, 6};
    //vector<int> A{-2147483648, -2147483648};

    cout << solution.maxRotateFunction(A);
}
