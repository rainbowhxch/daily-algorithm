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
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
private:
    void postorder(Node *root, vector<int> &res) {
        if (root == nullptr)    return;
        for (auto i : root->children) {
            postorder(i, res);
        }
        res.emplace_back(root->val);
    }
};
