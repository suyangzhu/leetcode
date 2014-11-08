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
/**
 * The MaxSumThroughRoot returns the max value through the root, it may be left-root or right-root or root.
 */
    int MaxSumThroughRoot(TreeNode *root, int &maxSum) {
        if (!root) return 0;
        int leftVal = MaxSumThroughRoot(root->left, maxSum);
        int rightVal = MaxSumThroughRoot(root->right, maxSum);
        
        int sum = leftVal > rightVal? 
                  leftVal + root->val:
                  rightVal + root->val;
        int tmp = leftVal + root->val + rightVal;
        maxSum = max(tmp, maxSum);
        return sum;
    }
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;   // Here must assign INT_MIN
        MaxSumThroughRoot(root, maxSum);
        return maxSum;
    }

    int max(int a, int b) {
	    return a>b?a:b;
    }
};

int main() {
	TreeNode* p0 = new TreeNode(20);
	TreeNode* p1 = new TreeNode(0);
	TreeNode* p2 = new TreeNode(-19);
	TreeNode* p3 = new TreeNode(9);
	TreeNode* p4 = new TreeNode(0);
	p0->left = p1;
	p0->right = p2;
	p1->left = p3;
	p1->right = p4;
	Solution sol;
	std::cout << sol.maxPathSum(p0) << std::endl;
}

