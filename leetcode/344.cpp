#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int d = s.size()-1;

        for( ; i < s.size()/2; i++, d--) {
            char temp = s[i];

            s[i] = s[d];
            s[d] = temp;
        }
    }
};

int main()
{
    Solution solution;
    vector<char> s{'H', 'a', 'n', 'n', 'a', 'h'};
    solution.reverseString(s);

    for(char i : s) {
        cout << i;
    }
}
