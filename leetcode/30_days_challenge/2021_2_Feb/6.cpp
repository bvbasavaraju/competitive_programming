/****************************************************
Date: Feb 6th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3628/
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
  Q: Binary Tree Right Side View

    Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

    Example:

    Input: [1,2,3,null,5,null,4]
    Output: [1, 3, 4]
    Explanation:

       1            <---
     /   \
    2     3         <---
     \     \
      5     4       <---
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
    //This needs additional looping on output argument.
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
  
  void levelTraverse(TreeNode* node, int depth, vector<int>& latestVals)
  {
    //We can return just an output argument as answer
    if(node == nullptr)
    {
      return;
    }
    
    if(latestVals.size() < depth)
    {
      latestVals.push_back({node->val});
    }
    else
    {
      latestVals[depth-1] = node->val;
    }
    
    levelTraverse(node->left, depth+1, latestVals);
    levelTraverse(node->right, depth+1, latestVals);
  }
public:
  vector<int> rightSideView(TreeNode* root) 
  {
//     vector<vector<int>> vals;
//     levelTraverse(root, 1, vals);
    
//     vector<int> ans;
//     for(vector<int>& v : vals)
//     {
//       ans.push_back(v.back());
//     }
    
    vector<int> ans;
    levelTraverse(root, 1, ans);
    
    return ans;
  }
};