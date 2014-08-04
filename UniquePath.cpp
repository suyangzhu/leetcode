#include <iostream>
#include <stack>
#include <vector>
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
    vector<TreeNode* > binaryGenerateTree(int A[], int begin, int end) {
        vector<TreeNode* > vec;
        int i, j, k;
        int leftSize;
        int rightSize;
        if (end < begin) {
            vec.push_back(NULL);
            return vec;
        } 
        if (end == begin) {
                   TreeNode* root = (TreeNode*) malloc(sizeof(TreeNode));
                    root->val = A[end];
                    root->left = NULL;
                    root->right = NULL;
                    vec.push_back(root);
                    return vec;
        }
        for (i = begin; i <= end; i++) {
            vector<TreeNode*> leftVec = binaryGenerateTree(A, begin, i - 1);
            vector<TreeNode*> rightVec = binaryGenerateTree(A, i+1, end);
            leftSize = leftVec.size();
            rightSize = rightVec.size();
            for (j = 0; j < leftSize; j++) {
                for (k = 0; k < rightSize; k++) {
                    TreeNode* root = (TreeNode*) malloc(sizeof(TreeNode));
                    root->val = A[i];
                    root->left = leftVec[j];
                    root->right = rightVec[k];
                    vec.push_back(root);
                }
            }
        }
        return vec;
    }
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode* > vec;
        int index[n];
        int i, j, k;
        int leftSize, rightSize;
        for (i = 0; i < n; i++) {
            index[i] = i+1;
        }
        if (n == 0)  {
            vec.push_back(NULL);
            return vec;
        }
        vec = binaryGenerateTree(index, 0, n-1);
 
        return vec;
    }
    void traverse(TreeNode* root) {
      if (root == NULL)
         return;
      std::cout << root->val;
      traverse(root->left);
  
      traverse(root->right);
    }
};

int main() {
  Solution sol;
  vector<TreeNode*> vec = sol.generateTrees(10);
  int size = vec.size();
  int i;
  for (i = 0; i < size; i++) {
    sol.traverse(vec[i]);
    std::cout << std::endl;
  }
  return 0;
}
