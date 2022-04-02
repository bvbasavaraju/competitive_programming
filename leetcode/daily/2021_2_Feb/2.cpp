/****************************************************
Date: Feb 2nd

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3625/
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
  Q: Trim a Binary Search Tree

  Given the root of a binary search tree and the lowest and highest boundaries as low and high, 
  trim the tree so that all its elements lies in [low, high]. 
  Trimming the tree should not change the relative structure of the elements that will remain in the tree 
  (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

  Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

  Example 1:
    Input: root = [1,0,2], low = 1, high = 2
    Output: [1,null,2]

  Example 2:
    Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
    Output: [3,2,null,1]

  Example 3:
    Input: root = [1], low = 1, high = 2
    Output: [1]

  Example 4:
    Input: root = [1,null,2], low = 1, high = 3
    Output: [1,null,2]

  Example 5:
    Input: root = [1,null,2], low = 2, high = 4
    Output: [2]

  Constraints:
    The number of nodes in the tree in the range [1, 104].
    0 <= Node.val <= 104
    The value of each node in the tree is unique.
    root is guaranteed to be a valid binary search tree.
    0 <= low <= high <= 104
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
  TreeNode* trimTree(TreeNode* node, int low, int high)
  {
    if(node == nullptr)
    {
      return nullptr;
    }
    
    if(node->val >= low && node->val <= high)
    {
      node->left = trimTree(node->left, low, high);
      node->right = trimTree(node->right, low, high);
      
      return node;
    }
    
    TreeNode* temp = nullptr;
    temp = trimTree(node->left, low, high);
    if(temp != nullptr)
    {
      return temp;
    }

    temp = trimTree(node->right, low, high);
    return temp;
  }
  
public:
  TreeNode* trimBST(TreeNode* root, int low, int high) 
  {
    return trimTree(root, low, high);
  }
};