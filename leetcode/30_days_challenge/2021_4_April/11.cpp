/****************************************************
Date: April 11th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3701/
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
  Q: Deepest Leaves Sum

  Given the root of a binary tree, return the sum of values of its deepest leaves.

  Example 1:
    Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
    Output: 15

  Example 2:
    Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
    Output: 19

  Constraints:
    The number of nodes in the tree is in the range [1, 104].
    1 <= Node.val <= 100

  Hide Hint #1  
    Traverse the tree to find the max depth.
  Hide Hint #2  
    Traverse the tree again to compute the sum required.
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
  void collectValsInLevels(TreeNode* node, int level, vector< vector<int> >& vals)
  {
    if(node == nullptr)
    {
      return;
    }
    
    if(vals.size() < level)
    {
      vals.push_back({node->val});
    }
    else
    {
      vals[level-1].push_back(node->val);
    }
    
    collectValsInLevels(node->left, level+1, vals);
    collectValsInLevels(node->right, level+1, vals);
  }
  
public:
  int deepestLeavesSum(TreeNode* root) 
  {
    vector< vector<int> > vals;
    collectValsInLevels(root, 1, vals);
    
    int ans = 0;
    vector<int>& temp = vals[vals.size()-1];
    for(int& n : temp)
    {
      ans += n;
    }
    
    return ans;
  }
};