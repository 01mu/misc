#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int i, j, sz = intervals.size(), c = 0;

        for(i = 0; i < sz; i++) {
            for(j = i+1; j < sz; j++) {
                if( (intervals[i][0] <= intervals[j][0]) &&
                    (intervals[i][1] >= intervals[j][1])) {
                        c++;
                        intervals[j][0] = -1, intervals[j][1] = -1;
                }
            }
        }

        return sz-c;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> intervals{{1, 4}, {3, 6}, {2, 8}};

    sort(intervals.begin(), intervals.end());

    cout << solution.removeCoveredIntervals(intervals);
}
