#include <bits/stdc++.h>
using namespace std;

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
  TreeNode* getMergedTree(TreeNode* node1, TreeNode* node2)
  {
    if(node1 == nullptr && node2 == nullptr)
    {
      return nullptr;
    }
    
    int val = 0;
    TreeNode* left1 = nullptr; 
    TreeNode* left2 = nullptr;
    TreeNode* right1 = nullptr;
    TreeNode* right2 = nullptr;
    
    if(node1 != nullptr)
    {
      val += node1->val;
      left1 = node1->left;
      right1 = node1->right;
    }
    
    if(node2 != nullptr)
    {
      val += node2->val;
      left2 = node2->left;
      right2 = node2->right;
    }
    
    TreeNode* node = new TreeNode(val);
    
    node->left = getMergedTree(left1, left2);
    node->right = getMergedTree(right1, right2);
    
    return node;
  }
public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
  {
    return getMergedTree(root1, root2);
  }
};