/****************************************************
Date: March 5th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3657/
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
  Q: Average of Levels in Binary Tree

  Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
  
  Example 1:
    Input:
         3
        / \
       9  20
         /  \
        15   7
    Output: [3, 14.5, 11]
    Explanation:
      The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

  Note:
    The range of node's value is in the range of 32-bit signed integer.
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
  void collectValsInLevel(TreeNode* node, int level, vector< vector<long long> >& vals)
  {
    if(node == nullptr)
    {
      return;
    }
    
    if(vals.size() < level)
    {
      vals.push_back({node->val, 1});
    }
    else
    {
      vals[level-1][0] += node->val;
      vals[level-1][1]++;
    }
    
    collectValsInLevel(node->left, level+1, vals);
    collectValsInLevel(node->right, level+1, vals);
  }
    
public:
  vector<double> averageOfLevels(TreeNode* root) 
  {
    vector< vector<long long> > vals;
    collectValsInLevel(root, 1, vals);
    
    vector<double> ans;
    for(vector<long long>& data : vals)
    {
      ans.push_back((data[0] * 1.0)/data[1]);
    }
    
    return ans;
  }
};