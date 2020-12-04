struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr || cloned == nullptr)
            return nullptr;
        if (original == target)
            return cloned;

        TreeNode *left_res = getTargetCopy(original->left, cloned->left, target);
        TreeNode *right_res = getTargetCopy(original->right, cloned->right, target);

        return left_res == nullptr ? right_res : left_res;
    }
};
