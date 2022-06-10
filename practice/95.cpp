#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
    vector<TreeNode*> generateTrees(int start, int end)
    {
      vector<TreeNode*> trees;
      if(start > end)
      {
        trees.push_back(nullptr);
        return trees;
      }
      
      if(start == end)
      {
        TreeNode* node = new TreeNode(start);
        trees.push_back(node);
        return trees;
      }
      
      for(int i = start; i <= end; ++i)
      {
        vector<TreeNode*> leftTrees = generateTrees(start, i-1);
        vector<TreeNode*> rightTrees = generateTrees(i+1, end);
        
        for(int j = 0; j < leftTrees.size(); ++j)
        {
          for(int k = 0; k < rightTrees.size(); ++k)
          {
            TreeNode* root = new TreeNode(i);
            root->left = leftTrees[j];
            root->right = rightTrees[k];
            trees.push_back(root);
          }
        }
      }
      
      return trees;
    }
public:
  vector<TreeNode*> generateTrees(int n) 
  {
    return generateTrees(1, n);
  }
};