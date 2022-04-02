/****************************************************
Date: May 6th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/
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
  Q: Convert Sorted List to Binary Search Tree

  Given the head of a singly linked list where elements are sorted in ascending order, 
  convert it to a height balanced BST.

  For this problem, a height-balanced binary tree is defined as a binary tree in which 
  the depth of the two subtrees of every node never differ by more than 1.

  Example 1:
    Input: head = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]
    Explanation: 
      One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

  Example 2:
    Input: head = []
    Output: []

  Example 3:
    Input: head = [0]
    Output: [0]

  Example 4:
    Input: head = [1,3]
    Output: [3,1]

  Constraints:
    The number of nodes in head is in the range [0, 2 * 104].
    -10^5 <= Node.val <= 10^5
*/

struct ListNode 
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
  TreeNode* CreateTree(ListNode* head, ListNode* tail)
  {
    if(head == tail)
    {
      return nullptr;
    }
    
    if(head->next == tail)
    {
      TreeNode* node = new TreeNode(head->val);
      return node;
    }
    
    ListNode* mid = head;
    ListNode* temp = mid;
    
    while((temp != tail) && (temp->next != tail))
    {
      mid = mid->next;
      temp = temp->next->next;
    }
    
    TreeNode* node = new TreeNode(mid->val);
    node->left = CreateTree(head, mid);
    node->right = CreateTree(mid->next, tail);
    
    return node;
  }
public:
  TreeNode* sortedListToBST(ListNode* head) 
  {
    return CreateTree(head, nullptr);
  }
};