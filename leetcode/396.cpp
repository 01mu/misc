#include <iostream>
#include <vector>

using namespace std;

/*class Solution {
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
};*/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int i = 0;

        long long int mx = 0;
        long long int total = 0;
        long long int mult = 0;

        long long int sz = A.size();

        if(sz == 0) return 0;

        for(i = 0; i < sz; i++) {
            total += A.at(i);
            mult += i * A.at(i);
        }

        mx = mult;

        for(i = sz - 1; i >= 0; i--){
            mult += total - sz * A.at(i);
            mx = max(mx, mult);
        }

        return mx;
    }
};

int main()
{
    Solution solution = Solution();

    //vector<int> A{};
    //vector<int> A{4, 3, 2, 6};
    //vector<int> A{-2147483648, -2147483648};
    vector<int> A{2147483647,2147483647};

    cout << solution.maxRotateFunction(A);
}
