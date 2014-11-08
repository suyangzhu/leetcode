#include <iostream>
#include <climits>

class TreeNode {
	public:
	TreeNode(int n):val(n), right(NULL), left(NULL) {}
	int val;
	TreeNode* right;
	TreeNode* left;
};

bool isBSTHelper(TreeNode* root, int& prev) {
	if (!root) return true;
	if (!(isBSTHelper(root->left, prev))) {
		std::cout << "1" << std::endl;
		return false;
	}
	if (!((root->val> prev) && (prev = root->val))) {
		
		std::cout << "2" << std::endl;
		return false;
	}
	if (!isBSTHelper(root->right, prev)) {
		std::cout << "3" << std::endl;
		return false;
	}
	return true;
}

bool isBST(TreeNode *root) {
	int prev = INT_MIN;
	return isBSTHelper(root, prev);
}

int main() {
	TreeNode* root =new TreeNode(0);
	TreeNode* left = new TreeNode(-1);
	TreeNode* right = new TreeNode(2);
//	root->left = left;
//	root->right = right;
	if (isBST(root)) std::cout << "T" << std::endl;
	else std::cout << "F" << std::endl;
	return 0;
}
