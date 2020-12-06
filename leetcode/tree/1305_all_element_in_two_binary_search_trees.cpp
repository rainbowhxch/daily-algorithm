#include <vector>
#include <stack>

using std::vector;
using std::stack;

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode *> s1, s2;
        TreeNode *cur1 = root1, *cur2 = root2;
        vector<int> res;

        while (!s1.empty() || cur1 || !s2.empty() || cur2) {
            while (cur1) {
                s1.push(cur1);
                cur1 = cur1->left;
            }
            while (cur2) {
                s2.push(cur2);
                cur2 = cur2->left;
            }

            if (s1.empty() || (!s2.empty() && s2.top()->val <= s1.top()->val)) {
                cur2 = s2.top();
                s2.pop();
                res.push_back(cur2->val);
                cur2 = cur2->right;
            } else {
                cur1 = s1.top();
                s1.pop();
                res.push_back(cur1->val);
                cur1 = cur1->right;
            }
        }

        return res;
    }
};
