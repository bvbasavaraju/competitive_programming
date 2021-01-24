/****************************************************
Date: Jan 24th

link: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3613/
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
  Q: Merge k Sorted Lists

  You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
  Merge all the linked-lists into one sorted linked-list and return it.

  Example 1:
    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation:
      The linked-lists are:
      [
        1->4->5,
        1->3->4,
        2->6
      ]
      merging them into one sorted list:
      1->1->2->3->4->4->5->6

  Example 2:
    Input: lists = []
    Output: []

  Example 3:
    Input: lists = [[]]
    Output: []

  Constraints:
    k == lists.length
    0 <= k <= 10^4
    0 <= lists[i].length <= 500
    -10^4 <= lists[i][j] <= 10^4
    lists[i] is sorted in ascending order.
    The sum of lists[i].length won't exceed 10^4.
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
private:
  void mergeLists(ListNode* l1, ListNode* l2, ListNode*& merged)
  {
    if((l1 == nullptr) && (l2 == nullptr))
    {
      return;
    }
    
    if(l1 == nullptr)
    {
      merged = l2;
      return;
    }
    else if(l2 == nullptr)
    {
      merged = l1;
      return;
    }
    else
    {
      ListNode* start_ptr = nullptr;
      while((l1 != nullptr) && (l2 != nullptr))
      {
        if(merged == nullptr)
        {
          if(l1->val <= l2->val)
          {
            merged = l1;
            l1 = l1->next;
          }
          else
          {
            merged = l2;
            l2 = l2->next;
          }
          
          start_ptr = merged;
        }
        else
        {
          if(l1->val <= l2->val)
          {
            merged->next = l1;
            merged = merged->next;
            
            l1 = l1->next;
          }
          else
          {
            merged->next = l2;
            merged = merged->next;
            
            l2 = l2->next;
          }
        }
      }
      
      while(merged->next != nullptr)
      {
        merged = merged->next;
      }
      
      if(l1 != nullptr)
      {
        merged->next = l1;
      }
      if(l2 != nullptr)
      {
        merged->next = l2;
      }
      
      merged = start_ptr;
    }
  }
  
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) 
  {
    int l = lists.size();
    if(l == 0)
    {
      return nullptr;
    }
       
    ListNode* ans = lists[0];
    for(uint32_t i = 1; i < l; ++i)
    {
      ListNode* list = lists[i];
      
      ListNode* merged = nullptr;
      mergeLists(ans, list, merged);
      
      ans = merged;
    }

    return ans;
  }
};