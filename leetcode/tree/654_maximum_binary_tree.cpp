#include <vector>
#include <algorithm>

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return constructMaximumBinaryTree(nums.cbegin(), nums.cend());
    }

private:
	TreeNode *constructMaximumBinaryTree(vector<int>::const_iterator begin, vector<int>::const_iterator end) {
		if (begin == end)
			return nullptr;
		vector<int>::const_iterator max_one = std::max_element(begin, end);
		TreeNode *root = new TreeNode(*max_one);
		root->left = constructMaximumBinaryTree(begin, max_one);
		root->right = constructMaximumBinaryTree(max_one+1, end);

		return root;
	}
};
