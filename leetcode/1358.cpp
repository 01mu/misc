#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int a, b, c, i, j, total = 0, len = s.length();

        for(int i = 0; i < len; i++) {
            a = 0, b = 0, c = 0;
            j = i;

            while(!a || !b || !c) {
                switch(s[j++]) {
                    case 'a': a++; break;
                    case 'b': b++; break;
                    default: c++; break;
                }

                if(j > len) {
                    break;
                }
            }

            total++;

            if(j != len) {
                total += len-j;
            }
        }

       return total;
    }
};

int main()
{
    Solution solution;

    cout << solution.numberOfSubstrings("abcabc");
}
