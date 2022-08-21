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
private:
    
  bool isSame(TreeNode* node, TreeNode* subNode)
  {
    if(node == nullptr)
    {
      return subNode == nullptr ? true : false;
    }
    if(subNode == nullptr)
    {
      return node == nullptr ? true : false;
    }
    
    if(node->val != subNode->val)
    {
      return false;
    }
    
    bool ans = isSame(node->left, subNode->left);
    if(ans)
    {
      ans = isSame(node->right, subNode->right);
    }
    
    return ans;
  }
  
  bool validateSubTree(TreeNode* node, TreeNode* subNode)
  {
    if(node == nullptr)
    {
      return false;
    }
    
    bool ans = false;
    if(node->val == subNode->val)
    {
      ans = isSame(node, subNode);
    }
    
    if(!ans)
    {
      ans = validateSubTree(node->left, subNode);
    }
    
    if(!ans)
    {
      ans = validateSubTree(node->right, subNode);
    }
    
    return ans;
  }
  
public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) 
  {
    return validateSubTree(root, subRoot);
  }
};