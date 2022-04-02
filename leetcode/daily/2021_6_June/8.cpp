/****************************************************
Date: June 8th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3772/
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
  Q: Construct Binary Tree from Preorder and Inorder Traversal

  Given two integer arrays preorder and inorder where preorder is the preorder traversal 
  of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

  Example 1:
    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]

  Example 2:
    Input: preorder = [-1], inorder = [-1]
    Output: [-1]

  Constraints:
    1 <= preorder.length <= 3000
    inorder.length == preorder.length
    -3000 <= preorder[i], inorder[i] <= 3000
    preorder and inorder consist of unique values.
    Each value of inorder also appears in preorder.
    preorder is guaranteed to be the preorder traversal of the tree.
    inorder is guaranteed to be the inorder traversal of the tree.
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
  TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int s, int e, int& index, unordered_map<int, int>& data)
  {
    if(s > e)
    {
      return nullptr;
    }
    
    int val = preorder[index];
    int i = data[preorder[index]];
    
    index++;
    
    TreeNode* node = new TreeNode(val);
    
    node->left = construct(preorder, inorder, s, i-1, index, data);
    node->right = construct(preorder, inorder, i+1, e, index, data);
    
    return node;
  }

public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
  {
    int l = inorder.size();
    unordered_map<int, int> data;
    for(int i = 0; i < l; ++i)
    {
      data[inorder[i]] = i;
    }
    
    int index = 0;
    return construct(preorder, inorder, 0, l-1, index, data);
  }
};