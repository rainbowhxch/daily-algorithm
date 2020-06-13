#include <vector>
using std::vector;

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1_leaves;
        vector<int> root2_leaves;

        dfs(root1, root1_leaves);
        dfs(root2, root2_leaves);
        return root1_leaves == root2_leaves;
    }

private:
    void dfs(TreeNode *root, vector<int> &leaves)
    {
        if (root->left == nullptr && root->right == nullptr)
            leaves.emplace_back(root->val);
        if (root->left != nullptr)  dfs(root->left, leaves);
        if (root->right != nullptr) dfs(root->right, leaves);
    }
};
