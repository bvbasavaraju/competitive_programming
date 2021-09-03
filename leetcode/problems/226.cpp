/*
  Q: 226. Invert Binary Tree
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

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
  void reverseTree(TreeNode* node)
  {
    if(node == nullptr)
    {
      return;
    }
    
    reverseTree(node->left);
    reverseTree(node->right);
    
    TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;
  }
  
public:
  TreeNode* invertTree(TreeNode* root) 
  {    
    reverseTree(root); 
    return root;
  }
};
