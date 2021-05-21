/****************************************************
Date: May 20th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3744/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
  Q: Binary Tree Level Order Traversal

  Given the root of a binary tree, return the level order traversal of its nodes' 
  values. (i.e., from left to right, level by level).

  Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]

  Example 2:
    Input: root = [1]
    Output: [[1]]

  Example 3:
    Input: root = []
    Output: []

  Constraints:
    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000
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
private:
  void levelTraverse(TreeNode* node, int depth, vector<vector<int>>& vals)
  {
    if(node == nullptr)
    {
      return;
    }
    
    if(vals.size() < depth)
    {
      vals.push_back({node->val});
    }
    else
    {
      vals[depth-1].push_back(node->val);
    }
    
    levelTraverse(node->left, depth+1, vals);
    levelTraverse(node->right, depth+1, vals);
  }
public:
  vector<vector<int>> levelOrder(TreeNode* root) 
  {
    vector<vector<int>> ans;
    levelTraverse(root, 1, ans);
//     queue<pair<TreeNode*, int> > nodes;
//     nodes.push(std::make_pair(root, 1));
    
//     while(!nodes.empty())
//     {
//       pair<TreeNode*, int> p = nodes.front();
//       nodes.pop();
      
//       TreeNode* node = p.first;
//       int level = p.second;
//       if(node != NULL)
//       {
//         if(ans.size() < level)
//         {
//           vector<int> v = {node->val};
//           ans.push_back(v);
//         }
//         else
//         {
//           ans[level-1].push_back(node->val);
//         }
        
//         nodes.push(std::make_pair(node->left, level+1));
//         nodes.push(std::make_pair(node->right, level+1));
//       }
//     }
    
    return ans;
  }
};