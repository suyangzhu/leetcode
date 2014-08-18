#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& list) {
        if (root == NULL) 
            return;
        inorder(root->left, list);
        list.push_back(root);
        inorder(root->right, list);
    }
    
    void findSwitch(vector<TreeNode*>& list) {
        int size = list.size();
        int i;
        TreeNode* min = NULL;
        TreeNode* max = NULL;
        for (i = 0; i < size - 1; i++) {
            if (list[i]->val > list[i+1]->val) {
                max = list[i];
                break;
            }
        }
        for (i = 0; i < size-1; i++) {
            if (list[i]->val > list[i+1]->val)
                min = list[i+1];
        }
        int tmp = min->val;
        min->val = max->val;
        max->val = tmp;
        
    }

    void recoverTree(TreeNode *root) {
        vector<TreeNode*> vec;
       
        if (root == NULL)
            return;
        inorder(root, vec);
        findSwitch(vec);
    }
};

void inoderTraverse(TreeNode* root) {
  if (root == NULL)
      return;
  inoderTraverse (root->left);
  std::cout << root->val;
  inoderTraverse (root->right);
}
int main() {
  TreeNode* p0 = (TreeNode*) malloc(sizeof(TreeNode));
  TreeNode* p1 = (TreeNode*) malloc(sizeof(TreeNode));
  TreeNode* p2 = (TreeNode*) malloc(sizeof(TreeNode));
  p0->val = 1;
  p1->val = 2;
  p2->val = 3;
  p0->left = p1;
  p0->right = p2; 
  p1->left = NULL;
  p1->right = NULL;
  p2->left = NULL;
  p2->right = NULL;
  Solution sol;
  inoderTraverse(p0);
  sol.recoverTree(p0);
  inoderTraverse(p0);
  return 0;
}
