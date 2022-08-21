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
  int traverse(TreeNode* node, int& tilt)
  {
    if(node == nullptr)
    {
      return 0;
    }
    
    int leftSum = traverse(node->left, tilt);
    int rightSum = traverse(node->right, tilt);
    
    tilt += abs(leftSum - rightSum);
    
    return node->val + leftSum + rightSum;
  }
public:
  int findTilt(TreeNode* root) 
  {
    int ans = 0;
    traverse(root, ans);
    
    return ans;
  }
};