#include <vector>
using std::vector;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
private:
    void preorder(Node *root, vector<int> &res) {
        if (root == nullptr) return;
        res.emplace_back(root->val);
        for (auto i : root->children) {
            preorder(i, res);
        }
    }
};
