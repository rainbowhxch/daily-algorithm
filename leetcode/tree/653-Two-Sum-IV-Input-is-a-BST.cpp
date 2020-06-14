/* Given a Binary Search Tree and a target number, return true if there exist two elements
in the BST such that their sum is equal to the given target.

Example 1:

Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True */

#include <set>
using std::set;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> prev_node;
        return findTarget(root, k, prev_node);
    }

private:
    bool findTarget(TreeNode *root, int k, set<int> &prev_node) {
        if (root != nullptr) {
            if (prev_node.count(k-root->val) > 0) return true;
            prev_node.insert(root->val);
            return findTarget(root->left, k, prev_node) || findTarget(root->right, k, prev_node);
        }

        return false;
    }
};
