#include <iostream>
#include <vector>

using namespace std;

/*
  Q: Reverse Linked List

  Reverse a singly linked list.

  Example:
    Input: 1->2->3->4->5->NULL
    Output: 5->4->3->2->1->NULL

  Follow up:
    A linked list can be reversed either iteratively or recursively. Could you implement both?
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
  void getPrevious(ListNode* node, ListNode*& prev, ListNode*& ans)
  {
    if(node == nullptr)
    {
      ans = prev;
      return;
    }
    
    getPrevious(node->next, node, ans);
    node->next = prev;
  }
public:
  ListNode* reverseList(ListNode* head) 
  {
    //recursive approach
    // ListNode* ans = nullptr;
    // ListNode* start = nullptr;
    // getPrevious(head, start, ans); 
    
    //Iterative approach
    vector<ListNode*> ptrs;
    while(head != nullptr)
    {
      ptrs.push_back(head);
      head = head->next;
    }
    
    int l = ptrs.size();
    if(l > 0)
    {
      for(int i = l-1; i > 0; --i)
      {
        ptrs[i]->next = ptrs[i-1];
      }
      ptrs[0]->next = nullptr;

      return ptrs[l-1];
    }
    
    return nullptr;
  }
};