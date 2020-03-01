#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int i, c = 0, t = 0, p;
        vector<int> res;

        sort(nums.begin(), nums.end());

        for(i = 0; i < nums.size(); i++) {
            if(nums[i] > p) {
                (++c) += t;
                t = 0;
            } else if(nums[i] == p) {
                t += 1;
            }

            res.push_back(c);
            p = nums[i];
        }

        return res;
    }
};

int main()
{
    Solution solution;

    vector<int> nums{8, 1, 2, 2, 3};

    for(auto i : solution.smallerNumbersThanCurrent(nums)) {
        cout << i << " ";
    }
}
