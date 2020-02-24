#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int c = 0;

        while(num > 0) {
            if(num % 2 == 0) {
                num /= 2;
                c++;
            } else {
                num -= 1;
                c++;
            }
        }

        return c;
    }
};

int main()
{
    Solution solution;
    int num = 233;

    cout << solution.numberOfSteps(num);
}
