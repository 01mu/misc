#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int i, j, min = INT_MAX, sz = arr.size();
        vector<vector<int>> temp, res;

        for(i = 0; i < sz; i++) {
            for(j = 0; j < sz; j++) {
                if(j == i) {
                    continue;
                }

                if(arr[i] < arr[j]) {
                    vector<int> a{arr[i], arr[j]};
                    temp.push_back(a);

                    if(arr[j] - arr[i] <= min) {
                        min = arr[j] - arr[i];
                    }
                }
            }
        }

        for(i = 0; i < temp.size(); i++) {
            if(temp[i][1] - temp[i][0] == min) {
                res.push_back(temp[i]);
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> arr{1, 3, 6, 10, 15};

    vector<vector<int>> res  = solution.minimumAbsDifference(arr);

    for(auto a : res) {
        cout << a[0] << " " << a[1] << endl;
    }
}
