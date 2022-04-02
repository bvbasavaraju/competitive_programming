/****************************************************
Date: April 14th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3701/
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
  Q: Partition List

  Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
  You should preserve the original relative order of the nodes in each of the two partitions.

  Example 1:
    Input: head = [1,4,3,2,5,2], x = 3
    Output: [1,2,2,4,3,5]

  Example 2:
    Input: head = [2,1], x = 2
    Output: [1,2]

  Constraints:
    The number of nodes in the list is in the range [0, 200].
    -100 <= Node.val <= 100
    -200 <= x <= 200
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
  ListNode* partition(ListNode* head, int x) 
  {
    vector<int> vals;
    
    ListNode* node = head;
    ListNode* prev = nullptr;
    while(node != nullptr)
    {
      if(node->val < x)
      {
        vals.push_back(node->val);
        
        if(prev == nullptr)
        {
          head = node->next;
        }
        if(node->next == nullptr && prev != nullptr)
        {
          prev->next = nullptr;
        }
      }
      else
      {
        if(prev != nullptr)
        {
          prev->next = node;
        }
        prev = node;
      }
      node = node->next;
    }
    
    node = head;
    prev = nullptr;
    
    for(int n : vals)
    {
      while(node != nullptr && node->val < x)
      {
        prev = node;
        node = node->next;
      }
      
      ListNode* node_ = new ListNode(n);
      node_->next = node;
      if(prev != nullptr)
      {
        prev->next = node_;
      }
      else
      {
        head = node_;
      }
      prev = node_;
    }
    
    return head;
  }
};