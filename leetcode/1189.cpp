#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int c, d;
        unordered_map<char, int> a;

        for(char b : text) {
            switch(b) {
                case 'b':
                case 'a':
                case 'l':
                case 'o':
                case 'n':
                    a[b] += 1;
                    break;
            }
        }

        c = min(a['b'], min(a['a'], a['n']));
        d = min(a['l'], a['o']);

        if(d >= 2*c) {
            return c;
        } else {
            return d;
        }
    }
};

int main()
{
    Solution solution;
    string text = "loonbalxballpoonb";

    cout << solution.maxNumberOfBalloons(text);
}
