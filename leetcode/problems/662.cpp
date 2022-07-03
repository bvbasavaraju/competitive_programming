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
   // int width(TreeNode* r, int l, int pos, vector<int>& left)
   // {
   //   if(r == nullptr)
   //   {
   //     return 0;
   //   }
   //   if (left.size() <= l)
   //   {
   //     left.push_back(pos);
   //   }
   //   return max(pos - left[l] + 1, max(width(r->right, l + 1, pos * 2, left), width(r->left, l + 1, pos * 2 - 1, left)));
   // }
  
  //Pratial result!
//   void captureValuesInLevels(TreeNode* node, int level, TreeNode* dummySiblingNode, vector<vector<int>>& values)
//   {
//     if(values.size() < level)
//     {
//       values.push_back({node == nullptr ? INT_MIN : node->val});
//     }
//     else
//     {
//       values[level-1].push_back(node == nullptr ? INT_MIN : node->val);
//     }
    
//     if(node != nullptr)
//     {
//       if(node->left == nullptr || node->right == nullptr)
//       {
//         if(node->left != nullptr)
//         {
//           captureValuesInLevels(node->left, level+1, dummySiblingNode, values);
//           captureValuesInLevels(dummySiblingNode, level+1, dummySiblingNode, values);
//         }
//         else if(node->right != nullptr)
//         {
//           captureValuesInLevels(dummySiblingNode, level+1, dummySiblingNode, values);
//           captureValuesInLevels(node->right, level+1, dummySiblingNode, values);
//         }
//         else
//         {
//           captureValuesInLevels(nullptr, level+1, dummySiblingNode, values);
//           captureValuesInLevels(nullptr, level+1, dummySiblingNode, values);
//         }
//       }
//       else
//       {
//         captureValuesInLevels(node->left, level+1, dummySiblingNode, values);
//         captureValuesInLevels(node->right, level+1, dummySiblingNode, values);
//       }

//     }
//   }
  
  
public:
  int widthOfBinaryTree(TreeNode* root) 
  {
    queue<pair<TreeNode*, int>> nodeAndItsPosition;
    
    nodeAndItsPosition.push({root, 0});
    
    int ans = 0;
    while(!nodeAndItsPosition.empty())
    {
      long long leftMostPos = nodeAndItsPosition.front().second;
      long long rightMostPos = nodeAndItsPosition.back().second;
      
      ans = max(ans, static_cast<int>(rightMostPos - leftMostPos + 1LL));
      
      int nodeCount = nodeAndItsPosition.size();
      for(int i = 0; i < nodeCount; ++i)
      {
        TreeNode* node = nodeAndItsPosition.front().first;
        long long nodePos = nodeAndItsPosition.front().second;
        
        nodeAndItsPosition.pop();
        
        if(node->left != nullptr)
        {
          nodeAndItsPosition.push({node->left, (2 * nodePos + 1LL)});
        }
        
        if(node->right != nullptr)
        {
          nodeAndItsPosition.push({node->right, (2 * nodePos + 2LL)});
        }
      }
    }
    
    return ans;
    
    // Partial result
//     TreeNode* dummySiblingNode = new TreeNode(INT_MIN);
//     vector< vector<int> > values;
//     captureValuesInLevels(root, 1, dummySiblingNode, values);
    
//     int ans = 0;
//     for(vector<int>& v : values)
//     {      
//       int leftMost = -1;
//       int rightMost = -1;
//       for(int i = 0, j = v.size() - 1; (i < v.size()) && (j >= 0) && (leftMost == -1 || rightMost == -1); ++i, --j)
//       {
//         if(leftMost == -1 && v[i] != INT_MIN)
//         {
//           leftMost = i;
//         }
        
//         if(rightMost == -1 && v[j] != INT_MIN)
//         {
//           rightMost = j;
//         }
//       }
      
//       ans = max(ans, rightMost - leftMost + 1);
      
//       // std::cout << leftMost << " " << rightMost << " ==> ";
//       // for(int n : v)
//       // {
//       //   std::cout << n << " ";
//       // }
//       // std::cout << std::endl;
//     }
    
//     return ans;
  }
};