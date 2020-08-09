/****************************************************
Date: July 8th

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3417/
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
#include <set>

using namespace std;
/*
  Q: Path Sum III

  You are given a binary tree in which each node contains an integer value.
  Find the number of paths that sum to a given value.
  The path does not need to start or end at the root or a leaf, 
  but it must go downwards (traveling only from parent nodes to child nodes).
  The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

  Example:
    root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
          10
        /  \
       5   -3
      / \    \
     3   2   11
    / \   \
   3  -2   1

    Return 3. The paths that sum to 8 are:
    1.  5 -> 3
    2.  5 -> 2 -> 1
    3. -3 -> 11
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
public:
    int pathSum(TreeNode* root, int sum) {
      return 0;   
    }
};