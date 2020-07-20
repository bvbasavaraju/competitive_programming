/****************************************************
Date: July 20th

link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3393/
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
  Q: Remove Linked List Elements

  Remove all elements from a linked list of integers that have value val.
  
  Example:
    Input:  1->2->6->3->4->5->6, val = 6
    Output: 1->2->3->4->5
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
  ListNode* removeElements(ListNode* head, int val) 
  {
    ListNode* node = head;
    ListNode* prev = NULL;
    while(node != NULL)
    {
      if(node->val == val)
      {
        if(node == head)
        {
          head = node->next;
        }
        
        if(node->next == NULL && prev != NULL)
        {
          prev->next = NULL;
        }
      }
      else
      {
        if(prev != NULL)
        {
          prev->next = node;
        }
        prev = node;
      }
      
      node = node->next;
    }
    
    return head;
  }
};