#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
private:
  void traverse(Node* node, int level, int& ans)
  {
    if(node == nullptr)
    {
      return;
    }
    
    ans = max(ans, level);
    for(Node* child : node->children)
    {
      traverse(child, level+1, ans);
    }
  }
public:
  int maxDepth(Node* root) 
  {
    int ans = 0;
    traverse(root, 1, ans);
    
    return ans;
  }
};