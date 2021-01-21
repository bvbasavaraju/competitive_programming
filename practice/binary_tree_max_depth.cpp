#include <iostream>
#include <pair>
#include <queue>
#include <vector>

using namespace std;

/*
  Q: Maximum Depth of Binary Tree

  Given the root of a binary tree, return its maximum depth.
  A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

  Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: 3

  Example 2:
    Input: root = [1,null,2]
    Output: 2
  
  Example 3:
    Input: root = []
    Output: 0

  Example 4:
    Input: root = [0]
    Output: 1

  Constraints:
    The number of nodes in the tree is in the range [0, 104].
    -100 <= Node.val <= 100
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
  void getDepth(TreeNode* node, int depth, int& ans)
  {
    if(node == NULL)
    {
      return;
    }
    
    if(node->left == NULL && node->right == NULL)
    {
      ans = max(ans, depth);
    }
    
    getDepth(node->left, depth+1, ans);
    getDepth(node->right, depth+1, ans);
  }
  
public:
  int maxDepth(TreeNode* root) 
  {
    int ans = 0;
    getDepth(root, 1, ans);
    
    return ans;
  }
};
