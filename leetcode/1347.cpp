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
                display(v.first, a[v.first]);
                c++;
            } else if(a[v.first] > 0 && b[v.first] > 0) {
                z = (a[v.first] - b[v.first]);

                if(z >= 1) {
                    display(v.first, z);
                    c += z;
                }
            }
        }

        cout << endl;

        for(auto & v : b) {
            if(b[v.first] > a[v.first]) {
                display(v.first, b[v.first]-a[v.first]);
            }
        }

        cout << endl;

        return c;
    }

    void display(char ch, int a) {
        int i;

        for(i = 0; i < a; i ++) {
            cout << ch << " ";
        }
    }
};

int main()
{
    Solution solution;
    string s = "anagram", t = "smodoaa";

    cout << solution.minSteps(s, t);
}
