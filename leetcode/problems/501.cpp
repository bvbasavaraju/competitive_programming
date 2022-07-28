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
  void collectNodeAndFreq(TreeNode* node, unordered_map<int, int>& freq)
  {
    if(node == nullptr)
    {
      return;
    }
    
    freq[node->val]++;
    
    collectNodeAndFreq(node->left, freq);
    collectNodeAndFreq(node->right, freq);
  }
  
//   void collectMostFreq(TreeNode* node, int val, int count, int& maxi, vector<int>& ans)
//   {
//     if(node == nullptr)
//     {
//       if(maxi == count)
//       {
//         if(val != ans.back())
//         {
//           ans.push_back(val);
//         }
//       }
//       else if(maxi < count)
//       {
//         maxi = count;
//         ans = {val};
//       }
//       return;
//     }
    
//     if(node->val == val)
//     {
//       count++;
//     }
    
//     if(maxi == count)
//     {
//       if(val != ans.back())
//       {
//         ans.push_back(val);
//       }
//     }
//     else if(maxi < count)
//     {
//       maxi = count;
//       ans = {val};
//     }
    
//     if(val != node->val)
//     {      
//       val = node->val;
//       count = 1;
//     }
    
//     collectMostFreq(node->left, val, count, maxi, ans);
//     collectMostFreq(node->right, val, count, maxi, ans);
//   }
  
public:
  vector<int> findMode(TreeNode* root) 
  {
//     int maxi = 0;
//     vector<int> ans;
    
//     collectMostFreq(root, root->val, 0, maxi, ans);
//     return ans;
    
    unordered_map<int, int> freq;
    
    collectNodeAndFreq(root, freq);
    
    map<int, vector<int>> modes;
    for(auto it = freq.begin(); it != freq.end(); ++it)
    {
      modes[it->second].push_back(it->first);
    }
    
    auto it = modes.end();
    it--;
    
    return it->second;
  }
};