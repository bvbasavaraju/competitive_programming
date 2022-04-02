/****************************************************
Date: April 18th

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
  Q: Remove Nth Node From End of List

  Given the head of a linked list, remove the nth node from the end of the list and return its head.

  Follow up: Could you do this in one pass?

  Example 1:
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

  Example 2:
    Input: head = [1], n = 1
    Output: []

  Example 3:
    Input: head = [1,2], n = 1
    Output: [1]

  Constraints:
    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz

  Hide Hint #1  
    Maintain two pointers and update one with a delay of n steps.
*/

struct ListNode 
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution 
{
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) 
  {
    vector<ListNode*> ptrs;
    while(head != nullptr)
    {
      ptrs.push_back(head);
      head = head->next;
    }
    
    int l = ptrs.size();
    int pos_node_to_remove = l-n;
    if(pos_node_to_remove == 0)
    {
      return (l > 1)? ptrs[1] : nullptr;
    }
    
    ptrs[pos_node_to_remove-1]->next = ptrs[pos_node_to_remove]->next;
    return ptrs[0];
  }
};