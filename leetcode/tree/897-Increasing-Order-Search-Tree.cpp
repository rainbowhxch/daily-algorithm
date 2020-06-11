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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *res = new TreeNode(0);
        cur = res;
        inorder(root);
        return res->right;
    }
private:
    TreeNode *cur;
    void inorder(TreeNode *root) {
        if (root == nullptr) return;
        inorder(root->left);
        root->left = nullptr;
        cur->right = root;
        cur = cur->right;
        inorder(root->right);
    }
};
