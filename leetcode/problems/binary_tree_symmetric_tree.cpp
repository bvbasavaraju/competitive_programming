#include <iostream>
#include <pair>
#include <queue>
#include <vector>

using namespace std;

/*
  Q: Symmetric Tree

  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

  For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
       1
      / \
     2   2
    / \ / \
   3  4 4  3
    

  But the following [1,2,2,null,3,null,3] is not:

       1
      / \
     2   2
      \   \
      3    3
    

    Follow up: Solve it both recursively and iteratively.
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
  void levelTraversal(TreeNode* node, int level, vector< vector<int> >& vals)
  {    
    if(vals.size() < level)
    {
      vals.push_back({ node ? node->val : -1});
    }
    else
    {
      vals[level-1].push_back({node ? node->val : -1});
    }
    
    if(node != NULL)
    {
      levelTraversal(node->left, level+1, vals);
      levelTraversal(node->right, level+1, vals);
    }
  }
  
  bool isSymmetric(const vector<int>& v)
  {
    int l = v.size();
    for(int i = 0; i < l-1; ++i)
    {
      if(v[i] != v[l-1-i])
      {
        return false;
      }
    }
    
    return true;
  }
public:
  bool isSymmetric(TreeNode* root) 
  {
    vector< vector<int> > levelVals;
    levelTraversal(root, 1, levelVals);
    
    for(vector<int>& v : levelVals)
    {
      if(!isSymmetric(v))
      {
        return false;
      }
    }
    
    return true;
  }
};