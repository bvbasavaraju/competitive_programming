#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
  int getCount(TreeNode* node, bool& isBalanced)
  {
    if(node == nullptr)
    {
      return 0;
    }
    
    if(!isBalanced)
    {
      return 0;
    }
    
    int ans = INT_MAX;
    
    int leftCount = getCount(node->left, isBalanced);
    int rightCount = getCount(node->right, isBalanced);
    
    if(abs(leftCount - rightCount) > 1)
    {
      isBalanced = false;
      return 0;
    }
    
    return 1 + max(leftCount, rightCount);
  }
  
public:
  bool isBalanced(TreeNode* root) 
  {
    if(root == nullptr)
    {
      return true;
    }
    
    bool balanced = true;
    getCount(root, balanced);
    
    return balanced;
  }
};