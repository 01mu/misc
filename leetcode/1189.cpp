#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int c;
        unordered_map<char, int> a;

        for(auto b : "balon") {
            a[b] = 0;
        }

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

        c = a['b'];

        if(a['a'] >= c && a['l'] >= c*2 && a['o'] >= c*2 && a['n'] >= c) {
            return c;
        }

        return 0
    }
};

int main()
{
    Solution solution;
    string text = "loonbalxballpoon";

    cout << solution.maxNumberOfBalloons(text);
}
