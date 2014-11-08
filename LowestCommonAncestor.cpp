

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class TreeNode {
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int n) : val(n), left(NULL), right(NULL) {}
};

bool CanCover(TreeNode* root, TreeNode* ptr) {
	if (!root) return false;
	if (root == ptr) return true;
	return CanCover(root->left, ptr) || CanCover(root->right, ptr);
}	

TreeNode* LowestCommonAncestorHelpter(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root)  return NULL;
	if (root == p  || root == q) return root;
	bool is_p_left = CanCover(root->left, p);
	bool is_q_left = CanCover(root->left, p);
	if (is_p_left != is_q_left) return root; // one on left , the other on right;
	TreeNode* side = is_p_left?root->left:root->right;
	return LowestCommonAncestorHelpter(side, p, q);
}

TreeNode* LowestCommonAncestor (TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!CanCover(root, p) || !CanCover(root, q)) return NULL;
	return LowestCommonAncestorHelpter(root, p, q);
}

TreeNode* LowestCommonAncestorHelpter2 (TreeNode* root, TreeNode* p, TreeNode* q, bool& hasP, bool& hasQ) {
	if (!root) return NULL;
	if (root == p) {
		hasP = true;
		return root;
	}
	if (root == q) {
		hasQ = true;
		return root;
	}
	TreeNode* left = LowestCommonAncestorHelpter2(root->left, p, q, hasP, hasQ);
	TreeNode* right = LowestCommonAncestorHelpter2(root->right, p, q, hasP, hasQ);
	if (left && right) return root;
	return (left?left:right);
}

TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
	bool hasP = false;
	bool hasQ = false;
	TreeNode* result = LowestCommonAncestorHelpter2(root, p, q, hasP, hasQ) ;
	if (hasQ && hasP || hasP && CanCover(root, q)) || hasQ && CanCover(root, p) {
		return result;
	}
	return NULL;
}

}

int main() {
}

