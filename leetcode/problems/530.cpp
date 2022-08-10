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
//   void solve(TreeNode* node, set<int>& vals)
//   {
//     if(node == nullptr)
//     {
//       return;
//     }
    
//     vals.insert(node->val);
    
//     solve(node->left, vals);
//     solve(node->right, vals);
//   }
  
  void solve(TreeNode* node, int& prev, int& ans)
  {
    if(node == nullptr)
    {
      return;
    }
    
    solve(node->left, prev, ans);
    
    ans = min(ans, node->val - prev);
    prev = node->val;
    
    solve(node->right, prev, ans);
  }
public:
  int getMinimumDifference(TreeNode* root) 
  {
//     set<int> vals;
//     solve(root, vals);
    
//     int ans = INT_MAX;
//     int num = INT_MAX;
//     for(auto it = vals.begin(); it != vals.end(); ++it)
//     {
//       ans = min(ans, abs(num - *it));
//       num = *it;
//     }
    
//     return ans;
    int prev = -1000000;
    int ans = INT_MAX;
    solve(root, prev, ans);
    
    return ans;
  }
};