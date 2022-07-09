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
  void getAllRootPaths(TreeNode* node, int sum, int targetSum, vector<int> rootPath, vector<vector<int>>& rootPaths)
  {
    if(node == nullptr)
    {      
      return;
    }
    
    sum += node->val;
    rootPath.push_back(node->val);
    if(node->left == nullptr && node->right == nullptr)
    {
      if(sum == targetSum)
      {
        rootPaths.push_back(rootPath);  
      }
      return;
    }
    
    if(node->left)
    {
      getAllRootPaths(node->left, sum, targetSum, rootPath, rootPaths); 
    }
    if(node->right)
    {
      getAllRootPaths(node->right, sum, targetSum, rootPath, rootPaths);
    }
  }
public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
  {
    int sum = 0;
    vector<int> rootPath;
    vector<vector<int>> rootPaths;
    
    getAllRootPaths(root, sum, targetSum, rootPath, rootPaths);
    
    return rootPaths;
  }
};