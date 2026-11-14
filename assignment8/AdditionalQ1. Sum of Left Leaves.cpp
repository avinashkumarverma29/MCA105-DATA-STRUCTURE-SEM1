#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    int sum = 0;
    if (root->left && !root->left->left && !root->left->right) {
        sum += root->left->val;
    }
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}