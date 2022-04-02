/****************************************************
Date: May 16th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3744/
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
  Q: Binary Tree Cameras

  Given a binary tree, we install cameras on the nodes of the tree. 
  Each camera at a node can monitor its parent, itself, and its immediate children.
  Calculate the minimum number of cameras needed to monitor all nodes of the tree.

  Example 1:
    Input: [0,0,null,0,0]
    Output: 1
    Explanation:
      One camera is enough to monitor all nodes if placed as shown.

  Example 2:
    Input: [0,0,null,0,null,0,null,null,0]
    Output: 2
    Explanation:
      At least two cameras are needed to monitor all nodes of the tree. 
      The above image shows one of the valid configurations of camera placement.

  Note:
    The number of nodes in the given tree will be in the range [1, 1000].
    Every node has value 0.
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
  const int HAS_CAMERA;
  const int NOT_NEEDED;
  const int NO_CAMERA;
  
  int getCount(TreeNode* node, int& ans)
  {
    if(node == nullptr)
    {
      return NOT_NEEDED;
    }
    
    int l = getCount(node->left, ans);
    int r = getCount(node->right, ans);
    
    if((l == NO_CAMERA) || (r == NO_CAMERA))
    {
      ans++;
      return HAS_CAMERA;
    }
    else if((l == HAS_CAMERA) || (r == HAS_CAMERA))
    {
      return NOT_NEEDED;
    }
    else
    {
      return NO_CAMERA;
    }
  }
public:
  Solution()
    : HAS_CAMERA(0),
      NOT_NEEDED(1),
      NO_CAMERA(2)
  {}
  
  int minCameraCover(TreeNode* root) 
  {
    int ans = 0;
    if(getCount(root, ans) == NO_CAMERA)
    {
      ans++; 
    }
    
    return ans;
  }
};