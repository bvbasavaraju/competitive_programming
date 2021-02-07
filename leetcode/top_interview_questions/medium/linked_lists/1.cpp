#include <iostream>

using namespace std;

/*
  Q: Add Two Numbers

  You are given two non-empty linked lists representing two non-negative integers. 
  The digits are stored in reverse order, and each of their nodes contains a single digit. 
  Add the two numbers and return the sum as a linked list.

  You may assume the two numbers do not contain any leading zero, except the number 0 itself.

  Example 1:
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 
      342 + 465 = 807.

  Example 2:
    Input: l1 = [0], l2 = [0]
    Output: [0]

  Example 3:
    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]

  Constraints:
    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
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
  void addNodes(int val1, int val2, int& carry, ListNode*& node)
  {
    int sum = val1 + val2 + carry;
    carry = sum / 10;
    
    if(node == nullptr)
    {
      node = new ListNode(sum % 10);
    }
    else
    {
      node->next = new ListNode(sum % 10);
      node = node->next;
    }
  }
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
  {
    int carry = 0;
    ListNode* ans = nullptr;
    ListNode* node = nullptr;
    while(l1 != nullptr && l2 != nullptr)
    {
      addNodes(l1->val, l2->val, carry, node);
      if(ans == nullptr)
      {
        ans = node;
      }
      
      l1 = l1->next;
      l2 = l2->next;
    }
    
    while(l1 != nullptr)
    {
      addNodes(l1->val, 0, carry, node);
      if(ans == nullptr)
      {
        ans = node;
      }
      
      l1 = l1->next;
    }
    
    while(l2 != nullptr)
    {
      addNodes(l2->val, 0, carry, node);
      if(ans == nullptr)
      {
        ans = node;
      }
      
      l2 = l2->next;
    }

    if(carry > 0)
    {
      addNodes(0, 0, carry, node);
    }
    return ans;
  }
};