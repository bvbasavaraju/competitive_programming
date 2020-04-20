/****************************************************
Date: April 20th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3305/
****************************************************/

#include <iostream>
#include <vector>
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
  Q: Construct Binary Search Tree from Preorder Traversal
  Return the root node of a binary search tree that matches the given preorder traversal.
  (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left
  has a value < node.val, and any descendant of node.right has a value > node.val.
  Also recall that a preorder traversal displays the value of the node first, then traverses 
  node.left, then traverses node.right.)

  Example 1:

  Input: [8,5,1,7,10,12]
  Output: [8,5,10,1,7,null,12]

      8
     / \
    5   10
   / \    \
  1   7    12

  Note: 

  1 <= preorder.length <= 100
  The values of preorder are distinct.
*/

/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{  
private:
  TreeNode* CreateTreeNode(vector<int>& data, int& i, int upper_limit)
  {
    if(i >= data.size() || data[i] > upper_limit)
    {
      return NULL;
    }
    
    int val = data[i++];
    TreeNode* node = new TreeNode(val);
    node->left = CreateTreeNode(data, i, val);
    node->right = CreateTreeNode(data, i, upper_limit);
    
    return node;
  }
  
public:
  TreeNode* bstFromPreorder(vector<int>& preorder) 
  {
    int i = 0;
    //O(N) solution
    return CreateTreeNode(preorder, i, INT_MAX);
    
    /*  // O(nlogn) solution
    TreeNode* ans = NULL;
    
    int l = preorder.size();
    for(int i = 0; i < l; ++i)
    {
      int v = preorder[i];
      TreeNode* node = new TreeNode();
      if(node == NULL)
      {
        return NULL;
      }
      
      node->val = v;
      if(i == 0)
      {
        ans = node;
      }
      else
      {
        TreeNode* temp = ans;
        while(temp != NULL)
        {
          if(temp->val > v)
          {
            if(temp->left == NULL)
            {
              temp->left = node;
              break;
            }
            temp = temp->left;
          }
          else
          {
            if(temp->right == NULL)
            {
              temp->right = node;
              break;
            }
            temp = temp->right;
          }
        }
      }
    }
    
    return ans;*/
  }
};