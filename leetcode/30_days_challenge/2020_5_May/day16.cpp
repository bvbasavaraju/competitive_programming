/****************************************************
Date: May 16th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3331/
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
  Q: Odd Even Linked List

  Given a singly linked list, group all odd nodes together followed by the even nodes.
  Please note here we are talking about the node number and not the value in the nodes.

  You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

  Example 1:
    Input: 1->2->3->4->5->NULL
    Output: 1->3->5->2->4->NULL

  Example 2:
    Input: 2->1->3->5->6->4->7->NULL
    Output: 2->3->6->7->1->5->4->NULL

  Note:
    The relative order inside both the even and odd groups should remain as it was in the input.
    The first node is considered odd, the second node even and so on ...
*/

/**
 * Definition for singly-linked list.
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
  ListNode* oddEvenList(ListNode* head) 
  {
    if(head == NULL)
    {
      return head;
    }
    
    ListNode* odd_node = head;    
    ListNode* even_node_start = odd_node->next;
    ListNode* even_node = even_node_start;
    
    while(even_node != NULL && even_node->next != NULL)
    {
      odd_node->next = even_node->next;
      even_node->next = odd_node->next->next;
      odd_node->next->next = even_node_start;
      
      odd_node = odd_node->next;
      even_node = even_node->next;
    }
    
    return head;
  }
};