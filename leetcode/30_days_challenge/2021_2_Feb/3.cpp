/****************************************************
Date: Feb 3rd

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3627/
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
  Q: Linked List Cycle

  Given head, the head of a linked list, determine if the linked list has a cycle in it.

  There is a cycle in a linked list if there is some node in the list that can be 
  reached again by continuously following the next pointer. 
  Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
  Note that pos is not passed as a parameter.

  Return true if there is a cycle in the linked list. Otherwise, return false.

  Example 1:
    Input: head = [3,2,0,-4], pos = 1
    Output: true
    Explanation:
      There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

  Example 2:
    Input: head = [1,2], pos = 0
    Output: true
    Explanation:
      There is a cycle in the linked list, where the tail connects to the 0th node.

  Example 3:
    Input: head = [1], pos = -1
    Output: false
    Explanation:
      There is no cycle in the linked list.

  Constraints:
    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.

  Follow up: Can you solve it using O(1) (i.e. constant) memory?
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
  bool hasCycle(ListNode *head) 
  {
    ListNode* fast_node = head;
    while((fast_node != nullptr) && (head != nullptr))
    {
      fast_node = fast_node->next;
      if(fast_node == nullptr)
      {
        break;
      }
      
      fast_node = fast_node->next;
      head = head->next;
      
      if(head == fast_node)
      {
        return true;
      }
    }
    
    return false;
  }
};