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
    bool isUnivalTree(TreeNode* root) {
        bool is_unival = true;
        if (root->left != nullptr) {
            is_unival = (root->val == root->left->val) && isUnivalTree(root->left);
        }
        if (root->right != nullptr) {
            is_unival = is_unival &&  (root->val == root->right->val) && isUnivalTree(root->right);
        }

        return is_unival;
    }
};
