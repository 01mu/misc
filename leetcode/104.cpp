#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return max(check(1, root->left), check(1, root->right));
    }

    int check(int depth, TreeNode* node) {
        if(node->left != NULL) {
            depth = check(++depth, node->left);
        }

        if(node->right != NULL) {
            depth = check(++depth, node->right);
        }

        return depth;
    }
};


int main()
{
    Solution solution;
    TreeNode root(3), b(9), c(20), d(15), e(7);

    root.left = &b, root.right = &c;
    c.left = &d, d.right = &e;

    cout << solution.maxDepth(&root);
}
