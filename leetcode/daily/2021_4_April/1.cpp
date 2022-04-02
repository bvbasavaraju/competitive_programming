/****************************************************
Date: April 1st

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3693/
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
  Q Palindrome Linked List

  Given the head of a singly linked list, return true if it is a palindrome.

  Example 1:
    Input: head = [1,2,2,1]
    Output: true

  Example 2:
    Input: head = [1,2]
    Output: false

  Constraints:
    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9

  Follow up: Could you do it in O(n) time and O(1) space?
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
  bool check(ListNode* node, ListNode** nodePtr)
  {
    if(node == nullptr)
    {
      return true;
    }
    
    if(!check(node->next, nodePtr))
    {
      return false;
    }
    
    bool ans = (*nodePtr)->val == node->val;
    
    (*nodePtr) = (*nodePtr)->next;
    
    return ans;
  }
public:
  bool isPalindrome(ListNode* head) 
  {
    //O(n) - time, O(1) - space
    return check(head, &head);
    
    //O(n) space and time
//     vector<int> nums;
    
//     while(head != nullptr)
//     {
//       nums.push_back(head->val);
      
//       head = head->next;
//     }
    
//     int l = nums.size();
//     for(int i = 0; i < l/2; ++i)
//     {
//       if(nums[i] != nums[l-1-i])
//       {
//         return false;
//       }
//     }
    
//     return true;
  }
};