/****************************************************
Date: April 20th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3709/
****************************************************/

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

/*
  Q: N-ary Tree Preorder Traversal

  Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
  Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

  Example 1:
    Input: root = [1,null,3,2,4,null,5,6]
    Output: [1,3,5,6,2,4]

  Example 2:
    Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]

  Constraints:
    The number of nodes in the tree is in the range [0, 104].
    0 <= Node.val <= 104
    The height of the n-ary tree is less than or equal to 1000.

  Follow up:
    Recursive solution is trivial, could you do it iteratively?
*/

/*
// Definition for a Node.
*/
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

class Solution 
{
private:
  void getValues(Node* node, vector<int>& ans)
  {
    if(node == nullptr)
    {
      return;
    }
    
    ans.push_back(node->val);
    
    for(Node*& ch : node->children)
    {
      getValues(ch, ans);
    }
  }
  
public:
  vector<int> preorder(Node* root) 
  {
    vector<int> ans;
    getValues(root, ans);
    
    return ans;
  }
};