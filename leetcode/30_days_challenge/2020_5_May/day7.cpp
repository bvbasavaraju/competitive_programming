/****************************************************
Date: May 7th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/
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
  Q: Cousins in Binary Tree
  In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
  Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
  We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
  Return true if and only if the nodes corresponding to the values x and y are cousins.

  Example 1:
    Input: root = [1,2,3,4], x = 4, y = 3
    Output: false

  Example 2:
    Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
    Output: true

  Example 3:
    Input: root = [1,2,3,null,4], x = 2, y = 3
    Output: false

  Note:
    The number of nodes in the tree will be between 2 and 100.
    Each node has a unique integer value from 1 to 100.
*/

/**
 * Definition for a binary tree node.
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
  unordered_map<int, std::pair<int, int>> node_parent_depth_map;
  
  void traceParentDepthMap(TreeNode* node, int parent, int depth)
  {
    if(node == NULL)
    {
      return;
    }
    
    node_parent_depth_map[node->val] = std::make_pair(parent, depth);
    traceParentDepthMap(node->left, node->val, depth+1);
    traceParentDepthMap(node->right, node->val, depth+1);
  }
  
public:
  bool isCousins(TreeNode* root, int x, int y) 
  {
    traceParentDepthMap(root, -1, 0);
    
    if((node_parent_depth_map.size() <= 0) || (node_parent_depth_map[x].first == node_parent_depth_map[y].first) 
       ||(node_parent_depth_map[x].second != node_parent_depth_map[y].second))
    {
      return false;
    }
    
    return true;
  }
};