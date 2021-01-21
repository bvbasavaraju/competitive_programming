#include <iostream>
#include <pair>
#include <queue>
#include <vector>

using namespace std;

/*
  Q: Path Sum

  Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
  A leaf is a node with no children.

  Example 1:
    Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    Output: true

  Example 2:
    Input: root = [1,2,3], targetSum = 5
    Output: false
 
  Example 3:
    Input: root = [1,2], targetSum = 0
    Output: false

  Constraints:
    The number of nodes in the tree is in the range [0, 5000].
    -1000 <= Node.val <= 1000
    -1000 <= targetSum <= 1000
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
  void isTargetReachable(TreeNode* node, int target, bool& reached)
  {
    if(node == NULL)
    {
      return;
    }
    
    if(node->left == NULL && node->right == NULL)
    {
      if(node->val == target)
      {
        reached = true;
      }
    }
    
    if(!reached)
    {
      isTargetReachable(node->left, target-node->val, reached);
    }
    
    if(!reached)
    {
      isTargetReachable(node->right, target-node->val, reached);
    }
  }
  
public:
  bool hasPathSum(TreeNode* root, int targetSum) 
  {
    bool ans = false;
    isTargetReachable(root, targetSum, ans);
    
    return ans;
  }
};