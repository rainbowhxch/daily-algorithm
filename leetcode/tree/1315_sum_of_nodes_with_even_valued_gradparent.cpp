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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, false, false);
    }

private:
    int dfs(TreeNode *root, bool isParentEven, bool isGrapEven)
    {
        if (root == nullptr)
            return 0;

        int sum = 0;
        if (isGrapEven) {
            sum += root->val;
        }
        isGrapEven = isParentEven;
        isParentEven = root->val % 2 == 0 ? true : false;

        sum += dfs(root->left, isParentEven, isGrapEven);
        sum += dfs(root->right, isParentEven, isGrapEven);

        return sum;
    }
};
