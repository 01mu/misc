#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int i, c = 0;
        unordered_map<char, int> m;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(i = 0; i < s.length(); i++) {
            if(s[i] != t[i] && m[s[i]] == 0) {
                m[s[i]] += 1;
                c++;
            }
        }

        cout << s << endl << t;

        return c;
    }
};

int main()
{
    Solution solution;
    string s = "friend", t = "family";

    cout << solution.minSteps(s, t);
}
