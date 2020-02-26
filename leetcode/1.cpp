#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> z;

        for(int a : nums) {
            if(z[a]) {
                res.push_back(z[a]);
                res.push_back(a);
            }

            if(!z[target-a]) {
                z[target-a] = a;
            }
        }

        return res;
    }
};

int main()
{
    int target = 9;
    vector<int> nums{2, 7, 11, 15};

    Solution solution;

    vector<int> res = solution.twoSum(nums, target);

    cout << res[0] << " " << res[1];
}
