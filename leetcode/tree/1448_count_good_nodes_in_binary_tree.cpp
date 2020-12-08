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
    int goodNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int cnt = 0;
        goodNodes(root->left, root->val, cnt);
        goodNodes(root->right, root->val, cnt);

        return cnt + 1;
    }
private:
    void goodNodes(TreeNode *root, int maxValInPath, int &cnt) {
        if (root == nullptr)
            return;
        if (root->val >= maxValInPath) {
            ++cnt;
            maxValInPath = root->val;
        }
        goodNodes(root->left, maxValInPath, cnt);
        goodNodes(root->right, maxValInPath, cnt);
    }
};
