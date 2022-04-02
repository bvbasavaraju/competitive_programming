/****************************************************
Date: May 14th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3737/
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
  Q: Flatten Binary Tree to Linked List

  Given the root of a binary tree, flatten the tree into a "linked list":
    + The "linked list" should use the same TreeNode class where the right child pointer 
      points to the next node in the list and the left child pointer is always null.
    + The "linked list" should be in the same order as a pre-order traversal of the binary tree.

  Example 1:
    Input: root = [1,2,5,3,4,null,6]
    Output: [1,null,2,null,3,null,4,null,5,null,6]

  Example 2:
    Input: root = []
    Output: []

  Example 3:
    Input: root = [0]
    Output: [0]

  Constraints:
    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100

  Follow up: Can you flatten the tree in-place (with O(1) extra space)?

  Hide Hint #1  
    If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
  void doJob(TreeNode* node)
  {
    if(node == nullptr)
    {
      return;
    }
    
    if(node->left == nullptr && node->right == nullptr)
    {
      return;
    }
    
    TreeNode* left = node->left;
    TreeNode* right = node->right;
    if(left == nullptr)
    {
      doJob(right);
    }
    else if(right == nullptr)
    {
      node->right = left;
      doJob(node->right);
      node->left = nullptr;
    }
    else
    {
      doJob(left);
      
      TreeNode* ptr = node->left;
      
      //Reaching to the end of the flattened tree
      while(ptr->right != nullptr)
      {
        ptr = ptr->right;
      }
      
      ptr->right = right;
      node->right = left;
      node->left = nullptr;
      
      doJob(right);
    }
  }
 
public:
  void flatten(TreeNode* root) 
  {
    doJob(root);
  }
};