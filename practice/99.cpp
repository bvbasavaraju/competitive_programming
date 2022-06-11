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
  int recover(TreeNode* node, bool& recovered)
  {
    if(node == nullptr)
    {
      return -1;
    }
    
    if(recovered)
    {
      return -1;
    }
    
    int maxValLeft = recover(node->left, recovered);
    int maxValRight = recover(node->right, recovered);
    
    if(maxValLeft != -1 && maxValRight != -1)
    {
      if(maxValLeft > maxValRight)
      {
        swap(node->left->val, node->right->val);
        recovered = true;
      }
      else if(maxValLeft > node->val)
      {
        swap(node->left->val, node->val);
        recovered = true;
      }
      else if(node->val > maxValRight)
      {
        swap(node->right->val, node->val);
        recovered = true;
      }
    }
    else if(maxValLeft != -1)
    {
      if(maxValLeft > node->val)
      {
        swap(node->left->val, node->val);
        recovered = true;
      }
    }
    else if(maxValRight != -1)
    {
      if(node->val > maxValRight)
      {
        swap(node->right->val, node->val);
        recovered = true;
      }
    }
    
    return max({node->val, maxValLeft, maxValRight});
  }
  
public:
  void recoverTree(TreeNode* root) 
  {
    bool recovered = false;
    recover(root, recovered);
  }
};

int main()
{
  TreeNode* root = nullptr;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  vector<int> preOrder = {1, 3, -1, -1, 2};
  root = new TreeNode(1);
  left = new TreeNode(3);
  right = new TreeNode(2);
  left->right = right;
  root->left = left;

  Solution s;
  s.recoverTree(root);

  return 0;
}

