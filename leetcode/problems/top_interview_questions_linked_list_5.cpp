#include <iostream>
#include <vector>

using namespace std;

/*
  Q: Palindrome Linked List

  Given a singly linked list, determine if it is a palindrome.

  Example 1:
    Input: 1->2
    Output: false

  Example 2:
    Input: 1->2->2->1
    Output: true

  Follow up:
  Could you do it in O(n) time and O(1) space?
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
  bool isPalindrome_(ListNode* node, ListNode*& start)
  {
    if((node == nullptr) || (start == nullptr))
    {
      return true;
    }
    
    bool ans = isPalindrome_(node->next, start);
    if(!ans || (start->val != node->val))
    {
      return false;
    }
       
    start = start->next;    
    return ans;
  }
  
public:
  bool isPalindrome(ListNode* head) 
  {
    //Time -> O(n) , space ->O(1)
    return isPalindrome_(head, head);
    
    //Time -> O(n) , space ->O(n)
//     vector<ListNode*> ptrs;
//     while(head != nullptr)
//     {
//       ptrs.push_back(head);
      
//       head = head->next;
//     }
    
//     int l = ptrs.size();
//     for(int i = 0; i < l/2; ++i)
//     {
//       if((ptrs[i] != nullptr) && (ptrs[l-i-1] != nullptr) && (ptrs[i]->val != ptrs[l-i-1]->val))
//       {
//         return false;
//       }
//     }
    
//     return true;
  }
};