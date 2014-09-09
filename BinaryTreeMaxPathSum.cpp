#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
using namespace std;
class Solution {
public:
    int maxPathThrougRoot(TreeNode* root, int& maxVal) {
	    if (!root)
		    return 0;
	    int leftVal = maxPathThrougRoot(root->left, maxVal);
	    int rightVal = maxPathThrougRoot(root->right, maxVal);
	    int result = leftVal>rightVal? (leftVal+root->val > root->val? leftVal+root->val:root->val):
		                           (rightVal+root->val > root->val? rightVal+root->val:root->val);
	    int tmp = result > leftVal+root->val+rightVal? result:leftVal+root->val + rightVal;
	    if(tmp > maxVal)
		    maxVal = tmp;
	    return result;
    }
    int maxPathSum(TreeNode *root) {
        if (!root) 
            return 0;
	int result = INT_MIN;
	maxPathThrougRoot(root, result);
	return result;
    }
};

int main() {
	TreeNode *p0= new TreeNode(2);
	TreeNode *p1= new TreeNode(1);
	p0->left = p1;
	Solution sol;
	std::cout << sol.maxPathSum(p0) << std::endl;
}
