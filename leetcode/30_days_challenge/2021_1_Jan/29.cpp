/****************************************************
Date: Jan 29th

link: https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3621/
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
  Q: Vertical Order Traversal of a Binary Tree

  Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
  For each node at position (x, y), its left and right children will be at positions (x - 1, y - 1) and (x + 1, y - 1) respectively.
  The vertical order traversal of a binary tree is a list of non-empty reports for each unique x-coordinate from left to right. 
  Each report is a list of all nodes at a given x-coordinate. The report should be primarily sorted by y-coordinate from highest y-coordinate to lowest. 
  If any two nodes have the same y-coordinate in the report, the node with the smaller value should appear earlier.

  Return the vertical order traversal of the binary tree.

  Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[9],[3,15],[20],[7]]
    Explanation: 
      Without loss of generality, we can assume the root node is at position (0, 0):
      The node with value 9 occurs at position (-1, -1).
      The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2).
      The node with value 20 occurs at position (1, -1).
      The node with value 7 occurs at position (2, -2).

  Example 2:
    Input: root = [1,2,3,4,5,6,7]
    Output: [[4],[2],[1,5,6],[3],[7]]
    Explanation: 
      The node with value 5 and the node with value 6 have the same position according to the given scheme.
      However, in the report [1,5,6], the node with value 5 comes first since 5 is smaller than 6.

  Constraints:
    The number of nodes in the tree is in the range [1, 1000].
    0 <= Node.val <= 1000
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
  void verticalTraverse(TreeNode* node, int x, int y, map<int, vector< vector<int> > >& report)
  {
    if(node == nullptr)
    {
      return;
    }
    
    report[x].push_back({y, node->val});
    
    verticalTraverse(node->left, x-1, y-1, report);
    verticalTraverse(node->right, x+1, y-1, report);
  }
  
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) 
  {
    map<int, vector< vector<int> > > report;
    verticalTraverse(root, 0, 0, report);
    
    vector< vector<int> > ans;
    for(auto it = report.begin(); it != report.end(); ++it)
    {
      vector< vector<int> >& r = it->second;
      sort(r.begin(), r.end(), [](const vector<int>& p1, const vector<int>& p2) -> bool 
           {
             return (p1[0] > p2[0]) || ((p1[0] == p2[0]) && (p1[1] < p2[1]));
           });
      
      vector<int> vals;
      for(vector<int>& p : r)
      {
        vals.push_back(p[1]);
      }
      
      ans.push_back(vals);
    }
    
    return ans;
  }
};