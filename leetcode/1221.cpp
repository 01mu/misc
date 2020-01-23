#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int i, c = 0, ct = 0;

        for(i = 0; i < s.length(); i++) {
            if(s[i] == 'R') {
                c++;
            } else {
                c--;
            }

            if(c == 0) {
                ct++;
            }
        }

        return ct;
    }
};

int main()
{
    Solution solution;
    string s = "RLRRLLRLRL";

    cout << solution.balancedStringSplit(s);
}
