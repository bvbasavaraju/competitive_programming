#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
  ListNode* deleteDuplicates(ListNode* head) 
  {
    ListNode* node = head;
    
    if(node == nullptr || node->next == nullptr)
    {
      return head;
    }
    
    unordered_map<int, int> freq;
    while(node != nullptr)
    {
      freq[node->val]++;
      node = node->next;
    }
    
    node = head;
    ListNode* root  = nullptr;
    ListNode* node_  = nullptr;
    while(node != nullptr)
    {
      if(freq[node->val] == 1)
      {
        if(node_ != nullptr)
        {
          node_->next = new ListNode(node->val);
          node_ = node_->next;
        }
        else
        {
          node_=  new ListNode(node->val);;
          root = node_;
        }
      }
      
      node = node->next;
    }
    
    return root;

//    for below code!! edge case [1,1,2,2] is failing!!
//     int val = node->val;
//     ListNode* prev = node;
//     ListNode* prevToPrev = nullptr;
//     node = node->next;
//     bool rootIsSafe = false;
//     while(node != nullptr)
//     {
//       if(node->val != val)
//       {
//         prevToPrev = prev;
//         prev = node;
//         val = node->val;
//         node = node->next;
        
//         rootIsSafe = true;
//       }
//       else
//       {
//         while(node != nullptr && node->val == val)
//         {
//           node = node->next;
//         }
        
//         if(prevToPrev != nullptr)
//         {
//           prevToPrev->next = node;
//           prev = prevToPrev;
//         }
        
//         if(!rootIsSafe)
//         {
//           head = node;
//         }
//       }
//     }
    
//     return rootIsSafe ? head : nullptr;
  }
};