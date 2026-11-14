#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildInPost(const vector<int>& post, int& postIdx, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;
    int rootVal = post[postIdx--];
    Node* root = new Node(rootVal);
    int inIdx = inMap[rootVal];

    // Build right subtree first because post-order is Left -> Right -> Root
    root->right = buildInPost(post, postIdx, inIdx + 1, inEnd, inMap);
    root->left = buildInPost(post, postIdx, inStart, inIdx - 1, inMap);
    return root;
}

Node* constructFromInPost(const vector<int>& in, const vector<int>& post) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < in.size(); i++) inMap[in[i]] = i;
    int postIdx = post.size() - 1;
    return buildInPost(post, postIdx, 0, in.size() - 1, inMap);
}