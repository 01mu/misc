#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        int i;

        for(i = 1; i <= 15; i++) {
            if(i % 15 == 0) {
                result.push_back("FizzBuzz");
            } else if(i % 3 == 0) {
                result.push_back("Fizz");
            } else if(i % 5 == 0) {
                result.push_back("Buzz");
            } else {
                result.push_back(to_string(i));
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> result = solution.fizzBuzz(15);

    for(string s: result) {
        cout << s << endl;
    }
}
