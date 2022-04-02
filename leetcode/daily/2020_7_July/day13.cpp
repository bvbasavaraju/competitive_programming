/****************************************************
Date: July 13th

link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
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
  Q: Same Tree

  Given two binary trees, write a function to check if they are the same or not.
  Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

  Example 1:
    Input:    1         1
             / \       / \
            2   3     2   3

            [1,2,3],   [1,2,3]
    Output: true

  Example 2:

    Input:    1         1
             /           \
            2             2

            [1,2],     [1,null,2]
    Output: false

  Example 3:
    Input:   1         1
            / \       / \
           2   1     1   2

          [1,2,1],   [1,1,2]
    Output: false
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
  bool validateIfNodeIsSame(TreeNode* node1, TreeNode* node2)
  {
    if((node1 == NULL) && (node2 == NULL))
    {
      return true;
    }
    if((node1 != NULL) && (node2 != NULL) && (node1->val == node2->val))
    {
      return (validateIfNodeIsSame(node1->left, node2->left) && validateIfNodeIsSame(node1->right, node2->right));
    }
      
    return false;
  }

public:
  bool isSameTree(TreeNode* p, TreeNode* q) 
  {
    return validateIfNodeIsSame(p, q);
  }
};