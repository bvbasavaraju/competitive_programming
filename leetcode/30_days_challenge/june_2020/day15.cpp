/****************************************************
Date: June 15th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3361/
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
  Q: Search in a Binary Search Tree

  Given the root node of a binary search tree (BST) and a value.
  You need to find the node in the BST that the node's value equals the given value.
  Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

  For example, 
  Given the tree:
          4
         / \
        2   7
       / \
      1   3
  And the value to search: 2

  You should return this subtree:

        2     
       / \   
      1   3
  In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.
  Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.
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
  TreeNode* getNode(TreeNode* node, int val)
  {
    if(node == NULL)
    {
      return NULL;
    }
    
    if(node->val == val)
    {
      return node;
    }
    
    TreeNode* leftNode = getNode(node->left, val);
    if(leftNode != NULL)
    {
      return leftNode;
    }
    
    TreeNode* rightNode = getNode(node->right, val);
    if(rightNode != NULL)
    {
      return rightNode;
    }
    
    return NULL;
  }
  
public:
  TreeNode* searchBST(TreeNode* root, int val) 
  {
    return getNode(root, val);
  }
};