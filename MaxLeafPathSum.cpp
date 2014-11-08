#include <iostream>
#include <climits>
class TreeNode {
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int n) : val(n), left(NULL), right(NULL) {}
};
class Solution {
public:	
	bool PrintPath(TreeNode* root, TreeNode* target) {
		if (!root) return false;
		if (root == target || 
		    PrintPath(root->left, target) ||
		    PrintPath(root->right, target)) {
			std::cout << root->val << std::endl;
			return true;
		}
		return false;
	}

	void GetTargetLeaf(TreeNode* root, int &maxSum, int curr_sum, TreeNode*&target) {
		if (!root) return;
		curr_sum += root->val;
		if (!root->left && !root->right) {
			if (curr_sum > maxSum) {
				target = root;
				maxSum = curr_sum; 
			}
		}
		GetTargetLeaf(root->left, maxSum, curr_sum, target);
		GetTargetLeaf(root->right, maxSum, curr_sum, target);
	}
    int max(int a, int b) {
	    return a>b?a:b;
    }
};

int main() {
	TreeNode* p0 = new TreeNode(20);
	TreeNode* p1 = new TreeNode(0);
	TreeNode* p2 = new TreeNode(+19);
	TreeNode* p3 = new TreeNode(9);
	TreeNode* p4 = new TreeNode(0);
	p0->left = p1;
	p0->right = p2;
	p1->left = p3;
	p1->right = p4;
	Solution sol;
	int start = INT_MIN;
	TreeNode* target;
	sol.GetTargetLeaf(p0, start, 0, target);
	sol.PrintPath(p0, target);
}

