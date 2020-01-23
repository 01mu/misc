#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int i, c = 0, lk = 0, x, ct = 0;

        for(i = 0; i < s.length(); i++) {
            if(lk == 0) {
                lk = 1;
                x = i;
            }

            if(s[i] == 'R') {
                c++;
            } else {
                c--;
            }

            if(c == 0) {
                ct++;
                lk = 0;
                cout << s.substr(x, i+1)  << " " << x << " " << i << endl;
            }
        }

        return ct;
    }
};

int main()
{
    Solution solution;
    string s = "RLRRRLLRLL";

    cout << solution.balancedStringSplit(s);
}
