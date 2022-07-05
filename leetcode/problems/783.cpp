#include<bits/stdc++.h>
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
  
  //This is slower solution!!
//   void getValues(TreeNode* node, priority_queue<int>& values)
//   {
//     if(node == nullptr)
//     {
//       return;
//     }
    
//     values.push(node->val);
    
//     getValues(node->left, values);
//     getValues(node->right, values);
//   }
  
  void getMinDiff(TreeNode* node, int& prev, int& ans)
  {
    if(node == nullptr)
    {
      return;
    }
    
    getMinDiff(node->left, prev, ans);
    
    if(prev != INT_MAX)
    {
      ans = min(ans, abs(node->val - prev));
    }
    prev = node->val;
    
    getMinDiff(node->right, prev, ans);
  }
  
public:
  int minDiffInBST(TreeNode* root) 
  {
    //Key is BST. So, if we traverse in order, then it will be in ascending order!!
    
    int prev = INT_MAX;
    int ans = INT_MAX;
    
    getMinDiff(root, prev, ans);
    
    return ans;
    
    //This is slower solution!!
//     priority_queue<int> values;
    
//     getValues(root, values);
    
//     int ans = INT_MAX;
//     int num = values.top();
//     values.pop();
    
//     while(!values.empty())
//     {
//       ans = min(ans, abs(values.top() - num));
//       num = values.top();
//       values.pop();
//     }
    
//     return ans;
  }
};