#include <iostream>
#include <vector>
#include <queue>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeHelper(preorder, inorder, 0, preorder.size(), 0, inorder.size());     
    }
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int nPreorderStart, int nPreorderEnd, int nInorderStart, int nInorderEnd) {
        int len = nPreorderEnd-nPreorderStart;
        if (len <= 0)
            return NULL;
        if (len == 1) {
            TreeNode* node = new TreeNode(preorder[nPreorderStart]);
            return node;
        }
        TreeNode* node = new TreeNode(preorder[nPreorderStart]);
        int i;
        for (i = 0; i < nInorderEnd-nInorderStart; i++) {
            if (inorder[i+nInorderStart] == preorder[nPreorderStart])
                break;
        }
 //       vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+i+1);
 //       vector<int> rightPreorder(preorder.begin()+i+1, preorder.end());
 //       vector<int> leftInorder(inorder.begin(), inorder.begin()+i);
 //       vector<int> rightInorder(inorder.begin()+i+1, inorder.end());
        node->left = buildTreeHelper(preorder, inorder, nPreorderStart+1, nPreorderStart+i+1, nInorderStart, nInorderStart+i);
        node->right = buildTreeHelper(preorder, inorder, nPreorderStart+i+1, nPreorderEnd, nInorderStart+i+1, nInorderEnd);
        return node;
    }
};
void BFS(TreeNode* root) {
	queue<TreeNode*> nodeQueue;
	if (root == NULL) 
		return;
	nodeQueue.push(root);
	while (!nodeQueue.empty()) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();
		std::cout << node->val << std::endl;
		if (node->left) nodeQueue.push(node->left);
		if (node->right) nodeQueue.push(node->right);
	}
	return;

}
int main() {
	vector<int> preorder;
	vector<int> inorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(5);
	preorder.push_back(3);
	preorder.push_back(6);
	preorder.push_back(7);

	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(6);
	inorder.push_back(3);
	inorder.push_back(7);
	Solution sol;
	TreeNode* root = sol.buildTree(preorder, inorder);
	BFS(root);
	return 0;
}
