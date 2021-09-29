/****************************************************
Date: September 29th

https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/640/week-5-september-29th-september-30th/3992/
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
  Q: Split Linked List in Parts

  Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

  The length of each part should be as equal as possible: no two parts should have a size differing by more than one. 
  This may lead to some parts being null.

  The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have 
  a size greater than or equal to parts occurring later.

  Return an array of the k parts.

  Example 1:
    Input: head = [1,2,3], k = 5
    Output: [[1],[2],[3],[],[]]
    Explanation:
      The first element output[0] has output[0].val = 1, output[0].next = null.
      The last element output[4] is null, but its string representation as a ListNode is [].

  Example 2:
    Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
    Output: [[1,2,3,4],[5,6,7],[8,9,10]]
    Explanation:
      The input has been split into consecutive parts with size difference at most 1, 
      and earlier parts are a larger size than the later parts.

  Constraints:
    The number of nodes in the list is in the range [0, 1000].
    0 <= Node.val <= 1000
    1 <= k <= 50

  Hide Hint #1  
    If there are N nodes in the list, and k parts, then every part has N/k elements, except the first N%k parts have an extra one.
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
  vector<ListNode*> splitListToParts(ListNode* head, int k) 
  {
    int count = 0;
    ListNode* node = head;
    while(node != nullptr)
    {
      count++;
      node = node->next;
    }
    
    int numOfNodes = (count <= k) ? 1 : count/k;
    int numOfAdditionalNodes = count % k; 
    bool addAdditionNode = ((count % k) > 0) && ((count % k) != count);
    
    int i = 0;
    count = 0;
    node = head;
    vector<ListNode*> ans(k, nullptr);
    while(node != nullptr)
    {
      ListNode* temp = node->next;
      if(ans[i] == nullptr)
      {
        ans[i] = node;
      }
      
      count++;
      if(count >= numOfNodes)
      {
        if((count == numOfNodes) && i < numOfAdditionalNodes && numOfNodes >= 1 && addAdditionNode)
        {
          //additional node for the first time;
        }
        else
        {
          i++;
          count = 0;
          node->next = nullptr;
        }
      }
      
      node = temp;
    }
    
    return ans;
  }
};