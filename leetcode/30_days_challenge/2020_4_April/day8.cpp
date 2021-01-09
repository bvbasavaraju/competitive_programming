/****************************************************
Date: April 8th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3290/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
  Q:  Middle of the Linked List

  Given a non-empty, singly linked list with head node head, return a middle node of linked list.
  If there are two middle nodes, return the second middle node.

  Example 1:
  Input: [1,2,3,4,5]
  Output: Node 3 from this list (Serialization: [3,4,5])
  The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
  Note that we returned a ListNode object ans, such that:
  ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.

  Example 2:
  Input: [1,2,3,4,5,6]
  Output: Node 4 from this list (Serialization: [4,5,6])
  Since the list has two middle nodes with values 3 and 4, we return the second one.

  Note:
  The number of nodes in the given list will be between 1 and 100.
*/


/*
 * Definition for singly-linked list.
 */
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
  ListNode* middleNode(ListNode* node) 
  {
    vector<ListNode*> node_ptrs;
    while(node != NULL)
    {
      node_ptrs.push_back(node);
      node = node->next;
    }
    
    return node_ptrs[node_ptrs.size() / 2];
  }
};