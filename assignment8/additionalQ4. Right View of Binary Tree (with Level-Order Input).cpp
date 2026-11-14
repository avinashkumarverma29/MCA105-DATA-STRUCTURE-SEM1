#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();
        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

vector<int> rightView(Node* root) {
    vector<int> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Node* curr = q.front();
            q.pop();
            if (i == sz - 1) res.push_back(curr->data);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return res;
}

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Node* root = buildTree(arr);
        vector<int> ans = rightView(root);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i + 1 < ans.size() ? " " : "");
        }
        cout << "\n";
    }
    return 0;
}