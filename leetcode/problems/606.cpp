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
  void getString(TreeNode* node, string& str)  
  {
    if(node == nullptr)
    {
      return;
    }
    
    bool opened = false;
    
    if(!str.empty())
    {
      str.push_back('(');
      opened = true;
    }
    
    str += std::to_string(node->val);
    
    getString(node->left, str);
    
    if(node->left == nullptr && node->right != nullptr)
    {
      str += "()";
    }
    
    getString(node->right, str);
    
    if(opened)
    {
      str.push_back(')');
    }
  }
  
public:
  string tree2str(TreeNode* root) 
  {
    string ans = "";
    
    getString(root, ans);
    
    return ans;
  }
};