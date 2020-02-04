#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> shift(vector<int> & arr, int s) {
        int len = arr.size(), i, p;
        vector<int> v;

        if(s > len) {
            s %= len;
        }

        p = len-s;

        for(i = p; i < len; i++) {
            v.push_back(arr[i]);
        }

        for(i = 0; i < p; i++) {
            v.push_back(arr[i]);
        }

        return v;
    }

    vector<vector<int>> stack(vector<int> & arr, int lvls) {
        int i, c = 0;
        vector<vector<int>> v;
        vector<int> temp;

        for(i = 0; i < arr.size(); i++) {
            temp.push_back(arr[i]);
            c++;

            if(c == lvls) {
                v.push_back(temp);
                temp.clear();
                c = 0;
            }
        }

        return v;
    }

    vector<int> flat(vector<vector<int>> & arr) {
        vector<int> v;

        for(vector<int> a : arr) {
            for(int i : a) {
                v.push_back(i);
            }
        }

        return v;
    }

public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int width = grid[0].size();
        vector<int> a = flat(grid);

        a = shift(a, k);

        return stack(a, width);
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> grid{   {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};

    int k = 0;

    vector<vector<int>> stacked = solution.shiftGrid(grid, k);

    for(vector<int> v : stacked) {
        for(int i: v) {
            cout << i << " ";
        }

        cout << endl;
    }
}
