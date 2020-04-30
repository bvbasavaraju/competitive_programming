/****************************************************
Date: April 30th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3315/
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
  Q: Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree

  Given a binary tree where each path going from the root to any leaf form a valid sequence,
  check if a given string is a valid sequence in such binary tree. 

  We get the given string from the concatenation of an array of integers arr and 
  the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.

  Example 1:
    Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
    Output: true
    Explanation: 
    The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
    Other valid sequences are: 
    0 -> 1 -> 1 -> 0 
    0 -> 0 -> 0

  Example 2:
    Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
    Output: false 
    Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.

  Example 3:
    Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
    Output: false
    Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.

  Constraints:
    1 <= arr.length <= 5000
    0 <= arr[i] <= 9
    Each node's value is between [0 - 9].

  Hide Hint #1  
    Depth-first search (DFS) with the parameters: current node in the binary tree and current position in the array of integers.
  Hide Hint #2  
    When reaching at final position check if it is a leaf node.
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
  bool isPositionValid(TreeNode* node, vector<int>& arr, int pos)
  {
    if(node == NULL)
    {
      if(pos < arr.size())
      {
        return false;
      }
      else
      {
        return true;
      }
    }
    
    if(pos >= arr.size() || arr[pos] != node->val)
    {
      return false;
    }
    
    bool left_result = isPositionValid(node->left, arr, pos+1);
    bool right_result = isPositionValid(node->right, arr, pos+1);
    
    bool this_pos_result =  left_result || right_result;
    
    if(pos == arr.size() - 1)
    {
      this_pos_result = this_pos_result && (node->left == NULL) && (node->right == NULL);
    }
    
    return this_pos_result;
  }
  
public:
  bool isValidSequence(TreeNode* root, vector<int>& arr) 
  {
    return isPositionValid(root, arr, 0);
  }
};