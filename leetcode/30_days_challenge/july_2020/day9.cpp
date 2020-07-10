/****************************************************
Date: July 9th

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
  Q: Maximum Width of Binary Tree - Not Accepted!!

  Given a binary tree, write a function to get the maximum width of the given tree.
  The width of a tree is the maximum width among all levels.
  The binary tree has the same structure as a full binary tree, but some nodes are null.

  The width of one level is defined as the length between the end-nodes 
  (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes 
  are also counted into the length calculation.

  Example 1:
    Input: 

              1
            /   \
           3     2
          / \     \  
         5   3     9 
    Output: 4
    Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

  Example 2:
    Input: 
             1
            /  
           3    
          / \       
         5   3     

    Output: 2
    Explanation: The maximum width existing in the third level with the length 2 (5,3).

  Example 3:
    Input: 
             1
            / \
           3   2 
          /        
         5      
    Output: 2
    Explanation: The maximum width existing in the second level with the length 2 (3,2).

  Example 4:
    Input: 
             1
            / \
           3   2
          /     \  
         5       9 
        /         \
       6           7
    Output: 8
    Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).

  Note: Answer will in the range of 32-bit signed integer.
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
   int width(TreeNode* r, int l, int pos, vector<int>& left)
   {
     if(r == nullptr)
     {
       return 0;
     }
     if (left.size() <= l)
     {
       left.push_back(pos);
     }
     return max(pos - left[l] + 1, max(width(r->right, l + 1, pos * 2, left), width(r->left, l + 1, pos * 2 - 1, left)));
   }
  
public:
  int widthOfBinaryTree(TreeNode* root) 
  {
    vector<int> v;
    return width(root, 0, 1, v);
  }
};