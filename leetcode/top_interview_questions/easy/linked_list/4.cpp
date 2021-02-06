#include <iostream>
#include <vector>

using namespace std;

/*
  Q: Merge Two Sorted Lists

  Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

  Example 1:
    Input: l1 = [1,2,4], l2 = [1,3,4]
    Output: [1,1,2,3,4,4]

  Example 2:
    Input: l1 = [], l2 = []
    Output: []

  Example 3:
    Input: l1 = [], l2 = [0]
    Output: [0]

  Constraints:
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both l1 and l2 are sorted in non-decreasing order.
*/

struct ListNode 
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
      ListNode* ans = NULL;
      ListNode* node = ans;
      
      while((l1 != NULL) && (l2 != NULL))
      {
        if(l1->val <= l2->val)
        {
          if(node == NULL)
          {
            node = l1;
            ans = node;
          }
          else
          {
            node->next = l1;
            node = node->next;
          }
          
          l1 = l1->next;
        }
        else
        {
          if(node == NULL)
          {
            node = l2;
            ans = node;
          }
          else
          {
            node->next = l2;
            node = node->next;
          }
          
          l2 = l2->next;
        }
      }
      
      while(l1 != NULL)
      {
        if(node != NULL)
        {
          node->next = l1;
          node = node->next;
        }
        else
        {
          node = l1;
          ans = node;
        }
        
        l1 = l1->next;
      }
      
      while(l2 != NULL)
      {
        if(node != NULL)
        {
          node->next = l2;
          node = node->next;
        }
        else
        {
          node = l2;
          ans = node;
        }
        
        l2 = l2->next;
      }
      
      return ans;
      //O(3n)
//       vector<int> v;
      
//       while(l1 != NULL)
//       {
//         v.push_back(l1->val);
//         l1 = l1->next;
//       }
      
//       while(l2 != NULL)
//       {
//         v.push_back(l2->val);
//         l2 = l2->next;
//       }
      
//       sort(v.begin(), v.end());
      
//       int l = v.size();
//       ListNode* retVal = NULL;
//       ListNode* p = retVal;
//       for(int i = 0; i < l; i++)
//       {
//         ListNode* n = new ListNode(v[i]);
//         if(p == NULL)
//         {
//           p = n;
//           retVal = p;
//         }
//         else
//         {
//           p->next = n;
//           p = p->next;
//         }
//       }
      
//       return retVal;
    }
};