#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        vector<int> temp(A.size(), 0);
        vector<int> totals;

        int z = 0;
        int max = 0;

        if(A.size() == 0) return 0;

        while(z < A.size()) {
            int total = 0;

            for(int i = 0; i < A.size(); i++) {
                int newIdx = i + z;

                if(newIdx >= A.size()) {
                    newIdx -= A.size();
                }

                temp.at(i) = A.at(newIdx);
                total += i * temp.at(i);
            }

            totals.push_back(total);

            z++;
        }

        max = totals.at(0);

        for(int i = 1; i < totals.size(); i++) {
            if(totals.at(i) > max) {
                max = totals.at(i);
            }
        }

        return max;
    }
};

int main()
{
    Solution solution = Solution();

    //vector<int> A{};
    //vector<int> A{4, 3, 2, 6};
    vector<int> A{-2147483648, -2147483648};

    cout << solution.maxRotateFunction(A);
}
