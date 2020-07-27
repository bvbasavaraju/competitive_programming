/****************************************************
Date: July 27th

link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3393/
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
  Q: Construct Binary Tree from Inorder and Postorder Traversal
  
  Given inorder and postorder traversal of a tree, construct the binary tree.

  Note:
    You may assume that duplicates do not exist in the tree.

  For example, given
    inorder = [9,3,15,20,7]
    postorder = [9,15,7,20,3]
    
    Return the following binary tree:
     3
    / \
   9  20
      / \
     15  7
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
  TreeNode* dfs(vector<int>& in, vector<int>& post, TreeNode* node)
  {
    if(post.empty() || (node && node->val == in.back()))
    {
      return NULL;
    }
    
    TreeNode* root = new TreeNode(post.back());
    
    post.pop_back();
    root->right = dfs(in, post, root);
    
    in.pop_back();
    root->left = dfs(in, post, node);
    
    return root;
  }
  
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
  {
    if(inorder.size() <= 0 && postorder.size() <= 0)
    {
      return NULL;
    }
    
    return dfs(inorder, postorder, (TreeNode*) NULL);
  }
};