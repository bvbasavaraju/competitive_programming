/****************************************************
Date: May 20th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3335/
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
  Q: Kth Smallest Element in a BST
  Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

  Note:
  You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

  Example 1:
    Input: root = [3,1,4,null,2], k = 1
      3
      / \
    1   4
      \
      2
    Output: 1

  Example 2:
    Input: root = [5,3,6,2,4,null,null,1], k = 3
          5
          / \
        3   6
        / \
      2   4
      /
    1
    Output: 3
  
  Follow up:
    What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

  Hide Hint #1  
    Try to utilize the property of a BST.
  Hide Hint #2  
    Try in-order traversal. (Credits to @chan13)
  Hide Hint #3  
    Wat if you could modify the BST node's structure?
  Hide Hint #4  
    The optimal runtime complexity is O(height of BST).
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
  TreeNode* getKthSmall(TreeNode* node, int k, int& count)
  {
    if(node == NULL)
    {
      return NULL;
    }
    
    TreeNode* left = getKthSmall(node->left, k, count);
    
    if(left != NULL)
    {
      return left;
    }
    
    count++;
    if(count == k)
    {
      return node;
    }
    
    return getKthSmall(node->right, k, count);
  }
  
public:
  int kthSmallest(TreeNode* root, int k)
  {
    int count = 0;
    TreeNode* ans = getKthSmall(root, k, count);
    
    return ans != NULL ? ans->val : -1;
  }
};