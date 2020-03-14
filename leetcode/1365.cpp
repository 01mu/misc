#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int i = 0, c = 0, t = 0, p;

        vector<int> res(nums.size());

        unordered_map<int, int> a;
        unordered_map<int, vector<int>> b;

        while(i < nums.size()) {
            b[nums[i]].push_back(i++);
        }

        sort(nums.begin(), nums.end());

        for(int j : nums) {
            if(j > p) {
                (++c) += t;
                t = 0;
            } else if(j == p) {
                t++;
            }

            res[b[j][a[j]++]] = c;
            p = j;
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
