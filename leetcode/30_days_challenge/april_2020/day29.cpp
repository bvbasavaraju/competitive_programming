/****************************************************
Date: April 29th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3314/
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
  Q: Binary Tree Maximum Path Sum

  Given a non-empty binary tree, find the maximum path sum.
  For this problem, a path is defined as any sequence of nodes from some starting node to any node
  in the tree along the parent-child connections. 
  The path must contain at least one node and does not need to go through the root.

  Example 1:
  Input: [1,2,3]

         1
        / \
       2   3

  Output: 6

  Example 2:
  Input: [-10,9,20,null,null,15,7]
    -10
    / \
   9  20
     /  \
    15   7

  Output: 42
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
  int sumForThisNode(TreeNode* node, int& sum)
  {
    if(node == NULL)
    {
      return 0;
    }
    
    int left_sum = sumForThisNode(node->left, sum);
    int right_sum = sumForThisNode(node->right, sum);
    
    //Max sum in the path!
    int max_path_sum = max(node->val, node->val + max(left_sum, right_sum));
    
    //max sum including the node!
    int max_sum_tree = max(max_path_sum, node->val + left_sum + right_sum);
    
    sum = max(sum, max_sum_tree);
    
    //return the max path sum!
    return max_path_sum;
  }
  
public:
  int maxPathSum(TreeNode* root) 
  {
    int sum = INT_MIN;
    sumForThisNode(root, sum);
    
    return sum;
  }
};