/*
 * https://leetcode.com/problems/reorder-list/
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * initLL(const int * z, int n) {
    ListNode * head = new ListNode(z[0]);
    ListNode * next = head;

    for(int i = 1; i < n; i++) {
        next->next = new ListNode(z[i]);
        next = next->next;
    }

    next = head;

    return next;
}

void showLL(ListNode * node) {
    ListNode * next = node;

    while(next->next != NULL) {
        cout << next->val << " ";
        next = next->next;
    }

    cout << next->val << " ";
}

ListNode * getLast(ListNode * node) {
    ListNode * next = node;
    ListNode * prev = next;

    while(next->next != NULL) {
        prev = next;
        next = next->next;
    }

    prev->next = NULL;

    return next;
}


ListNode * getNodeIdx(ListNode * node, int index) {
    int c = 0;

    ListNode * next = node;

    if(index == 0) {
        return node;
    }

    while(next->next != NULL) {
        next = next->next;

        c++;

        if(c == index) {
            return next;
            break;
        }
    }

    return NULL;
}

int swap(ListNode * node, int index) {
    ListNode * indexed = getNodeIdx(node, index);
    ListNode * temp = NULL;

    if(indexed == NULL) {
        return 0;
    }

    temp = indexed->next;
    indexed->next = getLast(indexed);

    if(temp != indexed->next) {
        indexed->next->next = temp;
        return 1;
    }
}

int main()
{
    const int n = 7;
    const int vals[n] = {1, 2, 3, 4, 5, 6, 7};

    ListNode * ll = initLL(vals, n);

    int idx = 0;

    while(swap(ll, idx)) {
        idx += 2;
    }

    showLL(ll);
}
