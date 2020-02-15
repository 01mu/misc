#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int i, c = 0, z;
        unordered_map<char, int> a, b;

        for(i = 0; i < s.length(); i++) {
            a[s[i]]++;
            b[t[i]]++;
        }

        for(auto & v : a) {
            if(a[v.first] > 0 && b[v.first] == 0) {
                cout << v.first << ", ";
                c++;
            } else if(a[v.first] > 1 && b[v.first] > 0) {
                z = (a[v.first] - b[v.first]);
                cout << v.first << " (" << z << "), ";
                c += z;
            }
        }

        cout << endl;

        for(auto & v : b) {
            if(b[v.first] > a[v.first]) {
                cout << v.first << ", ";
            }
        }

        return c;
    }
};

int main()
{
    Solution solution;
    string s = "friend", t = "family";

    cout << solution.minSteps(s, t);
}
