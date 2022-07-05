#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution 
{
private:
  TreeNode* getNode(TreeNode* node, int val)
  {
    if(node == nullptr)
    {
      return nullptr;
    }
    
    if(node->val == val)
    {
      return node;
    }
    
    TreeNode* ans = getNode(node->left, val);
    if(ans == nullptr)
    {
      ans = getNode(node->right, val);
    }
    
    return ans;
  }
public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
  {
    return getNode(cloned, target->val);
  }
};