#include <iostream>
#include <pair>
#include <queue>
#include <vector>

using namespace std;

/*
  Q: Binary Tree Level Order Traversal

  Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

  For example:
  Given binary tree [3,9,20,null,null,15,7],
     3
    / \
   9  20
     /  \
    15   7
  return its level order traversal as:
  [
    [3],
    [9,20],
    [15,7]
  ]

*/
struct TreeNode 
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
  vector<vector<int>> levelOrder(TreeNode* root) 
  {
    vector<vector<int>> ans;
    
    queue<pair<TreeNode*, int> > nodes;
    nodes.push(std::make_pair(root, 1));
    
    while(!nodes.empty())
    {
      pair<TreeNode*, int> p = nodes.front();
      nodes.pop();
      
      TreeNode* node = p.first;
      int level = p.second;
      if(node != NULL)
      {
        if(ans.size() < level)
        {
          vector<int> v = {node->val};
          ans.push_back(v);
        }
        else
        {
          ans[level-1].push_back(node->val);
        }
        
        nodes.push(std::make_pair(node->left, level+1));
        nodes.push(std::make_pair(node->right, level+1));
      }
    }
    
    return ans;
  }
};