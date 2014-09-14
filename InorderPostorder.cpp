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
    TreeNode *buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int poststart, int postend) {
        if (inend - instart < 1) 
            return NULL; 
        else
        if (postend-poststart == 1) {
            TreeNode *node = new TreeNode(postorder[poststart]);
            return node;
        } else {
            TreeNode *node = new TreeNode(postorder[postend-1]);
            int i;
            for (i = 0; i < inend-instart; i++) {
                if (inorder[instart+i] == postorder[postend-1]) {	
			std::cout << inorder[instart+i] << std::endl;
                    break;
		}
            }
	    std::cout << node->val << std::endl;
            node->left = buildTreeHelper(inorder, postorder, instart, instart+i, poststart, poststart+i);
            node->right = buildTreeHelper(inorder, postorder, instart+i+1, inend, poststart+i, postend-1);
            return node;
        }
        
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeHelper(inorder, postorder, 0, inorder.size(), 0, postorder.size());
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
	vector<int> postorder;
	vector<int> inorder;
	postorder.push_back(4);
	postorder.push_back(5);
	postorder.push_back(2);
	postorder.push_back(6);
	postorder.push_back(7);
	postorder.push_back(3);
	postorder.push_back(1);

	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(6);
	inorder.push_back(3);
	inorder.push_back(7);
	Solution sol;
	TreeNode* root = sol.buildTree( inorder, postorder);
	BFS(root);
	return 0;
}
