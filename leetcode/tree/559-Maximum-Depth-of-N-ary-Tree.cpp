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
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;

        int child_depth = 0;
        for (auto i : root->children) {
            child_depth = std::max(child_depth, maxDepth(i));
        }
        return child_depth + 1;
    }
};
