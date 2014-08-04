/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void recursionPath(TreeNode* root, int sum, vector<int>& seed, vector<vector<int> >& result) {
      if (root == NULL) {
        return;
      }
      if ((root->left == NULL) && (root->right == NULL)) {
         sum -= root->val;
         seed.push_back(root->val);
         if(sum == 0) {
           result.push_back(seed);
         }
         seed.pop_back();
         sum += root->val;
         return;
      }
      seed.push_back(root->val);
      sum-= root->val; 
        recursionPath(root->left, sum, seed, result); 
        recursionPath(root->right, sum, seed, result);
      seed.pop_back();
      sum += root->val;
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
      vector<vector<int> > result;
      vector<int> vec;
      recursionPath(root, sum, vec, result);
      return result;
    }
};

int main () {
  Solution sol;
  int i, j;

  TreeNode* root = (TreeNode* ) malloc (sizeof(TreeNode));
  TreeNode* leftNode = (TreeNode* )malloc (sizeof(TreeNode));
  TreeNode* rightNode = (TreeNode* )malloc (sizeof(TreeNode));
  TreeNode* Node1 = (TreeNode* )malloc (sizeof(TreeNode));
  TreeNode* Node2 = (TreeNode* )malloc (sizeof(TreeNode));
  root->val = 1;
  root->left = leftNode;
  root->right = rightNode;
//  root->right = rightNode;
  
  
  leftNode->val = 2;
  leftNode->left = NULL;
  leftNode->right = NULL;
  
  rightNode->val = 3;
  rightNode->left = NULL;
  rightNode->right = NULL; 
  Node1->val = 4;
  Node1->left = Node2;
  Node1->right = NULL; 
  Node2->val = 5;
  Node2->left = NULL;
  Node2->right = NULL; 
  vector<vector<int> > vec = sol.pathSum(root, 4);
  
  for (i = 0; i < vec.size() ; i++) {
    for (j = 0; j < vec[i].size(); j++) {
      std::cout << vec[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
