#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildPreIn(const vector<int>& pre, int& preIdx, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;
    int rootVal = pre[preIdx++];
    Node* root = new Node(rootVal);
    int inIdx = inMap[rootVal];

    root->left = buildPreIn(pre, preIdx, inStart, inIdx - 1, inMap);
    root->right = buildPreIn(pre, preIdx, inIdx + 1, inEnd, inMap);
    return root;
}

Node* constructFromPreIn(const vector<int>& pre, const vector<int>& in) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < in.size(); i++) inMap[in[i]] = i;
    int preIdx = 0;
    return buildPreIn(pre, preIdx, 0, in.size() - 1, inMap);
}