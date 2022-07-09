#include<bits/stdc++.h>
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
  void recover(TreeNode* node, TreeNode*& prev, TreeNode*& first, TreeNode*& second)
  {
    if(node == nullptr)
    {
      return;
    }
    
    //left node
    recover(node->left, prev, first, second);
    
    //current node - operate here!! ex: in ordere of given example 1 is => 3 2 1 . if BST was proper, then it would have been ascending in order like, 1 2 3
    if(first == nullptr && prev->val > node->val)
    {
      first = prev;
    }
    
    if(first != nullptr && prev->val > node->val)
    {
      second = node;
    }
    
    prev = node;
    
    //right node
    recover(node->right, prev, first, second);
  }
  
public:
  void recoverTree(TreeNode* root) 
  {
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);
    
    recover(root, prev, first, second);
    
    swap(first->val, second->val);
  }
};