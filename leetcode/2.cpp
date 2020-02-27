#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    int ll_val(ListNode * l) {
        int i = 0, val = 0;

        ListNode * t = l;

        while(t != NULL) {
            val += t->val * pow(10, i++);
            t = t->next;
        }

        return val;
    }

    void get_digits(vector<int> & digits, int num) {
        if(num > 9) {
            get_digits(digits, num / 10);
        }

        digits.push_back(num % 10);
    }

public:
    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
        int num = ll_val(l1) + ll_val(l2), rev = 0;
        vector<int> digits;

        while(num > 0) {
            rev = rev * 10 + num % 10;
            num = num / 10;
        }

        get_digits(digits, rev);

        return feed(digits);
    }

    ListNode * feed(vector<int> vals) {
        int i;
        ListNode * l = new ListNode(vals[0]), * t = l;

        for(i = 1; i < vals.size(); i++) {
            t->next = new ListNode(vals[i]);
            t = t->next;
        }

        return l;
    }
};

int main()
{
    Solution solution;

    ListNode * res = solution.addTwoNumbers(
        solution.feed({2, 4, 3}),
        solution.feed({5, 6, 4})
    );

    ListNode * t = res;

    while(t != NULL){
        cout << t->val;
        t = t->next;
    }
}
