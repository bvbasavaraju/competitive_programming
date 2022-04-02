/****************************************************
Date: August 31st

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/553/week-5-august-29th-august-31st/3441/
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
#include <set>

using namespace std;

/*
  Q: Delete Node in a BST

  Given a root node reference of a BST and a key, delete the node with the given key in the BST.
  Return the root node reference (possibly updated) of the BST.

  Basically, the deletion can be divided into two stages:

  Search for a node to remove.
  If the node is found, delete the node.
  Note: Time complexity should be O(height of tree).

  Example:
  root = [5,3,6,2,4,null,7]
  key = 3

        5
       / \
      3   6
     / \   \
    2   4   7

    Given key to delete is 3. So we find the node with value 3 and delete it.
    One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

        5
       / \
      4   6
     /     \
    2       7

    Another valid answer is [5,2,6,null,4,null,7].

        5
       / \
      2   6
       \   \
        4   7
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
  TreeNode* findMin(TreeNode* node)
  {
    TreeNode* current_node = node;
    if(current_node != NULL)
    {
      while(current_node->left != NULL)
      {
        current_node = current_node->left;
      }
    }
    
    return current_node;
  }
public:
  TreeNode* deleteNode(TreeNode* root, int key) 
  {
    if(root == NULL)
    {
      return root;
    }
    else if(key < root->val)
    {
      root->left = deleteNode(root->left, key);
    }
    else if(key > root->val)
    {
      root->right = deleteNode(root->right, key);
    }
    else
    {
      if(root->left == NULL && root->right == NULL)
      {
        delete root;
        root = NULL;
      }
      else if(root->left == NULL)
      {
        TreeNode* node = root;
        root = root->right;
        delete node;
      }
      else if(root->right == NULL)
      {
        TreeNode* node = root;
        root = root->left;
        delete node;
      }
      else
      {
        TreeNode* node = findMin(root->right);
        root->val = node->val;
        root->right = deleteNode(root->right, node->val);
      }
    }
    
    return root;
  }
};