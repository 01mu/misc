#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j, sz = nums.size(), k = 0;

        for(i = 0; i < sz; i++) {
            if(nums[i] == 0 && i <= sz-1-k) {
                for(j = i; j < sz-1; j++) {
                    nums[j] = nums[j+1];
                }

                nums[sz-1-i] = 0;
                k++;
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums{0, 1, 0, 3, 12};

    solution.moveZeroes(nums);

    for(auto a : nums) {
        cout << a << endl;
    }
}
