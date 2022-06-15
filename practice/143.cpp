#include<bits/stdc++.h>
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
private:
  void reorder(ListNode* node, ListNode*& movingNode, bool& reorderComplete)
  {
    if(node == nullptr)
    {
      return;
    }
    
    reorder(node->next, movingNode, reorderComplete);
    
    if(reorderComplete)
    {
      return;
    }

    if(movingNode == node)
    {
      reorderComplete = true;
      return;
    }
    
    ListNode* nextMovingNode = movingNode->next;
    if(nextMovingNode == node)
    {
      movingNode = nextMovingNode;
      reorderComplete = true;
      return;
    }
    
    movingNode->next = node;
    node->next = nextMovingNode;
    movingNode = nextMovingNode;
  }
  
public:
  void reorderList(ListNode* head) 
  {
    bool reorderComplete = false;
    ListNode* movingNode = head;
    reorder(head, movingNode, reorderComplete);
    movingNode->next = nullptr;
  }
};