#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> buildTrees(int start, int end) {
    if (start > end) return {nullptr};
    vector<TreeNode*> allTrees;

    for (int i = start; i <= end; i++) {
        vector<TreeNode*> leftTrees = buildTrees(start, i - 1);
        vector<TreeNode*> rightTrees = buildTrees(i + 1, end);

        for (TreeNode* l : leftTrees) {
            for (TreeNode* r : rightTrees) {
                TreeNode* curr = new TreeNode(i);
                curr->left = l;
                curr->right = r;
                allTrees.push_back(curr);
            }
        }
    }
    return allTrees;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return buildTrees(1, n);
}