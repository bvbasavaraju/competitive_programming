#include <iostream>
#include <pair>
#include <queue>
#include <vector>

using namespace std;

/*
  Q: Lowest Common Ancestor of a Binary Tree

  Solution
  Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

  According to the definition of LCA on Wikipedia: 
    “The lowest common ancestor is defined between two nodes p and q as the lowest node in T 
    that has both p and q as descendants (where we allow a node to be a descendant of itself).”

  Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3
    Explanation: 
      The LCA of nodes 5 and 1 is 3.

  Example 2:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    Output: 5
    Explanation: 
      The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

  Example 3:
    Input: root = [1,2], p = 1, q = 2
    Output: 1

  Constraints:
    The number of nodes in the tree is in the range [2, 105].
    -109 <= Node.val <= 109
    All Node.val are unique.
    p != q
    p and q will exist in the tree.
*/

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
  void levelTraverse(TreeNode* node, vector<int>& levels, vector<TreeNode*>& nodes, unordered_map<int, int>& pos, int depth)
  {
    if(node == NULL)
    {
      return;
    }
    
    levels.push_back(depth);
    nodes.push_back(node);
    pos[node->val] = levels.size() - 1;
    
    levelTraverse(node->left, levels, nodes, pos, depth+1);
    levels.push_back(depth);
    nodes.push_back(node);
    pos[node->val] = levels.size() - 1;
    
    levelTraverse(node->right, levels, nodes, pos, depth+1);
    
    levels.push_back(depth);
    nodes.push_back(node);
    pos[node->val] = levels.size() - 1;
  }
  
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
  {
    vector<int> levels;
    vector<TreeNode*> nodes; 
    unordered_map<int, int> pos;
    
    levelTraverse(root, levels, nodes, pos, 1);
    
    int p_pos = pos[p->val];
    int q_pos = pos[q->val];
    
    int min_pos = min(p_pos, q_pos);
    TreeNode* ans = NULL;
    for(int i = min_pos; i <= max(p_pos, q_pos); ++i)
    {
      if(levels[min_pos] >= levels[i])
      {
        min_pos = i;
        ans = nodes[i];
      }
    }
    
    return ans;
  }
};