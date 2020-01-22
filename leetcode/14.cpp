#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, j, g = strs.size()-1, c = 0;
        string s = strs[0], res = "";

        for(i = 0; i < s.length(); i++) {
            for(j = 1; j < strs.size(); j++) {
                if(strs[j][i] == s[i]) {
                    c++;
                }
            }

            if(c == g) {
                res.push_back(s[i]);
            }

            c = 0;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<string> strs{"flower", "flow", "flight"};

    cout << solution.longestCommonPrefix(strs);
}
