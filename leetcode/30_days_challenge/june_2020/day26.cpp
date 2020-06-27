/****************************************************
Date: June 26th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3372/
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
#include <string_view>

using namespace std;

/*
  Q: Sum Root to Leaf Numbers

  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
  An example is the root-to-leaf path 1->2->3 which represents the number 123.
  Find the total sum of all root-to-leaf numbers.

  Note: A leaf is a node with no children.

  Example:
    Input: [1,2,3]
       1
      / \
     2   3
    Output: 25
    Explanation:
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.
    Therefore, sum = 12 + 13 = 25.

  Example 2:
    Input: [4,9,0,5,1]
         4
        / \
       9   0
      / \
     5   1
    Output: 1026
    Explanation:
    The root-to-leaf path 4->9->5 represents the number 495.
    The root-to-leaf path 4->9->1 represents the number 491.
    The root-to-leaf path 4->0 represents the number 40.
    Therefore, sum = 495 + 491 + 40 = 1026.
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
  vector<int> nums;
    
  bool collectNums(TreeNode* node, int num)
  {
    if (node == NULL)
    {
        return true;
    }

    num = num * 10;
    num += node->val;

    bool reachedLeftEnd = collectNums(node->left, num);
    bool reachedRightEnd = collectNums(node->right, num);
    
    if (reachedLeftEnd && reachedRightEnd)
    {
        nums.push_back(num);
    }
    
    return false;
  }
  
public:
  int sumNumbers(TreeNode* root) 
  {
    int num = 0;
    collectNums(root, num);
    
    int ans = 0;
    for(int& n : nums)
    {
      ans += n;
    }
    
    return ans;
  }
};