#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i;
        int flag = 0;
        bool r = false;

        for(i = 1; i < nums.size(); i++) {
            if(nums[i-1] > nums[i] && !flag) {
                nums[i-1] = nums[i] - 1;
                flag = true;
            }

            cout << nums[i] << " ";
        }

        cout << endl << r;
    }
};

int main()
{
    vector<int> nums({4, 2, 3});
    //vector<int> nums({3, 4, 2, 3});

    Solution solution;

    solution.checkPossibility(nums);
}
