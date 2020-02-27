#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int c = 0, max = 0;
        unordered_map<char, int> a;

        for(char ch : s) {
            if(!a[ch]) {
                c++;
                a[ch] = 1;
            } else {
                a.clear();
                a[ch] = 1;

                if(c > max) {
                    max = c;
                }

                c = 1;
            }
        }

        return max;
    }
};

int main()
{
    Solution solution;

    cout << solution.lengthOfLongestSubstring("abcabcbb");
}
