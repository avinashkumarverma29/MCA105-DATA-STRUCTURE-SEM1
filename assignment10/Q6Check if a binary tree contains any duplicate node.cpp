#include <iostream>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool checkDuplicates(TreeNode* root, unordered_set<int>& visited) {
    if (!root) return false;
    
    if (visited.count(root->val)) {
        return true;
    }
    visited.insert(root->val);
    
    return checkDuplicates(root->left, visited) || checkDuplicates(root->right, visited);
}

bool hasDuplicateValues(TreeNode* root) {
    unordered_set<int> visited;
    return checkDuplicates(root, visited);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2); // Duplicate value '2'

    if (hasDuplicateValues(root)) {
        cout << "Duplicates Found (true)" << endl;
    } else {
        cout << "No Duplicates (false)" << endl;
    }
    return 0;
}