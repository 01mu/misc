#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int c = 0, t = 0, p;

        vector<int> res(nums.size());

        unordered_map<int, int> a;
        unordered_map<int, vector<int>> b;

        for(int i = 0; i < nums.size(); i++) {
            b[nums[i]].push_back(i);
        }

        sort(nums.begin(), nums.end());

        for(int i : nums) {
            if(i > p) {
                (++c) += t;
                t = 0;
            } else if(i == p) {
                t++;
            }

            res[b[i][a[i]++]] = c;
            p = i;
        }

        return res;
    }
};

int main()
{
    Solution solution;

    vector<int> nums{8, 1, 2, 2, 3};

    for(int i : solution.smallerNumbersThanCurrent(nums)) {
        cout << i << " ";
    }
}
