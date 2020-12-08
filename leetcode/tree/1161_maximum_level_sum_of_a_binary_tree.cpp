#include <queue>

using std::queue;

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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr)
            return 1;
        int max_level = 1, max_sum = root->val;
        queue<TreeNode *> q;
        q.push(root);

        int cur_level = 0, cur_sum;
        while (!q.empty()) {
            ++cur_level;
            cur_sum = 0;
            int cur_size = q.size();
            for (int i = 0; i < cur_size; ++i) {
                TreeNode *cur_node = q.front();
                q.pop();
                cur_sum += cur_node->val;
                if (cur_node->left)
                    q.push(cur_node->left);
                if (cur_node->right)
                    q.push(cur_node->right);
            }
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
                max_level = cur_level;
            }
        }

        return max_level;
    }
};
