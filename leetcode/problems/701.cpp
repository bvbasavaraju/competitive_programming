/*
  Q: 701. Insert into a Binary Search Tree
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
  void getNodeToInsert(TreeNode* node, int val, TreeNode*& prev_node)
  {
    if(node == NULL)
    {
      return;
    }
    
    prev_node = node;
    if(node->val > val)
    {
      getNodeToInsert(node->left, val, prev_node);
    }
    else
    {
      getNodeToInsert(node->right, val, prev_node);
    }
  }
public:
  TreeNode* insertIntoBST(TreeNode* root, int val) 
  {
    TreeNode* prev_node = NULL;
    getNodeToInsert(root, val, prev_node);
    
    TreeNode* node = new TreeNode(val);
    if(prev_node == NULL)
    {
      root = node;
    }
    else if(prev_node->val > val)
    {
      prev_node->left = node;
    }
    else
    {
      prev_node->right = node;
    }
    
    return root;
  }
};