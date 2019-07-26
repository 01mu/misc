/*
 * https://leetcode.com/problems/palindrome-pairs/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int check(string & a, string & b) {
    string z = a + b;

    int l = z.size();

    for(int i = 0, j = z.size() - 1; i < z.size(); i++, j--) {
        if(z.at(i) == z.at(j)) {
            l--;
        }
    }

    if(l == 0) {
        cout << z << endl;

        return 1;
    }
}

int main()
{
    vector<string> words{"abcd", "dcba", "lls", "s", "sssll"};
    //vector<string> words{"bat", "tab", "cat"};

    vector<vector<int>> res;

    for(int i = 0; i < words.size(); i++) {
        for(int j = 0; j < words.size(); j++) {
            if(i != j) {
                if(check(words.at(i), words.at(j)) == 1) {
                    res.push_back({i, j});
                }
            }
        }
    }

    for(vector<int> a: res) {
        for(int val: a) {
            cout << val << " ";
        }

        cout << endl;
    }
}
