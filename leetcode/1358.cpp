#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int a, b, c, i, j, total = 0, len = s.length();

        for(i = 0; i < len; i++) {
            a = 0, b = 0, c = 0;
            j = i;

            do {
                switch(s[j++]) {
                    case 'a': a++; break;
                    case 'b': b++; break;
                    default: c++; break;
                }
            } while((!a || !b || !c) && j <= len);

            total += len-j+1;
        }

       return total;
    }
};

int main()
{
    Solution solution;

    cout << solution.numberOfSubstrings("aaaaaabc");
}
