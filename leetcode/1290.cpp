#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode * next = head;
        string st = "";

        while(next != NULL) {
            st += to_string(next->val);
            next = next->next;
        }

        return dec(stoi(st));
    }

    int dec(int n)
    {
        int num = n, prev;
        int d = 0;
        int base = 1;
        int temp = num;

        while(temp) {
            prev = temp % 10;
            temp = temp / 10;
            d += prev * base;
            base *= 2;
        }

        return d;
    }
};

int main()
{
    ListNode    * head = new ListNode(1),
                * a = new ListNode(0),
                * b = new ListNode(1);

    head->next = a;
    a->next = b;

    Solution solution;

    cout << solution.getDecimalValue(head);
}
