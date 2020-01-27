#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int i, ct = 0;
        vector<int> p;
        vector<vector<int>> res;
        unordered_map<int, vector<int>> c;

        for(i = 0; i < groupSizes.size(); i++) {
            c[groupSizes[i]].push_back(i);
        }

        for(auto &a : c) {
            for(i = 0; i < c[a.first].size(); i++) {
                p.push_back(c[a.first][i]);
                ct++;

                if(ct == a.first) {
                    res.push_back(p);
                    p.clear();
                    ct = 0;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> groupSizes{3, 3, 3, 3, 3, 1, 3};

    vector<vector<int>> sol = solution.groupThePeople(groupSizes);

    for(auto a : sol) {
        for(int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
}
