#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        vector<int> leftInorder;
        vector<int> leftPostorder;
        vector<int> rightInorder;
        vector<int> rightPostorder;
        TreeNode* root;
        if (inorder.size() == 0) {
            return NULL;
        }
        root = (TreeNode*) malloc(sizeof(TreeNode));
        int rootVal = postorder.back();
        root->val = rootVal;
        if (inorder.size() == 1) {
            root->val = rootVal;
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        int size = inorder.size();
        int i;
        for (i = 0; i < size; i++) {
            if (inorder[i] == rootVal) {
                i++;
                break;
            }
            leftInorder.push_back(inorder[i]);
        }
        for (; i < size; i++) {
            rightInorder.push_back(inorder[i]);
        }
        int leftSize = leftInorder.size();
        int rightSize = rightInorder.size();
        for (i = 0; i < leftSize; i++) {
            leftPostorder.push_back(postorder[i]);
        }
        for (i = 0; i < rightSize; i++) {
            rightPostorder.push_back(postorder[leftSize + i]);
        }
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
        return root;
    }

};

void inorderTraverse(TreeNode* root) {
  if (!root) {
    return;
  } 
//  std::cout << "Step 1" << std::endl;
  inorderTraverse(root->left);
  std::cout << root->val;
  inorderTraverse(root->right);
}
void postorderTraverse(TreeNode* root) {
  if (!root)
    return ;
  postorderTraverse(root->left);
  postorderTraverse(root->right);
  std::cout << root->val;
}

int main() {
  vector<int> inorder;
  vector<int> postorder;
  inorder.push_back(4);
  inorder.push_back(2);
  inorder.push_back(5);
  inorder.push_back(1);
  inorder.push_back(6);
  inorder.push_back(3);
  inorder.push_back(7);
  postorder.push_back(4);
  postorder.push_back(5);
  postorder.push_back(2);
  postorder.push_back(6);
  postorder.push_back(7);
  postorder.push_back(3);
  postorder.push_back(1);
  Solution sol;
  TreeNode* root = sol.buildTree(inorder, postorder);
  std::cout << "In order" << std::endl;
  inorderTraverse(root);
  std::cout << std::endl;
  std::cout << "Post Order" << std::endl;
  postorderTraverse(root);
  std::cout << std::endl;
  return 0;
}
