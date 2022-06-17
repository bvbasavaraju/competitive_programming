#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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