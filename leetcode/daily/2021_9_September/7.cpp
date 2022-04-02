/****************************************************
Date: September 7th

link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3966/
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
  void reverse(ListNode* node, ListNode*& prev, ListNode*& ans)
  {
    if(node == nullptr)
    {
      ans = prev;
      return;
    }
    
    reverse(node->next, node, ans);
    node->next = prev;
  }
public:
  ListNode* reverseList(ListNode* head) 
  {
    ListNode* ans = nullptr;
    ListNode* prev = nullptr;
    reverse(head, prev, ans);
    
    return ans;
  }
};